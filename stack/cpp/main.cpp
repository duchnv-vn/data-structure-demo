#include <iostream>
#include "stack.h"
using namespace std;

struct Data
{
    int id;
    string name;
};

int main()
{
    Stack<double> s1(2);
    s1.push(1.1);
    s1.push(2.2);
    cout << "s1 getTop 1: " << s1.getTop() << endl;
    s1.push(3.3);
    s1.pop();
    cout << "s1 getTop 2: " << s1.getTop() << endl;

    cout << "---------" << endl;

    Stack<double> s2 = {3};
    cout << "s2 getTop 1: " << s2.getTop() << endl;
    s2.push(1.1);
    s2.push(2.2);
    s2.push(3.3);
    s2.pop();
    cout << "s2 getTop 2: " << s2.getTop() << endl;

    cout << "---------" << endl;

    Stack<double> s3{2};
    cout << "s3 getTop 1: " << s3.getTop() << endl;
    s3.push(1.1);
    s3.pop();
    cout << "s3 getTop 2: " << s3.getTop() << endl;

    cout << "---------" << endl;

    Stack<Data> s4(5);
    cout << "s4 getTop 1: " << s4.getTop().id << endl;
    Data d1 = {1, "Duc"};
    s4.push(d1);
    cout << "s4 getTop 1: " << s4.getTop().id << endl;
    s4.push({.id = 2, .name = "Duc 2"});
    s4.push({3, "Duc 3"});
    cout << "s4 getTop 1: " << s4.getTop().id << endl;
}
