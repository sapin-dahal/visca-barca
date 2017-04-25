// Lab 6: Clock class implementation file
// Name: Sapin Dahal
// Date: 03/28/2014
#define _CTR_SECURE_NO_WARNINGS 1
#include <iostream>
#include <iomanip>
#include <ctime>
#include "Clock.h"
using namespace std;


// function to get the current time and store in the hr and min fields of Clock class
// input: nothing
// return: nothing
// effect: hr has the current system hour
//         min has the current system minute
Clock::Clock()
{
    updateTime();
    num_remin =0;
    reminarr = NULL;
}
//updating with the current time funciton
void Clock::updateTime()
{
    time_t now = time(0);   // get current time in epoch time
    tm *ltm = localtime(&now);  // convert epoch time to time struct (see below)
    hour = ltm->tm_hour;      // access hour field of struct
    minute = ltm->tm_min;      // access minute field of struct
}
//constructor with agreements
void Clock::setup(int h, int m)
{
    if (h>0 && h<23)
    {
        hour = h;
    }else
    {
        hour = 0;
    }
    if (m>0)
    {
        minute =m;
    }else
    {
        minute =0;
    }
}
Clock::Clock(int h, int m)
{
    setup(h,m);
    format ();
    num_remin =0;
    reminarr = NULL;
    
    
}
//copy constructor
Clock::Clock(const Clock &obj)
{
    hour = obj.hour;
    minute = obj.minute;
    num_remin=obj.num_remin;
    reminarr =new string [num_remin];
    for (int i=0; i<num_remin;i++)
    {
        reminarr[i]=obj.reminarr[i];
    }
    
}
//setting the reminder
void Clock::setReminder()
{
    cout<<"Enter the number of remainder :";
    cin>>num_remin;
    reminarr = new string [num_remin];
    cin.ignore();
    for (int i= 0; i<num_remin; i++)
    {
        cout<<"Enter remainder : ";
        getline(cin,reminarr[i]);
        
    }
    cout<<endl;
}
//displays or prints out the remainder that are set above
void Clock::showReminder()
{
    cout<<"Reminders : \n";
    for (int i=0; i<num_remin;i++)
        cout<<reminarr[i]<<endl;
}
//set time function
void Clock::setTime(int h, int m)
{
    setup(h,m);
    format ();
}
//formatting
void Clock::format()
{
    if (minute>59 )
    {
        hour +=(minute/60);
        minute = minute %60;
    }
    if (hour >23)
    {
        hour = hour%24;
    }
    if (hour<0)
        hour+=24;
}
//ostream function to output the data
ostream & operator<< (ostream & o, const Clock & obj)
{
    o <<setw(2)<<setfill('0')<< obj.hour <<":"<<setw(2)<<setfill('0')<<obj.minute <<"\n";
    return o;
}
//noyt equal operator comparing the two objects and returns bool
bool Clock::operator!=(const Clock & obj)
{
    if ( (hour != obj.hour) || (minute != obj.minute) )
    {
        return true;
    }
    else
        return false;
}
//minus operator
int Clock::operator- (const Clock &obj)
{
    int temp;
    temp = (((hour - obj.hour)*60)+(minute - obj.minute));
    return temp;
}
//equal operator it should only be use if there is data in heap
Clock Clock:: operator = (const Clock &obj)
{
    this -> hour = obj.hour;
    this -> minute = obj.minute;
    this->num_remin=obj.num_remin;
    reminarr = new string [num_remin];
    for (int i=0; i<num_remin;i++)
    {
        this->reminarr[i] = obj.reminarr[i];
    }
    return *this;
}
//prefix operator to increase the number by 1 each time BEFORE it runs
Clock Clock::operator++()
{
    ++minute;
    format();
    return*this;
}
//postfix operator to increase the number by 1 each time AFTER it runs once
Clock Clock::operator++(int)
{
    Clock temp=*this;
    minute++;
    format();
    return temp;
}
//greater than operator
bool Clock::operator>(const Clock & obj)
{
    if (hour > obj.hour)
        return true;
    else if (hour == obj.hour)
    {
        if (minute > obj.minute)
            return true;
        else
            return false;
    }
    else
        return false;
    
}
//less then operator
bool Clock::operator<(const Clock & obj)
{
    if (hour < obj.hour)
        return true;
    else if (hour == obj.hour)
    {
        if (minute < obj.minute)
            return true;
        else
            return false;
    }
    else
        return false;
    
}

