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
** File name: menu.c
** Made by: jchichep
** File created  on  Tue Sep  3 14:24:43 2013 by jchichep
** Last modified on  Wed Jan  8 20:51:52 2014 by jchichep
*/

#include	<unistd.h>
#include	"color.h"
#include	"function.h"
#include	"key.h"

int			get_key()
{
	char	 tab[3];

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
