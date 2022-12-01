#include <iostream>
#include "History.hpp"
#include "Transaction.hpp"


#ifndef MARMOSET_TESTING
unsigned int Transaction::assigned_trans_id = 0;
int main() 
{
  History history{};
  history.read_history();
  std::cout << "**Unsorted** \n";
  history.print();
  std::cout << "**Sorted**\n";
  history.sort_by_date();
  history.print();
}
#endif
