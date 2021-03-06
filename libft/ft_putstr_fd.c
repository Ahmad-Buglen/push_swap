/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dphyliss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 10:34:10 by dphyliss          #+#    #+#             */
/*   Updated: 2019/04/24 11:05:57 by dphyliss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putstr_fd(char const *s, int fd)
{
	size_t	i;

	if (s && (fd >= 0))
	{
		i = 0;
		while (s[i] != '\0')
		{
			write(fd, &s[i], 1);
			++i;
		}
	}
}
