/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrajaobe <rrajaobe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 15:31:02 by rrajaobe          #+#    #+#             */
/*   Updated: 2021/12/05 01:00:16 by rrajaobe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
*	This functions check which key was pressed,
*	left/right or up/down and the correct function will
*	let the player move. At the end update the map.
*/
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
	update_map(game);
	return (0);
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
		if (game->map[game->player_pos_x + 1][game->player_pos_y] == '1')
		{
			printf("%s Player cannot run into walls!\n", ERROR);
			return ;
		}
		game->player_pos_x += 1;
	}
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
}

void	ft_exit(void)
{
	exit(0);
}
