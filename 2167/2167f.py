from functools import cache

def main():
    t = int(input())
    for _ in range(t):
        [n, k] = map(int, input().strip().split())

        graph = {}
        for i in range(1, n + 1):
            graph[i] = []
        
        for _ in range(n - 1):
            [a, b] = map(int, input().strip().split())
            graph[a].append(b)
            graph[b].append(a)
    
        dp = {}
        output = 0
        for root in range(1, n + 1):
            # cur, prev, visited
            stack = [(root, None, False)]

            while stack:
                cur, prev, visited = stack.pop()

                if len(graph[cur]) == 1 and prev is not None:
                    dp[(cur, prev)] = (int(k <= 1), 1)
                    continue

                if not visited:
                    # add to revisit
                    stack.append((cur, prev, True))

                    # add children
                    for neigh in graph[cur]:
                        if neigh != prev and (neigh, cur) not in dp:
                            stack.append((neigh, cur, False))
                else: 
                    res = 0
                    node_count = 1

                    # already computed
                    for neigh in graph[cur]:
                        if neigh != prev:
                            child_res, child_count = dp[(neigh, cur)]
                            res += child_res
                            node_count += child_count
                    
                    if node_count >= k:
                        res += 1
                    dp[(cur, prev)] = (res, node_count)
            
            output += dp[(root, None)][0]
        
        print(output)


if __name__ == "__main__":
    main()
