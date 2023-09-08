/*===============================================================================
this program uses a function to apply AND operator on an unkown amount of natural numbers.
the program also print to screen the command it was given and the result both in decimal and hexadecimal bases.
===============================================================================*/
#include <stdio.h>
#include <stdarg.h>

int and_func(int arg_num,...);
void res_print(int result);

int main()
{
	int result;
	result = and_func(3,3000,50000,2,11);
	res_print(result);
	result = and_func(2, 2050555,1);
	res_print(result);
	result = and_func(6,1,1,1,1,1,1);
	res_print(result);
	result = and_func(4,12,5,80,66);
	res_print(result);
	
	return 0;
}

/*===============================================================================
this function gets an unkown number of integers and return the result of applying AND operator on them.
the first integer that this function gets states the number of integer the function is getting.
===============================================================================*/
int and_func(int arg_num,...)
{
	va_list ptr;
	int num1, num2, result;
	int i;
	
	va_start(ptr, arg_num);
	
	if(arg_num <= 2)/*no more than two nambers where given*/
	{
		if(arg_num == 0)
		{
			result = 0;
			printf("no numbers enterd\n");
		}
		else if(arg_num == 1)
		{
			result = va_arg(ptr,int);
			printf("only one number enterd (hexadecimal in parenthesis): %d (%x)\n", num1, num1);
		}
		else
		{
			num1 = va_arg(ptr,int);
			num2 = va_arg(ptr,int);
			result = num1 & num2;
			printf("the command enterd (hexadecimal in parenthesis):\n");
			printf("%d (%x) & %d (%x)\n", num1, num1, num2, num2);
		}
	}
	else
	{
		num1 = va_arg(ptr,int);
		num2 = va_arg(ptr,int);
		printf("the command enterd (hexadecimal in parenthesis):\n");
		printf("%d (%x) & ",num1,num1);
		for(i = 2; i < arg_num; i++)
		{
			printf("%d (%x) & ",num2,num2);
			result = num1 & num2;
			num1 = num2;
			num2 = va_arg(ptr,int);
		}
		printf("%d (%x)\n",num2, num2);
	}

	va_end(ptr);
	return result;
}

/*===============================================================================
this function prints a number in decimal and hexadecimal bases.
it gets an integer to print and return nothing.
===============================================================================*/
void res_print(int result)
{
	printf("the result number in decimal base is:\n");
	printf("%d\n", result);
	printf("the result number in hexadecimal base is:\n");
	printf("%x\n", result);
	printf("=========================================\n");
}
