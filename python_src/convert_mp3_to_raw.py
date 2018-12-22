import sys
from pydub import AudioSegment
import numpy as np
import struct
'''
def to_binary(byte_string):
    length = len(byte_string)
    idx = length - 1
    res_int = 0
    while idx >= 0:
        shift = (length - 1 - idx) * 8
        res_int |= (int(byte_string[idx]) << shift)
    return res_int

def to_samples(byte_string):
    samples = byte_string.split("\\x")
    for i in samples:
        samples[i] = to_binary(samples[i])
    return samples
def from_binary(num):
    if num == 0:
        return '\x00'
    s = ""
    arr = []
    idx = 0
    mask = 0xff
    while idx < 4:
        byte = ((mask << idx * 8) & num) >> idx * 8
        idx += 1
        arr.append(byte)
    idx = len(arr) - 1
    foundFirstNonZero = False
    while idx >= 0:
        if arr[idx] != 0:
            foundFirstNonZero = True
        if foundFirstNonZero:
            s += "\\x" + str(arr[idx])
        idx -= 1
    return s
def from_samples(samples):
    s = "b'"
    for samp in samples:
        s += from_binary(samp)
    return s
'''
def to_sample_array(binary_string):
    arr = []
    idx = 0
    for i in range(len(binary_string)):
        print(binary_string[i: i + 1])
        #arr.append(memoryview(binary_string[i: i + 1]).cast("H"))
    return arr

def from_sample_array(sample_array):
    s = "b'"
    for samp in sample_array:
        s += struct.pack("<H", sampe)
    return s

if len(sys.argv) < 3:
    print("Need more args")
    sys.exit(1)

sound = AudioSegment.from_mp3(sys.argv[1])


out_file = open(sys.argv[2], 'wb')

out_file.write(sound._data)

#out_file2 = open("test.pcm", "wb")
#out_file2.write(from_sample_array(to_sample_array(sound._data)))


