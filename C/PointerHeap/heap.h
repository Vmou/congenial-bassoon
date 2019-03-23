typedef struct heap_node * hnode;
typedef struct heap_struct * hp;
struct heap_node
{
  int data;
  hnode lchild;
  hnode rchild;
  hnode parent;
};

struct heap_struct
{
  hnode head;
  hnode last;
  int size;
};
