#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int value;
    struct node * next;
}NODE;


void pause(){
    ;
}

void list_print_rev(NODE * temp){
    if(temp== NULL)
        return; 
    list_print_rev(temp->next);
    printf("%d ", temp->value);
    return;
}




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
        //pause();
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

    int a=10;
    float b=-5.4;
    int e = b;
    
    int k= &b;
    printf("\n %d %ld\n",k,&b );
    
    int c = a+b;
    printf("\nc = %d %d\n",c, e);

    float d = a+b;
    printf("\nc = %f\n",d);
    
    printf("\n\n");

    NODE* head;
    head=NULL;
    int value=10;

    head=insert_at_begining(head,10);
    head=insert_at_begining(head,3);
    head=insert_at_begining(head,20);
    display_list(head);
    list_print_rev(head);
    
    display_list(head);
    search_and_delete(&head, 10);
    display_list(head);
    return 0;
    insert_at_end(&head, 39);
    head=insert_at_begining(head,3);
    insert_at_end(&head, 19);

    display_list(head);
    search_and_delete(&head, 20);

    display_list(head);
    list_print_rev(head);
    return 0;
}
