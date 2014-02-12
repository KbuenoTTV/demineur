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
** Project name: demineur
** File name: basics.c
** Made by: jchichep
** File created  on  Tue Sep  3 14:10:01 2013 by jchichep
** Last modified on  Thu Nov 14 23:50:09 2013 by jchichep
*/

#include	<unistd.h>
#include	"color.h"

int		ft_atoi(char *str)
{
  int		ret;
  int		i;
  int		neg;

  i = 0;
  if (str[0] == '-')
    {
      neg = 1;
      i = 1;
    }
  ret = 0;
  while (str[i] >= '0' && str[i] <= '9')
    {
      if (neg == 1)
	ret = ret * 10 - str[i] + '0';
      else
	ret = ret * 10 + str[i] - '0';
      i++;
    }
  return (ret);
}

void		ft_putchar(char c)
{
  (void)write(1, &c, 1);
}

void		ft_bzero(char *str, int nb)
{
  int		i;

  i = 0;
  while (i < nb)
    {
      str[i++] = 0;
    }
}

int		ft_strlen(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    {
      i++;
    }
  return (i);
}

void		ft_putstr(char *str)
{
  (void)write(1, str, ft_strlen(str));
}

void		ft_putnbr(int nb)
{
  if (nb == -2147483648)
    ft_putstr("-2147483648");
  if (nb < 0)
    {
      ft_putchar('-');
      nb = -nb;
    }
  if (nb / 10 > 0)
    ft_putnbr(nb/10);
  ft_putchar('0' + nb % 10);
}

void		ft_putstr_color(char *str, char *color)
{
  ft_putstr(color);
  ft_putstr(str);
  ft_putstr(NORMAL);
}
