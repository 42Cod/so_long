/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahautlatinis <mahautlatinis@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 11:14:12 by malatini          #+#    #+#             */
/*   Updated: 2021/04/23 10:53:59 by mahautlatin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

char	*ft_strstr(const char *haystack, const char *needle)
{
	int i;
	int j;

	i = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[i])
	{
		j = 0;
		while (haystack[i + j] == needle[j] && needle[j] && haystack[i + j])
		{
			if (needle[j + 1] == '\0')
				return ((char *)&haystack[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}

int		ft_isspace(char c)
{
	if (c == ' ')
	//c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r'
		return (SUCCESS);
	return (ERROR);
}

/*
int	c_atoi(t_map *map, char *line, int *res, int *i)
{
	int	len;
	(void)map;
	int sign;

	sign = 1;
	while (line[*i] == ' ' && line[*i] )
		(*i)++;
	while ((line[*i] == '-' || line[*i] == '+') && line[*i])
	{
		if (line [*i] == '-')
			sign = -sign;
		(*i)++;
	}
	len = ft_strlen(line) - 1;
	while (ft_isdigit(line[*i]) && line[*i] && *i < len)
	{
		*res = *res * 10 + line[*i] - '0';
		(*i)++;
	}
	if (line[*i] != '\0' && ft_isalpha(line[*i]) && line[*i] != ' ')
	{
		printf("Invalid char mentionned in RGB.\n");
		exit (ERROR);
	}
	return (*res * sign);
}
*/
