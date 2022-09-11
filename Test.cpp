#include <iostream>

int main();

int main()
{
    int End {20};
    for (int start {1}; start >= End; ++start)
    {
        std::cout << start << std::endl;
    }
    return 0;

}