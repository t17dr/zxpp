'''
    Preprocess the original instructions.cpp for better performance,
    add more timing information, perform automatic correctness checks

    Usage:
        python instructions_preprocess.py <instructions.orig>
        Creates <instructions.orig>.new in the same directory
'''

import sys
import re

PREFIXES = {0: 0, 0xDD: 1, 0xFD: 2, 0xED: 3, 0xCB: 4}
TEST = []

def process(lines):
    ''' Map the original std::unordered_map to an std::array '''
    for key, line in enumerate(lines):
        result = \
        re.match(r"\s*(opcode\s+oc|oc)\s*=\s*{(0x[\d\w]+|[\d\w]+),(0x[\d\w]+|[\d\w]+),(0x[\d\w]+|[\d\w]+)};",\
        line)
        if result != None:
            is_declaration = True if result.group(1) == "opcode oc" else False
            prefix1 = int(result.group(2), 0)
            prefix2 = int(result.group(3), 0)
            byte = int(result.group(4), 0)
            opcode = ((PREFIXES[prefix1] + 4) if prefix1 > 0 else 0) \
             * 256 + (PREFIXES[prefix2]) * 256 + byte
            if opcode not in TEST:
                TEST.append(opcode)
            else:
                print("collision!")
                return
            lines[key] = "    int " if is_declaration else "    "
            lines[key] = lines[key] + "oc = " + str(opcode) + ";\n"

def validate(lines):
    ''' Basic instruction sanity check using the mnemonic comments '''

    prev_bytes = 0

    i = 1
    good = True

    for line in lines:
        line = re.sub("\n", "", line)

        comment = \
        re.match(r"\s*//\s*([\w]+)(\s+[\w\s\d\(\)\-\>\+\']+)?(,([\w\s\d\(\)\-\>\+\']+))?\s*", line)
        if comment != None:
            instruction = comment.group(1)
            operands = [str(comment.group(2)) if comment.group(2) else "",
                        str(comment.group(4)) if comment.group(4) else ""]

            # remove everything except n, nn or d
            operands = [re.sub(r"(?!n|nn|d).", "", op, re.DOTALL) for op in operands]

            num_bytes = 0
            if "nn" in operands:
                num_bytes = 2
            elif ("n" in operands) and ("d" in operands):
                num_bytes = 2
            elif ("n" in operands) or ("d" in operands):
                num_bytes = 1

            prev_bytes = num_bytes

        instruction = re.match(r"\s*i\s*=\s*\{\s*\d+\s*,\s*\d+\s*,\s*(\d+).*", line)
        if instruction != None:
            num_bytes = int(instruction.group(1))
            if prev_bytes != num_bytes:
                print("Sanity check failed: line " + str(i))
                print("Should have " + str(prev_bytes) + " bytes, has " + str(num_bytes))
                good = False

        i += 1
    if good:
        print("Sanity check successful")

def count_valid_cycles(cycles):
    return sum(1 for cycle in cycles if cycle[1] > 0)

def parse_timing(lines):
    '''
        Parse the input timing File
        Credit and big thanks to Spektre http://stackoverflow.com/users/2521214/spektre
        from http://stackoverflow.com/questions/15692091/whats-the-proper-implementation-for-hardware-emulation/18911590#18911590
    '''

    print("Parsing timing database", end="")
    i = 0

    timings = []
    for line in lines:

        if i % 20 == 0:
            print(".", end="")
        i += 1

        inst = re.match(r"([\w\d]+)\s+(\d+)\s+(\d+)\s+([\w\d\.]+)\s+(\d)+\s+([\w\d\.]+)\s+(\d)+\s+([\w\d\.]+)\s+(\d)+\s+([\w\d\.]+)\s+(\d)+\s+([\w\d\.]+)\s+(\d)+\s+([\w\d\.]+)\s+(\d)+\s+([\w\d\.]+)\s+(\d)+(.+)", line)
        if inst != None:
            dic = {"opcode": inst.group(1), \
                   "t0": int(inst.group(2)), \
                   "t1": int(inst.group(3)), \
                   "cycles": ( \
                       (inst.group(4), int(inst.group(5))), \
                       (inst.group(6), int(inst.group(7))), \
                       (inst.group(8), int(inst.group(9))), \
                       (inst.group(10), int(inst.group(11))), \
                       (inst.group(12), int(inst.group(13))), \
                       (inst.group(14), int(inst.group(15))), \
                       (inst.group(16), int(inst.group(17))), \
                    ), \
                    "mnemonic": inst.group(18) \
                    }
            dic["cntCycles"] = count_valid_cycles(dic["cycles"])
            timings.append(dic)
        else:
            print("Error parsing line in timings table.")

    print("")   # Newline

    return timings

