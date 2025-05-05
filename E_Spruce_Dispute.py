import sys
import threading
from collections import defaultdict, deque
import heapq

def main():
    input = sys.stdin.readline
    t = int(input())
    for _ in range(t):
        n = int(input())
        adj = [[] for _ in range(n+1)]
        edges = [None]*(n)
        for i in range(1, n):
            u, v = map(int, input().split())
            edges[i] = (u, v)
            adj[u].append(v)
            adj[v].append(u)

        # 1) First DFS: compute parent1, subtree1, tin/tout, diffArr
        parent1 = [0]*(n+1)
        subtree1 = [0]*(n+1)
        tin = [0]*(n+2)
        tout = [0]*(n+2)
        diffArr = [0]*(n+2)
        timer = 0

        stack = [(1, 0, 0)]  # (v, parent, next_child_index)
        while stack:
            v, p, idx = stack.pop()
            if idx == 0:
                parent1[v] = p
                subtree1[v] = 1
                timer += 1
                tin[v] = timer
            if idx < len(adj[v]):
                u = adj[v][idx]
                stack.append((v, p, idx+1))
                if u != p:
                    stack.append((u, v, 0))
            else:
                tout[v] = timer
                if p != 0:
                    sz = subtree1[v]
                    oth = n - sz
                    if sz <= oth:
                        diffArr[tin[v]]   += 1
                        diffArr[tout[v]+1] -= 1
                    else:
                        diffArr[1]        += 1
                        diffArr[n+1]      -= 1
                        diffArr[tin[v]]   -= 1
                        diffArr[tout[v]+1] += 1
                    subtree1[p] += subtree1[v]

        # prefix sum to get smallCount
        for i in range(1, n+1):
            diffArr[i] += diffArr[i-1]
        smallCount = [0]*(n+1)
        for v in range(1, n+1):
            smallCount[v] = diffArr[tin[v]]

        # 2) Choose best edge (A,B)
        bestL = float('inf')
        A = B = 1
        for i in range(1, n):
            x, y = edges[i]
            a, b = min(x,y), max(x,y)
            if parent1[b] == a:
                compB = subtree1[b]
            else:
                compB = n - subtree1[a]
            oth = n - compB
            orig_min = min(compB, oth)
            L = orig_min + smallCount[b] - (1 if compB <= oth else 0)
            if L < bestL:
                bestL = L
                A, B = a, b

        # 3) Rebuild adj2 by removing B and reconnecting its neighbors to A
        adj2 = [[] for _ in range(n+1)]
        for v in range(1, n+1):
            if v == B: continue
            for u in adj[v]:
                if u == B: continue
                adj2[v].append(u)
        for u in adj[B]:
            if u != A:
                adj2[A].append(u)
                adj2[u].append(A)

        # 4) Second DFS on adj2 from root=A to compute subtree3
        parent3 = [-1]*(n+1)
        subtree3 = [0]*(n+1)
        order = []
        stack = [A]
        parent3[A] = 0
        while stack:
            v = stack.pop()
            order.append(v)
            for u in adj2[v]:
                if u != parent3[v]:
                    parent3[u] = v
                    stack.append(u)
        for v in reversed(order):
            subtree3[v] = 1
            for u in adj2[v]:
                if u != parent3[v]:
                    subtree3[v] += subtree3[u]

        # 5) Find centroid cent2 of this n-1 node tree
        nodes_tprime = n-1
        cent2 = A
        bestHeavy = nodes_tprime
        for v in order:
            heavy = nodes_tprime - subtree3[v]
            for u in adj2[v]:
                if u != parent3[v]:
                    heavy = max(heavy, subtree3[u])
            if heavy < bestHeavy:
                bestHeavy = heavy
                cent2 = v

        # 6) Partition nodes (excluding B & cent2) into groups around cent2
        used = [False]*(n+1)
        used[B] = True
        used[cent2] = True

        groups = [[cent2]]
        for u in adj2[cent2]:
            if used[u]: continue
            grp = []
            dq = deque([u])
            used[u] = True
            while dq:
                w = dq.popleft()
                grp.append(w)
                for x in adj2[w]:
                    if not used[x]:
                        used[x] = True
                        dq.append(x)
            groups.append(grp)

        # 7) Pair off nodes from largest groups to assign colors
        pq = [(-len(grp), i) for i, grp in enumerate(groups) if grp]
        heapq.heapify(pq)
        color_ans = [0]*(n+1)
        color_ans[B] = 0
        cur_color = 1
        while len(pq) > 1:
            _, i1 = heapq.heappop(pq)
            _, i2 = heapq.heappop(pq)
            v1 = groups[i1].pop()
            v2 = groups[i2].pop()
            color_ans[v1] = cur_color
            color_ans[v2] = cur_color
            cur_color += 1
            if groups[i1]:
                heapq.heappush(pq, (-len(groups[i1]), i1))
            if groups[i2]:
                heapq.heappush(pq, (-len(groups[i2]), i2))

        # 8) Output A B (ensuring B is the larger) and the colors
        if max(A, B) != B:
            A, B = B, A
        print(A, B)
        print(" ".join(str(color_ans[i]) for i in range(1, n+1)))

if _name_ == "_main_":
    threading.Thread(target=main).start()