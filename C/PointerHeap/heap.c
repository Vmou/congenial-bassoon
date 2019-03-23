#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

hp new_heap(void)
{
  hp heap;
  heap = (hp)malloc(sizeof(struct heap));
  if (heap==NULL)
    {
      fprintf(stderr, "Allocation of new heap error.");
      exit(1);
    }
  heap->head = NULL;
  heap->last = NULL;
  heap->size = 0;
}

void free_heap(hp heap)
{
  free_node(heap->head);
  free(heap);
}

hnode new_node(void)
{
  hnode node;
  node = (hnode)malloc(sizeof(struct heap_node));
  if (node==NULL)
    {
      fprintf(stderr, "Allocation of new node error.");
      exit(1);
    }
  node->data = 0;
  node->lchild = NULL;
  node->rchild = NULL;
  node->parent = NULL;
  return node;
}

void free_node(hnode node)
{
  if (node!=NULL)
    {
      free_node(node->lchild);
      free_node(node->rchild);
      free(node);
    }
}

void insert(hp heap, hnode node)
{
  if (heap->last==NULL)
    {
      heap->last = node;
      heap->head = node;
      heap->size = 1;
    }
  else
    {

    }
}

int is_root(hnode node)
{
  return (node->parent == NULL);
}

int is_lchild(hnode node)
{
  return (node->parent->lchild == node);
}

int is_rchild(hnode node)
{
  return (node->parent->rchild == node);
}

int is_leaf(hnode node)
{
  return (node->lchild == NULL && node->rchild == NULL);
}

void upheap(hnode node)
{
  if (is_root(node))
    return;

}

void swap(hnode* node1, hnode* node2)
{
  hnode tmp;
  tmp = *node1;
  (*node1)->lchild = (*node2)->lchild;
  (*node1)->rchild = (*node2)->rchild;
  (*node1)->parent = (*node2)->parent;



}
