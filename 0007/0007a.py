import sys

def main():
    board = [line.strip() for line in sys.stdin]

    res = 0
    for i in range(8):
        if board[i] == 'B' * 8:
            res += 1
    
    if res < 8:
        for j in range(8):
            if "".join(board[i][j] for i in range(8)) == 'B' * 8:
                res += 1
    
    print(res)

if __name__ == "__main__":
    main()
