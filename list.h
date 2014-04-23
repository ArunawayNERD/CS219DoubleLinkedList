#ifndef JP_LIST_H //JP is incase there already is LIST_H somewhere 
#define JP_LIST_H

/*
 * John Pigott
 * CS219
 * List Homework
 * Last Modified: 4/18/14 
 */
#include <iostream>
using namespace std;
struct node
{
    int data;
    node *next;
    node *prev;
};

class jp_list
{
         
    public:
        jp_list();
        void push_head(int);
        void push_tail(int);
        int pop_head(); //removes the head node and returns it
        int pop_tail(); //removes the tail node and returns it
        int size();
        void display_all();
 
    private:
        node *head;
};

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
    node *temp = head->next;
    int temp_data = head->next->data;

    head->next = temp->next;
    temp->next->prev = head;

    delete temp;
    temp = 0;

    return temp_data;
}

int jp_list::pop_tail()
{
    node *temp = head->prev;
    int temp_data = head->prev->data;

    head->prev = temp->prev;
    temp->prev->next = head;

    delete temp;
    temp = 0;

    return temp_data;
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


#endif 
