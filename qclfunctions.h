#ifndef QCLFUNCTIONS_H
#define QCLFUNCTIONS_H
#include <iostream>

using namespace std;

namespace qcl {

typedef int Data;

class MyList {

public:
    MyList();
    ~MyList();
    bool isEmpty();
    void show();
    void push(Data dt);
    void pop();
    Data onTop();
    Data onTail();
    void clean();

private:
    struct Node{
        Data datum;
        Node* link;
        } *first, *last;

};

}

#endif // QCLFUNCTIONS_H
