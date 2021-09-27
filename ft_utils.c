/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 08:31:02 by ikhadem           #+#    #+#             */
/*   Updated: 2021/09/27 08:32:04 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_isdigit(int c)
{
	return (c <= '9' && c >= '0');
}

int	ft_isspace(int c)
{
	unsigned char	i;

	i = (unsigned char)c;
	if (i == ' ')
		return (1);
	if (i == '\n')
		return (1);
	if (i == '\t')
		return (1);
	if (i == '\v')
		return (1);
	if (i == '\r')
		return (1);
	if (i == '\f')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int				sign;
	long			res;

	sign = 1;
	res = 0;
	while (ft_isspace(*str) && *str)
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (ft_isdigit(*str) && *str)
	{
		res = res * 10 + (unsigned int)(*str - '0');
		str++;
	}
	return (res * sign);
}

int	ft_strisdigit(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}
