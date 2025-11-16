# from functools import cache

def main():
    t = int(input())
    for _ in range(t):
        [n, k] = map(int, input().strip().split())

        graph = {}
        subtrees = {}
        for i in range(1, n + 1):
            graph[i] = []
            subtrees[i] = 1
        
        for _ in range(n - 1):
            [a, b] = map(int, input().strip().split())
            graph[a].append(b)
            graph[b].append(a)

        stack = [(1, None, False)]
        while stack:
            cur, prev, done = stack.pop()
            if not done:
                stack.append((cur, prev, True))
                for neigh in graph[cur]:
                    if neigh != prev:
                        stack.append((neigh, cur, False))
            else:
                for neigh in graph[cur]:
                    if neigh != prev:
                        subtrees[cur] += subtrees[neigh]
        
        res = 0

        # for each node, it can be split as:
        #   1. number of nodes in its subtree (subtrees[i])
        #   2. number of nodes not in its subtree (n - subtrees[i])
        #
        # if subtrees[i] >= k, then all _roots_ in the n - subtrees[i] nodes would be countable
        # if (n - subtrees[i]) >= k, then all _roots_ in the subrees[i] nodes would be countable
        for i in range(1, n + 1):
            if subtrees[i] >= k:
                res += n - subtrees[i]
            if n - subtrees[i] >= k:
                res += subtrees[i]
        
        # the above doesn't account for the case of selecting i iself as the root of the entire tree,
        # so add n to compensate
        print(res + n)


if __name__ == "__main__":
    main()
