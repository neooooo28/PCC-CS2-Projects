#ifndef DATE_LIB_H
#define DATE_LIB_H

#include <iostream>

using namespace std;

void Add_Date(int& m,int& d,int& y, int days);                  //Date + num_days
void AddInverse_Date(int& m, int& d, int& y, int days);         //Date - num_days
int Subtract_Date(int end_m, int end_d, int end_y,              //Date - Date
                  int start_m, int start_d, int start_y);

int Date_to_DayNum(int m,int d,int y);                       //convert date to num_days
void DayNum_to_Date (int days,
                     int& m, int& d, int &y);      //convert num_days to date

//Date_to_DayNum
int YearNum_to_Days(int y);
int MonthNum_to_Days(int m);
int Days_in_Month(int m);

int Days_each_Month (int m, int y);

//DayNum_to_Date
int ConvertYear(int days);
int ConvertMonth(int days);
int ConvertDay(int days, int y);

//Counting Leap Years
int Num_Leap_Year (int EPOCH, int y);

//Size of the Year (leap, no leap)
int YearSize (int y);

//Validity
bool date_is_valid(int m, int d, int y);
bool is_LeapYear(int y);

void Input_Date(int &m, int &d, int &y);
void Print_Date(int m, int d, int y);



#endif // DATE_H
