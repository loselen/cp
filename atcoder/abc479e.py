import sys
from itertools import accumulate

input = lambda: sys.stdin.readline().rstrip("\r\n")


def ii():
    return int(input())


def mi():
    return map(int, input().split())


def euler_tour(adj, root=0):
    n = len(adj)
    tin = [0 for _ in range(n)]
    tout = [0 for _ in range(n)]
    flat = []
    seen = [False for _ in range(n)]
    seen[root] = True
    st = [(root, 0)]
    while st:
        u, i = st.pop()
        if i == 0:
            tin[u] = len(flat)
            flat.append(u)
        if i < len(adj[u]):
            st.append((u, i + 1))
            v = adj[u][i]
            if not seen[v]:
                seen[v] = True
                st.append((v, 0))
        else:
            tout[u] = len(flat)
    return tin, tout, flat


def range_add_offline(n, updates):
    d = [0 for _ in range(n + 1)]
    for l, r, v in updates:
        d[l] += v
        d[r + 1] -= v
    return list(accumulate(d[:n]))


n = ii()

edges = []
graph = [[] for _ in range(n)]
for i in range(n - 1):
    src, dest = mi()
    src -= 1
    dest -= 1
    graph[src].append(dest)
    graph[dest].append(src)
    edges.append((src, dest))

tin, tout, flat = euler_tour(graph)

print((tin, tout, flat))

updates = []
for i, (u, v) in enumerate(edges):
    src = u if tin[u] > tin[v] else v
    cur_size = tout[src] - tin[src]
    if cur_size > n - cur_size:
        updates.append((tin[src], tout[src] - 1, i + 1))
    else:
        updates.append((0, n - 1, i + 1))
        updates.append((tin[src], tout[src] - 1, -(i + 1)))

added = range_add_offline(n, updates)
ans = [(idx, val) for idx, val in zip(flat, added)]
ans = sorted(ans, key=lambda x: x[0])

for i in range(n):
    print(ans[i][1], end=" ")
print()
