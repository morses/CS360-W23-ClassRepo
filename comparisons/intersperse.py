
# Love this "Pythonic" version, from https://stackoverflow.com/questions/5655708/python-most-elegant-way-to-intersperse-a-list-with-an-element
def intersperse(seq, value):
    res = [value] * (2 * len(seq) - 1)
    res[::2] = seq
    return res

print(f'empty string -> {"".join(intersperse("",","))}')
print(f'A -> {"".join(intersperse("A",","))}')
print(f'AB -> {"".join(intersperse("AB",","))}')
print(f'ABCDEFG -> {"".join(intersperse("ABCDEFG",","))}')

print("Using join by itself")
print(f'empty string -> {",".join("")}')
print(f'A -> {",".join("A")}')
print(f'AB -> {",".join("AB")}')
print(f'ABCDEFG -> {",".join("ABCDEFG")}')

print("And it works with other types:")
print(f'[] -> {intersperse([],"9")}')
print(f'[1] -> {intersperse([1],"9")}')
print(f'[1,2] -> {intersperse([1,2],"9")}')
print(f'[1,2,3,4,5] -> {intersperse([1,2,3,4,5],"9")}')

# And finally with an external library: pip3 install more-itertools
from more_itertools import intersperse
print("using more_itertools")
print(list(intersperse('o',"L"*6)))