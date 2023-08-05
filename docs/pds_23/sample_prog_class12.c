#include<stdio.h>
#include<stdlib.h>


typedef struct node Node;

Node *  create_list();
void add_element(Node ** head, int x);
Node *create_node();
void show_list(Node * head);

struct node {
  int val;
  struct node * next;
};


Node *  create_list(){
  Node * head = NULL;  
  return head ; 

}

Node *create_node(){
  Node * new  = (Node *) malloc(sizeof(Node));
  //if (new== NULL) {
  //  return some error message
  //}
 return new; 
}
void show_list(Node * head){
  Node * temp = head;
  printf("list : ");
  while(temp != NULL){
    printf("%d --->  ", temp->val); 
    temp = temp->next;
  }
  printf("---- list end\n");
}


void add_element(Node ** head, int x){
  Node * temp;
  if (*head == NULL){
    Node * new = create_node();
    (*new).val = x;
    (*new).next = NULL;
    *head = new;
     
  }else{
     temp  = *head;      
     while(temp->next !=NULL){
       temp  =  temp->next; // (*temp).next 
     }
     Node *new = create_node();
     new->val=  x;
     new -> next = NULL;
     temp -> next = new;
  }
}

int main (){

  Node * head = create_list();
  
  add_element(&head, 5);
  show_list(head);
  
  add_element(&head, 3);
  show_list(head);  
  
  add_element(&head, 8);
  show_list(head);
}