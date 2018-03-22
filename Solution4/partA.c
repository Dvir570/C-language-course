#include <stdlib.h>

struct node{
  struct node *next;
  struct node *middle;
  int value;
  int index;
};
struct node *head;
int *arr;
int length = 0;

int take(int num){
    struct node *newNode;
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->value = num;
    newNode->index = head->index +1;
    newNode->next = newNode;
    head->next = newNode;
    if(newNode->index == 0)
        newNode->middle = newNode;
    else if(newNode->index%2 == 0)
        newNode->middle = head->middle;
    else
        newNode->middle= head->middle->next;
    head = newNode;
    return head->middle->value;
}

int take2(int num){
    int *temp;
    if(length == 0){
        temp = (int *)malloc(sizeof(num));
    }
    else temp = (int *)malloc(sizeof(arr+1));
    int i=0,j=0;
    while(i<length && arr[i]<num){
        temp[j]=arr[i];
        i++;
        j++;
    }
    temp[j]=num;
    j++;
    while(i<length){
        temp[j]=arr[i];
        i++;
        j++;
    }
    arr=temp;
    return arr[length/2];
    
}