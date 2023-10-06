#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct stack
{
	int *a;
	int tos;
	int size;
} std;

void display();
void push(char);
int pop();
int peep();
int is_Empty();
int is_Full();
int prec(char ch);

// char ip[]="{a+(b*c)+(b+c)+(d*e)}";
char *op;
char ip[] = "{a+b*c/f-[d*e/g]}";

int main()
{
	std.tos = -1;

	int i = 0, j = 0;

	char ch, s;

	int l = strlen(ip);

	std.size = l;

	printf("%d\n", l);

	std.a = (int *)malloc(sizeof(int) * std.size);

	op = (char *)malloc(sizeof(char) * l);

	for (i = l - 1; i >= 0; i--)
	{
		ch = ip[i];
		switch (ch)
		{
		case '}':
		case ')':
		case ']':
			push(ch);
			display();
			break;
		case '[':
		case '{':
		case '(':
			while (!(peep() == '}' || peep() == ')' || peep() == ']'))
			{
				op[j] = pop();
				printf("%c\n", op[j]);
				j++;
			}
			s = pop();
			break;
		case '+':
		case '-':
		case '/':
		case '*':
			// printf("%c\n",ch);
			while (!is_Empty() && (prec(ch) < prec(peep())))
			{
				op[j++] = pop();
			}
			push(ch);
			break;
		default:
			op[j++] = ch;
			// j++;
			// break;
		}
	}
	op[j] = '\0';
	// printf("%d",j);
	i = 0;
	// printf("%s\n",op);

	l = strlen(op);
	// printf("%d",l);
	char str[l];
	while (op[i] != '\0')
	{
		str[i] = op[l - i - 1];
		// printf("%c\n",op[i]);
		i++;
	}

	str[i] = '\0';

	printf("%s", str);
	free(op);
	free(std.a);
	op = NULL;
	std.a = NULL;
}
int prec(char ch)
{
	switch (ch)
	{
	case '*':
	case '/':
		printf("*/\n");
		return 3;
	case '+':
	case '-':
		printf("+-\n");
		return 2;
	case ')':
	case '}':
	case ']':
		printf("( { [\n");
		return 1;
	}
}
void display()
{
	if (!is_Empty())
	{
		for (int i = 0; i <= std.tos; i++)
		{
			printf("%c ", std.a[i]);
		}
	}
	else
	{
		printf("Stack is Empty");
	}
}
int is_Empty()
{
	if (std.tos == -1)
	{
		return 1;
	}
	return 0;
}
int is_Full()
{
	if (std.tos == std.size - 1)
	{
		return 1;
	}
	return 0;
}
void push(char num)
{
	if (!(is_Full()))
	{
		std.tos++;
		std.a[std.tos] = num;
		printf("%d\n", std.tos);
	}
	else
	{
		printf("Stack is Full");
	}
}
int pop()
{
	char x;
	if (!(is_Empty()))
	{
		x = std.a[std.tos];
		std.tos--;
		return x;
	}
	else
	{
		printf("Stack is Empty\n");
	}
	return x;
}
int peep()
{
	int x = -11;
	if (!(is_Empty()))
	{
		x = std.a[std.tos];
	}
	else
	{
		printf("Stack is Empty\n");
	}
	return x;
}
