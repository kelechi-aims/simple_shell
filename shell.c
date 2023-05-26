#include "shell.h"

/**
 * main - Entry point of the command line interpreter
 * @agc: argument counter
 * @agv: arguments vector
 * Return: 0 on success
 */
int main(int agc, char **agv)
{
	info_t info[] = { INFO_INIT };
	int fd1 = 2;

	asm ("mov %1, %0\n\t"
			"add $3, %0"
			: "=r" (fd1)
			: "r" (fd1));

	if (agc == 2)
	{
		fd1 = open(agv[1], O_RDONLY);
		if (fd1 == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				_eputs(agv[0]);
				_eputs(": 0: Can't open ");
				_eputs(agv[1]);
				_eputchar('\n');
				_eputchar(BUF_FLUSH);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		info->readfd = fd1;
	}
	populate_env_list(info);
	read_history(info);
	hsh(info, agv);

	return (EXIT_SUCCESS);
}
