#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Node structure
struct node
{
    int data;
    struct node *next;
};

struct node *top = NULL;

// Push operation
void push(int value)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = top;
    top = newnode;
}

// Pop operation
int pop()
{
    if (top == NULL)
    {
        printf("Stack Underflow\n");
        return -1;
    }

    struct node *temp = top;
    int value = temp->data;
    top = top->next;
    free(temp);

    return value;
}

int main()
{
    char postfix[100];
    int i, op1, op2, result;

    printf("Enter postfix expression: ");
    fgets(postfix, sizeof(postfix), stdin);

    for (i = 0; postfix[i] != '\0'; i++)
    {
        if (isdigit(postfix[i]))
        {
            push(postfix[i] - '0');
        }
        else if (postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/')
        {
            op2 = pop();
            op1 = pop();

            switch (postfix[i])
            {
                case '+': result = op1 + op2; break;
                case '-': result = op1 - op2; break;
                case '*': result = op1 * op2; break;
                case '/': result = op1 / op2; break;
            }

            push(result);
        }
    }

    printf("Result = %d\n", pop());

    return 0;
}
