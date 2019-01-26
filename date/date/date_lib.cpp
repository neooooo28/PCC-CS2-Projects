#include "date_lib.h"
#include <iostream>
#include <iomanip>

using namespace std;

const int EPOCH = 1970;

void Add_Date(int& m, int& d, int& y, int days) {
    int n;
    days = Date_to_DayNum(m,d,y);
    days += n;
    DayNum_to_Date(days,m,d,y);
    Print_Date(m,d,y);
}

//Function different from Subtract_Date
//This is the additive inverse function of Add_Date
void AddInverse_Date(int& m, int& d, int& y, int days) {
    int n;
    days = Date_to_DayNum(m,d,y);
    days -= n;
     DayNum_to_Date(days,m,d,y);
    Print_Date(m,d,y);
}

//Inputs two dates, returns an integer value
//of different between two dates
int Subtract_Date(int end_m, int end_d, int end_y,       //date - date
                   int start_m, int start_d, int start_y) {
    int start, end, diff;
    start = Date_to_DayNum(start_m,start_d,start_y);
    end = Date_to_DayNum(end_m,end_d,end_y);
    diff = end-start;
    return diff;
}
//==================================================
int Date_to_DayNum(int m,int d,int y) {
    int total_days;
    total_days = YearNum_to_Days(y) + MonthNum_to_Days(m) + d - 1;
    // -1 for Zero-Index --> Day 0
    return total_days;
}
//Number of days from 01/01/1970 to 01/01/y
//Starting year
int YearNum_to_Days(int y) {
    int total_days;
    total_days = y - EPOCH;
    total_days = (total_days*365) + Num_Leap_Year(EPOCH,y);
    return total_days;
}
//Number of days from 01/01/y to m/01/y
int MonthNum_to_Days(int m) {
    int total_days = 0;
    int count = 0;
    // 1 <= m <= 12
    for (int i=1; i<=m; i++) {
        count++;
        total_days += Days_in_Month(i);
    }
    //cout<<endl<<"Count DEBUG: "<<count<<endl;
    return total_days;
}
//Accumulates the days in month from 01/01 to m/01
//Starting month
int Days_in_Month(int m) {
    int days = 0;
    switch (m) {
    case 1:
        days=0;
        break;
    case 2: //Jan
        days=31;
        break;
    case 3: //Feb
        days=28;
        break;
    case 4: //Mar
        days=31;
        break;
    case 5: //Apr
        days=30;
        break;
    case 6: //May
        days=31;
        break;
    case 7: //Jun
        days=30;
        break;
    case 8: //Jul
        days=31;
        break;
    case 9: //Aug
        days=31;
        break;
    case 10: //Sep
        days=30;
        break;
    case 11: //Oct
        days=31;
        break;
    case 12: //Nov
        days=30;
        break;
    }
    return days;
}
//===============================================
void DayNum_to_Date (int days,int& m,int& d,int& y) {   
    y = ConvertYear(days);
    m = ConvertMonth(days);
    d = ConvertDay(days,y);
    //Print_Date(m,d,y);
}
int ConvertYear(int days) {
    int year;
    year = days/365;
    year += EPOCH;
    return year;
}
int ConvertMonth(int days) {
    int month, days_left;
    days_left = days%365;
    month = days_left/30;
    if (month==0 || month<0)
        month=1;
    return month;
}
int ConvertDay(int days, int y) {
    int day, days_left;
    days_left = days%365;
    day = days_left%30;
    day -= Num_Leap_Year(EPOCH,y)+1;
    if (day==0 || day<0)
        day=1;
    return day;
}
//=================================================
int Days_each_Month (int m, int y) {
    int days = 0;
    if (m==3 || m==5 || m==7 || m==8 || m==10 || m==12) {
        days = 31;
    } //Mar,May,Jul,Aug,Oct,Dec
    if (m==1 || m==4 || m==6 || m==9 || m==11) {
        days = 30;
    } //Jan,Apr,Jun,Sept,Nov
    if (m==2 && is_LeapYear(y)) {
        days = 29;
    } //Feb Leap
    if (m==2 && !is_LeapYear(y)) {
        days = 28;
    } //Feb !Leap
    return days;
}
//Determining if y is leap year or not
bool is_LeapYear(int y) {
    if ((y%4==0) && (y%100!=0) || (y%400==0)) {
        //cout<<"LY DEBUG: "<<y<<" is a leap year.";
        return true;
    }
    //cout<<"LY DEBUG: "<<y<<" is not a leap year.";
    return false;
}
//Number of leap years means number of EXTRA days in the year
int Num_Leap_Year (int EPOCH, int y) {
    int leap_year = 0;
    for (int i=EPOCH; i<=y; i++) {
        if ((i%4==0) && (i%100!=0) || (i%400==0)) {
            //cout<<i<<" ";
            //DEBUG: lists all leap years from [epoch,y]
            leap_year++;
        }
    }
    return leap_year;
}
//Returns number of days, given (leap) year
int YearSize (int y) {
    int days;
    if (is_LeapYear(y)) {
        days = 366;
    } //means y is leap
    if (!is_LeapYear(y)) {
        days = 365;
    }
    return days;
}

//=================================================
//Input validity function
bool Date_is_Valid(int m, int d, int y) {
    if (m<1 || m>12)        //1 <= month <= 12
        return false;
    if (m==2 && d>29)       //Max: Feb 29
        return false;
    if (d<1 || d>31)        //1 <= day <= 31
        return false;
    if (y<1970)             //EPOCH starts at 1970
        return false;
    return true;
}
//Function to Input Date
void Input_Date(int& m,int& d,int& y) {
    char slash;
    do {
        cout<<"Date: ";
        cin>>m>>slash>>d>>slash>>y;
    } while (!(Date_is_Valid(m,d,y)));
}
//Function to Print Date
void Print_Date(int m, int d, int y) {
    //int m=0, d=0, y=0;
    cout<<"["<<
          setw(2)<<setfill('0')<<m<<"/"<<
          setw(2)<<setfill('0')<<d<<"/"<<
          setw(4)<<setfill('0')<<y<<"]";
}

//=================================================
/*
This algorithm is not mine. I got it from
https://alcor.concordia.ca//~gpkatch/gdate-algorithm.html
for debugging purposes only.
Epoch is 03/01/1970 compared to 01/01/1970

Method: https://alcor.concordia.ca//~gpkatch/gdate-method.html

void date_algo_not_mine (int days,
                         int& m, int& d, int& y) {
    int ddd=0, mi=0;
    y = 1970;
    y = (10000*days + 14780)/3652425;
    ddd = days - (365*y + y/4 - y/100 + y/400);
    if (ddd < 0) {
        y = y - 1;
        ddd = days - (365*y + y/4 - y/100 + y/400);
    }
    mi = (100*ddd + 52)/3060;
    m = (mi + 2)%12 + 1;
    y = (y + (mi + 2)/12) + EPOCH;
    d = ddd - (mi*306 + 5)/10 + 1;
    Print_Date(m,d,y);
    //cout<<m<<"/"<<d<<"/"<<y;
}
*/
