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
** File name: level.c
** Made by: jchichep
** File created  on  Tue Sep  3 16:17:48 2013 by jchichep
** Last modified on  Fri Jan  3 16:31:58 2014 by jchichep
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"function.h"
#include	"size.h"

void		easy_level()
{
	t_size	size;

	size.h = 10;
	size.l = 10;
	size.m = 10;
	ft_putstr("\033[?25l\n");
	start_game(&size);
}

void		med_level()
{
	t_size	size;

	size.h = 16;
	size.l = 16;
	size.m = 40;
	ft_putstr("\033[?25l\n");
	start_game(&size);
}

void		hard_level()
{
	t_size	size;

	size.h = 16;
	size.l = 30;
	size.m = 99;
	ft_putstr("\033[?25l\n");
	start_game(&size);
}

int		verify_arg(t_size *size)
{
	if (size->h < 1 || size->h > 40)
		return (0);
	if (size->l < 1 || size->l > 80)
		return (0);
	if (size->m >= size->h * size->l)
		return (0);
	return (1);
}

void		custom_level()
{
	t_size	size;
	int		verify;
	char		*str;

	unset_raw_mode();
	str = malloc(sizeof(*str) * 1024);
	verify = -1;
	while (verify != 1)
    {
		if (verify == 0)
			ft_putstr("Valeur incorrecte \n");
		ft_bzero(str, 1024);
		ft_putstr("Quelle hauteur? (maximum 40)\n");
		read(0, str, 1023);
		size.h = ft_atoi(str);
		ft_bzero(str, 1023);
		ft_putstr("Quelle longueur? (maximum 80)\n");
		read(0, str, 1023);
		size.l = ft_atoi(str);
		ft_bzero(str, 1023);
		ft_putstr("Combien de mines? (maximum (hauteur * longueur) - 1\n");
		read(0, str, 1023);
		size.m = ft_atoi(str);
		verify = verify_arg(&size);
    }
	set_raw_mode();
	ft_putstr("\033[?25l\n");
	start_game(&size);
}
