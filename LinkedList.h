// Header and implementation for linked list with template
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
using namespace std;

template <class T>
class LinkedList
{
private:
    struct ListNode
    {
        T data ;
        struct ListNode * next;  // pointer to the next node
    };
    
    ListNode *head;   // List head pointer
    
public:
    LinkedList() { head = NULL; }
    ~LinkedList();
    
    // Linked list operations
    void insertNode(T);
    bool deleteNode(T);
    void displayList() const;
};


/////////// Implementation portion of linked list with template  //////////////

// displayList: print all list data
template <class T>
void LinkedList<T>::displayList() const
{
    ListNode * ptr = head;	// set pointer to begin of list
    
    while (ptr != NULL)      // walk to end of list
    {
        cout << ptr->data << endl;		// print data of each node
        ptr = ptr->next;				// go to next node
    }
}

// insertNode: add a node in list order
template <class T>
void LinkedList<T>::insertNode(T newValue)
{
    ListNode *newNode;
    ListNode *pLoc;				// locate pointer
    ListNode *pPre = NULL;		// previous pointer
    
    // Allocate a new node and store newValue
    newNode = new ListNode;
    newNode->data = newValue;
    newNode->next = NULL;
    
    if (head == NULL)    // insert first node
    {
        head = newNode;
    }
    else				// insert in existing list
    {
        // walk to the correct location
        pLoc = head;        // pLoc is at the begin of list
        pPre = NULL;		// pPre is null
        // walk until end of list or until current node data is larger than newNode data
        while (pLoc != NULL && pLoc->data < newValue)
        {
            pPre = pLoc;
            pLoc = pLoc->next;
        }
        
        // insert at correct location
        if (pPre == NULL)	// insert at begin of list
        {
            head = newNode;
            newNode->next = pLoc;
        }
        else				// insert in middle or end of list
        {
            pPre->next = newNode;
            newNode->next = pLoc;
        }
    }
}

template <class T>
bool LinkedList<T>::deleteNode(T toBeDeleted)
{
    ListNode *pLoc;			// locate pointer
    ListNode *pPre;			// previous pointer
    
    if (!head)		   // If the list is empty, done
        return true;
    
    // walk to find node to be deleted
    pLoc = head;
    pPre = NULL;
    while (pLoc != NULL && pLoc->data < toBeDeleted)
    {
        pPre = pLoc;
        pLoc = pLoc->next;
    }
    
    // if found
    if (pLoc != NULL && pLoc->data == toBeDeleted)
    {
        if (pPre)	// remove node at middle or end
            pPre->next = pLoc->next;	// link previous node with next node
        else		// remove node at beginning
            head = pLoc->next;
        delete pLoc;				// release memory of pLoc
        return true;
    }
    return false;
}

// destructor, delete all nodes
template <class T>
LinkedList<T>::~LinkedList()
{
    ListNode *ptr = head;		// start at begin of list
    while (ptr != NULL)			// while not at end of list
    {
        head = head->next;		// find next node
        delete ptr;				// delete current node
        ptr = head;				// set current node to next node
    }
}


#endif
