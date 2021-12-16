/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrajaobe <rrajaobe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 09:16:22 by rrajaobe          #+#    #+#             */
/*   Updated: 2021/12/16 13:50:41 by rrajaobe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"
/*
*	This project is about building a Videogame in 2D.
*	A player inside a map should collect all the collectible items 
*	and then go to the exit.
*	The bonus part handles the extra case of having at 
*	the same time an enemy in the map, that should move randomly 
*	and not collide with the position in the map of our player.
*
*	First of all I initialize my struture and my methods.
*	After that I start the library minilibx, create the new window,
*	parse the map and initialize the graphic.
*	Then I wait: going throught an infinite loop, 
*	I wait for events to occur as keycodes pressed
*	that will be captured from the function mlx_key_hook. 
*/

int	main(int argc, char **argv)
{
	t_game	game;

	ft_initialize_struct(&game, argv, argc);
	ft_initalize_methods(&game, argv[1]);
	game.mlx = mlx_init();
	game.window = mlx_new_window(game.mlx, game.column * 100,
			game.row * 100, "THE DRAGON'S REDEMPTION");
	ft_create_graphic(&game);
	mlx_key_hook(game.window, movement_checker, &game);
	mlx_hook(game.window, 17, (1L << 17), ft_exit, &game);
	mlx_loop(game.mlx);
	exit (0);
	return (0);
}
