#include <iostream>
#include "History.hpp"
#include "Transaction.hpp"


#ifndef MARMOSET_TESTING
unsigned int Transaction::assigned_trans_id = 0;
int main() 
{
  History history{};
  Transaction *pointer{new Transaction("fart",21,10,2004,true,7,530)};
  history.insert(pointer);
}
#endif
