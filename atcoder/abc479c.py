import sys

input = lambda: sys.stdin.readline().rstrip("\r\n")


def mi():
    return map(int, input().split())


def subset_sums(a):
    # Input: list a (len <= ~20). Output: list of all 2^n subset sums.
    sums = [[0, 0]]
    for x, y in a:
        sums += [[s[0] + x, s[1] + y] for s in sums]
    return sums


n, w = mi()
weight_val = []
for i in range(n):
    weight_val.append([0, 0])
    weight_val[i][1], weight_val[i][0] = mi()

possible = subset_sums(weight_val)
cur_ans = 0
# print(possible)

for i in range(len(possible)):
    if possible[i][0] <= w and possible[i][1] > cur_ans:
        cur_ans = possible[i][1]

print(cur_ans)
