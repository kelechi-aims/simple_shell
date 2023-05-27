#include "shell.h"

/**
 * *_strncpy - It copies a string
 * @dest: string that the src string is appended to
 * @src: string that is appended to the dest string
 * @n: miximum number of byte from src
 *
 * Return: dest
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i;

	for (i = 0; i < n && src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	for (; i < n; i++)
	{
		dest[i] = '\0';
	}
	return (dest);
}

/**
 * *_strncat - it concatenates two strings
 * @dest: string where src string is append to
 * @src: string that is append to the dest string
 * @n: third parameter and an integer
 *
 * Return: dest
 */

char *_strncat(char *dest, char *src, int n)
{
	int destlen = 0, srclen = 0;

	while (dest[destlen] != '\0')
	{
		destlen++;
	}
	while (srclen < n)
	{
		dest[destlen] = src[srclen];
		if (src[srclen] == '\0')
		{
			break;
		}
		destlen++;
		srclen++;
	}
	return (dest);
}
/**
 * *_strchr - it locates a character in a string
 * @s: the string character
 * @c: the character to locate
 * Return: a pointer or null
 */
char *_strchr(char *s, char c)
{
	unsigned int i;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == c)
		{
			return (s + i);
		}
	}
	if (s[i] == c)
	{
		return (s + i);
	}
	return ('\0');
}
