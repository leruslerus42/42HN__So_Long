/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enemy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrajaobe <rrajaobe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 10:06:32 by rrajaobe          #+#    #+#             */
/*   Updated: 2021/12/04 04:19:50 by rrajaobe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	randomizer(t_game *game, int count)
{
	if ((count == 0 || count == 2)
		&& game->map[game->enemy_pos_x - 1][(game->enemy_pos_y)] == '0')
		game->enemy_pos_x --;
	else if ((count == 1 || count == 3)
		&& game->map[game->enemy_pos_x + 1][(game->enemy_pos_y)] == '0')
		game->enemy_pos_x ++;
	else if ((count == 2 || count == 0)
		&& game->map[game->enemy_pos_x][(game->enemy_pos_y - 1)] == '0')
		game->enemy_pos_y --;
	else if ((count == 3 || count == 1)
		&& game->map[game->enemy_pos_x][(game->enemy_pos_y + 1)] == '0')
		game->enemy_pos_y ++;
	else
		count = -1;
	return (count);
}

void	random_enemy_movement(t_game *game)
{
	int	count;
	int	i;

	game->enemy_pos_y_previous = game->enemy_pos_y;
	game->enemy_pos_x_previous = game->enemy_pos_x;
	i = 0;
	while (TRUE)
	{
		count = rand() % 4;
		count = randomizer(game, count);
		if (count != -1 || i == 1000)
			break ;
		i++;
	}
	game->map[game->enemy_pos_x][game->enemy_pos_y] = 'X';
	game->map[game->enemy_pos_x_previous][game->enemy_pos_y_previous] = '0';
	game_over_test(game);
	mlx_put_image_to_window(game->mlx, game->window, game->background_img,
		game->enemy_pos_y_previous * 100, game->enemy_pos_x_previous * 100);
	mlx_put_image_to_window(game->mlx, game->window, game->enemy_img,
		game->enemy_pos_y * 100, game->enemy_pos_x * 100);
}

void	calculate_enemy_position(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->column)
	{
		j = 0;
		while (j < game->row)
		{
			if (game->map[j][i] == 'X')
			{
				game->enemy_pos_x = j;
				game->enemy_pos_y = i;
				game->enemy_pos_x_previous = j;
				game->enemy_pos_y_previous = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	game_over_test(t_game *game)
{
	if (game->player_pos_x == game->enemy_pos_x
		&& game->player_pos_y == game->enemy_pos_y)
	{
		printf ("You loose! The Wolf have reached Youuu =(");
		exit(0);
	}
}
