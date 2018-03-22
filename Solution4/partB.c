#include <stdbool.h>
#include <string.h>

struct stackNode{
  struct stackNode *prev;
  char value;
};

struct stackNode *s_head = NULL;
bool isStringBalanced(char** sentence, int size) {
    int i=0;
    for(;i<size;i++){
        char *word = *(sentence+i);
        int j= 0;
        for(;word+j<word+strlen(word);j++){
            if(*(word+j)=='(' || *(word+j)=='[' || *(word+j)=='{'){
                struct stackNode *newNode = (struct stackNode *)malloc(sizeof(struct stackNode));
                newNode->value=*(word+j);
                newNode->prev=s_head;
                s_head = newNode;
            }
            else if(*(word+j)==')'){
                if(!s_head)
                    return false;
                if(s_head->value != '(')
                    return false;
                struct stackNode *destroy = s_head;
                s_head = s_head->prev;
                free(destroy);
            }else if(*(word+j)==']'){
                if(!s_head)
                    return false;
                if(s_head->value != '[')
                    return false;
                struct stackNode *destroy = s_head;
                s_head = s_head->prev;
                free(destroy);
            }else if(*(word+j)=='}'){
                if(!s_head)
                    return false;
                if(s_head->value != '{')
                    return false;
                struct stackNode *destroy = s_head;
                s_head = s_head->prev;
                free(destroy);
            }
        }
    }
    if(s_head)
        return false;
    return true;
}