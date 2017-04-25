// Lab 6: Clock class header file
// Name: Sapin Dahal
// Date: 03/28/2014

#include <string>
using namespace std;

class Clock
{
protected:
    int hour;
    int minute;
    //formating
    void format();
private:
    int num_remin;
    string * reminarr;
public:
    //defualt constructor
    Clock();
    //construction with argument
    Clock (int h, int m);
    //copy constructor
    Clock (const Clock &obj);
private:
    //mutator
    void sethour (int inhour);
    void setminute (int inminute);
    void setup(int h, int m);
public:
    void setReminder ();
    void setTime(int h, int m);
    
    //accessor
    string getreminder (string remainarr) const;
    void showReminder ();
    
    //functions
    void updateTime();
    
    
    //function overloading
    friend ostream & operator<< (ostream & o, const Clock & obj);
    
    //not equal operator
    bool operator!=(const Clock & obj);
    
    //subtraction operator
    int operator-(const Clock & obj);
    
    //equal operator
    Clock operator = (const Clock &obj);
    
    //prefix operator
    Clock operator++();
    
    //postfix operator
    Clock operator++(int);
    
    //greater than operator
    bool operator>(const Clock & obj);
    
    //less then operator
    bool operator<(const Clock & obj);
    
    //destructor
    ~Clock() { delete [] reminarr; }
    
};

