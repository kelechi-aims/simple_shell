#include "shell.h"

/**
* bfree - it frees a pointer and NULLs the address
* @ptr: the address of the pointer to freed
*
* Return: 1 if freed, 0 if otherwise.
*/

int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
