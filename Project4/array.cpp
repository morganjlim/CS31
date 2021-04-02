//the purpose of this program is to create a sort of library
//of common things that can be done with arrays
#include <iostream>
#include <string>
#include <cassert>
using namespace std;

//function declarations
bool hasDuplicates(const string array[], int size); //done
int  countAllDigits(const string array[], int size); //done
bool isInDecreasingOrder(const string array[], int size);
int  shiftRight(string array[], int size, int amount, string placeholder);
int  find(const string array[], int size, string match); //done
int  replaceAllCharacters(string array[], int size, char findLetter, char replaceLetter); //done

int main()

{

	string folks[8] = {"samwell", "jon", "margaery", "daenerys", "tyrion", "sansa", "howard123", "jon"};
	string people[5] = { "samwell", "jon", "margaery", "daenerys", "tyrion" };
	string names[5] = { "a", "b", "c", "d", "e" };
	string namesB[5] = {"e", "d", "c", "b", "a"};
	string list[7] = { "a100", "bottle", "face34", "geek56", "geek56","sun3day", "z3ro_s3bum"};
	string a[6] = { "alpha", "beta", "gamma", "gamma", "beta", "delta" };

	//valid test cases
	assert(hasDuplicates(a, 3) == false);
	assert(hasDuplicates(a, 6) == true);
	assert(hasDuplicates(folks, 5) == false);
	assert(hasDuplicates(folks, 8) == true);
	assert(hasDuplicates(list, 7) == true);
	assert(hasDuplicates(list, 4) == false);
	//invalid test cases; size <= 0
	assert(hasDuplicates(folks, -1) == false);
	assert(hasDuplicates(list, -5) == false);
	assert(hasDuplicates(list, 0) == false);

	//valid test cases
	assert(countAllDigits(folks, 8) == 3);
	assert(countAllDigits(list, 7) == 12);
	assert(countAllDigits(a, 6) == 0);
	assert(countAllDigits(list, 4) == 7);
	//invalid test cases; size <= 0
	assert(countAllDigits(folks, -108) == -1);
	assert(countAllDigits(list, 0) == -1);

	//valid test cases
	assert(isInDecreasingOrder(people, 5) == false);
	assert(isInDecreasingOrder(names, 5) == true);
	assert(isInDecreasingOrder(people, 0) == true);
	assert(isInDecreasingOrder(names, 1) == true);
	assert(isInDecreasingOrder(namesB, 5) == false);
	//invalid test cases
	assert(isInDecreasingOrder(names, -1) == false);
	assert(isInDecreasingOrder(namesB, -5) == false);

	//valid test cases
	assert(replaceAllCharacters(people, 5, 'z', 'a') == 0);
	assert(replaceAllCharacters(people, 5, 'a', '_') == 4);
	assert(replaceAllCharacters(list, 4, 'e', '!') == 4);
	//invalid test cases
	assert(replaceAllCharacters(people, -5, 'z', 'a') == -1);
	assert(replaceAllCharacters(list, 0, 'e', '!') == -1);

	//valid test cases
	assert(shiftRight(people, 5, 3, "foo") == 3);
	assert(shiftRight(names, 5, 4, "_") == 4);
	//invalid test cases
	assert(shiftRight(people, -5, 3, "foo") == -1);
	assert(shiftRight(names, 5, -4, "_") == -1);
	   	  
	cout << "All tests succeeded" << endl;

	return 0;
}

//function definitions
//function that returns whether the array has duplicates
bool hasDuplicates(const string array[], int size)
{
	bool duplicate(false), stop(false);
	int i(0);

	if (size <= 0)
	{
		return false;
	}

	while(!stop && i < size)
	{
		int j(0);
		while(!stop && j < size)
		{
			//if not comparing the same index
			if (array[i] == array[j] && i != j)
			{
				stop = true;
				duplicate = true;
			}
			j++;
		}
		i++;
	}
	return duplicate;
}

//function that counts the total number of digits the array
int  countAllDigits(const string array[], int size)
{
	int countOfDigits(0);

	if (size <= 0)
	{
		return -1;
	}
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < array[i].size(); j++)
		{
			//if the index is a digit
			if (array[i][j] >= '0' && array[i][j] <= '9')
			{
				countOfDigits++;
			}
		}
	}
	return countOfDigits;
}

//function that checks if the array is in decreasing order
bool isInDecreasingOrder(const string array[], int size)
{
	if (size < 0)
	{
		return false;
	}
	else if (size == 0 || size == 1)
	{
		return true;
	}


	for (size_t i = 1; i < size; i++)
	{		
		if (array[i - 1] > array[i])
		{
			return false;
		}
	}
	return true;
}

//function that moves all indices amount to the right
int  shiftRight(string array[], int size, int amount, string placeholder)
{
	int count(0);

	if (size < 0 || amount < 0)
	{
		return -1;
	}
	else if (size == 0 || amount == 0)
	{
		return 0;
	}
	else if (size <= amount)
	{
		for (size_t i = 0; i < size; i++)
		{
			array[i] = placeholder;
		}
		return size;
	}
	else
	{
		for(int i = amount - 1; i > -1; i--)
		{
			if (i + amount < size)
			{
				array[i + amount] = array[i];
			}
			array[i] = placeholder;
		}
		//check array by output
		/*for (size_t k = 0; k < size; k++)
		{
			cout << array[k] << endl;
		}*/

		return amount;
	}


	return count;
}

//function that return the index at which a string is found in an array
int  find(const string array[], int size, string match)
{
	bool stop = false;
	int i(0);

	if (size <= 0)
	{
		return -1;
	}

	//loop to find index that the string is found
	while (!stop && i < size)
	{
		if (array[i] == match)
		{
			return i;
			stop = true;
		}
		i++;
	}

	//if the string was not found at all
	if (!stop)
	{
		return -1;
	}
	

	return 0;
}

//function that replaces findLetter with replaceLetter
int  replaceAllCharacters(string array[], int size, char findLetter, char replaceLetter)
{
	int count(0);

	if (size <= 0)
	{
		return -1;
	}

	//loop to replace the letters
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < array[i].size(); j++)
		{
			if (array[i][j] == findLetter)
			{
				array[i][j] = replaceLetter;
				count++;
			}
		}
	}

	//check array with ouput
	/*for (size_t k = 0; k < size; k++)
	{
		cout << array[k] << endl;
	}*/
	return count;
}

