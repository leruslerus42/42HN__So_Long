/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrajaobe <rrajaobe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 09:39:09 by rrajaobe          #+#    #+#             */
/*   Updated: 2021/12/05 21:49:32 by rrajaobe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# include "../libft/libft.h"
# include "../mlx/mlx.h"

# define TRUE  1
# define FALSE 0
# define ERROR "Error\n"

typedef struct s_game{
	void	*mlx;
	void	*window;

	int		row;
	int		column;
	int		height;
	int		width;

	char	**map;

	int		player_pos_x;
	int		player_pos_y;
	int		player_pos_x_previous;
	int		player_pos_y_previous;
	int		enemy_pos_x;
	int		enemy_pos_y;
	int		enemy_pos_x_previous;
	int		enemy_pos_y_previous;

	int		collectible_sum;
	int		sum_moves;

	void	*background_img;
	void	*player_img;
	void	*collectible_img;
	void	*exit_img;
	void	*wall_img;
	void	*enemy_img;
	void	*player_ev_img;
}	t_game;

typedef struct s_graphic{
	char	*file;
	char	*file2;
	char	*file3;
	char	*file4;
	char	*file5;
	char	*file6;
	char	*file7;
}	t_graphic;

/*---------------------SO_LONG -----------------------------------*/
int		main(int argc, char **argv);

/*---------------FT_INITIALIZATION -------------------------------*/
void	ft_initialize_struct(t_game *game, char **argv, int argc);
void	ft_initalize_methods(t_game *game, char *argv);
void	calculate_player_position(t_game *game);
void	calculate_collectible_sum(t_game *game);

/*---------------------MAP_READER---------------------------------*/
void	calculate_map_coordinates(char *argv, t_game *game);
int		ft_count_rows(const char *s, int c);
void	map_creation(t_game *game, char *s);
int		map_creation_2(t_game *game, char *s, int i, int k);
void	check_map_creations_errors(t_game *game);

/*---------------------MAP_PRITER---------------------------------*/
void	ft_create_graphic(t_game *game);
void	ft_initialize_graphic(t_game *game, t_graphic *images);
void	ft_map_printer(t_game *game);
void	ft_map_printer_2(t_game *game, int i, int j);

/*---------------------MAP_UPDATE---------------------------------*/
void	update_map(t_game *game);
void	update_map_2(t_game *game);
int		ft_exit(void);

/*---------------------GET_NEXT_LINE------------------------------*/
char	*get_next_line(int fd);
int		ft_my_strchr(const char *s, int c);

/*---------------------MOVEMENTS-----------------------------------*/
int		movement_checker(int keycode, t_game *game);
void	moving_up_down(t_game *game, int keycode);
void	moving_left_right(t_game *game, int keycode);

/*-------------------ERROR_MANAGEMENT--------------------------------*/
void	ft_error_ber(char **argv, int argc);
int		ft_error_walls_bad_aligned(t_game *game);
int		ft_error_map_not_rectangular(t_game *game);
int		ft_error_check_gaming_items(t_game *game);
char	*ft_error_items_2_wrong_inputs(t_game *game, char *s, int i, int j);

/*---------------------ENEMY----------------------------------------*/
void	calculate_enemy_position(t_game *game);
void	random_enemy_movement(t_game *game);
void	game_over_test(t_game *game);

#endif