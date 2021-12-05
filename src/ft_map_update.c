/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_update.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrajaobe <rrajaobe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 22:57:59 by rrajaobe          #+#    #+#             */
/*   Updated: 2021/12/05 22:59:38 by rrajaobe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
/*
*	Updating the map every time a player makes a move.
*	The possible conditions are: 
*	if the player runs in a collectible, if he runs
*	in an empty space or if he had already collected all
*	the items and can go to the exit.
*	At the end the enemy will make his move.
*/
void	update_map(t_game *game)
{
	char	*s;

	game->sum_moves += 1;
	s = ft_strjoin("MOVES: ", ft_itoa(game->sum_moves));
	mlx_string_put(game->mlx, game->window,
		1 * 100, 1 * 100, 10 << 24 | 200 << 16 | 100 << 8 | 4, s);
	free(s);
	if (game->map[game->player_pos_x][game->player_pos_y] == 'E')
	{
		if (game->collectible_sum == 0)
		{
			printf("You won the Game! :D\n\n");
			exit(0);
		}
		else
		{
			printf("You have to collect all the items first =P!\n\n");
			game->player_pos_x = game->player_pos_x_previous;
			game->player_pos_y = game->player_pos_y_previous;
			return ;
		}
	}
	update_map_2(game);
}

void	update_map_2(t_game *game)
{
	if (game->map[game->player_pos_x][game->player_pos_y] == 'C')
	{
		game->collectible_sum -= 1;
		mlx_put_image_to_window(game->mlx, game->window, game->background_img,
			game->player_pos_y * 100, game->player_pos_x * 100);
	}
	game->map[game->player_pos_x][game->player_pos_y] = 'P';
	game->map[game->player_pos_x_previous][game->player_pos_y_previous] = '0';
	mlx_put_image_to_window(game->mlx, game->window, game->background_img,
		game->player_pos_y_previous * 100, game->player_pos_x_previous * 100);
	if (BONUS == 1)
		game_over_test(game);
	if (game->collectible_sum == 0 && game->sum_moves)
		mlx_put_image_to_window(game->mlx, game->window, game->player_ev_img,
			game->player_pos_y * 100, game->player_pos_x * 100);
	else
		mlx_put_image_to_window(game->mlx, game->window, game->player_img,
			game->player_pos_y * 100, game->player_pos_x * 100);
	if (BONUS == 1)
		random_enemy_movement(game);
}

int	ft_exit(void)
{
	exit(0);
}
