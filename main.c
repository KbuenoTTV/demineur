/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchichep <jchichep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/25 08:24:38 by jchichep          #+#    #+#             */
/*   Updated: 2014/03/25 08:24:42 by jchichep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<signal.h>
#include	<stdlib.h>
#include	"function.h"
#include	"option.h"

static t_opt	g_option[]=
{
    {1, easy_level},
    {2, med_level},
    {3, hard_level},
    {4, custom_level},
    {'q', quit},
    {0, NULL},
};

void	quit()
{
	unset_raw_mode();
	ft_putstr("\033[?12l\033[?25h");
	exit (0);
}

int	main()
{
	int	lvl;

	signal(SIGINT, catch_sigint);
	lvl = show_menu();
	get_option(lvl, g_option);
	unset_raw_mode();
	return (0);
}
