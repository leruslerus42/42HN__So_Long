/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrajaobe <rrajaobe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 15:31:02 by rrajaobe          #+#    #+#             */
/*   Updated: 2021/12/04 04:25:42 by rrajaobe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_map(t_game *game)
{
	char	*s;

	game->sum_moves += 1;
	s = ft_strjoin("MOVES: ", ft_itoa(game->sum_moves));
	mlx_string_put(game->mlx, game->window, 1*100, 1*100, 10 << 24 | 200 << 16 | 100 << 8 | 4, s);
	free(s);
	/*1) CONDITION: END GAME*/
	if (game->map[game->player_pos_x][game->player_pos_y] == 'E')
	{
		if (game->collectible_sum == 0)
		{
			printf("You won the Game! :D\n\n");
			exit(0);
		}
		else
		{
			printf("You have to collect all the collectibles before running into the exit!\n\n");
			game->player_pos_x = game->player_pos_x_previous;
			game->player_pos_y = game->player_pos_y_previous;
			return ;
		}
	}
	/*RUNNING IN COLLECTIBLE CONDITION*/
	if (game->map[game->player_pos_x][game->player_pos_y] == 'C')
	{
		game->collectible_sum -= 1;
		mlx_put_image_to_window(game->mlx, game->window, game->background_img, game->player_pos_y * 100, game->player_pos_x * 100);
	}
	
	/*ELSE RUNNING IN EMPTY SPACE EGAL*/
	game->map[game->player_pos_x][game->player_pos_y] = 'P';
	game->map[game->player_pos_x_previous][game->player_pos_y_previous] = '0';
	mlx_put_image_to_window(game->mlx, game->window, game->background_img, game->player_pos_y_previous * 100, game->player_pos_x_previous * 100);
	/*SET PLAYER_IMG IN CURRENT XPOS YPOS*/
	game_over_test(game);


	if (game->collectible_sum == 0 && game->sum_moves)
		mlx_put_image_to_window(game->mlx, game->window, game->player_evolution_img, game->player_pos_y * 100, game->player_pos_x * 100);
	else
		mlx_put_image_to_window(game->mlx, game->window, game->player_img, game->player_pos_y * 100, game->player_pos_x * 100);

	random_enemy_movement(game);
}

void	moving_up_down(t_game *game, int keycode)
{
	if (keycode == 126 || keycode == 13)
	{
		if (game->map[game->player_pos_x - 1][(game->player_pos_y)] == '1')
		{
			printf("%s Player cannot run into walls!\n", ERROR);
			return ;
		}		
		game->player_pos_x -= 1;
	}
	else if (keycode == 125 || keycode == 1)
	{
		if (game->map[game->player_pos_x + 1][game->player_pos_y] == '1') //if wall
		{
			printf("%s Player cannot run into walls!\n", ERROR);
			return ;
		}
		game->player_pos_x += 1;
	}
	update_map(game);
}

void	moving_left_right(t_game *game, int keycode)
{

	if (keycode == 123 || keycode == 0)
	{
		if ((game->map[game->player_pos_x][game->player_pos_y - 1]) == '1')
		{
			printf("%s Player cannot run into walls!\n", ERROR);
			return ;
		}	
		game->player_pos_y -= 1;
	}
	else if (keycode == 124 || keycode == 2)
	{
		if ((game->map[game->player_pos_x][game->player_pos_y + 1]) == '1')
		{
			printf("%s Player cannot run into walls!\n\n", ERROR);
			return ;
		}
		game->player_pos_y += 1;
	}
	update_map(game);
}

int	movement_checker(int keycode, t_game *game)
{
	game->player_pos_y_previous = game->player_pos_y;
	game->player_pos_x_previous = game->player_pos_x;
	if (keycode == 123 || keycode == 0)
		moving_left_right(game, keycode);
	if (keycode == 124 || keycode == 1 )
		moving_left_right(game, keycode);
	if (keycode == 126 || keycode == 13)
		moving_up_down(game, keycode);
	if (keycode == 125 || keycode == 2)
		moving_up_down(game, keycode);
	if (keycode == 53)
		exit(0);
	return (0);
}
