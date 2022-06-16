/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   player_move.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rharing <rharing@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/17 12:18:13 by rharing       #+#    #+#                 */
/*   Updated: 2022/02/16 15:35:04 by rharing       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	void	step_count(t_vars *vars)
{
	static int	count;

	count += 1;
	vars->nom_score = count;
	write(1, "Steps: ", 7);
	ft_putnbr_fd(count, 1);
	write(1, "\n", 1);
}

void	move_left(t_vars *vars, int *x, int *y)
{
	*x -= 31;
	vars->pos_x = *x;
	putmap(vars);
	if (wall_check(vars) == 1)
	{
		*x += 31;
		vars->pos_x = *x;
	}
	else
		step_count(vars);
	show_score(vars);
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->img, *x, *y);
}

void	move_up(t_vars *vars, int *x, int *y)
{
	*y += 31;
	vars->pos_y = *y;
	putmap(vars);
	if (wall_check(vars) == 1)
	{
		*y -= 31;
		vars->pos_y = *y;
	}
	else
		step_count(vars);
	show_score(vars);
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->img, *x, *y);
}

void	move_right(t_vars *vars, int *x, int *y)
{
	*x += 31;
	vars->pos_x = *x;
	putmap(vars);
	if (wall_check(vars) == 1)
	{
		*x -= 31;
		vars->pos_x = *x;
	}
	else
		step_count(vars);
	show_score(vars);
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->img, *x, *y);
}

void	move_down(t_vars *vars, int *x, int *y)
{
	*y -= 31;
	vars->pos_y = *y;
	putmap(vars);
	if (wall_check(vars) == 1)
	{
		*y += 31;
		vars->pos_y = *y;
		show_score(vars);
	}
	else
		step_count(vars);
	show_score(vars);
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->img, *x, *y);
}
