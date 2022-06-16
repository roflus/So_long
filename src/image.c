/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   image.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rharing <rharing@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/17 12:18:47 by rharing       #+#    #+#                 */
/*   Updated: 2022/02/16 12:44:36 by rharing       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_image(t_vars *vars)
{
	vars->img_collect = mlx_xpm_file_to_image(vars->mlx, "./sprites/Bone.xpm", \
	&vars->img_width, &vars->img_height);
	vars->img = mlx_xpm_file_to_image(vars->mlx, "./sprites/Dog.xpm", \
	&vars->img_width, &vars->img_height);
	vars->background_img = mlx_xpm_file_to_image(vars->mlx, \
	"./sprites/grass.xpm", &vars->img_width, &vars->img_height);
	vars->wallimg = mlx_xpm_file_to_image(vars->mlx, "./sprites/bush.xpm", \
	&vars->img_width, &vars->img_height);
	vars->img_exit = mlx_xpm_file_to_image(vars->mlx, "./sprites/Exitdog.xpm", \
	&vars->img_width, &vars->img_height);
	vars->img_levelclear = mlx_xpm_file_to_image(vars->mlx, \
	"./sprites/levelclear.xpm", &vars->img_width, &vars->img_height);
}
