/*
 * John Pigott
 * CS219
 * List Homework
 * Last Modifed: 4/18/14
 */
#include <iostream>
#include <cstdlib>
#include "list.h"
using namespace std;

int main()
{
    jp_list my_list;
    
    srand(time(0));    

    cout << "Size: " <<  my_list.size() << endl << endl;
    for(int i = 0; i < 100; i++)
    {
        my_list.push_head(rand() % 100);
    }

    my_list.display_all();

    cout << "\nSize: " << my_list.size() << endl;

    return 0; 
}
