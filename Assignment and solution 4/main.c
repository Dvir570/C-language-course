#include <stdio.h>
#include <stdlib.h>
#include "partA.h"
#include "partB.h"
#include "partC.h"
int main(){
    ////---part A.1---
    // head = (struct node *)malloc(sizeof(struct node));
    // head->index = -1;
    // int num;
    // while(1){
    //     printf("enter number:\n");
    //     scanf("%d", &num);
    //     printf(">> %d\n", take(num));
    // }
    
    
    ////---part A.2---
    // int num;
    // arr = malloc(0);
    // while(1){
    //     printf("enter number:\n");
    //     scanf("%d", &num);
    //     printf(">> %d\n", take2(num));
    //     length++;
    // }
    
    //// ---part B---
    // char *sentence[] = { "if(", "5[>]{7}", "){", "return;}"};
    // printf("result (1=true, 0=false): %d\n",isStringBalanced(sentence, 4));
    
    //---part C---
    struct myClass mc;
    mc.m_x = 10;
    printf("myClass befor add: %d\n",mc.m_x);
    mc.func = &add;
    mc.func(&mc, 10);
    printf("myClass after add: %d\n",mc.m_x);
    
    struct Derived der;// = (struct Derived *)malloc(sizeof(struct Derived));
    der.super = &mc;//(struct myClass *)malloc(sizeof(struct myClass));
    der.super->m_x=1;
    printf("Derived befor xor: %d\n",der.super->m_x);
    der.func = &xor;
    der.func(&der, 1);
    printf("Derived after xor: %d\n",der.super->m_x);
    
    struct Derived2 der2;// = (struct Derived2 *)malloc(sizeof(struct Derived2));
    der2.super = &mc;
    der2.super->m_x=1;
    printf("Derived2 befor add: %d\n",der2.super->m_x);
    der2.func = &add2;
    der2.func(&der2, 10);
    printf("Derived2 after add: %d\nm_y = %d\n",der2.super->m_x, der2.m_y);
    
    return 0;
}