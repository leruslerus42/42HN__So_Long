/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_reader.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrajaobe <rrajaobe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 07:40:27 by rrajaobe          #+#    #+#             */
/*   Updated: 2021/12/05 04:37:04 by rrajaobe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/*
* 	First I first calculate the numer of columns and rows of the map.
*/
void	calculate_map_coordinates(char *argv, struct s_game *game)
{
	int		fd;
	char	*s;//char	*temp; use laterfor leaks

	fd = open(argv, O_RDONLY);
	if (fd == -1)
		exit(0);
	s = ft_strdup("");
	s = get_next_line(fd);
	game->row = ft_count_rows(s, '\n');
	game->column = ft_my_strchr(s, '\n');
	map_creation(game, s);
}

int	ft_count_rows(const char *s, int c)
{
	unsigned int	i;
	unsigned int	len;
	unsigned int	count;

	i = 0;
	count = 1;
	len = ft_strlen(s);
	if (!len)
		return (0);
	while (i < len)
	{
		if (s[i] == c)
			count++;
		i++;
	}
	return (count);
}

/*
*	Then I can create the map with the total number of rows and
*	columns as extremes.
*	Endly I check all the possible errors that could occur by the map's creation.
*	K is the index of the monodimensional map contained in the string s; 
*	line 89 is important because means we encountered a new line '\n', 
*	so we have to create a new row.
*/
void	map_creation(t_game *game, char *s)
{
	int		i;
	int		k;

	game->map = (char **) malloc (sizeof (char *) * game->row);
	if (!game->map)
		exit(0);
	i = 0;
	k = 0;
	while (i < game->row)
	{
		game->map[i] = (char *) malloc (game->column + 1);
		k = map_creation_2(game, s, i, k);
		i++;
	}
	free(s);
	check_map_creations_errors(game);
}

int	map_creation_2(t_game *game, char *s, int i, int k)
{
	int	j;

	j = 0;
	while (j < game->column + 1)
	{
		if (j == game->column)
		{
			game->map[i][j] = '\0';
			k++;
			break ;
		}	
		game->map[i][j] = s[k];
		j++;
		k++;
	}
	return (k);
}

/*
*	Endly I search for possible errors that could have occured
*	by the map's creation.
*/
void	check_map_creations_errors(t_game *game)
{
	if (ft_error_walls_bad_aligned(game) == TRUE)
		exit(0);
	if (ft_error_check_gaming_items(game) == TRUE)
		exit(0);
	if (ft_error_map_not_rectangular(game) == TRUE)
		exit(0);
}
