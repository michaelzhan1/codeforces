#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <vector>

int main()
{
    int n;
    std::cin >> n;

    std::unordered_map<std::string, long long> score_map;

    std::vector<std::pair<std::string, long long>> scores;

    std::string name;
    long long score;
    for (int i = 0; i < n; ++i)
    {
        std::cin >> name >> score;
        score_map[name] += score;

        scores.push_back({name, score});
    }

    long long m = std::max_element(
                score_map.begin(), score_map.end(), [](const auto &p1, const auto &p2)
                { return p1.second < p2.second; })
                ->second;

    std::unordered_set<std::string> winners;
    for (const auto& [key, value] : score_map) {
        if (value == m) {
            winners.insert(key);
        }
    }

    if (winners.size() == 1) {
        std::cout << *winners.begin() << std::endl;
    } else {
        score_map.clear();
        for (const auto& p : scores) {
            score_map[p.first] += p.second;

            auto it = winners.find(p.first);
            if (score_map[p.first] >= m && it != winners.end()) {
                std::cout << p.first << std::endl;
                break;
            }
        }
    }


    return 0;
}
