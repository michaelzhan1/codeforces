#include <iostream>
#include <string>
#include <vector>

using vi = std::vector<int>;
using vvi = std::vector<vi>;

int main()
{
    std::string start, end;
    std::getline(std::cin, start);
    std::getline(std::cin, end);

    int startCol = start[0] - 'a';
    int startRow = start[1] - '0';
    int endCol = end[0] - 'a';
    int endRow = end[1] - '0';

    int colDiff = std::abs(endCol - startCol);
    int rowDiff = std::abs(endRow - startRow);
    std::cout << std::max(colDiff, rowDiff) << std::endl;

    while (startCol != endCol || startRow != endRow)
    {
        if (endCol > startCol)
        {
            startCol++;
            std::cout << 'R';
        }
        else if (endCol < startCol)
        {
            startCol--;
            std::cout << 'L';
        }

        if (endRow > startRow)
        {
            startRow++;
            std::cout << 'U';
        }
        else if (endRow < startRow)
        {
            startRow--;
            std::cout << 'D';
        }

        std::cout << std::endl;
    }

    return 0;
}
