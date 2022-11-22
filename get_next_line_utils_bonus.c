/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rouali <rouali@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 12:24:14 by rouali            #+#    #+#             */
/*   Updated: 2022/11/22 12:24:16 by rouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strchr(char *str, int rchr)
{
	int		i;
	char	c;

	i = 0;
	c = (char)rchr;
	while (str[i] != c && str[i])
		i++;
	if (str[i] == c)
		return (1);
	else
		return (0);
}

char	*ft_strjoin(char *str, char *buffer)
{
	size_t	i;
	size_t	j;
	char	*rstr;

	if (!str)
	{
		str = malloc(sizeof(char) * 1);
		str[0] = '\0';
	}
	rstr = malloc(sizeof(char) * ((ft_strlen(str) + ft_strlen(buffer)) + 1));
	if (!rstr)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i])
	{
		rstr[i] = str[i];
		i++;
	}
	while (buffer[j])
		rstr[i++] = buffer[j++];
	rstr[i] = '\0';
	free(str);
	return (rstr);
}

char	*ft_read_nline(char *str)
{
	int		i;
	int		j;
	char	*rnline;

	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	if (str[0] == 0)
		return (NULL);
	rnline = malloc(sizeof(char) * (i + 2));
	if (!rnline)
		return (NULL);
	j = 0;
	while (str[j] != '\n' && str[j])
	{
		rnline[j] = str[j];
		j++;
	}
	if (str[j] == '\n')
	{
		rnline[j] = '\n';
		j++;
	}
	rnline[j] = '\0';
	return (rnline);
}

char	*ft_read_rline(char *str)
{
	int		i;
	int		j;
	char	*s;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == 0)
	{
		free(str);
		return (NULL);
	}
	i++;
	s = malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!s)
		return (NULL);
	j = 0;
	while (str[i] != '\0')
		s[j++] = str[i++];
	s[j] = '\0';
	free(str);
	return (s);
}
