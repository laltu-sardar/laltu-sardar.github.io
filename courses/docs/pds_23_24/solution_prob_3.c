/** This program creates a linked list.
  * create, append, search, delete a node.
  */
#include<stdio.h>
#include<stdlib.h>


typedef struct node
{
	float val;
	struct node *next;
} Node;


int getMenu();
void createList(Node**);
void printList(Node*);

void appendNode(Node**, float);
void prependNode(Node**, float);
void addNode(Node**, float);
void delNode(Node**, float);

int isEmpty(Node*);
int search(Node*, float);
void sortList(Node**);
void reverseList(Node**);
void changeHead(Node**);

int main()
{
	Node *head = NULL;
	float newval;
	int menu = 1, searchStatus = 0;

    //createList(&head);
    //printList(head);

    while(menu != 0)
    {
        menu = getMenu();
        switch(menu)
        {
            case 1: // add a node
                printf("Enter a number: ");
                scanf("%f", &newval);
                addNode(&head, newval);
                printf("The new list is: ");
                printList(head);
                break;

            case 2: // search a value
                printf("Enter the number: ");
                scanf("%f", &newval);
                searchStatus = search(head, newval);
                if(searchStatus == 1)
                    printf("%f is on the list. \n", newval);
                else
                    printf("%f is NOT on the list. \n", newval);
                break;

            case 3: // delete a node
                printf("Enter a number: ");
                scanf("%f", &newval);
                delNode(&head, newval);
                printf("The new list is: ");
                printList(head);
                break;

            case 4: // sort the list
                sortList(&head);
                printf("The new list is: ");
                printList(head);
                break;

            case 5: // reverse the list
                reverseList(&head);
                printf("The new list is: ");
                printList(head);
                break;

            case 6: // question 3
                changeHead(&head);
                printf("The new list is: ");
                printList(head);
                break;

            case 0:
                printf("The new list is: ");
                printList(head);
                break;

            default:
                printf("The new list is: ");
                printList(head);
                break;
        }
    }

	return 0;
}


int getMenu()
{
    int menu;

    printf("Enter 1 to add a node, 2 to search, 3 to delete, 4 to sort, 5 to reverse, 6 to move last node to first and 0 to terminate: ");
    scanf("%d", &menu);
    return menu;
}


void createList(Node **headRef)
{
    Node *curr, *newNode;
	float newval;
	int status = 1;

    if((*headRef) == NULL)
    {
        (*headRef) = (Node *)malloc(sizeof(Node));
        if((*headRef) == NULL)
        {
            printf("Error! memory not allocated.");
            exit(1);
        }
        printf("Enter a number: ");
        scanf("%f", &newval);
        (*headRef)->val = newval;
        (*headRef)->next = NULL;
        curr = (*headRef);
    }

    while(status == 1)
    {
        printf("Enter 1 to add a number, 0 to end: ");
        scanf("%d", &status);
        if(status == 1)
        {
            printf("Enter a number: ");
            scanf("%f", &newval);
            newNode = (Node *)malloc(sizeof(Node));
            newNode->val = newval;
            newNode->next = NULL;
            curr->next = newNode;
            curr = curr->next;
        }
    }
}


void printList(Node *head)
{
    Node *curr;

    curr = head;
    while(curr != NULL)
    {
        printf("%f, ", curr->val);
        curr = curr->next;
    }
    printf("\n");
}


/** Given a reference (pointer to pointer) to the head of a list
  * and the value, appends a new node at the end.
  **/
void appendNode(Node **headRef, float newval)
{
	Node *newNode, *curr;

	curr = (*headRef); /** used in step 5 **/

	/** 1. Allocate memory **/
	newNode = (Node *)malloc(sizeof(Node));
	/** 2. Assign the data **/
	newNode->val = newval;
	/** 3. This new node is going to be the last node, so make next of it as NULL **/
	newNode->next = NULL;
	/** 4. If the Linked List is empty, then make the new node as head **/
	if((*headRef) == NULL)
	{
        (*headRef) = newNode;
        return;
	}
	/** 5. Else traverse till the last node **/
	while(curr->next != NULL)
		curr = curr->next;
	/** 6. Change the next of last node **/
	curr->next = newNode;
	return;
}


