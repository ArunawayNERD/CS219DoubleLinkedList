#ifndef JP_LIST_H //JP is incase there already is LIST_H somewhere 
#define JP_LIST_H

/*
 * John Pigott
 * CS219
 * List Homework
 * 3/31/14
 */

struct node
{
    node():data(0), next(0), prev(0){};
    node(int nd_data, node *next_nd, node *prev_nd)
                                :data(nd_data), next(next_nd), prev(prev_nd){};
   
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
