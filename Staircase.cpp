#include <iostream>

int main();

int main()
{
    double x{};
    std::cout << "Enter value of x: ";
    std::cin >> x;

    int stair{};
    if (x >= 0)
    {
        for (int i{0}; i <= x; ++i)
        {
            if (x-i < 1.0)
            {
                stair = i;
            }
        }
    }
    else
    {
        for (int f {0}; f >=x; --f)
        {
            if ( x-f > -1.0)
            {
                stair = f-1;
            }
        }
    }
    std::cout << "The value of stair(x) is: ";
    std::cout << stair;
    std::cout << std::endl;
    return 0;
}