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
    dir2 = [[""] * n for _ in range(n)]
    dir5 = [[""] * n for _ in range(n)]
    factors = count_factors(arr[-1][-1])
    dp2[-1][-1] = factors
    dp5[-1][-1] = factors

    for i in range(n - 2, -1, -1):
        factors_i = count_factors(arr[i][-1])
        dp2[i][-1] = add(factors_i, dp2[i + 1][-1])
        dp5[i][-1] = add(factors_i, dp5[i + 1][-1])
        dir2[i][-1] = "D" + dir2[i + 1][-1]
        dir5[i][-1] = "D" + dir5[i + 1][-1]

        factors_j = count_factors(arr[-1][i])
        dp2[-1][i] = add(factors_j, dp2[-1][i + 1])
        dp5[-1][i] = add(factors_j, dp5[-1][i + 1])
        dir2[-1][i] = "R" + dir2[-1][i + 1]
        dir5[-1][i] = "R" + dir5[-1][i + 1]

    for i in range(n - 2, -1, -1):
        for j in range(n - 2, -1, -1):
            factors = count_factors(arr[i][j])

            # dp2 takes minimum 2 route
            if dp2[i + 1][j][0] < dp2[i][j + 1][0]:
                dp2[i][j] = add(factors, dp2[i + 1][j])
                dir2[i][j] = "D" + dir2[i + 1][j]
            else:
                dp2[i][j] = add(factors, dp2[i][j + 1])
                dir2[i][j] = "R" + dir2[i][j + 1]
            
            # dp5 takes minimum 5 route
            if dp5[i + 1][j][1] < dp5[i][j + 1][1]:
                dp5[i][j] = add(factors, dp5[i + 1][j])
                dir5[i][j] = "D" + dir5[i + 1][j]
            else:
                dp5[i][j] = add(factors, dp5[i][j + 1])
                dir5[i][j] = "R" + dir5[i][j + 1]
    
    min2 = min(dp2[0][0])
    min5 = min(dp5[0][0])
    if min2 < min5:
        print(min2)
        print(dir2[0][0])
    else:
        print(min5)
        print(dir5[0][0])

            

if __name__ == "__main__":
    main()
