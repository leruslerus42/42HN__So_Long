/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_printer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrajaobe <rrajaobe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 07:43:09 by rrajaobe          #+#    #+#             */
/*   Updated: 2021/12/04 05:32:18 by rrajaobe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
*	Here I first initialize the graphic part converting the Assets in the format
*	XPM, so that I can print the charachters of the map.
*/
void	ft_create_graphic(t_game *game)
{
	t_graphic	images;

	ft_initialize_graphic(game, &images);
	ft_map_printer(game);
}

void	ft_initialize_graphic(t_game *game, t_graphic *images)
{
	images->file = "./Imgs_100x100/background.xpm";
	images->file2 = "./Imgs_100x100/Dragon.xpm";
	images->file3 = "./Imgs_100x100/coin.xpm";
	images->file4 = "./Imgs_100x100/money.xpm";
	images->file5 = "./Imgs_100x100/Fire.xpm";
	images->file6 = "./Imgs_100x100/Wolf.xpm";
	images->file7 = "./Imgs_100x100/Dragon_Ev.xpm";
	game->background_img = mlx_xpm_file_to_image
		(game->mlx, images->file, &(game->height), &(game->width));
	game->player_img = mlx_xpm_file_to_image
		(game->mlx, images->file2, &(game->height), &(game->width));
	game->collectible_img = mlx_xpm_file_to_image
		(game->mlx, images->file3, &(game->height), &(game->width));
	game->exit_img = mlx_xpm_file_to_image
		(game->mlx, images->file4, &(game->height), &(game->width));
	game->wall_img = mlx_xpm_file_to_image
		(game->mlx, images->file5, &(game->height), &(game->width));
	game->enemy_img = mlx_xpm_file_to_image
		(game->mlx, images->file6, &(game->height), &(game->width));
	game->player_evolution_img = mlx_xpm_file_to_image
		(game->mlx, images->file7, &(game->height), &(game->width));
	game->height = game->row;
	game->width = game->column;
}

void	ft_map_printer(t_game *game)
{
	int		i;
	int		j;

	i = 0;
	while (i < game->column)
	{
		j = 0;
		while (j < game->row)
		{
			mlx_put_image_to_window(game->mlx, game->window,
				game->background_img, (i * 100), (j * 100));
			ft_map_printer_2(game, i, j);
			j++;
		}
		i++;
	}
}

void	ft_map_printer_2(t_game *game, int i, int j)
{
	if (game->map[j][i] == '1')
		mlx_put_image_to_window(game->mlx, game->window, game->wall_img,
			(i * 100), (j * 100));
	else if (game->map[j][i] == 'C')
		mlx_put_image_to_window(game->mlx, game->window, game->collectible_img,
			(i * 100), (j * 100));
	else if ((game->map[j][i]) == 'P')
		mlx_put_image_to_window(game->mlx, game->window, game->player_img,
			(i * 100), (j * 100));
	else if (game->map[j][i] == 'E')
		mlx_put_image_to_window(game->mlx, game->window, game->exit_img,
			(i * 100), (j * 100));
	else if (game->map[j][i] == 'X')
		mlx_put_image_to_window(game->mlx, game->window, game->enemy_img,
			(i * 100), (j * 100));
}
