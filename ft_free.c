/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarishe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 14:19:53 by ikarishe          #+#    #+#             */
/*   Updated: 2018/04/16 15:15:04 by ikarishe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

void	free_piece_data(t_shape *piece)
{
	int i;

	i = 0;
	while (i < piece->dim_y)
	{
		free(piece->data[i]);
		i++;
	}
}

void	free_board_data(t_board *board)
{
	int i;

	i = 0;
	while (i < board->dim_y)
	{
		free(board->data[i]);
		i++;
	}
}

void	delete_list(t_list **head)
{
	t_list	*current;
	t_list	*next;

	current = *head;
	while (current)
	{
		next = current->next;
		free(current->content);
		free(current);
		current = next;
	}
	*head = NULL;
}
