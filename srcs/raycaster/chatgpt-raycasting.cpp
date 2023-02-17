#include "mlx.h"
#include <math.h>

#define WIDTH 640
#define HEIGHT 480
#define MAPWIDTH 24
#define MAPHEIGHT 24
#define SCALE 16
#define FOV M_PI / 3.0
#define DEPTH 32

typedef struct	s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		map[MAPWIDTH][MAPHEIGHT];
}				t_data;

void	init_map(t_data *data)
{
	int x, y;

	for (x = 0; x < MAPWIDTH; x++)
	{
		for (y = 0; y < MAPHEIGHT; y++)
		{
			if (x == 0 || y == 0 || x == MAPWIDTH - 1 || y == MAPHEIGHT - 1)
				data->map[x][y] = 1;
			else
				data->map[x][y] = 0;
		}
	}
}

void	draw_map(t_data *data)
{
	int x, y;

	for (x = 0; x < MAPWIDTH; x++)
	{
		for (y = 0; y < MAPHEIGHT; y++)
		{
			if (data->map[x][y])
				mlx_pixel_put(data->mlx_ptr, data->win_ptr, x * SCALE, y * SCALE, 0xFFFFFF);
		}
	}
}

void	draw_player(t_data *data, int x, int y)
{
	mlx_pixel_put(data->mlx_ptr, data->win_ptr, x * SCALE, y * SCALE, 0xFF0000);
}

void	draw_rays(t_data *data, int x, int y, double angle)
{
	double	ray_x, ray_y;
	double	dist, height;
	int		map_x, map_y;
	int		color;
	int		i;

	i = 0;
	while (i < WIDTH)
	{
		// cast a ray
		ray_x = x + (i - WIDTH / 2) * cos(angle) / DEPTH;
		ray_y = y + (i - WIDTH / 2) * sin(angle) / DEPTH;
		map_x = (int)ray_x;
		map_y = (int)ray_y;

		// calculate distance to wall
		while (map_x >= 0 && map_y >= 0 && map_x < MAPWIDTH && map_y < MAPHEIGHT && !data->map[map_x][map_y])
		{
			ray_x += cos(angle) / DEPTH;
			ray_y += sin(angle) / DEPTH;
			map_x = (int)ray_x;
			map_y = (int)ray_y;
		}

		// draw ray on screen
		dist = sqrt(pow(ray_x - x, 2) + pow(ray_y - y, 2));
		height = SCALE / dist * DEPTH;
		color = 0xFF0000 / dist;
		if (height > HEIGHT)
			height = HEIGHT;
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, i, HEIGHT / 2 - height / 2, color);
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, i, HEIGHT / 2 + height / 2, color);

		i++;
	}
}

int		main(void)
{
	t_data	data;
	int		x, y;
	double	angle;

	data.mlx_ptr = mlx
