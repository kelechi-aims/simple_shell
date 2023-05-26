#include "shell.h"

/**
 * is_delim - checks if character is a delimeter
 * @c: the char to checked
 * @delim: the delimeter string
 * Return: 1 if true, 0 if false
 */
int is_delim(char c, char *delim)
{
	while (*delim)
	if (*delim++ == c)
		return (1);
	return (0);
}

/**
 * _isalpha - checks for alphabetic character
 * @c: The char input
 * Return: 1 if c is alphabetic, 0 otherwise
 */

int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * _atoi - converts a string to an integer
 * @s: parameter of the function
 *
 * Return: value 0
 */
int _atoi(char *s)
{
	int a = 1;
	unsigned int b = 0;
	char c = 0;

	while (*s)
	{
		if (*s == '-')
		{
			a = a * -1;
		}
		else if (*s >= '0' && *s <= '9')
		{
			c = 1;
			b = b * 10 + *s - '0';
		}
		else if (c)
		{
			break;
		}
		s++;
	}
	if (a < 0)
	{
		b = (-b);
	}
	return (b);
}
