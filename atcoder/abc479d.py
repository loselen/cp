import sys

input = lambda: sys.stdin.readline().rstrip("\r\n")


def mi():
    return map(int, input().split())


def li():
    return list(map(int, input().split()))


INF = float("inf")

n, q = mi()
left = [INF for _ in range(n)]
right = [INF for _ in range(n)]

left[1:] = li()
right[: n - 1] = li()

premin = [INF for _ in range(n)]
sufmin = [INF for _ in range(n)]

sufmin[-1] = left[-1]
premin[0] = right[0]

for i in range(n - 2, -1, -1):
    sufmin[i] = min(left[i], sufmin[i + 1])
for i in range(1, n):
    premin[i] = min(right[i], premin[i - 1])

for _ in range(q):
    src, dest = mi()
    src -= 1
    dest -= 1

    if src == 0:
        print(right[0])
        continue
    if src == n - 1:
        print(left[n - 1])
        continue

    if dest > src:
        print(min(right[src], left[src] + premin[src - 1]))
        continue
    if dest < src:
        print(min(left[src], right[src] + sufmin[src + 1]))
        continue
