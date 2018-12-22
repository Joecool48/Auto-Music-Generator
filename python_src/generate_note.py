import sys
import struct
if len(sys.argv) < 4:
    print("Must specify path of output file, sample number, and number of samples")
file = open(sys.argv[1], "wb")
b = b""
for i in range(0, int(sys.argv[3])):
    b += struct.pack("<H", int(sys.argv[2]))[0:]
print(b)
file.write(b)
file.flush()
