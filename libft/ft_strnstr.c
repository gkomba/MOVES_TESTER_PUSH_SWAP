/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkomba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 08:11:07 by gkomba            #+#    #+#             */
/*   Updated: 2024/05/16 16:13:32 by gkomba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t n)
{
	int		j;
	size_t	i;

	i = 0;
	if (*little == '\0')
		return ((char *)big);
	while (*big != '\0' && i < n)
	{	
		if (*big == little[0])
		{
			j = 0;
			while (big[j] == little[j] && little[j] != '\0')
				j++;
			if (little[j] == '\0')
				return ((char *)big);
		}
		i++;
		big++;
	}
	return (0);
}
