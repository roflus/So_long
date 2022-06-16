/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rharing <rharing@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/17 12:16:14 by rharing       #+#    #+#                 */
/*   Updated: 2022/02/16 14:12:02 by rharing       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <get_next_line.h>
# include <libft.h>

typedef struct s_vars {
	void	*mlx;
	void	*mlx_win;
	void	*img;
	void	*wallimg;
	void	*img_collect;
	void	*img_exit;
	char	*wall_path;
	void	*background_img;
	void	*img_levelclear;
	char	**map;
	char	*temp_map;
	int		img_width;
	int		img_height;
	int		startx;
	int		starty;
	int		pos_x;
	int		pos_y;
	int		wall_x;
	int		wall_y;
	int		exit_x;
	int		exit_y;
	int		window_size_x;
	int		window_size_y;
	int		f;
	int		i;
	int		score;
	int		nom_score;
	int		p_num;
	int		c_num;
	int		e_num;
	int		line_count;
}				t_vars;	

// display functions
void	show_score(t_vars *vars);

// image functions
void	put_image(t_vars *vars);

// player_move functions
void	move_up(t_vars *vars, int *x, int *y);
void	move_down(t_vars *vars, int *x, int *y);
void	move_left(t_vars *vars, int *x, int *y);
void	move_right(t_vars *vars, int *x, int *y);

// move_check functions
int		wall_check(t_vars *vars);
void	exit_check(t_vars *vars, int *x, int *y);

// keyhooks functions
int		key_hook(int keycode, t_vars *vars);
int		close_game(t_vars *vars);
int		key_hook_close(int keycode, t_vars *vars);

// map functions
void	mapinput(char *input[], t_vars *vars);

// mapcheck functions
void	checkmap(t_vars *vars);
void	error_exit(void);

// mapfill functions
void	putmap(t_vars *vars);

#endif