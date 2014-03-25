/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basics.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchichep <jchichep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/25 08:21:43 by jchichep          #+#    #+#             */
/*   Updated: 2014/03/25 08:35:46 by jchichep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		ft_putnbr(nb / 10);
	ft_putchar('0' + nb % 10);
}

void		ft_putstr_color(char *str, char *color)
{
	ft_putstr(color);
	ft_putstr(str);
	ft_putstr(NORMAL);
}
