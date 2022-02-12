//
//  main.c
//  Queue
//
//  Created by 6272 on 1/3/2562 BE.
//  Copyright © 2562 6272. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include "Queue.h"

int main(int argc, const char * argv[]) {
    int i, price, money;
    Queue Q;
    Q.head=NULL;
    Q.tail=NULL;
    Q.size=0;
    
    for(i=1;i<argc;i++){
      money = 0;
        if(strcmp(argv[i],"x")==0){
            if(Q.size == 0) printf("The queue is empty!\n");
            else {
              price=dequeue(&Q);
              if(price > 0)
              {
                printf("You have to pay %d\n", price);
                while(money<price)
                {
                  printf("Cash: ");
                  scanf("%d",&money);
                }
                if(money>price)
                {
                  printf("Change is: %d\n", money-price);
                }
                printf("Thank you!\n");
              }
              else printf("NO FOOD!!!\n");
            }
        }
        else
        {
          enqueue(&Q, atoi(argv[i]),atoi(argv[i+1]));
          i++;
        }           
    }
    printf("===================================\n");
    if(Q.size > 0)
    {
      printf("\nThere are %d ppl left in the queue\n", Q.size);
    }
    return 0;
}