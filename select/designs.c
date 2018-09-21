/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   designs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psambo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 09:11:21 by psambo            #+#    #+#             */
/*   Updated: 2018/09/21 13:45:56 by psambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_put_yellow(char *str)
{
	ft_put_str(YELLOW);
	ft_put_str(str);
	ft_put_endl(NO_COLOUR);
}

/*void	ft_put_yellow(char *str)
{
	ft_put_str(YELLOW);
	ft_put_str(str);
	ft_put_endl(NO_COLOUR);
}*/

void	ft_put_underline(char *str, void (*ft_print)(char*))
{
	tputs(tgetstr("us", NULL), 1, ft_put_char);
	(*ft_print)(str);
	tputs(tgetstr("ue", NULL), 1, ft_put_char);
}

/*void	ft_put_underline_highlight(char *str, void (*ft_print)(char*))
{
	tputs(tgetstr("su", NULL), 1, ft_put_char);
	tputs(tgetstr("us", NULL), 1, ft_put_char);
	(*ft_print)(str);
	tputs(tgetstr("ue", NULL), 1, ft_put_char);
	tputs(tgetstr("se", NULL), 1, ft_put_char);
}*/

void	ft_put_highlight(char *str, void (*ft_print)(char*))
{
	tputs(tgetstr("se", NULL), 1, ft_put_char);
	(*ft_print)(str);
	tputs(tgetstr("so", NULL), 1, ft_put_char);
}
