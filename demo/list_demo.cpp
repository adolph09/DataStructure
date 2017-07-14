#include <iostream>
#include "../algorithm/list.h"

using namespace std;

int main()
{
    List<char> list;
    list.init();
    for (int i = 0; i < 1; i++) {
        list.insert_back('0' + i);
    }
    list.print();
    cout << list.find('0') << endl;
    cout << "len:" << list.length() << endl;
    for (int i = 1; i <= list.length(); i++)
        cout << "num:" << list.find(i) << endl;
    //for (int i = 0; i <3; i++) {
    //    list.insert(8, 'a' + i);
    //}
    list.insert(8, 'x');
    list.print();
    cout << list.get_tail()->element << endl;
    list.destory();
    //list.print(); // aleady destory, can't access
    return 0;
}