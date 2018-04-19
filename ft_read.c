/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarishe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 12:25:10 by ikarishe          #+#    #+#             */
/*   Updated: 2018/04/16 14:40:14 by ikarishe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

void	ft_free(char **str)
{
	if (*str)
		free(*str);
	*str = 0;
}

char	ft_get_player(char *line)
{
	char *s;

	s = line;
	while (*s != 'p')
		++s;
	++s;
	if (*s == '1')
		*s = 'o';
	else if (*s == '2')
		*s = 'x';
	ft_free(&line);
	return (*s);
}

void	ft_get_board(char *line, t_board *board)
{
	int i;

	i = 0;
	board->dim_x = 0;
	board->dim_y = 0;
	while (!ft_isdigit(line[i]))
		i++;
	while (ft_isdigit((line[i])))
	{
		board->dim_y = board->dim_y * 10 + (line[i] - '0');
		i++;
	}
	i++;
	while (ft_isdigit(line[i]))
	{
		board->dim_x = board->dim_x * 10 + (line[i] - '0');
		i++;
	}
	board->data = (char**)malloc(board->dim_x * board->dim_y * 2
			* sizeof(char *));
	ft_free(&line);
	get_next_line(0, &line);
	ft_free(&line);
	read_board(line, board);
}

void	ft_get_piece(char *line, t_shape *piece)
{
	int i;
	int dim_x;
	int dim_y;

	dim_x = 0;
	dim_y = 0;
	i = 0;
	while (!ft_isdigit(line[i]))
		i++;
	while (ft_isdigit(line[i]))
	{
		dim_x = dim_x * 10 + (line[i] - '0');
		i++;
	}
	i++;
	while (ft_isdigit(line[i]))
	{
		dim_y = dim_y * 10 + (line[i] - '0');
		i++;
	}
	piece->data = (char**)malloc(dim_x * dim_y * 2 * sizeof(char *));
	piece->dim_x = dim_y;
	piece->dim_y = dim_x;
	ft_free(&line);
	read_shape(line, piece);
}

int		ft_read(t_board *board, t_shape *piece, char *player)
{
	char	*line;

	while ((get_next_line(0, &line)) != 0)
	{
		if (*player == '0' && ft_strstr(line, ".filler"))
		{
			*player = ft_get_player(line);
		}
		else if (ft_strncmp(line, "Plateau", 2) == 0)
		{
			ft_get_board(line, board);
		}
		else if (ft_strncmp(line, "Piece", 2) == 0)
		{
			ft_get_piece(line, piece);
			return (1);
		}
	}
	return (0);
}
