#include <unistd.h>

int		main(int argc, char **argv)
{
	int		x;
	int		y;
	int		used[255];

	if (argc != 3)
		write(1, "\n", 1);
	else
	{
		x = 0;
		while (x < 255)
			used[x++] = 0;
		x = 2;
		while (x > 0)
		{
			y = 0;
			while (argv[x][y])
			{
				if (x == 2 && !used[(unsigned char)argv[x][y]])
					used[(unsigned char)argv[x][y]] = 1;
				else if (x == 1 && used[(unsigned char)argv[x][y]] == 1)
				{
					write(1, &argv[x][y], 1);
					used[(unsigned char)argv[x][y]] = 2;
				}
				y++;
			}
			x--;
		}
	}
	return (0);
}
