#include "shell.h"

/**
 * *_strcpy - copies the string pointed to by src, including
 * the terminating null byte (\0), to the buffer to by dest
 * @dest: First parameter of the function
 * @src: second parameter of the function
 *
 * Return: the pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	for (; src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';
	return (dest);
}

/**
 *_strdup - returns a pointer to a newly allocated space in memory,
 * which contains a copy of the string given as a parameter
 * @str: string parameter
 * Return: a pointer or NULL
 */
char *_strdup(const char *str)
{
	unsigned int len;
	char *newstr;

	if (str == NULL)
	{
		return (NULL);
	}
	len = strlen(str) + 1;
	newstr = malloc(sizeof(char) * len);
	if (newstr == NULL)
	{
		return (NULL);
	}
	strcpy(newstr, str);
	return (newstr);
}

/**
* _puts - prints an input string
* @str: the string to be printed
*
* Return: Nothing
*/
void _puts(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
}

/**
* _putchar - writes the character c to stdout
* @c: The character to print
*
* Return: On success 1.
* On error, -1 is returned, and errno is set appropriately.
*/
int _putchar(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(1, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}
