#include <iostream>
#include <cmath>

//Declaration of function
int main();

//Definition of function
int main()
{
    int x{0};
    bool is_True{1};
    
    //Variable
    int n{0};
    //Never say n = a value, always say n is assigned a value 

    //Standard (std) commands from iostream
    std::cout << "Hello World" << std::endl;
    std::cin >> n;
    std::cout << "n = " << n << std::endl;

    //Conditional operators (if, else if, else)
    if (n > 0)
    {
        //Only if this condition is true
    }
    else if(n == 0)
    {
        //Only runs if the first failed and this condition is true
    }
    else
    {
        //Only occurs if all other conditions are false
    }

    //Logical operators (and, not, or)

    //AND
    if ((x >= -10) && (x <= 10))
    {
        //Runs if and only if both statements are true
    }

    //OR
    if ( (x<50) || (x>-50) )
    {
        //Runs if either one of the conditions is true
    }

    //NOT
    if (!is_True);
    {
        //Runs if the opposite of the condition is true (in this case when is_True is false)
    }
    return 0;

    //Is a coordinate inside a circle of radius 100
    int xcord{0};
    int ycord{0};

    std::cout << "Enter the x coordinate" << std::endl;
    std::cin >> xcord;
    std::cout << "Enter the y coordinate" << std::endl;
    std::cin >> ycord;

    if ((xcord * xcord + ycord * ycord) <= 100)
    {
        std::cout << "The point is inside a circle of radius 100" << std::endl;
    }
    else
    {
        std::cout << "The point is outside the circle" << std::endl;
    }
    for (int x{0};x >= 100; ++x )
    {
        // Consists of a declaration, condition, and 
    }
}
//Identifiers: Start[_a-zA-Z] Rest[_a-zA-Z0-9]