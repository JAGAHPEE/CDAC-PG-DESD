struct stack
{
	int tos;
	int *a;
	int size;
}std;

void display();
void push(int);
int pop();
int peep();
int is_Empty();
int is_Full();
