#include <iostream>

int main();

int main()
{
    int CAD {0};
    std::cout << "Enter a currency in CAD:" << std::endl;
    std::cin >> CAD;

    double US;

    US = CAD / 1.3;

    std::cout << "There are " << US << " USD." << std:: endl;
    std::cout << "There are " << ceil(US*0.86) << " Pound sterling." << std::endl;
    std::cout << "There are " << ceil(US*0.87) << " Euro." << std::endl;
    std::cout << "There are " << ceil(US*100) << " US penny" << std::endl;
}