/*
  Author: Vmou
  Email:  vmou@outlook.com
  Data:   Mar, 22, 2019
  File:   main.c
 */

#include <stdio.h>
#include "ll.h"

int main()
{
  ll list = new_list();
  /*int arr[5] = {1,2,3,4,5};
    add_from_array(list, arr, 5); */

  add_from_input(list);

  lnode new = new_node_with(100);
  insert(list, new, 1);

  print_list(list);
  printf("Size:%d\n", list->size);
  lnode node = *(list_index(list, 1));

  printf("list[1]:%d\nprev:%d\nnext:%d\n", node->data,
         node->prev->data, node->next->data);
  free_list(list);
  print_list(list);
  return 0;
}
