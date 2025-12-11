from collections import defaultdict
import heapq

def read(to_type):
    return to_type(input())

def read_arr(to_type):
    return list(map(to_type, input().strip().split()))

def main():
    t = read(int)
    for _ in range(t):
        n, m = read_arr(int)
        vals = read_arr(int)
        graph = {i: set() for i in range(n)}

        for _ in range(m):
            a, b = read_arr(int)
            graph[a - 1].add(b - 1)
        
        
        # priority queue to track the lowest sum at the moment
        pq = [(val, i) for i, val in enumerate(vals)]
        heapq.heapify(pq)

        # for each node, have a map prev_value -> count of paths that got to prev_value.
        # then we can use this map to see how many times a fib series is reached
        res = 0
        counts = [defaultdict(int) for _ in range(n)]
        for node in graph:
            for neighbor in graph[node]:
                counts[neighbor][vals[node]] += 1
                res += 1

        visited = set()

        while pq:
            cur_val, cur = heapq.heappop(pq)
            if cur in visited:
                continue
            visited.add(cur)

            for prev_val, count in counts[cur].items():
                for nxt in graph[cur]:
                    nxt_val = vals[nxt]
                    if prev_val + cur_val == nxt_val:
                        counts[nxt][cur_val] += count
                        res += count
                        res %= 998244353
                        heapq.heappush(pq, (nxt_val, nxt))
        print(res)

if __name__ == "__main__":
    main()
