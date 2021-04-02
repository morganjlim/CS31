#include <iostream>
#include <string>
using namespace std;

int main()
{
	//declare and initialize variables
	string mealType(""), mealTime(""), studentOrStaff(""), residency;
	double mealPrice(0);

	//use function to print prices correctly
	cout.setf(ios::showpoint);
	cout.setf(ios::fixed);
	cout.precision(2);


	//ask for user input for mealType
	cout << "Ticket or BruinCard? ";
	getline(cin, mealType);

	//if incorrect input, exit
	if (mealType != "Ticket" && mealType != "BruinCard")
	{
		cout << "The kind value must either be Ticket or BruinCard.";
		return (-1);
	}

	//ask for mealTime
	cout << "Breakfast, Lunch, or Dinner? ";
	getline(cin, mealTime);

	//if incorrect input, exit
	if (mealTime != "Breakfast" && mealTime != "Lunch" && mealTime != "Dinner")
	{
		cout << "The meal value must either be Breakfast, Lunch or Dinner.";
		return (-1);
	}

	//determine meal type
	if (mealType == "BruinCard")
	{
		//ask for input to determine studentOrStaff
		cout << "Student or Staff? ";
		getline(cin, studentOrStaff);

		//if incorrect input, exit
		if ( studentOrStaff != "Student" && studentOrStaff != "Staff")
		{
			cout << "The type value must either be Student or Staff.";
			return (-1);
		}

		if (studentOrStaff == "Student")
		{
			//determine residency
			cout << "Resident? ";
			getline(cin, residency);

			//if incorrect input, exit
			if (residency != "Yes" && residency != "No")
			{
				cout << "The resident value must either be Yes or No.";
				return (-1);
			}

			//determine mealPrice based on residency
			if (residency == "Yes")
			{
				if (mealTime == "Breakfast")
				{
					mealPrice = 9.75;
				}
				else if (mealTime == "Lunch")
				{
					mealPrice = 11.25;
				}
				else if (mealTime == "Dinner")
				{
					mealPrice = 12.25;
				}
			}
			//determine price based on meal time
			else
			{
				if (mealTime == "Breakfast")
				{
					mealPrice = 10;
				}
				else if (mealTime == "Lunch")
				{
					mealPrice = 11.75;
				}
				else if (mealTime == "Dinner")
				{
					mealPrice = 12.75;
				}
			}
		}
		//determine price based on meal time
		else
		{
			if (mealTime == "Breakfast")
			{
				mealPrice = 11.25;
			}
			else if (mealTime == "Lunch")
			{
				mealPrice = 12.75;
			}
			else if (mealTime == "Dinner")
			{
				mealPrice = 14.75;
			}
		}
	}

	//if mealType == Ticket
	else
	{
		//determine mealPrice based on mealTime
		if (mealTime == "Breakfast")
		{
			mealPrice = 12.5;
		}
		else if (mealTime == "Lunch")
		{
			mealPrice = 14.5;
		}
		else if (mealTime == "Dinner")
		{
			mealPrice = 17;
		}
	}

	cout << "Thank you for eating at UCLA today.  Your meal cost is $" << mealPrice << ".";

	return (0);
}