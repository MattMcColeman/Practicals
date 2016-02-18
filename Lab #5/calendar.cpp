/**
* Author: Matt McColeman
* Description: Takes user input to either print a calender for an entire year or a specific month
* Date: 02/20/2015
*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

//function declarations
int printMonth(int year, int month);
int printYear(int year);
bool leapYear(int year);

int main ()
{ 
    int year;
    int month;
    int days;
    int choice;

    cout << "Type the option number you would like to execute." << endl;
    cout << "1. Print specific month of the calender." << endl;
    cout << "2. Print full calender of specific year." << endl;
    cout << "Enter here: ";
    cin >> choice;

    if(choice == 1)
    {
	    cout << "Please enter the number of the month and year to access calendar" << endl;
	    cout << "Enter month here: ";
	    cin >> month;
	    cout << "Enter year here: ";
	    cin >> year;
	    printMonth(year, month);
    }
    else if(choice == 2)
    {
	    cout << "Enter a year for a complete calender here: ";
	    cin >> year;
	    printYear(year);
    }
    else
    {
	    cout << "Invalid option... Exiting program..." << endl;
    }
}

//function prints out calender for specific year
int printYear(int year)
{
    for(int month = 1; month <= 12; month++)
    {
	printMonth(year, month);
    }
}

//function prints out the calender for specific month
int printMonth(int year, int month)
{
    int firstYear = 1797; //start year
    int firstLeapYear = 1804;
    int days;
    int firstDay;
    int count;
    int offset;
 
    string months[] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

    int daysInMonth[] = { 31,28,31,30,31,30,31,31,30,31,30,31}; //standard year
 
    int daysPassed[] = { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334}; //days passed at beginning of each month

    //calculates basic number of days passed 
    days = (year - firstYear) * 365;
    days += daysPassed[month-1];
    
    //add on the extra leapdays for past years
    for (int count = firstLeapYear; count < year ; count +=4)
    {
        if (leapYear(count) )
        {
            days++;
        }
    }

    //add leapday if its a leapyear and month is greater than Feb  
    if( month > 2 && leapYear(year) )
    {
        days++;
    }

    firstDay = days % 7; //used to determine day of week using remainder of days passed

    cout << "  " << months[month-1] << "   " << year << endl;	//header
    cout << "   S   " << "M  " << "Tu  " << " W  " << "Th   " << "F   " << "S   "<< endl;

    offset = 1 - firstDay; //determines which week day to start adding dates
    
    count = daysInMonth[month-1]; //gets the number of days in the month

    //adjust if dealing with February and year is leap year
    if(leapYear(year) && (month==2) )
    {
        count++;
    }

    //Prints calender where valid dates are
    for (int x = offset; x <= count; x +=7)
    {
        for(int i = x; (i < x+7) && (i <= count); i++)
        {
            if (i < 1)
            {
                cout << setw(4) << right << " "; 
            }
            else
            {
                cout << setw(4) << right << setfill(' ') << i;
            }
        }
        cout << endl;
    }
    cout << endl;
}

//checks for leap year
bool leapYear(int year)
{
    return (!(year%4)&&(year%100))||!(year%400);
}
