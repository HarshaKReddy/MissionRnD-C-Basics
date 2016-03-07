/*
OVERVIEW: 	Given date of births of two persons as inputs, return 1 if person one is elder,
2 if person two is elder, 0 if both are of same age.
Example: isOlder("24-07-2000", "25-07-2000") should return 1 as person one
is elder than person two.

INPUTS: 	DOBs of two persons as parameters in the format "DD-MM-YYYY".

OUTPUT: 	1 if person one is elder, 2 if person two is elder, 0 if both are of same age.

ERROR CASES: Return -1 if any DOB is invalid.

NOTES: 		Don't use any built-in C functions for comparisions. You are free to write any helper functions.
*/


int isLeap(int year)// returns 1 if the year is leap, else 0
{
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		return 1;
	return 0;
}

int isValid(int dd1, int mm1, int yy1)// returns 1 if date is valid
{
	if (mm1 > 12)
		return 0;
	int max_days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	if (mm1 == 2 && isLeap(yy1))
		max_days[1]++;

	if (dd1 > max_days[mm1 - 1])
		return 0;
	return 1;
}

int doblen(char *str)
{
	int len = 0;
	while (*(str++))len++;
	return len;
}

int isOlder(char *dob1, char *dob2) 
{
	if (doblen(dob1) != 10 || doblen(dob2) != 10)
		return -1;
	int dd1 = 0, mm1 = 0, yy1 = 0, dd2 = 0, mm2 = 0, yy2 = 0, i = 0;
	//converting string to int
	for (i; i < 2; i++)
	{
		dd1 = dd1 * 10 + (dob1[i] - '0');
		dd2 = dd2 * 10 + (dob2[i] - '0');
		mm1 = mm1 * 10 + (dob1[i + 3] - '0');
		mm2 = mm2 * 10 + (dob2[i + 3] - '0');
		yy1 = yy1 * 10 + (dob1[i + 6] - '0');
		yy2 = yy2 * 10 + (dob2[i + 6] - '0');
	}
	for (i = 8; i < 10; i++)
	{
		yy1 = yy1 * 10 + (dob1[i] - '0');
		yy2 = yy2 * 10 + (dob2[i] - '0');
	}

	// checking for validity
	if (!isValid(dd1, mm1, yy1) || !isValid(dd2, mm2, yy2))
		return -1;

	// equal
	if (yy1 == yy2 && mm1 == mm2 && dd1 == dd2)
		return 0;
	
	// 2 is elder
	if (yy1 > yy2)
		return 2;
	else if (yy2 > yy1) // 1 is elder
		return 1;

	if (mm1 > mm2)// years same but months different
		return 2;
	else if (mm2 > mm1)
		return 1;

	if (dd1 > dd2) // years and months are same dates are different 
		return 2;
	return 1;
}
