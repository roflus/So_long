/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_fillmap.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rharing <rharing@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/17 15:06:49 by rharing       #+#    #+#                 */
/*   Updated: 2022/02/16 13:07:16 by rharing       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	void	put_exit(t_vars *vars, int *x, int *y)
{
	if (vars->map[vars->f][vars->i] == 'E')
	{
		vars->exit_x = *x;
		vars->exit_y = *y;
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, \
		vars->img_exit, *x, *y);
	}
}

static	void	put_collect(t_vars *vars, int *x, int *y)
{
	if (vars->map[vars->f][vars->i] == 'C')
	{
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, \
		vars->img_collect, *x, *y);
		if (*x == vars->pos_x && *y == vars->pos_y)
		{
			vars->score += 1;
			vars->map[vars->f][vars->i] = '0';
			mlx_put_image_to_window(vars->mlx, vars->mlx_win, \
			vars->background_img, *x, *y);
		}
	}
}

static	void	put_walls(t_vars *vars, int *x, int *y)
{
	if (vars->map[vars->f][vars->i] == '1')
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, \
		vars->wallimg, *x, *y);
	if (vars->map[vars->f][vars->i] == '0')
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, \
		vars->background_img, *x, *y);
}

static	void	put_player(t_vars *vars, int *x, int *y)
{
	if (vars->map[vars->f][vars->i] == 'P')
	{
		vars->startx = *x;
		vars->starty = *y;
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, \
		vars->background_img, *x, *y);
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->img, *x, *y);
		vars->map[vars->f][vars->i] = '0';
	}
}

void	putmap(t_vars *vars)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	vars->i = 0;
	vars->f = 0;
	while (vars->f <= vars->line_count)
	{	
		while (vars->map[vars->f][vars->i] != '\0')
		{	
			put_walls(vars, &x, &y);
			put_player(vars, &x, &y);
			put_collect(vars, &x, &y);
			put_exit(vars, &x, &y);
			x += 31;
			vars->i++;
		}
		vars->i = 0;
		x = 0;
		y += 31;
		vars->f++;
	}
}
