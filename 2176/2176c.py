def read(to_type):
    return to_type(input())

def read_arr(to_type):
    return list(map(to_type, input().strip().split()))

def main():
    t = read(int)
    for _ in range(t):
        n = read(int)
        arr = read_arr(int)
        evens = [x for x in arr if x % 2 == 0]
        odds = [x for x in arr if x % 2 == 1]
        evens.sort()
        odds.sort()

        if len(odds) == 0:
            print(' '.join(['0'] * n))
            continue

        # take largest odd and increasing amount of evens, for len(evens)
        res = [odds[-1]]
        for i in range(len(evens) - 1, -1, -1):
            res.append(res[-1] + evens[i])
        
        # then to burn any odds, alternate 2nd to largest even_res, then largest even_res
        last = res[-1]
        last2 = res[-2] if len(res) >= 2 else 0
        for i in range(len(odds) - 1):
            if i % 2 == 0:
                res.append(last2)
            else:
                res.append(last)
        if len(odds) % 2 == 0:
            res[-1] = 0

        print(' '.join(map(str, res)))


if __name__ == "__main__":
    main()