def parse_opcode(opcode):
    """ Parse opcode string from timings.txt """
    parsed = re.match(r"([A-Fa-f\d]+)", opcode)
    dic = {}
    if parsed != None:
        opcode_bytes = []
        for i in range(0, len(parsed.group(1)), 2):
            opcode_bytes.append(parsed.group(1)[i:i+2])
        dic["bytes"] = opcode_bytes
    else:
        print("Failed to parse opcode")

    opcode_data = opcode[len(parsed.group(1)):]  # remove already parsed part
    has_word = False
    high_first = False
    opcode_byte_last = False
    data = []
    while len(opcode_data) > 0:
        parsed = re.match(r"(L\d|H\d|U\d|S\d|[A-Fa-f\d][A-Fa-f\d])", opcode_data)
        if parsed != None:
            typ = parsed.group(1)[0]
            if typ.lower() == "l" or typ.lower() == "h":
                if not has_word:
                    if typ.lower() == "h":
                        high_first = True
                    else:
                        high_first = False
                has_word = True
            is_byte = re.match(r"[A-Fa-f\d][A-Fa-f\d]", parsed.group(1))
            if is_byte != None:
                data.append(is_byte.group(0))
                opcode_byte_last = True
            else:
                data.append(typ)
            opcode_data = opcode_data[len(parsed.group(1)):]
        else:
            print("Error parsing opcode data")
            break
    dic["data"] = data
    dic["has_word"] = has_word
    dic["opcode_byte_last"] = opcode_byte_last
    if has_word:
        dic["high_first"] = high_first

    return dic

def parsed_opcode_to_list(opcode):
    ''' Create a list of bytes from parsed opcode from parse_opcode() '''
    opcode_bytes = opcode["bytes"]
    if opcode["opcode_byte_last"]:
        opcode_bytes.append(opcode["data"][-1])
    opcode_bytes = [int(x, 16) for x in opcode_bytes]
    while len(opcode_bytes) < 3:
        opcode_bytes.insert(0, 0)
    return opcode_bytes

def find_timing(opcode, timings):
    ''' Find timing entry by opcode '''
    # print(timings[12])
    # print(parse_opcode(timings[12]["opcode"]))
    # print(parsed_opcode_to_list(parse_opcode(timings[12]["opcode"])))
    # print(opcode)
    for row in timings:
        if opcode == parsed_opcode_to_list(parse_opcode(row["opcode"])):
            return row
    return False

CYCLES_ENUM = {"...": "MachineCycleType::UNUSED",\
               "M1R": "MachineCycleType::M1R",\
               "MRD": "MachineCycleType::MRD",\
               "MWR": "MachineCycleType::MWR",\
               "IOR": "MachineCycleType::IOR",\
               "IOW": "MachineCycleType::IOW",\
               "NON": "MachineCycleType::NON"}

def insert_timing(line, current_timing, bracket_pos):
    """ Insert given timing information to an instruction """
    edited = ""
    edited = line[0:bracket_pos+1] + ",\n        "
    edited += str(current_timing["cntCycles"]) + ", "
    edited += "{ "
    edited += ", ".join([CYCLES_ENUM[x[0]] for x in current_timing["cycles"]])
    edited += " },\n        "
    edited += "{ "
    edited += ", ".join([str(x[1]) for x in current_timing["cycles"]])
    edited += " }\n   "

    edited += line[bracket_pos+1:]

    return edited

def add_timing(lines, timings):
    ''' Add timing (machine cycles) information to instructions '''
    open_brackets = close_brackets = 0
    current_opcode = [0, 0, 0]
    current_timing = None

    print("Adding timing information", end="")

    i = 0
    for key, line in enumerate(lines):

        if i % 175 == 0:
            print(".", end="")
        i += 1

        is_oc = re.match(r"\s*(oc|opcode oc)\s*\=\s*\{\s*([a-zA-Z\dx]+)\s*,\s*([a-zA-Z\dx]+)\s*,\s*([a-zA-Z\dx]+)\}", line)
        if is_oc != None:
            current_opcode = [int(is_oc.group(2), 16), \
                              int(is_oc.group(3), 16), \
                              int(is_oc.group(4), 16)]
            current_timing = find_timing(current_opcode, timings)

        is_inst = re.match(r"\s*(i|Instruction i)\s*\=\s*\{", line)
        if is_inst != None:
            open_brackets = line.count("{")
            close_brackets = line.count("}")
            if open_brackets == close_brackets:
                # find second to last occurence of }
                inst_close = line.rfind("}", 0, line.rfind("}"))

                lines[key] = insert_timing(line, current_timing, inst_close)
        elif open_brackets > close_brackets:
            if line.find("{") != -1:
                open_brackets += 1

            bracket = line.find("}")
            if bracket != -1:
                close_brackets += 1
                if open_brackets == close_brackets + 1:
                    lines[key] = insert_timing(line, current_timing, bracket)

    print("")   # Newline


def validate_timing(lines, timings):
    ''' Validate instructions timing information '''
    pass

def validate_operands(lines, timings):
    ''' Validate operand size and order '''
    pass

def main():
    lines = []
    timings_lines = []
    with open(sys.argv[1]) as file:
        lines = file.readlines()

    with open("timings.txt") as file:
        timings_lines = file.readlines()
    timings = parse_timing(timings_lines)
    add_timing(lines, timings)

    process(lines)

    with open(sys.argv[1] + ".new", "w") as file:
        file.writelines(lines)
    validate(lines)

if __name__ == "__main__":
    main()
