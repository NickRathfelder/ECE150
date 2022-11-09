#include <iostream>

int main();

int main()
{
    std::size_t i{0};
    for (int x{-1}; x<2; ++x)
    {
        if((i+x) >2)
        {
            continue;
        }
        else
        {
            std::cout << (i+x);
        }
    }

}