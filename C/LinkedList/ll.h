/*
  Author: Vmou
  Email:  vmou@outlook.com
  Data:   Mar, 22, 2019
  File:   ll.h
*/

typedef struct linked_list_node * lnode;
typedef struct linked_list * ll;

struct linked_list_node
{
  int data;
  lnode prev;
  lnode next;
};

struct linked_list
{
  int size;
  lnode head;
};

extern lnode new_node(void);
extern lnode new_node_with(int data);
extern void free_node(lnode node);
extern ll new_list(void);
extern void free_list(ll list);
extern void print_list(ll list);
extern void append(ll list, int data);
extern void add_from_array(ll list, int arr[], int size);
extern lnode* list_index(ll list, int index);
extern void insert(ll list, lnode node, int index);
extern void add_from_input(ll list);
