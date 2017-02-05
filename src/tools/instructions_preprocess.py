import sys
import re

'''
    Preprocess the original instructions.cpp for better performance
'''

prefixes = { 0: 0, 0xDD: 1, 0xFD: 2, 0xED: 3, 0xCB: 4 }
test = []

def process(lines):
    ''' Map the original std::unordered_map to an std::array '''
    for key, line in enumerate(lines):
        result = re.match(r"\s*(opcode\s+oc|oc)\s*=\s*{(0x[\d\w]+|[\d\w]+),(0x[\d\w]+|[\d\w]+),(0x[\d\w]+|[\d\w]+)};", line)
        if (result != None):
            is_declaration = True if result.group(1) == "opcode oc" else False
            prefix1 = int(result.group(2), 0)
            prefix2 = int(result.group(3), 0)
            byte    = int(result.group(4), 0)
            oc = ((prefixes[prefix1] + 4) if prefix1 > 0 else 0) * 256 + (prefixes[prefix2]) * 256 + byte
            if oc not in test:
                test.append(oc)
            else:
                print("collision!")
                return
            lines[key] = "    int " if is_declaration else "    "
            lines[key] = lines[key] + "oc = " + str(oc) + ";\n"

def main():
    lines = []
    with open(sys.argv[1]) as f:
        lines = f.readlines();
    process(lines)
    with open(sys.argv[1] + ".new", "w") as f:
        f.writelines(lines)

if __name__ == "__main__":
    main()