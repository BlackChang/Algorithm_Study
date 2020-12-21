#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct NODE {
    int key;
    struct NODE* next;
};
struct NODE operator++(struct NODE a, int b){
    
    return a;
}
struct NODE* head;
int cnt = 0;

int stack_empty() {
    if (cnt == 0)
        return 1;
    
    return 0;
}

int stack_full() {
    if (cnt == 9)
        return 1;
    
    return 0;
}

void push(int key) {
    if (stack_full() == 1)
        printf("stack is full!\n");
    else {
        struct NODE* newnode = (struct NODE*)malloc(sizeof(struct NODE));
        struct NODE* ptr = head;

        newnode->key = key;
        newnode->next = NULL;

        ptr = head;
        if(stack_empty()){
            ptr = newnode;
            cnt++;
        }
        else{
            while(true){
                if(ptr->next == NULL){
                    ptr->next = newnode;
                    cnt++;
                    break;
                }
                else
                    ptr = ptr->next;
            }
            ptr->next = newnode;
            cnt++;
        }
    }
}
int pop() {
    if (stack_empty() == 1) {
        printf("stack is empty!\n");
        return -1;
    }
    else {
        struct NODE* ptr = head;
        
        int key = ptr->key;
        head = ptr->next;
        free(ptr);
        
        cnt--;
        
        return key;
    }
}

int main()
{
    struct NODE a;
    a++;
    
    head = (struct NODE*)malloc(sizeof(struct NODE));
    
    int menu;
    printf("Type a menu: 1.push 2.pop 3.print 4.finish\n");
    
    while (1) {
        printf("menu: ");
        scanf("%d", &menu);
        
        if (menu == 1) {
            int key;
            printf("Type a Key:   ");
            scanf("%d", &key);
            push(key);
        }
        else if (menu == 2) {
            pop();
        }
        else if (menu == 3) {
            struct NODE* ptr = head;
            if(stack_empty()){
                printf("stack is empty\n");
            }
            else{
                while (ptr != NULL) {
                    printf("%d\n", ptr->key);
                    ptr = ptr->next;
                }
            }
        }
        else if (menu == 4) {
            printf("finished!\n");
            break;
        }
        else {
            printf("\nWarning\n");
            printf("menu\n1.push 2.pop 3.print 4.finish\n");
        }
    }
    
}
