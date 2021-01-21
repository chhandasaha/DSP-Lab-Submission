#include<stdio.h>
#include<string.h>
#include <stdlib.h>
//func for selecting the precedence, * and / has higher precedence than + and -
int precedence(char op)
{
	if(op== '+' || op == '-')
	return 1;
	if(op == '*' || op == '/')
	return 2;
	return 0;
}
//func for arithmatic operation
int applyOperator(int a, int b, char op)
{
	switch(op)
	{
		case '+': return a+b;
		case '-': return a-b;
		case '*': return a*b;
		case '/': return a/b;
	}
}
//check if the expression is digit
int isDigit(int data) 
{ 
	return (data >= '0' && data<= '9');
}
//func for checking operand
int isOperand(char s)
{
	return (s == '+' || s == '-' || 
	   s == '*' || s == '/' || 
	   s == '(' || 
	   s == '^' ||
	   s == ')' );
}

int valStack[50], valTop=-1;// integer value stack
char opStack[50], opTop =-1;//operator stack

//function for value evaluation operation
int evaluate(char tokens[])
{
	int i;
	int len = strlen(tokens);
	for(i = 0; i< len; i++)
	{
		//if the toke is white space, ignore it
		if(tokens[i] == ' ')
			continue;
		//if current token is '(' push it to opStack	
		else if(tokens[i] =='('){
			opTop= opTop+1;
			opStack[opTop] = tokens[i];
		}
		//current token is a number push it to stack.
		else if(isDigit(tokens[i]))
		{
			int value = 0;
			while(i< len && isDigit(tokens[i]))
			{
				value = (value*10) + (tokens[i]-'0');
				i = i + 1;
			}
			valTop = valTop+1;
			valStack[valTop] = value;
			i = i-1;
		}
		//when closing brace is there solve the entire brace
		else if(tokens[i] == ')')
		{
			while(opTop != -1 && opStack[opTop] != '(' )
			{
				int value2 = valStack[valTop];
				valTop = valTop-1;
				
				int value1 = valStack[valTop];
				valTop = valTop-1;
				
				char operand = opStack[opTop];
				opTop = opTop-1;
				
				valTop = valTop + 1;
				valStack[valTop] = applyOperator(value1, value2, operand);
			}
			//pop the top which is opening brace
			if(opTop != -1)
				opTop = opTop-1;
		}
		else //an operator
		{
			//if the opStack is not empty and precedence of opTop is greater than or equal to the current token,
			//apply operator on top two elems of val Stack
			while(opTop != -1 && precedence(opTop) >= precedence(tokens[i]))
			{
				int value2 = valStack[valTop];
				valTop = valTop-1;
				
				int value1 = valStack[valTop];
				valTop = valTop-1;
				
				char operand = opStack[opTop];
				opTop = opTop-1;
				
				valTop = valTop+1;
				valStack[valTop] = applyOperator(value1, value2, operand);
			}
			//push current token to the opStack
			opTop = opTop+1;
			opStack[opTop] = tokens[i];
		}
	}
	//if the opStack is not empty apply operator on remaining elems
	while(opTop != -1)
	{
		int value2 = valStack[valTop];
		valTop = valTop-1;
				
		int value1 = valStack[valTop];
		valTop = valTop-1;
				
		char operand = opStack[opTop];
		opTop = opTop-1;
		
		valTop = valTop+1; 		
		valStack[valTop] = applyOperator(value1, value2, operand);
				
	}
	//Top value of the valstack is the result
	return valStack[valTop];		
}

_Bool isValidChar(char c){
	return isDigit(c) || isOperand(c);
}

int main()
{
	int i;
//	opStack[0] = '(';
//	opStack[i+1] = ')';
	
	char exp[100], exp2[100];
	scanf("%s", exp);
	int n = strlen(exp);
	while(i<n)
	{
   		if(isValidChar(exp[i]))
		{
   			exp2[i+1]=exp[i]; 
		}
		else
		{
	    	printf("Invalid");	
			return 0;		
		} 
		i++; 	
	}
     	
   	exp2[i+1]=')'; 
	
	printf("%d", evaluate(exp));
//	int m = evaluate("((10*7)*5)+((100-(75/15))+5)");
//	printf(" the value is : %d\n", m);
	
	return 0;
}
