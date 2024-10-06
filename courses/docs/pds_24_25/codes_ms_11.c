//Stack using array
#include<stdio.h>
#include<stdlib.h>

#define STACK_SIZE 10

typedef struct stack{
    int *arr;
    int size;
    int top_ctr;
}Stack;

Stack stack_create(int size){
    Stack stack;
    stack.arr = (int *)malloc(size * sizeof(int) );
    if (stack.arr==NULL) {
        printf("Error\n" );
        exit(1);
    }
    stack.size = size;
    stack.top_ctr = 0;
    return stack;
}

//returns 0 on success
int stack_push(Stack * stack, int value ){
    if (stack_is_full(*stack)){
        return 1;
    }
    stack->arr[stack->top_ctr]=value;
    stack->top_ctr += 1;
    return 0;
}

void stack_display(Stack s){
    printf("Displaying List:\n" );
    for (int i = s.top_ctr-1 ; i >=0 ; i--) {
            printf("%d --> ", s.arr[i]);
    }
    printf("end");
}

//return 1 if yes, else return 0
int stack_is_full(Stack stack){
    if (stack->top_ctr ==stack->size -1){
        return 1;
    }
    return 0;
}

int main(){
    Stack s  = stack_create(STACK_SIZE);
    stack_push(s, 10);
    stack_display(s);

    return 0;
}
