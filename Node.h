//
//  linkedlist.h
//  LinkedList_simple
//
//  Created by Mingmanas Sivaraksa on 5/2/2564 BE.
//

#ifndef Node_h
#define Node_h

struct node
{
    int data;
    struct node *nextPtr;
};

int value;
typedef struct node QNode;
typedef struct node* QNodePtr;



void enqueue(QNodePtr* head, QNodePtr* tail, int x)
{
  QNode *new_node=(QNode*) malloc(sizeof(QNode)); 
  if(new_node){
    new_node->data=x;
    new_node->nextPtr=NULL;
    if(*head==NULL) *head=new_node;
    else (*tail)->nextPtr=new_node;
    *tail=new_node;
  }
}

int dequeue(QNodePtr *head, QNodePtr* tail){
  QNodePtr t=*head;
  if(t){
  int value= t->data;
  *head= t->nextPtr;
  if(*head == NULL) *tail = NULL; 
  free(t);
  return value;
  }
  printf("emptyqueue\n");
  return 0;
}

void enqueue_struct(Queue* q, int x)
{
  QNode *new_node=(QNode*) malloc(sizeof(QNode)); 
  if(new_node){
    new_node->data=x;
    new_node->nextPtr=NULL;
    if(q->headPtr==NULL) q->headPtr=new_node;
    else (q->tailPtr)->nextPtr=new_node;
    q->tailPtr=new_node;
    q->size++;
  }
}

int dequeue_struct(Queue* q){
  QNodePtr t=q->headPtr;
  if(t){
  int value= t->data;
  q->headPtr= t->nextPtr;
  if(q->headPtr == NULL) q->tailPtr = NULL; 
  free(t);
  q->size--;
  return value;
  }
  printf("emptyqueue\n");
  return 0;
}


#endif
