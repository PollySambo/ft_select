/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exiting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psambo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 09:11:40 by psambo            #+#    #+#             */
/*   Updated: 2018/09/22 15:39:04 by psambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	exiting(void)
{
	t_pick	*out;

	out = ft_save_and_load(NULL, 1);
	free_memory(out);
	reset_iterm(&(out->term));
	exit(0);
}
