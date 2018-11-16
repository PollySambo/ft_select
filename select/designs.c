/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   designs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psambo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 09:11:21 by psambo            #+#    #+#             */
/*   Updated: 2018/09/22 15:28:47 by psambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	yellow(char *str)
{
	ft_putstr(YELLOW);
	ft_putstr(str);
	ft_putendl(NO_COLOUR);
}

void	underline(char *str, void (*ft_print)(char*))
{
	tputs(tgetstr("us", NULL), 1, ft_putchar);
	(*ft_print)(str);
	tputs(tgetstr("ue", NULL), 1, ft_putchar);
}

void	highlight(char *str, void (*ft_print)(char*))
{
	tputs(tgetstr("se", NULL), 1, ft_putchar);
	(*ft_print)(str);
	tputs(tgetstr("so", NULL), 1, ft_putchar);
}
