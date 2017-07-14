#include <iostream>
#include "../algorithm/list.h"

using namespace std;

int main()
{
    List<char> list;
    list.init();
    list.insert('s');
    list.insert('z');
    list.insert('d');
    list.insert('w');
    list.insert('q');
    list.insert(list.get_head()->next->next, 'k');
    list.print();
    cout << list.find(list.get_head()->next->next) << endl;
    cout << list.find('k') << endl;
    cout << list.find_prev('k') << endl;
    cout << list.find_prev('h') << endl;

}