#include <iostream>
#include <cmath>

//Declaration of function
int main();

//Definition of function
int main()
{
    //Variable
    int n{0};
    //Never say n = a value, always say n is assigned a value 

    //Standard (std) commands from iostream
    std::cout << "Enter an integer" << std::endl;
    std::cin >> n;
    std::cout << "n = " << n << std::endl;

    //Conditional operators (if, else if, else)
    if (n > 0)
    {
        std::cout << "n (=" << n << " ) is positive"
        << std::endl;
    }
    else if(n == 0)
    {
        std::cout << "n is zero" << std::endl;
    }
    else
    {
        std::cout << "n (= " << n << ") is negative" << std::endl; 
    }
    return 0;
}
//Identifiers: Start[_a-zA-Z] Rest[_a-zA-Z0-9]