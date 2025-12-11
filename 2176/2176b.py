def read(to_type):
    return to_type(input())

def read_arr(to_type):
    return list(map(to_type, input().strip().split()))

def main():
    t = read(int)
    for _ in range(t):
        n = read(int)
        s = read(str)

        s += s # account for cyclic string
        res = 0
        i = 0
        while i < len(s):
            count = 0
            while i < len(s) and s[i] == '0':
                count += 1
                i += 1
            i += 1
            res = max(res, count)
        print(res)


if __name__ == "__main__":
    main()
