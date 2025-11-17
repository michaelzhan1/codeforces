def read(to_type):
    return to_type(input())

def read_arr(to_type):
    return list(map(to_type, input().strip().split()))

def main():
    t = read(int)
    for _ in range(t):
        n = read(int)
        arr = read_arr(int)
        cost = read_arr(int)

        # sum up the most costful non-decreasing subsequence, then patch up the rest (in cost)
        dp = list(cost)
        for i in range(n):
            for j in range(i):
                if arr[i] >= arr[j]:
                    dp[i] = max(dp[i], dp[j] + cost[i])
        
        print(sum(cost) - max(dp))


if __name__ == "__main__":
    main()
