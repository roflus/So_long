/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   move_check.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rharing <rharing@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/17 12:18:33 by rharing       #+#    #+#                 */
/*   Updated: 2022/02/16 12:59:56 by rharing       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	wall_check(t_vars *vars)
{
	int	i;
	int	f;

	vars->wall_x = 0;
	vars->wall_y = 0;
	i = 0;
	f = 0;
	while (f <= vars->line_count)
	{
		while (vars->map[f][i] != '\0')
		{
			if (vars->map[f][i] == '1')
			{
				if (vars->wall_x == vars->pos_x && vars->wall_y == vars->pos_y)
					return (1);
			}	
			vars->wall_x = vars->wall_x + 31;
			i++;
		}
		i = 0;
		vars->wall_x = 0;
		vars->wall_y = vars->wall_y + 31;
		f++;
	}
	return (0);
}

static	int	collected_all_check(t_vars *vars)
{
	int	i;
	int	f;

	i = 0;
	f = 0;
	while (f <= vars->line_count)
	{
		while (vars->map[f][i] != '\0')
		{
			if (vars->map[f][i] == 'C')
				return (0);
			i++;
		}
		i = 0;
		f++;
	}
	return (1);
}

void	exit_check(t_vars *vars, int *x, int *y)
{
	if (vars->exit_x == *x && vars->exit_y == *y)
	{
		if (collected_all_check(vars) == 1)
		{
			mlx_destroy_window(vars->mlx, vars->mlx_win);
			vars->mlx_win = mlx_new_window(vars->mlx, 320, \
			320, "Dog Bone Adventure");
			mlx_put_image_to_window(vars->mlx, vars->mlx_win, \
			vars->img_levelclear, 0, 0);
			show_score(vars);
			mlx_hook(vars->mlx_win, 2, 1L << 0, key_hook_close, vars);
			mlx_hook(vars->mlx_win, 17, 0, close_game, vars);
		}
	}
}
