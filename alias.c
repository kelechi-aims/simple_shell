#include "shell.h"


/**
* is_chain - It tests if current char in buffer is a chain delimeter
* @info: the parameter struct
* @buf: the char buffer
* @p: address of current position in buffer
*
* Return: 1 if chain delimeter, 0 otherwise
*/
int is_chain(info_t *info, char *buf, size_t *p)
{
	size_t j = *p;

	if (buf[j] == '|' && buf[j + 1] == '|')
	{
		buf[j] = 0;
		j++;
		info->cmd_buf_type = CMD_OR;
	}
	else if (buf[j] == '&' && buf[j + 1] == '&')
	{
		buf[j] = 0;
		j++;
		info->cmd_buf_type = CMD_AND;
	}
	else if (buf[j] == ';')
	{
		buf[j] = 0;
		info->cmd_buf_type = CMD_CHAIN;
	}
	else
		return (0);
	*p = j;

	return (1);
}

/**
* check_chain - checks if we should continue chaining based on last status
* @info: the parameter struct
* @buf: the char buffer
* @p: the address of current position in buf
* @i: i
* @len: len
*
* Return: Void
*/
void check_chain(info_t *info, char *buf, size_t *p, size_t i, size_t len)
{
	size_t j = *p;

	if (info->cmd_buf_type == CMD_AND)
	{
		if (info->status)
		{
			buf[i] = 0;
			j = len;
		}
	}
	if (info->cmd_buf_type == CMD_OR)
	{
		if (!info->status)
		{
			buf[i] = 0;
			j = len;
		}
	}

	*p = j;
}

/**
* replace_alias - this replaces an alias in the tokenized string
* @info: the parameter struct
*
* Return: if replaced,1 , 0 if otherwise
*/
int replace_alias(info_t *info)
{
	int i;
	char *p;

	for (i = 0; i < 10; i++)
	{
		list_t *node = node_starts_with(info->alias, info->argv[0], '=');

		if (!node)
		{
			return (0);
		}
		free(info->argv[0]);
		p = _strchr(node->str, '=');

		if (!p)
			return (0);
		p = _strdup(p + 1);
		if (!p)
			return (0);
		info->argv[0] = p;
	}

	return (1);
}

/**
* replace_vars - it replaces vars in the tokenized string
* @info: the parameter struct
*
* Return: if replaced,1 , 0 if otherwise
*/
int replace_vars(info_t *info)
{
	int i = 0;
	list_t *node;

	for (i = 0; info->argv[i]; i++)
	{
		if (info->argv[i][0] != '$' || !info->argv[i][1])
			continue;

		if (!_strcmp(info->argv[i], "$?"))
		{
			replace_string(&(info->argv[i]),
					_strdup(convert_number(info->status, 10, 0)));
			continue;
		}

		if (!_strcmp(info->argv[i], "$$"))
		{
			replace_string(&(info->argv[i]),
					_strdup(convert_number(getpid(), 10, 0)));
			continue;
		}
		node = node_starts_with(info->env, &info->argv[i][1], '=');

		if (node)
		{
			replace_string(&(info->argv[i]),
					_strdup(_strchr(node->str, '=') + 1));
			continue;
		}
		replace_string(&info->argv[i], _strdup(""));
	}
	return (0);
}

/**
* replace_string - it replaces string
* @old: the address of old string
* @newStr: the new string
*
* Return: if replaced,1 , 0 if otherwise
*/
int replace_string(char **old, char *newStr)
{
	free(*old);
	*old = newStr;
	return (1);
}
