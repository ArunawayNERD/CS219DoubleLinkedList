/*
 * John Pigott
 * CS219
 * List Homework
 * Created: 4/1/14
 * Last Modifed: 4/15/14
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

jp_list::jp_list()
{
    head = new node;
    head->next = head;
    head->prev = head;
}

void jp_list::push_head(int nw_data)
{   
    node *temp = new node;
    temp->data = nw_data;
    
    temp->next = head->next;
    head->next->prev = temp;

    temp->prev = head;
    head->next = temp;
      
}

void jp_list::push_tail(int nw_data)
{
    node *temp = new node;
    temp->data = nw_data;

    head->prev->next = temp;
    temp->prev = head->prev;

    temp->next = head;
    head->prev = temp;
}

int jp_list::pop_head()
{
    node *old_head = head->next;

    if(old_head == head)
    {
        cout << "Nothing to pop. Returning -1 as placeholder\n";
        return -1;
    }
    int old_head_data = head->next->data;

    head->next = old_head->next;
    old_head->next->prev = head;
    
    delete old_head;
    old_head = 0;
    
    return old_head_data;
}

int jp_list::pop_tail()
{
    node *old_tail = head->prev;
    
    if(old_tail == head)
    {
        cout << "Nothing to pop. Returning -1 as placeholder\n";
        return -1;
    }

    int old_tail_data = head->prev->data;

    head->prev = old_tail->prev;
    old_tail->prev->next = head;

    delete old_tail;
    old_tail = 0;
    
    return old_tail_data;
}

int jp_list::size()
{
    int size = 0;
    node *crt_ptr; //pointer to current node
      
    crt_ptr = head->next;
    while(crt_ptr != head)
    {
        size += 1;
        crt_ptr = crt_ptr->next; //advance to the next node then loop        
    }

    return size;
}

void jp_list::display_all()
{
    node *crt_ptr = head->next;
   
    for(int i = 0; crt_ptr != head; i++)
    {
        cout << "Node " << (i+1) << ": " << crt_ptr->data << endl;
        
        crt_ptr = crt_ptr->next;
    }
}
