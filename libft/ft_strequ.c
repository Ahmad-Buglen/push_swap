/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dphyliss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 13:56:53 by dphyliss          #+#    #+#             */
/*   Updated: 2019/04/24 15:01:12 by dphyliss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strequ(char const *s1, char const *s2)
{
	size_t	i;

	if (s1 && s2)
	{
		i = 0;
		while ((s1[i] != '\0') && (s2[i] != '\0') && (s1[i] == s2[i]))
			i++;
		if ((s1[i] == '\0') && (s2[i] == '\0'))
			return (1);
		else
			return (0);
	}
	return (0);
}