/** Given a reference (pointer to pointer) to the head of a list
  * and the value, appends a new node at the begining.
  **/
void prependNode(Node **headRef, float newval)
{
	Node *newNode;

	/** 1. Allocate memory **/
	newNode = (Node *)malloc(sizeof(Node));
	/** 2. Assign the data **/
	newNode->val = newval;
	/** 3. This new node is going to be the head node, so make next of it as the old head node **/
    newNode->next = (*headRef);
    (*headRef) = newNode;
	return;
}


void addNode(Node **headRef, float newval)
{
    Node *curr, *newNode;

    if((*headRef) == NULL)
    {
        newNode = (Node *)malloc(sizeof(Node));
        newNode->val = newval;
        newNode->next = NULL;
        (*headRef) = newNode;
        return;
    }

    curr = (*headRef);
    while(curr != NULL)
    {
        /** New value already exists in the list **/
        if(curr->val == newval)
        {
            printf("%f already exists in the list. \n", newval);
            return;
        }
        else
        {
            newNode = (Node *)malloc(sizeof(Node));
            newNode->val = newval;

            /** New value is added in the beginning of the list **/
            if((curr == (*headRef)) && (newval < curr->val))
            {
                newNode->next = (*headRef);
                (*headRef) = newNode;
                //printf("%f added in the beginning of the list before %f. \n", newval, curr->val);
                return;
            }
            /** New value is added in the middle of the list **/
            else if((curr->next != NULL) && (curr->val < newval) && (newval < curr->next->val))
            {
                newNode->next = curr->next;
                curr->next = newNode;
                //printf("%f added in the list between %f and %f. \n", newval, curr->val, curr->next->val);
                return;
            }
            /** New value is added at the end of the list **/
            else if((curr->next == NULL) && (curr->val < newval))
            {
                newNode->next = NULL;
                curr->next = newNode;
                //printf("%f added at the end of the list after %f. \n", newval, curr->val);
                return;
            }
        }
        curr = curr->next;
    }
    return;
}


void delNode(Node **headRef, float newval)
{
    Node *prev, *curr;

    /** 1. If the Linked List is empty, then return **/
	if((*headRef) == NULL)
        printf("The list is EMPTY. \n");
    /** 2. delete the head node **/
    else if((*headRef)->val == newval)
        (*headRef) = (*headRef)->next;
    else
    {
        prev = (*headRef);
        curr = prev->next;
        while(curr != NULL)
        {
            if(curr->val == newval)
            {
                prev->next = curr->next;
                free(curr);
                return;
            }
            prev = prev->next;
            curr = prev->next;
        }
    }
    return;
}


int isEmpty(Node *head)
{
    if(head == NULL)
        return 1;
    else
        return 0;
}


int search(Node *head, float searchVal)
{
    Node *curr;
    int searchStatus = 0;

    curr = head;
    while(curr != NULL)
    {
        if(curr->val == searchVal)
        {
            searchStatus = 1;
            break;
        }
        curr = curr->next;
    }
    return searchStatus;
}


void sortList(Node** headRef)
{
    Node *curr, *index;
    int temp;

    curr = (*headRef);
    index = NULL;

    if((*headRef) == NULL)
        return;
    else
    {
        while(curr != NULL)
        {
            index = curr->next; // index points to the node next to curr
            while(index != NULL)
            {
                if(curr->val > index->val)
                {
                    temp = curr->val;
                    curr->val = index->val;
                    index->val = temp;
                }
                index = index->next;
            }
            curr = curr->next;
        }
    }
}


void reverseList(Node** headRef)
{
    Node *prev, *curr, *next;

    prev = NULL;
    curr = (*headRef);

    while(curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    (*headRef) = prev;
}


void changeHead(Node** headRef)
{
    Node *curr, *last;

    /// 0 nodes
    if((*headRef) == NULL)
        return;

    /// 1 node
    curr = (*headRef);
    if(curr->next == NULL)
        return;

    /// 2 or more nodes
    while(curr->next->next != NULL)
        curr = curr->next;
    printf("2nd last node is %f. \n", curr->val);
    last = curr->next;

    curr->next = NULL;
    last->next = (*headRef);
    (*headRef) = last;

    return;
}
