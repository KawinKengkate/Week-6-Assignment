//
//  Queue.h
//  Queue
//
//  Created by 6272 on 1/3/2562 BE.
//  Copyright © 2562 6272. All rights reserved.
//

#ifndef Queue_h
#define Queue_h
#include <stdlib.h>
typedef struct node{
    struct node* next;
    int order_number;
    int qty;
}order;

typedef struct {
    order *head,*tail;
    int size;
}Queue;

int cus=0;

void enqueue(Queue *q,int ord,int qty){
    order* new_node=(order*)malloc(sizeof(order));
    if(new_node){
        new_node->next=NULL;
        new_node->order_number=ord;
        new_node->qty=qty;
        if(q->head)/*q->size>0*/
            q->tail->next=new_node;
        else
            q->head=new_node;
        q->tail=new_node;
        q->size++;
        printf("My order is %d\n", q->tail->order_number);
    }
}

int  dequeue(Queue *q){
    int money = 0;
    if(q->size==0) {
        printf("No queue\n");
        return 0;
    }
    printf("Customer no: %d\n", ++cus);
    order *t =q->head;
    int x=t->order_number;
    switch(x)
    {
      case 1:
      printf("Ramen\n");
      money = q->head->qty*100; break;
      case 2:
      printf("Somtum\n");
      money = q->head->qty*20; break;
      case 3:
      printf("Fried Chicken\n");
      money = q->head->qty*50; break;
      default:
      money = 0; break;
    }
    
    q->head=q->head->next;
    if(!q->head) q->tail=NULL;
    q->size--;
    free(t);
    return money;
    
}
#endif /* Queue_h */