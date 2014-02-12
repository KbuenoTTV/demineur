/*
**          444    222222          GGG     AAA     MM   MM EEEEE
**         4444        222       GG       AA AA    MMMMMMM EE
**        44 44          22      GG  G   AA   AA   MM M MM EEEEE
**       44  44          22      GG  G  AAAAAAAAA  MM   MM EE
**      44   44         22         GGG AA       AA MM   MM EEEEE
**     4444444444      22
**     4444444444     22      SS  TTTTTT UU    UU DDDD   II   OOOO
**           44      22      SS     TT   UU    UU DD  DD II  OO  OO
**           44     22        SS    TT   UU    UU DD  DD II OO    OO
**           44    222         SS   TT   UU    UU DD  DD II  OO  OO
**           44    22222222   SS    TT     UUUU   DDDD   II   OOOO
**
** Project name: Demineur
** File name: main.c
** Made by: jchichep
** File created  on  Tue Sep  3 11:21:35 2013 by jchichep
** Last modified on  Fri Jan  3 16:32:00 2014 by jchichep
*/

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
