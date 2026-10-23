# %%

import sys

input = lambda: sys.stdin.readline().rstrip("\r\n")


def ii():
    return int(input())


def mi():
    return map(int, input().split())


def li():
    return list(map(int, input().split()))


n = ii()
nums = li()
sum = 0

for i in range(0, n, 2):
    sum += nums[i]

print(sum)
