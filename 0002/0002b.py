from functools import cache

@cache
def count_factors(n):
    res = [0, 0]
    while n % 2 == 0:
        n //= 2
        res[0] += 1
    while n % 5 == 0:
        n //= 5
        res[1] += 1
    return res


def add(f1, f2):
    return [f1[0] + f2[0], f1[1] + f2[1]]


def main():
    n = int(input())

    arr = []
    for _ in range(n):
        arr.append(list(map(int, input().strip().split())))

    dp2 = [[None] * n for _ in range(n)]
    dp5 = [[None] * n for _ in range(n)]
    factors = count_factors(arr[-1][-1])
    dp2[-1][-1] = factors
    dp5[-1][-1] = factors

    for i in range(n - 2, -1, -1):
        factors_i = count_factors(arr[i][-1])
        dp2[i][-1] = add(factors_i, dp2[i + 1][-1])
        dp5[i][-1] = add(factors_i, dp5[i + 1][-1])

        factors_j = count_factors(arr[-1][i])
        dp2[-1][i] = add(factors_j, dp2[-1][i + 1])
        dp5[-1][i] = add(factors_j, dp5[-1][i + 1])

    for i in range(n - 2, -1, -1):
        for j in range(n - 2, -1, -1):
            factors = count_factors(arr[i][j])

            # dp2 takes minimum 2 route
            if dp2[i + 1][j][0] < dp2[i][j + 1][0]:
                dp2[i][j] = add(factors, dp2[i + 1][j])
            else:
                dp2[i][j] = add(factors, dp2[i][j + 1])
            
            # dp5 takes minimum 5 route
            if dp5[i + 1][j][1] < dp5[i][j + 1][1]:
                dp5[i][j] = add(factors, dp5[i + 1][j])
            else:
                dp5[i][j] = add(factors, dp5[i][j + 1])
    
    min2 = min(dp2[0][0])
    min5 = min(dp5[0][0])
    if min2 < min5:
        print(min2)
        dp = dp2
        idx = 0
    else:
        print(min5)
        dp = dp5
        idx = 1

    
    i = 0
    j = 0
    path = ""
    while i < n - 1 and j < n - 1:
        if dp[i + 1][j][idx] < dp[i][j + 1][idx]:
            path += "D"
            i += 1
        else:
            path += "R"
            j += 1
    
    if i < n:
        path += "D" * (n - i - 1)
    if j < n:
        path += "R" * (n - j - 1)
    print(path)
        
        


            

if __name__ == "__main__":
    main()
