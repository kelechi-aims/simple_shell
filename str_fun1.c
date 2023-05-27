#include "shell.h"

/**
 * *_strcpy - it copies the string pointed to by src, including
 * the terminating null byte (\0)
 * @dest: First parameter
 * @src: Second parameter
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
 *_strdup - It returns a pointer to newly allocated space in memory
 * which contains a copy of the string given as parameter
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
* _puts - It prints an input string
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
* _putchar - it writes the character c to stdout
* @c: The character to be printed
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
