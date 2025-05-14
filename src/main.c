#include "cube.h"

int main(void)
{
	t_cube cube;

	ft_bzero(&cube, sizeof(t_cube));
	mlx_start_loop(&cube);
	return (0);
}
