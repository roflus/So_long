/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   display.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rharing <rharing@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/17 12:18:33 by rharing       #+#    #+#                 */
/*   Updated: 2022/02/16 15:31:49 by rharing       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	show_score(t_vars *vars)
{
	char	*temp_score;
	char	*temp_steps;

	temp_score = ft_itoa(vars->score);
	temp_steps = ft_itoa(vars->nom_score);
	if (temp_score == NULL || temp_steps == NULL)
		error_exit();
	mlx_string_put(vars->mlx, vars->mlx_win, 8, 16, 0x0, "Score:");
	mlx_string_put(vars->mlx, vars->mlx_win, 72, 16, 0x0, temp_score);
	mlx_string_put(vars->mlx, vars->mlx_win, 90, 16, 0x0, "Steps:");
	mlx_string_put(vars->mlx, vars->mlx_win, 160, 16, 0x0, \
	temp_steps);
	free(temp_steps);
	free(temp_score);
}
