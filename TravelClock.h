#include <string>
using namespace std;
class TravelClock : public Clock
{
private:
    string location ;
    int time_diff;
public:
    
    // Default constructor
    TravelClock(){location ="Saint Cloud "; time_diff =0;}
    
    // == function overloading
    bool operator==(const TravelClock & obj);
    
    // Input and output function overloading
    friend ostream & operator<< (ostream & o, const TravelClock & obj);
    friend istream & operator>> (istream & istr, TravelClock & object);
    
};
