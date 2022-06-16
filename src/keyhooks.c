/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   keyhooks.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rharing <rharing@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/17 12:17:44 by rharing       #+#    #+#                 */
/*   Updated: 2022/02/16 12:47:25 by rharing       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	void	player_start_pos(t_vars *vars, int *x, int *y)
{
	if (*x == 0 && *y == 0)
	{
		*x = vars->startx;
		*y = vars->starty;
		vars->pos_x = *x;
		vars->pos_y = *y;
	}
}

int	key_hook(int keycode, t_vars *vars)
{
	static int	x;
	static int	y;

	player_start_pos(vars, &x, &y);
	if (keycode == 0)
		move_left(vars, &x, &y);
	if (keycode == 1)
		move_up(vars, &x, &y);
	if (keycode == 2)
		move_right(vars, &x, &y);
	if (keycode == 13)
		move_down(vars, &x, &y);
	exit_check(vars, &x, &y);
	key_hook_close(keycode, vars);
	return (0);
}

int	close_game(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->mlx_win);
	exit(0);
}

int	key_hook_close(int keycode, t_vars *vars)
{
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->mlx_win);
		exit(0);
	}
	return (0);
}
