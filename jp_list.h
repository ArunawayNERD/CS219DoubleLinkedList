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
        jp_list(const jp_list&);
        void push_head(int);
        void push_tail(int);
        int pop_head(); //removes the head node and returns it
        int pop_tail(); //removes the tail node and returns it
        int size();
        void display_all();

        jp_list& operator= (const jp_list&);
        virtual ~jp_list(); 

    private:
        node *head;
};

jp_list::jp_list()
{
    head = new node;
    head->next = head;
    head->prev = head;
}

jp_list::jp_list(const jp_list& rt_side)
{
    head = new node;
    head->next = head;
    head->prev = head;

    node *crt_ptr = rt_side.head->next;
    while(crt_ptr != rt_side.head)
    {
       push_tail(crt_ptr->data);
       crt_ptr = crt_ptr->next;
    }        
}

jp_list::~jp_list()
{
    int list_size = size();

    for(int i = 0; i < list_size; i++)
    {
        pop_head();
    }
    
    delete head;
}

jp_list& jp_list::operator=(const jp_list& rt_side)
{
    if(this == &rt_side)
        return *this;

    int list_size = size();
    node *crt_ptr = head->next;

    //empty this list so the rt_side can be coppied in
    while(crt_ptr != head) 
    {
        crt_ptr = crt_ptr->next;
        pop_head();    
    }

    crt_ptr = rt_side.head->next;
    
    while(crt_ptr != rt_side.head)
    {
        push_tail(crt_ptr->data);
        crt_ptr = crt_ptr->next;
    }

   return *this;
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


//      Updated Circular Linked List Using C Language
/*
//      Complete Circular Linked List

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void create(struct node **h)
{
    struct node *curr, *ptr;
    int n, i;
    printf("\nEnter the number of node you want : ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        curr = (struct node *)malloc(sizeof(struct node));
        printf("\nEnter the data for Node %d : ", i + 1);
        scanf("%d", &curr->data);
        curr->next = NULL;

        if (*h == NULL)
        {
            *h = curr;
            ptr = curr;
            ptr->next = *h;
        }
        else
        {
            curr->next = *h;
            ptr->next = curr;
            ptr = curr;
        }
    }
}

void display(struct node *h)
{
    if (h == NULL)
    {
        return;
    }
    struct node *ptr;
    for (ptr = h; ptr->next != h; ptr = ptr->next)
    {
        printf("%d\t", ptr->data);
    }
    printf("%d\t", ptr->data);
}

void insert(struct node **h)
{
    struct node *curr, *ptr;
    int v, p;
    printf("Enter the data of Node which you want to insert : ");
    scanf("%d", &v);
    printf("Enter the position at which you want the node to insert : ");
    scanf("%d", &p);

    curr = (struct node *)malloc(sizeof(struct node));
    curr->data = v;
    curr->next = NULL;

    if (*h == NULL)
    {
        *h = curr;
        ptr = curr;
    }
    else if (p == 0)
    {
        for (ptr = *h; ptr->next != *h; ptr = ptr->next);
        curr->next = *h;
        ptr->next = curr;
        *h = curr;
    }
    else
    {
        ptr = *h;
        int i = 1;
        while (i < p)
        {
            ptr = ptr->next;
            i++;
        }
        curr->next = ptr->next;
        ptr->next = curr;
    }
}

void delete (struct node **h)
{
    struct node *ptr, *prev;
    int p;
    printf("\nEnter the position of Node which you want to delete : ");
    scanf("%d", &p);

    if (*h == NULL)
    {
        printf("\nCircular Linked List is Empty.\n");
    }
    else
    {
        ptr = *h;
        int i = 1;
        while (i < p && ptr->next != *h)
        {
            prev = ptr;
            ptr = ptr->next;
            i++;
        }
        if (i < p)
        {
            printf("Node Not Found.");
        }
        else if ((*h)->next == *h)
        {
            *h = NULL;
            free(ptr);
        }
        else if (p == 1)
        {
            for (prev = *h; prev->next != *h; prev = prev->next);
            prev->next = ptr->next;
            *h = ptr->next;
            free(ptr);
        }
        else
        {
            prev->next = ptr->next;
            free(ptr);
        }
    }
}

int main()
{
    struct node *head = NULL;
    create(&head);
    display(head);
    insert(&head);
    display(head);
    delete(&head);
    display(head);
    return 0;
}
*/
