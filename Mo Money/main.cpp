#include <iostream>
#include "History.hpp"
#include "Transaction.hpp"


#ifndef MARMOSET_TESTING
unsigned int Transaction::assigned_trans_id = 0;
int main() 
{
  Transaction *T1(new Transaction("fart",19,10,2021,true,6,53.0));
  Transaction *T2(new Transaction("balls",20,10,2020,false,6,54));

  if(*T1 < *T2)
  {
    std::cout << ", T1 is older than T2";
  }
  else
  {
    std::cout << "T1 is younger than T2 ";
  }
}
#endif
