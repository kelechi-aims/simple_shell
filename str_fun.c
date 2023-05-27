#include "shell.h"


/**
* _strlen - It returns the length of a string
* @s: It's the string whose length is to be checked
*
* Return: integer length of string
*/
int _strlen(char *s)
{
	int len = 0;

	while (s[len] != '\0')
	{
		len++;
	}
	return (len);
}

/**
* _strcmp - It performs lexicogarphic comparison of two strings.
* @s1: the first string
* @s2: the second string
*
* Return: negative if s1 < s2, positive if s1 > s2, zero if s1 == s2
*/
int _strcmp(char *s1, char *s2)
{
	int i = 0, diff = 0;

	while (diff == 0)
	{
		if (s1[i] == '\0' && s2[i] == '\0')
		{
			break;
		}
		diff = s1[i] - s2[i];
		i++;
	}
	return (diff);
}

/**
* starts_with - checks if needle starts with haystack
* @haystack: the string to search
* @needle: the substring to find
*
* Return: address of next char of haystack or NULL
*/
char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}

/**
* _strcat - concatenates two strings
* @dest: the destination buffer
* @src: the source buffer
*
* Return: pointer to destination buffer
*/
char *_strcat(char *dest, char *src)
{
	int destlen = 0, srclen = 0;

	while (dest[destlen] != '\0')
	{
		destlen++;
	}
	while (srclen >= 0)
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
