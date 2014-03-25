/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchichep <jchichep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/25 08:25:08 by jchichep          #+#    #+#             */
/*   Updated: 2014/03/25 08:25:11 by jchichep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPTION_H
# define OPTION_H

typedef struct	s_option
{
  int		key;
  void		(*ptr_func)();
}		t_opt;

int		get_option(int key, t_opt *g_option);
void		easy_level();
void		med_level();
void		hard_level();
void		custom_level();
void		quit();

#endif /* !OPTION_H */
