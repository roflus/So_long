/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rharing <rharing@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/13 16:21:20 by rharing       #+#    #+#                 */
/*   Updated: 2022/02/17 11:34:15 by rharing       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	void	start_game(t_vars *vars, char **argv)
{
	mapinput(argv, vars);
	checkmap(vars);
	vars->mlx_win = mlx_new_window(vars->mlx, vars->window_size_x, \
		vars->window_size_y, "Dog Bone Adventure");
	put_image(vars);
	putmap(vars);
}

static	int	arguments_check(int argc, char **argv)
{
	size_t	arg_length;

	if (argc != 2)
	{
		ft_putendl_fd("Error: \nTakes two arguments.", 1);
		return (0);
	}
	arg_length = ft_strlen(argv[1]);
	if (argv[1][arg_length - 1] != 'r' && argv[1][arg_length - 2] != 'e' && \
		argv[1][arg_length - 3] != 'b')
	{
		ft_putendl_fd("Error: \nInvalid file, can only read .ber files.", 1);
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (!arguments_check(argc, argv))
		return (0);
	vars.mlx = mlx_init();
	start_game(&vars, argv);
	mlx_hook(vars.mlx_win, 2, 1L << 0, key_hook, &vars);
	mlx_hook(vars.mlx_win, 17, 0, close_game, &vars);
	mlx_loop(vars.mlx);
}
