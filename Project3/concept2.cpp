//The purpose of this code is to take a string and to check whether
//it is valid by certain criteria set by the specs. If the string is
//not valid, the isValidRowerString() function returns false, and the
//rest of the functions that calculate the field values return -1.
//Otherwise, the field values are calculates and returned.
#include <iostream>
#include <string>
using namespace std;


//required functions for the project
bool isValidRowerString(string);
int totalDistance(string);
int heartRate(string);
int strokesPerMinute(string);
int elapsedMinutes(string);
int elapsedSeconds(string);

//helper functions
int number(string, int);
bool checkSpaceBefore(string, char, int);

//main function that asks for input and calls all the functions
int main()
{
	string rowerString("");

	cout << "Enter rower string: ";
	getline(cin, rowerString);

	if (rowerString == "quit")
	{
		return (-1);
	}
	cout << "elapsed minutes returns ";
	cout << elapsedMinutes(rowerString) << endl;
	cout << "elapsed seconds returns ";
	cout << elapsedSeconds(rowerString) << endl;
	cout << "strokesPerMinute returns ";
	cout << strokesPerMinute(rowerString) << endl;
	cout << "totalDistance returns ";
	cout << totalDistance(rowerString) << endl;
	cout << "heartRate returns ";
	cout << heartRate(rowerString) << endl;
	cout << "isvalidRowerString returns ";
	cout << isValidRowerString(rowerString) << endl;

	return (0);
}

