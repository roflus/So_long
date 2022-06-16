/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: rharing <rharing@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/17 12:18:03 by rharing       #+#    #+#                 */
/*   Updated: 2022/02/16 13:09:14 by rharing       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	int	nlcount(t_vars *vars, char *mapline)
{
	int	f;
	int	count;

	f = 0;
	count = 0;
	while (mapline[f] != '\0')
	{
		if (mapline[f] == '\n')
			count++;
		f++;
	}
	return (count);
}

static	int	fd_check(int fd)
{
	if (fd == -1)
		return (0);
	return (1);
}

static	int	check_empty_line_map(char *mapline)
{
	int	i;
	int	length;

	i = 0;
	length = ft_strlen(mapline);
	while (mapline[i] != '\0')
	{
		if (mapline[length - 1] == '\n')
			return (0);
		if (mapline[0] == '\n')
			return (0);
		if (mapline[i] == '\n')
		{
			if (mapline[i + 1] == '\n')
				return (0);
		}
		i++;
	}
	return (1);
}

static	void	create_map(t_vars *vars, char *mapline)
{
	if (!check_empty_line_map(mapline))
		error_exit();
	vars->line_count = nlcount(vars, mapline);
	vars->map = ft_split(mapline, '\n');
	if (vars->map == NULL)
		error_exit();
}

void	mapinput(char *input[], t_vars *vars)
{
	int		fd;
	char	*temp;
	char	*mapline;
	char	*newmapline;

	mapline = ft_calloc(1, 1);
	if (mapline == NULL)
		error_exit();
	fd = open(input[1], O_RDONLY);
	if (!fd_check(fd))
		error_exit();
	while (mapline)
	{
		temp = get_next_line(fd);
		if (!temp)
			break ;
		newmapline = mapline;
		mapline = ft_strjoin(newmapline, temp);
		free(newmapline);
		free(temp);
	}
	create_map(vars, mapline);
	free(mapline);
	close(fd);
}
