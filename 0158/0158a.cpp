#include <iostream>
#include <vector>

int main()
{
    int n, k;
    std::cin >> n >> k;
    std::vector<int> arr; // nonincreasing

    int val;
    for (int i = 0; i < n; i++)
    {
        std::cin >> val;
        arr.push_back(val);
    }

    // if 0, count all nonzero before this
    if (arr[k - 1] == 0)
    {
        for (size_t i = 0; i < arr.size(); i++)
        {
            if (arr[i] == 0)
            {
                std::cout << i << std::endl;
                break;
            }
        }
    }
    else
    {
        int val = arr[k - 1];
        size_t i = k - 1;

        while (i < arr.size() && arr[i] == val)
            i++;
        std::cout << i << std::endl;
    }

    return 0;
}
