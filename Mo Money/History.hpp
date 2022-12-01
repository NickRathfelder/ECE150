#ifndef _HISTORY_HPP_
#define _HISTORY_HPP_

#include <iomanip>
#include <iostream>
#include <string>

#include "Transaction.hpp"

class History {
public:
	// Constructor
	//
	History();

	// Destructor.
	//
	~History();

	// Read the transaction history from file.
	//
	void read_history();

	// Insert transaction in linked list.
	//
	void insert(Transaction *p_new_trans);

	void swap(Transaction *current, Transaction *previous);
	// Sort using insertion sort.
	//
	void insertSort(Transaction *current);
	void sort_by_date();

	// Update the acb members in the linked list.
	//
	void update_acb_cgl();

	// Compute the ACB, and CGL.
	//
	double compute_cgl(unsigned int year);

	// Print the transaction history.
	//
	void print();

	Transaction *get_p_head();

private:
	Transaction *p_head;
	Transaction *p_Final;
};

#endif
