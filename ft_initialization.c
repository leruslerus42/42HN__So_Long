/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialization.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrajaobe <rrajaobe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 10:07:16 by rrajaobe          #+#    #+#             */
/*   Updated: 2021/12/05 03:23:01 by rrajaobe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_initialize_struct(t_game *game, char **argv, int argc)
{
	ft_error_ber(argv, argc);
	game->player_pos_x = 0;
	game->player_pos_y = 0;
	game->player_pos_x_previous = 0;
	game->player_pos_y_previous = 0;
	game->map = NULL;
	game->row = 0;
	game->column = 0;
	game->sum_moves = 0;
	game->collectible_sum = 0;
}

void	ft_initalize_methods(t_game *game, char *argv)
{
	calculate_map_coordinates(argv, game);
	calculate_player_position(game);
	calculate_collectible_sum(game);
}

void	calculate_player_position(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->column)
	{
		j = 0;
		while (j < game->row)
		{
			if (game->map[j][i] == 'P')
			{
				game->player_pos_x = j;
				game->player_pos_y = i;
				game->player_pos_x_previous = j;
				game->player_pos_y_previous = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	calculate_collectible_sum(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->row)
	{
		j = 0;
		while (j < game->column)
		{
			if (game->map[i][j] == 'C')
				game->collectible_sum ++;
			j++;
		}
		i++;
	}
}