//function to check validity of the string
bool isValidRowerString(string rowerString)
{

	//check min
	int startingPositionMin(0), minutes(0), j(0), i(0), x(0);
	bool isColon = false;

	//check that there is field for time
	while (isColon != true && x != rowerString.size() - 1)
	{
		if (rowerString[x] == ':')
		{
			isColon = true;
		}
		x++;
	}

	if (isColon == false)
	{
		return false;
	}

	//if the input is invalid, return false
	if (rowerString[0] == '0')
	{
		return false;
	}

	//eat leading whitespace
	while (rowerString[i] == ' ')
	{
		i++;
	}

	//calculate the minute value
	if (rowerString[i] == ':')
	{
		minutes = 0;
	}
	//if there is something other than number in the minute field
	else if (rowerString[i] > '9' || rowerString[i] < '1')
	{
		return false;
	}
	else
	{
		if (rowerString[0] == ' ')
		{
			startingPositionMin = i - 1;
		}
		else
		{
			startingPositionMin = i;
		}

		minutes = number(rowerString, startingPositionMin);
	}

	if (minutes < 0 || minutes > 59)
	{
		return false;
	}

	//check sec
	int startingPositionSec(0), seconds(0);
	i = 0;
	bool stop = false;

	while (stop == false)
	{
		//check that there is no space between the : and the second value
		if (rowerString[i] == ':')
		{
			if (rowerString[i + 3] != ' ')
			{
				return false;
			}
			//calculate second value
			else
			{
				if (rowerString[i + 1] == '0')
				{
					startingPositionSec = i + 2;
					seconds = number(rowerString, startingPositionSec);
					stop = true;
				}
				else
				{
					startingPositionSec = i + 1;
					seconds = number(rowerString, startingPositionSec);
					stop = true;
				}
			}
		}
		i++;
	}

	//check that seconds is in the acceptable range
	//and that the format is correct
	if (seconds < 10)
	{
		if (rowerString[i + 1] == ' ')
		{
			return false;
		}
	}

	if (seconds > 59 || seconds < 0)
	{
		return false;
	}
	//check stroke

	int strokes(0); i = 0;  j = 0;
	bool missing = true;
	stop = false;

	//make sure that the string contain "s/m"
	while (j < (rowerString.size() - 2) && missing == true)
	{
		if (rowerString[j] == 's' &&
			rowerString[j + 1] == '/' &&
			rowerString[j + 2] == 'm')
		{
			missing = false;
		}
		j++;
	}

	if (missing)
	{
		return false;
	}

	//validity checks
	while (stop != true)
	{
		if (rowerString[i] == 's')
		{
			if (rowerString[i + 1] != '/' || rowerString[i + 2] != 'm')
			{
				return false;
			}

			i--;

			if (rowerString[i - 1] == ' ' && rowerString[i - 2] == ' ')
			{
				return false;
			}

			i--;

			while (rowerString[i] >=  '0' && rowerString[i] <= '9')
			{
				i--;
			}

			if (rowerString[i + 1] == '0')
			{
				return false;
			}

			strokes = number(rowerString, i);

			stop = true;
		}
		i++;
	}

	if (strokes < 1 || strokes > 999)
	{
		return false;
	}

	//check meters

	int distance(0); i = 0;
	stop = false;
	missing = true;

	//check for distance field
	for (int j = 0; j < (rowerString.size() - 2); j++)
	{
		if (rowerString[j] == ' ' &&
			rowerString[j + 1] == 'm' &&
			rowerString[j + 2] == ' ')
		{
			missing = false;
		}
	}

	if (missing)
	{
		return false;
	}

	//validity checks
	while (stop != true)
	{
		if (rowerString[i] == 'm' && rowerString[i - 1] == ' ')
		{
			i--;

			if (rowerString[i - 1] == ' ' && rowerString[i - 2] == ' ')
			{
				return false;
			}

			i--;

			while (rowerString[i] >= '0' && rowerString[i] <= '9')
			{
				i--;
			}

			if (rowerString[i + 1] == '0')
			{
				return false;
			}

			distance = number(rowerString, i);

			stop = true;
		}
		i++;
	}
	//make sur there arent random characters between
	//this field and the previous one
	if (!checkSpaceBefore(rowerString, 'm', i))
	{
		return false;
	}

	if (distance < 0)
	{
		return false;
	}

	//check heart rate

	int heartRateNum(0), startingPositionHr(0); i = 1;

	//validity checks
	if (rowerString[rowerString.size() - 1] < '0' || rowerString[rowerString.size() - 1] > '9')
	{
		return false;
	}

	if (rowerString[rowerString.size() - 1] == ' ')
	{
		return false;

	}

	while (rowerString[rowerString.size() - i] != ' ')
	{
		i++;
	}
	startingPositionHr = rowerString.size() - i;

	if (!checkSpaceBefore(rowerString, 'm', startingPositionHr))
	{
		return false;
	}

	heartRateNum = number(rowerString, startingPositionHr);

	if (heartRateNum < 1 || heartRateNum > 999)
	{
		return false;
	}
	
	return true;

}
int totalDistance(string rowerString)
{
	//first check if the rest of the string is valid
	if (isValidRowerString(rowerString) == false)
	{
		return (-1);
	}
	int distance(0), i(0);
	bool stop = false, missing = true;

	//validity checks
	for (size_t j = 0; j < (rowerString.size() - 2); j++)
	{
		if (rowerString[j] == ' ' &&
			rowerString[j + 1] == 'm' &&
			rowerString[j + 2] == ' ')
		{
			missing = false;
		}
	}

	if (missing)
	{
		return (-1);
	}

	while (stop != true)
	{
		if (rowerString[i] == 'm' && rowerString[i - 1] == ' ')
		{
			if (rowerString[i - 1] != ' ')
			{
				return (-1);
			}

			i--;

			if (rowerString[i - 1] == ' ' && rowerString[i - 2] == ' ')
			{
				return (-1);
			}

			i--;

			while (rowerString[i] >= '0' && rowerString[i] <= '9')
			{
				i--;
			}

			if (rowerString[i + 1] == '0')
			{
				return (-1);
			}

			distance = number(rowerString, i);

			stop = true;
		}
		i++;
	}

	if (!checkSpaceBefore(rowerString, 'm', i))
	{
		return (-1);
	}

	if (distance < 0)
	{
		return (-1);
	}
	else
	{
		return distance;
	}
}
int heartRate(string rowerString)
{
	//first check if the rest of the string is valid
	if (isValidRowerString(rowerString) == false)
	{
		return (-1);
	}

	int i(1), heartRate(0), startingPosition(0);

	//validity checks
	if (rowerString[rowerString.size() - 1] < '1' - 1 || rowerString[rowerString.size() - 1] > '9' + 1)
	{
		return (-1);
	}

	if (rowerString[rowerString.size() - 1] == ' ')
	{
		return (-1);
		
	}

	while (rowerString[rowerString.size() - i] != ' ')
	{
		i++;
	}
	startingPosition = rowerString.size() - i;

	if (!checkSpaceBefore(rowerString, 'm', startingPosition))
	{
		return (-1);
	}

	heartRate = number(rowerString, startingPosition);

	if (heartRate < 1 || heartRate > 999)
	{
		return (-1);
	}
	else
	{
		return heartRate;
	}
}
int strokesPerMinute(string rowerString)
{
	//first check if the rest of the string is valid
	int strokes(0), i(0);
	size_t j(0);

	//validity checks
	if (isValidRowerString(rowerString) == false)
	{
		return (-1);
	}

	bool stop = false, missing = true;

	while(j < (rowerString.size() - 2) && missing == true)
	{
		if (rowerString[j] == 's' &&
			rowerString[j + 1] == '/' &&
			rowerString[j + 2] == 'm')
		{
			missing = false;
		}
		j++;
	}

	if (missing)
	{
		return (-1);
	}	

	while (stop != true)
	{
		if (rowerString[i] == 's')
		{
			if (rowerString[i + 1] != '/' || rowerString[i + 2] != 'm')
			{
				return (-1);
			}

			i--;

			if (rowerString[i - 1] == ' ' && rowerString[i - 2] == ' ')
			{
				return (-1);
			}

			i--;

			while (rowerString[i] >= '0' && rowerString[i] <= '9')
			{
				i--;
			}

			if (rowerString[i + 1] == '0')
			{
				return (-1);
			}

			strokes = number(rowerString, i);

		stop = true;
		}
		i++;
	}

	if (strokes < 1 || strokes > 999)
	{
		return (-1);
	}
	else
	{
		return strokes;
	}

}
int elapsedMinutes(string rowerString)
{
	//first check if the rest of the string is valid
	int minutes(0), i(0), x(0);
	bool isColon = false;

	if (isValidRowerString(rowerString) == false)
	{
		return (-1);
	}

	//validity checks
	while (isColon == false && x != rowerString.size() - 1)
	{
		if (rowerString[x] == ':')
		{
			isColon = true;
		}
		x++;
	}

	if (isColon == false)
	{
		return (-1);
	}

	if (rowerString[0] == '0')
	{
		return false;
	}

	while (rowerString[i] == ' ')
	{
		i++;
	}

	if (rowerString[i] == ':')
	{
		return (0);
	}
	else if (rowerString[i] == '0')
	{
		return (-1);
	}
	else if (rowerString[i] > '9' || rowerString[i] < '1')
	{
		return(-1);
	}
	else
	{
		minutes = number(rowerString, i);
	}

	if (minutes < 0 || minutes > 59)
	{
		return (-1);
	}

	return minutes;
}
int elapsedSeconds(string rowerString)
{
	//first check if the rest of the string is valid
	int startingPosition(0), seconds(0), i(0), x(0);
	bool stop = false, isColon = false;

	if (isValidRowerString(rowerString) == false)
	{
		return (-1);
	}

	//check for time field
	while (isColon == false && x != rowerString.size() - 1)
	{
		if (rowerString[x] == ':')
		{
			isColon = true;
		}
		x++;
	}

	if (isColon == false)
	{
		return (-1);
	}

	while(stop == false)
	{
		if (rowerString[i] == ':')
		{
			if(rowerString[i + 3] != ' ')
			{
				return (-1);
			}
			else
			{
				if (rowerString[i + 1] == '0')
				{
					startingPosition = i + 2;
					seconds = number(rowerString, startingPosition);
					stop = true;
				}
				else
				{
					startingPosition = i + 1;
					seconds = number(rowerString, startingPosition);
					stop = true;
				}
			}
		}
		i++;
	}

	if (seconds < 10)
	{
		if (rowerString[i + 1] == ' ')
		{
			return (-1);
		}
	}
	if (seconds > 59 || seconds < 0)
	{
		return (-1);
	}

	return(seconds);
}
int number(string s, int startingposition)
{
	int result = 0;
	size_t length = s.length();
	// ignore leading whitespace
	while (startingposition < length && isspace(s[startingposition]))
	{
		startingposition = startingposition + 1;
	}
	// no leading zeros
	if (startingposition < length)
	{
		if (s.at(startingposition) >= '1' && s[startingposition] <= '9')
		{
			while (startingposition < length &&
				s.at(startingposition) >= '0' &&
				s.at(startingposition) <= '9')
			{
				int value = s.at(startingposition) - '0';
				result = (result * 10) + value;
				/// move on down the road
				startingposition = startingposition + 1;
			}
		}
	}
	else
	{
		result = -1;
	}
	return(result);
}
bool checkSpaceBefore(string rowerString, char toCheck, int startingPosition)
{
	//function that checks whether there are random characters between the field and a target field
	bool noLettersBetween(true);
	while (rowerString[startingPosition - 1] != toCheck)
	{
		if (rowerString[startingPosition - 1] != ' ')
		{
			noLettersBetween = false;
		}
		startingPosition--;
	}

	return noLettersBetween;
}