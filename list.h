#ifndef JP_LIST_H //JP is incase there already is LIST_H somewhere 
#define JP_LIST_H

/*
 * John Pigott
 * CS219
 * List Homework
 * Last Modified: 4/18/14 
 */

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
#endif 
