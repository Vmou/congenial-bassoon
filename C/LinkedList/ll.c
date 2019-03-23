/*
  Author: Vmou
  Email:  vmou@outlook.com
  Date:   Mar, 22, 2019
  File:   ll.c
*/

/*
  Descrption: A simple implementation of double linked list.
 */

#include <stdio.h>
#include <stdlib.h>
#include "ll.h"

lnode new_node(void)
{
  lnode l;
  l = (lnode)malloc(sizeof(struct linked_list_node));
  if (l == NULL)
    {
      fprintf(stderr, "Allocate new node memory error\n");
      exit(1);
    }
  l->prev = NULL;
  l->next = NULL;
  return l;
}

lnode new_node_with(int data)
{
  lnode l = new_node();
  l->data = data;
  return l;
}

void free_node(lnode node)
/*
  Free a node recusivly.
 */
{
  if (node != NULL)
    {
      free_node(node->next);
      free(node);
    }
}

ll new_list(void)
{
  ll list;
  list = (ll)malloc(sizeof(struct linked_list));
  if (list == NULL)
    {
      fprintf(stderr, "Allocate new list memory error\n");
      exit(1);
    }
  list->size = 0;
  list->head = NULL;
  return list;
}

void free_list(ll list)
{
  free_node(list->head);
  free(list);
}

void print_list(ll list)
{
  lnode node = list->head;
  printf("[");
  while(node != NULL)
    {
      printf("%d, ", node->data);
      node = (node->next);
    }
  printf("\b\b]\n");
}


void append_list(ll list, int data)
{
  if (list->head == NULL)
    {
      list->head = new_node_with(data);
      (list->size)++;
      return;
    }
  lnode node = new_node_with(data);
  lnode last = list->head;
  while (last->next != NULL)
    last = last->next;
  last->next = node;
  node->prev = last;


  (list->size)++;
}

void add_from_array(ll list, int arr[], int size)
{
  int i;
  for (i=0;i<size;i++)
    {
      append_list(list, arr[i]);
    }
}

lnode* list_index(ll list, int index)
{
  if (index > list->size)
    {
      fprintf(stderr, "Index out of bound.");
      exit(1);
    }
  int i;
  lnode *node = &(list->head);
  for (i=0; i<index;i++)
    node = &(*node)->next;
  return node;
}

void insert_node(ll list, lnode node, int index)
{
  lnode node_add = *(list_index(list, index));
  node->next = node_add;
  node->prev = node_add->prev;
  node->prev->next = node;
  node->next->prev = node;
  list->size++;
}

void add_from_input(ll list)
{
  int c;
  int i;
  while((scanf("%d\n", &i))!=EOF)
    append_list(list, i);
}

void remove_node(ll list, int index)
{
  lnode node_rm = *(list_index(list, index));
  node_rm->prev->next = node_rm->next;
  node_rm->next->prev = node_rm->prev;
  free(node_rm);
  list->size--;
}
