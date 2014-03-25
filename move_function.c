/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchichep <jchichep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/25 08:24:59 by jchichep          #+#    #+#             */
/*   Updated: 2014/03/25 08:36:11 by jchichep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"cursor.h"
#include	"size.h"

void		go_down(t_cursor *cursor, t_size *size)
{
	cursor->x += 1;
	cursor->x %= size->h;
}

void		go_up(t_cursor *cursor, t_size *size)
{
	cursor->x -= 1;
	if (cursor->x < 0)
		cursor->x += size->h;
}

void		go_right(t_cursor *cursor, t_size *size)
{
	cursor->y += 1;
	cursor->y %= size->l;
}

void		go_left(t_cursor *cursor, t_size *size)
{
	cursor->y -= 1;
	if (cursor->y < 0)
		cursor->y += size->l;
}

