/*
     Complete program of implementation and algorithms of
             stack data structures using
                 SINGLY LINKED LIST
                                -K.S.Ragavan
*/

/*
    pre-requisite: stack implementation using arrays
    Implementing stack using singly linked list will make the stack flexible.
    Hence the size of the stack doesn't need to be fixed.
*/

#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>

struct node
{
    int data;
    struct node* next;
}*top = NULL,*temp = NULL,*newnode = NULL;

/*
    top - points the top node
    temp - node used for stack
    newnode - used for allocating memory when new node is created
*/

struct node* create(int); // implements creation of new node int he implementation
void push(int);
void pop();
bool isempty();
int peek();

struct node* create(int data)
{
    newnode =  (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
};

void push(int data)
{
    if(top == NULL)
    {
        temp = create(data);
        top = temp;
    }
    else
    {
        temp = create(data);
        temp->next = top;
        top = temp;
    }
}

void pop()
{
    if(isempty())
    {
        printf("Stack Underflow\n");
        return;
    }
    top = top->next;
}

int peek()
{
    return top->data;
}

bool isempty()
{
    if(top == NULL)
        return true;
    else
        return false;
}

int main()
{
    printf("\t\t\tMENU BAR\n");
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Peek\n");
    printf("4. isempty\n");
    printf("Enter your choice: ");
    int choice;
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
        {
            printf("Enter the data that has to be pushed: ");
            int data;
            scanf("%d",&data);
            push(data);
        }
        break;
        case 2:
            pop();
            break;
        case 3:
            printf("Topmost element is: %d\n",peek());
            break;
        case 4:
        {
            if(isempty())
                printf("The stack is empty.\n");
            else
                printf("The stack is not empty.\n");
        }
        break;
        default:
            printf("Enter a valid choice.\n");
    }
    char control;
    printf("Do you want to continue[Y/N]: ");
    scanf(" %c",&control);
    system("pause");
    system("cls");
    if(control == 'y'|| control == 'Y')
        main();
    return 0;
}
