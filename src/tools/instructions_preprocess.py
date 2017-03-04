import sys
import re

'''
    Preprocess the original instructions.cpp for better performance
'''

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
                # print("\"" + prev_operands[0] + "\"" + " ; " + "\"" + prev_operands[1] + "\"")
                # print(prev_comment)
                good = False

        i += 1
    if good:
        print("Sanity check successful")

def parse_timing(lines):
    '''
        Parse the input timing File
        Credit and big thanks to Spektre http://stackoverflow.com/users/2521214/spektre
        from http://stackoverflow.com/questions/15692091/whats-the-proper-implementation-for-hardware-emulation/18911590#18911590
    '''

def add_timing(lines, timings):
    ''' Add timing (machine cycles) information to instructions '''
    pass

def validate_timing(lines, timings):
    ''' Validate instructions timing information '''
    pass

def main():
    lines = []
    with open(sys.argv[1]) as file:
        lines = file.readlines();
    process(lines)
    with open(sys.argv[1] + ".new", "w") as file:
        file.writelines(lines)
    validate(lines)

if __name__ == "__main__":
    main()
