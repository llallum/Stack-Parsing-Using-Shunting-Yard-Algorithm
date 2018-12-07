#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char stack[25];
int top = -1;


void push(char item)
{
    stack[++top] = item;
}

char pop()
{
    return stack[top--];
}

int precedence(char symbol)
{
    switch(symbol)
    {
    case '+':
    case '-':
        return 2;

    case '*':
    case '/':
        return 3;
    case '^':
        return 4;
    case '(':
    case ')':
    case '#':
        return 1;
        break;
    }
}


int isOperator(char symbol)
{
    switch(symbol)
    {
        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
        case '(':
        case ')':
            return 1;
            break;
        default:
            return 0;

    }


}


int convert(char infix[], char postfix[])
{
    int i, symbol,j = 0;
    stack[++top] = '#';

    for (i=0;i<strlen(infix);i++)
        {
            symbol = infix[i];
            if(isOperator(symbol))
                {
                    if(symbol == '(')
                        push(symbol);
                    else if (symbol == ')'){
                        while(stack[top] != '(')
                        {
                              postfix[j++] = pop();
                        }
                        pop();
                        }
                    else {
                        if(precedence(symbol)>(precedence(stack[top])))
                            push(symbol);
                        else
                        {
                            while(precedence(symbol)<=precedence(stack[top]))
                                postfix[j++] = pop();
                            push(symbol);
                        }
                    }
                }

            else
                postfix[j++] = symbol;
        }

    while(stack[top]!= '#')
        postfix[j++] = pop();
}

int main(void)
{

 char postfix [25] = {0};
 char infix[25] = "3+(4*2)-1^1(2*3)";

 //printf("%d", sizeof(infix));


 convert(infix, postfix);

 return 0;

}
