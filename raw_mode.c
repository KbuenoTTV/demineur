/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raw_mode.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchichep <jchichep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/25 08:25:18 by jchichep          #+#    #+#             */
/*   Updated: 2014/03/25 08:27:03 by jchichep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<termios.h>
#include	<signal.h>
#include	"function.h"
#include	"option.h"

int	get_option(int key, t_opt *g_option)
{
	int		i;

	i = 0;
	while (g_option[i].key)
	{
		if (g_option[i].key == key)
		{
			g_option[i].ptr_func();
			return (0);
		}
		i++;
    }
	if (g_option[i].key == 0)
	{
		return (-1);
	}
	return (0);
}

void		catch_sigint(int sig)
{
	sig = sig;
	ft_putstr("Please use q to quit the program\n");
	signal(SIGINT, catch_sigint);
}

void		unset_raw_mode()
{
	struct termios t;

	tcgetattr(0, &t);
	t.c_lflag += ICANON;
	t.c_lflag += ECHO;
	t.c_cc[VMIN] = 1;
	t.c_cc[VTIME] = 0;
	tcsetattr(0, TCSANOW, &t);
}

void		set_raw_mode()
{
	struct termios t;

	tcgetattr(0, &t);
	t.c_lflag &= ~ICANON;
	t.c_lflag &= ~ECHO;
	t.c_cc[VMIN] = 1;
	t.c_cc[VTIME] = 0;
	tcsetattr(0, TCSANOW, &t);
}
