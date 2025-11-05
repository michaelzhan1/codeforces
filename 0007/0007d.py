from collections import defaultdict

def main():
    s = input()

    mod1 = 10**9 + 7
    base = 91138233

    h1 = 0
    rh1 = 0
    pow1 = 1
    counts = defaultdict(int)
    res = 0
    for i, ch in enumerate(s):
        v = ord(ch)
        h1 = (h1 * base + v) % mod1
        rh1 = (rh1 + v * pow1) % mod1
        if h1 == rh1:
            counts[i] = 1 + counts[(i - 1) // 2]
            res += counts[i]
        pow1 = (pow1 * base) % mod1
    print(res)

if __name__ == "__main__":
    main()
