/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarishe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 14:17:47 by ikarishe          #+#    #+#             */
/*   Updated: 2018/04/12 14:19:36 by ikarishe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

void	ft_put_move(int y, int x)
{
	char *buf;

	buf = ft_itoa(y);
	ft_putstr(buf);
	free(buf);
	ft_putstr(" ");
	buf = ft_itoa(x);
	ft_putstr(buf);
	free(buf);
	ft_putstr("\n");
}
