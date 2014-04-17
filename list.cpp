/*
 * John Pigott
 * CS219
 * List Homework
 * 4/1/14
 */
#include <iostream>
#include <cstdlib>
#include "list.h"
using namespace std;

int main()
{
    jp_list my_list;
    
    cout << my_list.size() << endl;
    my_list.push_head(10);
    my_list.push_tail(20);
    my_list.push_head(30);
    my_list.push_tail(40);
    cout << my_list.size() << endl;   

    my_list.display_all();
/*    srand(time(0));    

    cout << "Size: " <<  my_list.size() << endl << endl;
    for(int i = 0; i < 100; i++)
    {
        my_list.push_head(rand() % 100);
    }

    my_list.display_all();

    cout << "\nSize: " << my_list.size() << endl;
    return 0;
*/
}

jp_list::jp_list()
{
    head = new node;
    head->next = head;
    head->prev = head;

    cout << "Head: " << head << endl; 
    cout << "AfterHead: " << head->next <<endl;
    cout << "BeforeHead: " << head->prev << endl << endl;

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
    int head_data = head->next->data;
    
    head->next = head->next->next;
    
    return head_data;
}

/* int jp_list::pop_tail()
{
    int tail_data;
    node *crt_ptr;
    int length = size();

    crt_ptr = head;
    
    //goes to second to last node
    for(int i = 0; i < (length-1); i++)
    {
        if(crt_ptr->next != 0)
        {
            crt_ptr = crt_ptr->next;
        }
     }

    tail_data = crt_ptr->next->data;
    
    crt_ptr->next = tail;

    return tail_data;
}*/

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
