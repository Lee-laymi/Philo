/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrsirab <skrsirab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 16:45:35 by skrairab          #+#    #+#             */
/*   Updated: 2023/01/20 23:06:46 by skrsirab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	w_count(char const *s, char c)
{
	int		i;

	i = 0;
	while (*s && *s == c)
		s++;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s != c && *s)
			i++;
		while (*s != c && *s)
			s++;
	}
	return (i);
}

static int	str_count(char const *s, char c)
{
	int		a;

	a = 0;
	while (*s && *s == c)
		s++;
	while (*s && *s != c)
	{
		a++;
		s++;
	}
	return (a);
}

static char	*w_chr(char const *s, char c)
{
	char	*wchr;
	int		l;

	l = str_count(s, c) + 1;
	while (*s && *s == c)
		s++;
	wchr = (char *)malloc(sizeof(char) * l);
	if (wchr == NULL)
		return (NULL);
	ft_strlcpy(wchr, s, l);
	return (wchr);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		k;
	int		j;

	j = w_count(s, c);
	str = (char **)malloc(sizeof(char *) * (j + 1));
	k = 0;
	if (str == NULL)
		return (NULL);
	while (j > k && *s)
	{
		str[k] = w_chr(s, c);
		while (*s == c && *s)
			s++;
		while (*s != c && *s)
			s++;
		k++;
	}
	str[k] = NULL;
	return (str);
}
