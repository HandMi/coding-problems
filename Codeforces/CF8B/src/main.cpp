#include <iostream>
#include <string>
#include <vector>

bool CheckValidityOfPath(std::string path)
{
    std::vector<std::vector<bool>> map(
        2 * path.size() + 3, std::vector<bool>(2 * path.size() + 3, false));
    auto x = path.size() + 1;
    auto y = path.size() + 1;
    map[x][y] = true;
    for (const auto &direction : path)
    {
        // check for shorter paths
        bool check = false;
        switch (direction)
        {
        case 'L':
            x -= 1;
            check =
                map[x][y] || map[x - 1][y] || map[x][y + 1] || map[x][y - 1];
            break;
        case 'R':
            x += 1;
            check =
                map[x][y] || map[x + 1][y] || map[x][y + 1] || map[x][y - 1];
            break;
        case 'D':
            y -= 1;
            check =
                map[x][y] || map[x + 1][y] || map[x - 1][y] || map[x][y - 1];
            break;
        case 'U':
            y += 1;
            check =
                map[x][y] || map[x + 1][y] || map[x - 1][y] || map[x][y + 1];
            break;
        }
        if (check)
        {
            return false;
        }
        else
        {
            map[x][y] = true;
        }
    }
    return true;
}

int main()
{
    std::string path;
    std::cin >> path;
    if (CheckValidityOfPath(path))
    {
        std::cout << "OK";
    }
    else
    {
        std::cout << "BUG";
    }
    return 0;
}
