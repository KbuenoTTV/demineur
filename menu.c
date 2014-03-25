/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchichep <jchichep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/25 08:24:48 by jchichep          #+#    #+#             */
/*   Updated: 2014/03/25 08:26:36 by jchichep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<unistd.h>
#include	"color.h"
#include	"function.h"
#include	"key.h"

int			get_key()
{
	char	tab[3];

	read(0, tab, 1);
	if (tab[0] == 27)
    {
		read(0, tab + 1, 1);
		if (tab[1] == 91)
		{
			read(0, tab + 2, 1);
		}
    }
	if (tab[0] == 27 && tab[1] == 91 && tab[2] == 66)
		return (DOWN);
	if (tab[0] == 27 && tab[1] == 91 && tab[2] == 65)
		return (UP);
	if (tab[0] == 27 && tab[1] == 91 && tab[2] == 68)
		return (LEFT);
	if (tab[0] == 27 && tab[1] == 91 && tab[2] == 67)
		return (RIGHT);
	return ((int)tab[0]);
}

int	show_menu()
{
	int	key;

	key = 0;
	ft_putstr_color("Press 1 for easy\n", M2);
	ft_putstr_color("Press 2 for medium\n", M3);
	ft_putstr_color("Press 3 for hard\n", M1);
	ft_putstr_color("Press 4 for custom\n", M4);
	set_raw_mode();
	while ((key < '1' || key > '4') && key != 'q')
    {
		key = get_key();
    }
	return (key - '0');
}
