import sys

input = lambda: sys.stdin.readline().rstrip("\r\n")


def ii():
    return int(input())


def si():
    return input()


n = ii()
s = si()

longest = 0
i = 0
while i < n:
    cur_long = 0
    while i < n and s[i] == "R":
        i += 1
        cur_long += 1
    longest = max(longest, cur_long)
    i += 1

print(longest)
