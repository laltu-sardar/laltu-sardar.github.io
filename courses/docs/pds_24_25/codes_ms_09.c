#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int value;
    struct node * next;
}NODE;

NODE*  insert_at_begining(NODE*head,int value){
    NODE* new=malloc(sizeof(NODE));
    new->value = value;
    new->next = head;
    return new;
}

void display_list(NODE* head){
    printf("\ndisplay_list ===.\n");
    NODE* tempt=head;
    if (head==NULL) {
        printf("Empty list.\n");
        return;
    }
    do {
        printf("%d  ",tempt->value);
        tempt=tempt->next;
    } while(tempt!=NULL);
}
NODE* create_node(int value){
    NODE* new=malloc(sizeof(NODE));
    new->value=value;
    new->next=NULL;
    return new;
}
void insert_at_end(NODE** head,int value){
    NODE* tempt=*head;
    NODE* new=create_node(value);
    if(tempt==NULL){
        *head=new;
        return;
    }
    while(tempt->next!=NULL){
        tempt=tempt->next;

    }
    tempt->next=new;
    return;
}
//if success return 0; else return 1
int search_and_delete(NODE ** head, int value){
    NODE *temp, * prev;
    temp = *head;
    prev = NULL;
    if (temp == NULL) {
        return 1;
    }
    while (temp != NULL) {
        if (temp->value==value) {
            printf("We got %d\n",value );
            if (prev==NULL) {
                *head = temp->next;
            }else{
                prev -> next = temp->next;
            }
            free(temp);
            return 0;

        }

        prev = temp;
        temp = temp->next;

    }
    return 0;
}


int main(){
    NODE* head;
    head=NULL;
    int value=10;

    head=insert_at_begining(head,10);
    head=insert_at_begining(head,3);
    head=insert_at_begining(head,20);
    display_list(head);
    search_and_delete(&head, 20);
    display_list(head);
    return 0;
    insert_at_end(&head, 39);
    head=insert_at_begining(head,3);
    insert_at_end(&head, 19);

    display_list(head);
    search_and_delete(&head, 20);

    display_list(head);
    return 0;
}
