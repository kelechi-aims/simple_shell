#include "shell.h"

/**
 * is_delim - It checks if the character is a delimeter
 * @c: the char to be checked
 * @delim: the delimeter string
 * Return: If true,1 , if false, 0
 */
int is_delim(char c, char *delim)
{
	while (*delim)
	if (*delim++ == c)
		return (1);
	return (0);
}

/**
 * _isalpha - checks for alphabet characters
 * @c: The char input
 * Return: if c is alphabetic, 1, 0 if otherwise
 */

int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * _atoi - this converts a string to an integer
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
