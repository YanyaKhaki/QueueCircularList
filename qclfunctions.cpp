#include "qclfunctions.h"
//#include <exception>

using namespace qcl;

MyList::MyList():
{
    first = nullptr;
    last = nullptr;
}

MyList::~MyList()
{
    clean();
}

bool MyList::isEmpty()
{
    if  ( first && last ){
        return 0;
    }
    return 1;
}

void MyList::show()
{
    Node *temp;
    temp = first;
    while( temp != first )
    {
        cout << temp -> datum << endl;
        temp = temp -> link;
    };
}

void MyList::push(Data dt)
{
    Node *temp = new Node;
    temp -> datum = dt;
    temp -> link = nullptr;
    if ( first == NULL )
    {
        last = first;
        first = temp;
    }
    else
    {
        last -> link = temp;
        last = temp;
    }
}

void MyList::pop()
{
    if( !isEmpty() )
    {
        first = first -> link;
        delete last -> link;
        last -> link = first;
    }
    if ( first == last )
    {
        delete first;
        first = nullptr;
        last = nullptr;
    }
}

Data MyList::onTop()
{
    if ( first == nullptr ){
        throw -1;
    }
    return first -> datum;
}

Data MyList::onTail()
{
    if ( last == nullptr ){
        throw -1;
    }
    return last -> datum;
}

void MyList::clean()
{
    while( !isEmpty() ){
        pop();
    }
}
