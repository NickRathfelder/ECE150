#include <iostream>
#include <climits>

#ifndef MARMOSET_TESTING
int main();
#endif

int ex(int n, int m);

int ex(int n, int m)
{
	int result{1};
	for(int f = 0;f < m; ++f)
	{
		result *=n;
	}
	return result;
}
unsigned int add_checksum( unsigned int n );

unsigned int add_checksum(unsigned int n)
{
	int d{0};
	bool isfinished {0};

	if ((n > 0) && (n <= 99999999))
	{
		int tempN{0};
		int temp{0};
		int sum{0};

		tempN = n;
		for (int i{7}; i >= 0; --i)
		{
			if (tempN /(ex(10,i)) == 0 )
			{
				continue;
			}
			else if (i % 2 == 0)
			{
				temp = (tempN/(ex(10,i))) * 2;
				while(temp > 9)
				{
					temp = (temp/10) + (temp%10);
				}
			}
			else
			{
				temp = tempN/(ex(10,i));
			}
			sum += temp;
			tempN = tempN % (ex(10,i));
		}
		d = (sum*9) % 10;
		n = n * 10 + d;

	return n;

	} 
	else
	{
		return (UINT_MAX);
	}
}
void add_checksum( unsigned int array[], std::size_t capacity );

void add_checksum( unsigned int array[], std::size_t capacity )
{
	for(int i = 0; i < capacity;i++)
	{
		array[i] = add_checksum(array[i]);
	}
}

bool verify_checksum( unsigned int n );

bool verify_checksum( unsigned int n )
{
	int newN{n/10};
	if ((n == add_checksum(newN)) && (n <= 999999999))
	{
		return true;
	}
	else
	{
		return false;
	}
}

unsigned int remove_checksum( unsigned int n );

unsigned int remove_checksum( unsigned int n )
{
	if((n > 999999999) || (verify_checksum(n) == false))
	{
		return UINT_MAX;
	}
	else
	{
		return(n/10);
	}
}

void remove_checksum( unsigned int array[], std::size_t capacity );

void remove_checksum( unsigned int array[], std::size_t capacity )
{
	for (int i = 0; i < capacity;i++)
	{
		array[i] = remove_checksum(array[i]);
	}
}

#ifndef MARMOSET_TESTING
int main() {
	unsigned int value_to_protect{12345678};
	unsigned int protected_value = add_checksum(value_to_protect);
	std::cout << "The value " << value_to_protect
		<< " with the checksum added is " << protected_value
		<< "." << std::endl;
	
	if (verify_checksum(protected_value))
	{
		std::cout << "The checksum is valid." << std::endl;
	}
	else   {
		std::cout << "The checksum is invalid." << std::endl;
	} 
	
	const std::size_t QTY_VALUES {3};
	unsigned int value_series[QTY_VALUES] {123456782, 854398, 234324};
	
	remove_checksum(value_series, QTY_VALUES);
	
	std::cout << "Series with checksums removed: ";
	for (std::size_t series_index {0};
		series_index < QTY_VALUES; series_index++)
	{
		std::cout << value_series[series_index] << " ";
	}

    std::cout << std::endl;
	
    return 0;
}
#endif