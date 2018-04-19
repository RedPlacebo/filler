/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filler.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarishe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 11:55:02 by ikarishe          #+#    #+#             */
/*   Updated: 2018/04/19 12:34:19 by ikarishe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILLER_H
# define FT_FILLER_H
# include "Libft_Final/libft.h"
# include "Libft_Final/get_next_line.h"
# include <stdlib.h>

typedef struct	s_pos
{
	int x;
	int	y;
	int strength;
}				t_pos;

typedef struct	s_shape
{
	char	**data;
	int		dim_x;
	int		dim_y;
	t_pos	pos;
}				t_shape;

typedef struct	s_board
{
	char	**data;
	int		dim_x;
	int		dim_y;
	t_pos	pos;
	t_pos	sum_player_pos;
	int		player_cell_count;
	int		player_surface_area;
	int		player_touching_area;
	double	player_avg_pos_x;
	double	player_avg_pos_y;
	t_pos	sum_enemy_pos;
	int		enemy_cell_count;
	double	enemy_avg_pos_x;
	double	enemy_avg_pos_y;
}				t_board;

typedef	struct	s_place
{
	int x_place;
	int y_place;
	int x;
	int y;
}				t_place;

int				ft_read(t_board *board, t_shape *piece, char *player);
void			ft_play(t_board *board, t_shape *piece, char *player);
int				try_place(t_board *board, t_shape *piece,
		t_place place, char *player);
void			ft_put_move(int y, int x);
void			free_piece_data(t_shape *piece);
void			free_board_data(t_board *board);
void			delete_list(t_list **head);
int				get_strength(t_board *board, t_shape *piece, t_pos pos_move,
		char *player);
int				analyze_boards(t_board *board, t_board *new_board,
		char *player);
void			ft_free(char **str);
void			read_board(char *line, t_board *board);
void			read_shape(char *line, t_shape *piece);
void			check_char(t_board *board, char *player, int x, int y);
int				grab_top_strength(t_board *board, t_board *new_board);
int				grab_bot_strength(t_board *board, t_board *new_board);

#endif
