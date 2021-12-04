/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_management.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrajaobe <rrajaobe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 08:48:44 by rrajaobe          #+#    #+#             */
/*   Updated: 2021/12/04 06:07:16 by rrajaobe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
*	Check if the map hat the right extension.
*/
void	ft_error_ber(char **argv, int argc)
{
	char	*ext;
	int		len_argv;
	int		len_ext;

	if (argc != 2)
		exit(0);
	len_argv = ft_strlen(argv[1]);
	ext = ft_strdup(".ber");
	len_ext = 4;
	while (len_ext-- && len_argv--)
	{
		if (ext[len_ext] != argv[1][len_argv])
		{
			printf( "%s in map formattation, wrong map extension\n", ERROR);
			exit(0);
		}
	}
}

/*
*	Check if the walls are well aligned.
*	I starts from one because we don't consider the first row (should be a wall itself),
*/
int	ft_error_walls_bad_aligned(t_game *game)
{
	int	i;

	i = 0;//esclusa prima linea
	while (i < game->column)
	{
		if (game->map[0][i] != '1'|| game->map[game->row - 1][i] != '1')
		{
			printf( "%s in map formattation, walls are bad aligned\n", ERROR);
			return (TRUE);
		}
	}
	i = 1;
	while (i < game->row - 1)//esclusa ultima linea
	{
		if (game->map[i][0] != '1' || game->map[i][game->column - 1] != '1')
		{
			printf( "%s in map formattation, walls are bad aligned\n", ERROR);
			return (TRUE);
		}
		i++;
	}
	return (FALSE);
}

/*	
*	Basic check that the map is not rectangular. 
*	The other testcases for this problem are implemented in the next function.
*/
int	ft_error_map_not_rectangular(t_game *game)
{
	if (game->column == game->row)
	{
		printf( "%s , map is not rectangular\n", ERROR);
		return (TRUE);
	}
	return(FALSE);
}

/*
*	Check if there is present at least one P-C-E and that the chars inserted 
*	in the map are allowed.
*/
int	ft_error_check_gaming_items(t_game *game)
{
	int		i;
	int		j;
	char	*s;

	s = malloc(3 * sizeof(int));
	ft_bzero(s, 3);
	i = 1;
	j = 1;
	while (i < game->row - 2)
	{
		j = 1;
		while (j < game->column - 2)
		{
			s = ft_error_check_gaming_items_2_plus_wrong_inputs(game, s, i, j);
			if (s[0] == 1 && s[1] == 1 && s[2] == 1)
				return (FALSE);
			j++;
		}
		i++;
	}
	printf("%s in map formattation, check to have at least one Player,one Collectible and one Exitand that the map is a rectangle!\n", ERROR);
	return (TRUE);
}

char	*ft_error_check_gaming_items_2_plus_wrong_inputs(t_game *game, char *s, int i, int j)
{
	char	*allowed_chars;
	int		len;

	allowed_chars = ft_strdup("10CPEX");
	len = 6;
	if (s[0] == 0 && game->map[i][j] == 'P')
		s[0] = 1;
	else if (s[1] == 0 && game->map[i][j] == 'E')
		s[1] = 1;
	else if (s[2] == 0 && game->map[i][j] == 'C')
		s[2] = 1;
	while (len--)
	{
		if (strchr(allowed_chars, game->map[i][j]))
			break;
		else if (len == 0)
		{
			printf( "%s in map formattation, not allowed charachters are used\n", ERROR);
			free(allowed_chars);
			exit(0);
		}
	}
	return (s);
}
