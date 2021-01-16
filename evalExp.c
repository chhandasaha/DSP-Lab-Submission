#include<stdio.h>
#include<string.h>
//func for selecting the precedence
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
int isDigit(int data) 
{ 
	return (data >= '0' && data<= '9');
}

int valStack[50], valTop=-1;
char opStack[50], opTop =-1;

void valPush(int valValue, int n){        
    if (valTop == n )   //n is capacity of the stack
    printf("\n Overflow: Stack is full.");   
    else   
    {           
        valTop = valTop +1;   
        valStack[valTop] = valValue;  
    }
}
//pop elem from stack top
void valPop(){   
    if(valTop == -1)   
    printf("Underflow: Empty Stack.");  
    else  
    valTop = valTop -1;   
}
void opPush(int opValue, int n){        
    if (opTop == n )   //n is capacity of the stack
    printf("\n Overflow: Stack is full.");   
    else   
    {           
        opTop = opTop +1;   
        opStack[opTop] = opValue;  
    }
}
//pop elem from stack top
void opPop(){   
    if(opTop == -1)   
    printf("Underflow: Empty Stack.");  
    else  
    opTop = opTop -1;   
}

//evaluation operation
int evaluate(char tokens[])
{
	int i;
	int len = strlen(tokens);
	for(i = 0; i< len; i++)
	{
		if(tokens[i] == ' ')
			continue;
			
		else if(tokens[i] =='('){
			opPush(tokens[i],len);
			//push(tokens[i],n);
		}
		else if(isDigit(tokens[i]))//current token is a number push it to stack.
		{
			int value = 0;
			while(i< len && isDigit(tokens[i]))
			{
				value = (value*10) + (tokens[i]-'0');
				i = i + 1;
			}
			valPush(value, len);
			i = i-1;
		}
		//when closing brace is there solve the entire brace
		else if(tokens[i] == ')')
		{
			while(opTop != -1 && opStack[opTop] != '(' )
			{
				int value2 = valStack[valTop];
				valPop();
				
				int value1 = valStack[valTop];
				valPop();
				
				char operand = opStack[opTop];
				opPop();
				
				valPush(applyOperator(value1, value2, operand), len);
			}
			if(opTop != -1)
				opPop();
		}
		else
		{
			while(opTop != -1 && precedence(opTop) >= precedence(tokens[i]))
			{
				int value2 = valStack[valTop];
				valPop();
				
				int value1 = valStack[valTop];
				valPop();;
				
				char operand = opStack[opTop];
				opPop();
				
				valPush(applyOperator(value1, value2, operand),len);
			}
			opPush(tokens[i],len);
		}
	}
	while(opTop != -1)
	{
		int value2 = valStack[valTop];
		valPop();
				
		int value1 = valStack[valTop];
		valPop();
				
		char operand = opStack[opTop];
		opPop();
				
		valPush(applyOperator(value1, value2, operand),len);
				
	}
	return valTop;		
}
int main()
{
	int x = evaluate("10 + 2 * 6");
	printf(" the evaluation is : %d\n", x);
	return 0;
}
