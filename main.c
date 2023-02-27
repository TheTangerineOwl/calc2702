// Гомзякова Софья АВТ-213
/*
Самостоятельно написать программу-калькулятор: в основном меню программа запрашивает
у пользователя действие и аргументы. Затем вызывает указанную функцию и выводит
результат. После этого снова запрашивает действие.
*/
#include <stdio.h>
#include <stdlib.h>

int menu(int, int);
int add(int x, int y) { return x + y; }
int subtract(int x, int y) { return x - y; }
int multiply(int x, int y) { return x * y; }

int (*select(char choice)) (int, int)
{
	switch (choice)
	{
	case '+': return add;
	case '-': return subtract;
	case '*': return multiply;
	case '0':
	{
		printf("\nDo you want to exit? Y/N: ");
		char c = getchar();
		while ('\n' == c || getchar() != '\n' || (c != 'Y' && c != 'N'))
		{
			if (c != '\n') while (getchar() != '\n');
			printf("\nError: incorrect input! Try again: ");
			c = getchar();
		}
		if ('Y' == c) exit(0);
		else return menu;
	}
	default:
	{
		printf("\nError: incorrect option! Try choosing again.\n");
		return menu;
	}
	}
}

int menu(int a, int b) {
	int (*action) (int, int);
	printf("\tChoose the action:\n+ Addition;\n- Subtraction;\n* Multiplication;\n0 exit.");
	printf("\nEnter: ");
	char choice = getchar();
	while ('\n' == choice || getchar() != '\n')
	{
		if (choice != '\n') while (getchar() != '\n');
		printf("\nError: incorrect option! Try choosing again: ");
		choice = getchar();
	}
	action = select(choice);
	int result = action(a, b);
	printf("Result:\n%d %c %d = %d", a, choice, b, result);
	return 0;
}

int main()
{
	printf("\t\tCALCULATOR\n");
	int a, b;
	while (1)
	{
		printf("\nEnter the first number: ");
		while ((scanf_s("%d", &a) == 0) || (getchar() != '\n'))
		{
			scanf_s("%*[^\n]");
			printf("Error: incorrect input! Try again: ");
		}
		printf("Enter the second number: ");
		while ((scanf_s("%d", &b) == 0) || (getchar() != '\n'))
		{
			scanf_s("%*[^\n]");
			printf("Error: incorrect input! Try again: ");
		}
		menu(a, b);
	}
	return 0;
}
