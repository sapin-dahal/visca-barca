#include <iostream>
#include <iomanip>
#include <ctime>
#include "Clock.h"
#include "TravelClock.h"
using namespace std;

ostream & operator<< (ostream & o, const TravelClock & obj)
{
    Clock time = static_cast<Clock>(obj);
    o <<obj.location<<" ";
    o<<time;
    return o;
}
istream & operator>> (istream & istr, TravelClock & object)
{
    char choice;
    cout<<"Enter the name of your Location : ";
    getline(istr,object.location);
    
    cout<<"Enter the time difference : ";
    istr>>object.time_diff;
    object.hour += object.time_diff;
    
    cout<<"Set reminder ? [Y/N] : ";
    istr>>choice;
    if (choice=='y')
    {
        object.setReminder();
    }
    else
    {
        istr.ignore();
    }
    object.format();
    return istr;
}
bool TravelClock::operator== (const TravelClock & obj)
{
    if(minute!= obj.minute || hour != obj.hour) return false;
    
    else return true;
}
