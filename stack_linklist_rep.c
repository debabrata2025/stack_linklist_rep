#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

//stack traversal
void stackTraversal(struct node *top){
    printf("element of the stack from top to bottom: \n");
    while (top!=NULL)
    {
        printf("%d\n", top->data);
        top = top->next;
    }
    printf("\n");
}



//isempty
int isEmpty(struct node *top){
    if (top == NULL)
    {
        return 1;
    }else{
        return 0;
    }
}

//isFull
int isFull(struct node *top){
    struct node *ptr = (struct node *) malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        return 1;
    }else{
        return 0;
    } 
}

//push to the head side because it takes O(1) time 
struct node *push(struct node *top, int data){
    struct node *p = (struct node *) malloc(sizeof(struct node));
    if (isFull(top))
    {
        printf("stack is overflowing %d can not be pushed to the stack\n");
    }else{
        p->data = data;
        p->next = top;
        printf("%d is pushed to the stack\n", data);
        return p;
    }
}
//pop ** -> pointer to pointer concept for de-referencing
int pop(struct node **top){
    if (isEmpty(*top))
    {
        printf("stack is underflowing, no element to remove\n");
    }else{
      struct node *p = *top;
      *top = (*top)->next;
      int x = p->data;
      free(p);
      return x;
    }
}

int stackTop(struct node *top){
    return top->data;
}
int stackBottom(struct node *top){
    struct node *p = top;
    if (isEmpty(top))
    {
        printf("stack is underflowing\n");
    }
    
    while (p->next != NULL)
    {
        p = p->next;
    }
    return p->data;
}

//peek operation
int peek(struct node *top, int pos){
    struct node *ptr = top;
    for (int i = 0; (i < pos-1 && ptr!=NULL); i++)
    {
        ptr = ptr->next;
    }
    if (ptr!=NULL)
    {
        return ptr->data;
    }else{
        return -1;
    }
    
    
}


int main()
{
    struct node *top = NULL;

    //push operation
    top = push(top, 10);
    top = push(top, 11);
    top = push(top, 12);
    top = push(top, 13);
    top = push(top, 14);
    top = push(top, 15);
    top = push(top, 16);
    top = push(top, 17);

    //stacktop
    printf("stack top\n");
    printf("%d is present to the top of the stack\n", stackTop(top));
    //stack bottom
    printf("stack bottom\n");
    printf("%d is present to the bottom of the stack\n", stackBottom(top));

    //peek operation
    printf("peek operation\n");
    int index;
    scanf("enter the position from where you want to peek an item\n");
    scanf("%d", &index);
    printf("%d is present at %d index\n", peek(top, index), index);
    
    // stack traversal
    printf("stack traversal \n");
    stackTraversal(top);


    
    //pop operation 
    printf("pop operation \n");
    printf("%d is popped from the stack\n", pop(&top));
    printf("%d is popped from the stack\n", pop(&top));
    printf("%d is popped from the stack\n", pop(&top));
    printf("%d is popped from the stack\n", pop(&top));
    printf("%d is popped from the stack\n", pop(&top));
    printf("%d is popped from the stack\n", pop(&top));
    printf("%d is popped from the stack\n", pop(&top));
    printf("%d is popped from the stack\n", pop(&top));


    return 0;
}