#include <iostream>
#include "qclfunctions.h"

using namespace std;
using namespace qcl;

int main()
{
    MyList *myList = new MyList();
    int elem;

    char res[2];
    res[0] = 'y';
    while( res[0] == 'y' )
    {
        char respond[256];
        printf("What to do?\n 1: show file\n 2: show the 1 elem\n 3: delete the 1 elem\n 4: show the last elem\n 5: add a new elem\n 6: clear all\n\n");
        scanf("%s", &respond);

        if ( myList -> isEmpty() ){
            cout<<"ERROR: the list is empty. Try to add a new element.";
        }
        else
        {
            if( !strcmp(respond, "1") )
            {
                myList -> show();
            }
            if( !strcmp(respond, "2") )
            {
                cout << "The first element is " << myList -> onTop() << endl;
            }
            if( !strcmp(respond, "3") )
            {
                myList -> pop();
                cout << "Done!" << endl;
            }
            if( !strcmp(respond, "4") )
            {
                cout << "The last element is " << myList -> onTail();
            }
        }
        if( !strcmp(respond, "5") )
        {
            cout << "Enter the new element: " << endl;
            cin >> elem;
            myList -> push(elem);
            cout << "Done!" << endl;
        }
        if( !strcmp(respond, "6") )
        {
            myList -> clean();
            cout << "Done!" << endl;
        }
        printf("More menu? (y/n)\n", respond);
        scanf("%s", &res);
    }

    delete myList;

    return 0;
}
