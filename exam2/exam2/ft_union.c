#include <unistd.h>

int		main(int argc, char **argv)
{
	int		x;
	int		y;
	int		used[255];

	if (argc != 3)
	{
		write(1, "\n", 1);
	}
	x = 0;
	while(x < 255)
		used[x++] = 0;
	x = 1;
	while(x < 3)
	{
		y = 0;
		while(argv[x][y])
		{
			if (!used[(unsigned char)argv[x][y]])
			{
				write(1, &argv[x][y], 1);
				used[(unsigned char)argv[x][y]] = 1;
			}
			y++;
		}
		x++;
	}
	return (0);
}
