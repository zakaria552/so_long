#include <mlx.h>

int main()
{
	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 600, 600, "So long");
	mlx_loop(mlx);
}