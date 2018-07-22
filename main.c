#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>

#include "operation.h"

int main()
{
	setlocale(LC_ALL, "Russian");

	char ch, b = ' ';
	int flag = 0;
	stack* p;

	FILE *mf;
	printf("Открытие файла : ");
	mf = fopen("test.txt", "r");

	if (mf == NULL)
	{
		printf("ошибка\n");
		return -1;
	}
	else
		printf("выполнено\n");

	create(&p);

	fscanf(mf, "%c", &ch);
	if (ch == 'x' || ch == 'y' || ch == 'z')
		flag = 1;

	while ((fscanf(mf, "%c", &ch)) != EOF && flag != 0)
	{
		if (ch != 'x' || ch != 'y' || ch != 'z')
			flag = 0;
		if ((ch == 'x' || ch == 'y' || ch == 'z') && flag == 1)
			flag = 0;
		else
			if (ch == '+' || ch == '-')
				flag = 2;
			else
				if (ch == 'x' || ch == 'y' || ch == 'z')
					flag = 1;
				else
					if (ch == '(' || ch == '[')
						p = pushdstack(ch, p);
					else
						if (ch == ')' || ch == ']')
							if (popdstack(&b, &p))
								if (ch == ')')
									flag = b == '(';
								else
									flag = b == '[';
							else
								flag = 0;

	}
	if (flag != 0 && flag != 2 && p == NULL)
		printf("Формула верна\n");
	else
		printf("Формула не верна\n");
}
