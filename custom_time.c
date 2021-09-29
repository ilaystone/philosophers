/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_time.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 11:33:01 by ikhadem           #+#    #+#             */
/*   Updated: 2021/09/29 14:02:56 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

unsigned long	time_diff(struct timeval t1, struct timeval t2)
{
	return ((t1.tv_sec * 1000000 + t1.tv_usec) - (t2.tv_sec * 1000000 + t2.tv_usec));
}

unsigned long	time_usec_to_ms(unsigned long value)
{
	return (value / 1000);
}

void	get_time(struct timeval *tv)
{
	gettimeofday(tv, NULL);
}