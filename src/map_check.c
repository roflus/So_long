/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_check.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rharing <rharing@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/17 12:18:40 by rharing       #+#    #+#                 */
/*   Updated: 2022/02/16 12:42:14 by rharing       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	int	pec_check(t_vars *vars)
{
	int	f;
	int	i;

	f = 0;
	vars->p_num = 0;
	vars->c_num = 0;
	vars->e_num = 0;
	while (f <= vars->line_count)
	{
		i = 0;
		while (vars->map[f][i] != '\0')
		{
			if (vars->map[f][i] == 'P')
				vars->p_num++;
			if (vars->map[f][i] == 'C')
				vars->c_num++;
			if (vars->map[f][i] == 'E')
				vars->e_num++;
		i++;
		}
	f++;
	}
	if (vars->p_num != 1 || vars->c_num == 0 || vars->e_num == 0)
		return (0);
	return (1);
}

static	int	char_check(char c)
{
	if (c == '1' || c == '0' || c == 'C' || c == 'P' || c == 'E')
		return (1);
	return (0);
}

static	void	checkmap_utils(t_vars *vars, int *f, int *i)
{
	int	len;
	int	num;

	num = vars->line_count;
	len = ft_strlen(vars->map[*f]);
	while (vars->map[*f][*i] != '\0')
	{
		if (char_check(vars->map[*f][*i]) != 1)
			error_exit();
		if (vars->map[0][*i] != '1' || vars->map[*f][0] != '1' || \
			vars->map[*f][len - 1] != '1' || vars->map[num][*i] != '1')
			error_exit();
		if (pec_check(vars) != 1)
			error_exit();
		*i = *i + 1;
	}
}

void	checkmap(t_vars *vars)
{
	int	f;
	int	i;

	f = 0;
	i = 0;
	while (f <= vars->line_count)
	{
		if (vars->map[0] == NULL)
			error_exit();
		checkmap_utils(vars, &f, &i);
		vars->window_size_x = i * 31;
		i = 0;
		f++;
	}
	vars->window_size_y = f * 31;
}

void	error_exit(void)
{
	char	*s;

	s = "Error:\nInvallid map";
	ft_putendl_fd(s, 1);
	exit(0);
}
