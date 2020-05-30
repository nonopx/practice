#include <stdio.h>

#define MAX_SIZE 1000

void get_input(char *input_str)
{
	printf(">>> ");
	scanf("%s", input_str);
}

int find_cor(char *input_str)
{
	int index = 0;
	int stack = 0;

	while (!(input_str[index] == '[' && stack == 0)) {
		if (input_str[index] == ']')
			stack++;
		if (input_str[index] == '[')
			stack--;
		index--;
	}
	return index;
}

void print_cells(int *bf_cells)
{
	for (int i = 0; i < 15; i++)
		printf("%d ", bf_cells[i]);
	printf("\n");
}

int brain_fuck()
{
	int bf_cells[MAX_SIZE] = { 0 };
	char input_str[MAX_SIZE] = { 0 };
	int index = 0;
	int cor;

	get_input(input_str);

	for (int i = 0; i < strlen(input_str); i++) {
		
		if (input_str[i] == '>')
			index++;
		if (input_str[i] == '<')
			index--;
		if (input_str[i] == '+')
			bf_cells[index]++;
		if (input_str[i] == '-')
			bf_cells[index]--;
		if (input_str[i] == ',')
			scanf("%c", bf_cells + index);
		if (input_str[i] == '.')
			printf("%c", bf_cells[index]);
		if (input_str[i] == '[')
			continue;
		if (input_str[i] == ']')
		{
			if (!bf_cells[index])
				continue;
			cor = find_cor(input_str + i - 1);
			i = i + (cor - 2);
		}
	}
}

int main()
{
	brain_fuck();
	return 0;
}