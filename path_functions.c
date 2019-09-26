#include "monty.h"
/**
 * check_int - verify if the value inside of the file is ingeger
 * @str: the value taken
 * Return: 0 on success and -1 on fail
*/
int check_int(char *str)
{
	int i = 0;

	for (i = 0; str != NULL && str[i] != '\0'; i++)
	{
		if (isdigit(str[i]) == 0)
		{
			return (-1);
		}

	}
	return (0);
}

/**
 * build_monty - read line by line the file content
 * @path: root of the file (argv[1])
 * Return: -1 on fail and 1 on success
 */

int build_monty(char *path)
{
	FILE *montyFile;
	char *line = NULL;
	int line_count = 0;
	size_t len = 0;
	ssize_t read;

	montyFile = fopen(path, "r");

	if (montyFile != NULL)
	{
		while ((read = getline(&line, &len, montyFile)) != EOF)
		{
			line_count++;
				if (line != NULL)
				{
					if (split_line(line, line_count) == -1)
					{
						free(line);
						fclose(montyFile);
						free_list();
						exit(EXIT_FAILURE);
					}
				}
		}
		free(line);
		fclose(montyFile);
	}
	else
		return (-1);
	return (1);
}

/**
 * split_line - split the line in 2 values (opcode and value)
 * @line: line to be splited
 * @line_count: number of line
 * Return: 0 on success and -1 on fail
 */


int split_line(char *line, unsigned int line_count)
{
	char *command, *value;
	char *separators = "\n ";

	if (line != NULL)
	{
		command = strtok(line, separators);
		if (command == NULL)
			return (0);
		value = strtok(NULL, separators);
		if (find_func(command, value, line_count) == -1)
			return (-1);
	}
	return (0);
}
