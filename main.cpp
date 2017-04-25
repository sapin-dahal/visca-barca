// Lab 7: linked list of TravelClock
// Name: Sapin Dahal
// Date: 03/28/2014

#include <iostream>
#include "Clock.h"
#include "TravelClock.h"
#include "LinkedList.h"
// add include files here

using namespace std;

int main()
{
    int num;
    TravelClock c;					// default clock object
    
    LinkedList<TravelClock> list;   // start a list of TravelClock objects
    list.insertNode(c);				// insert default clock
    
    cout << "Setting clocks\n";
    cout << "number of clocks: ";
    cin >> num;						// ask user for number of clocks
    cin.ignore(100,'\n');
    
    for (int i = 0; i < num; i++)	// loop num times
    {
        cin >> c;					// read in data for each clock
        list.insertNode(c);			// insert each clock into the list
    }
    
    cout << "\nAll clocks (including local clock)\n";
    list.displayList();				// display all clocks in list
    cout << endl << endl;
    
    int hr, min;
    cout << "Deleting clocks\n";
    for (int i = 0; i < 2; i++)		// loop twice to test clock deletes
    {
        cout << "Enter time of clock to be deleted: ";
        cin >> hr >> min;
        cin.ignore(100,'\n');
        c.setTime(hr, min);				// set target clock to be deleted
        if (list.deleteNode(c))			// delete from list and check for success
            cout << "Delete success\n";
        else
            cout << "Not found\n";
    }
    
    cout << "\nAll Clocks\n";
    list.displayList();				// display all clocks in list
    cout << endl << endl;
    
    /* uncomment this block if work in team:
     cout << "\nUpdating clocks\n";
     list.updateList();				// update all clocks to apppriate current time
     cout << "\nAll clocks\n";
     list.displayList();				// display all clocks in list
     cout << endl << endl;
     */
    return 0;
}
