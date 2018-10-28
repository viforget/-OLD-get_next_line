/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 01:35:11 by viforget          #+#    #+#             */
/*   Updated: 2018/10/28 17:41:24 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static	char	*ft_strnjoin(char const *s1, char const *s2, size_t n)
{
	int	i;
	int	i2;
	char*str;
	int	len;

	i = 0;
	i2 = 0;
	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (s1[i] != '\0')
	{
		str[i2] = s1[i];
		i++;
		i2++;
	}
	i = 0;
	while (s2[i] != '\0' && i < n)
		str[i2++] = s2[i++];
	str[i2] = '\0';
	return (str);
}

void	ft_shift(char *s, int n)
{
	while (s[n])
	{
		s[n] = s[n + 1];
		n++;
	}
}

static	size_t		fnd_n(char *str, size_t n)
{
	size_t	i;

	i = 0;
	while (n > 0 && str[i] != '\0')
		{
			if (str[i] == '\n')
				n--;
			i++;
		}
	return (i);
}

static	int			ft_min(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

int					get_next_line(const int fd, char **line)
{
	static	int		nb = BUFF_SIZE;
	static	char	cstr[BUFF_SIZE + 1];
	char			*str;
	int				check;
	int				fndn;

	check = 1;
	fndn = fnd_n(cstr, 1);
	str = ft_strsub(cstr, fndn, fnd_n(cstr, 2) - fndn);
	while (nb == BUFF_SIZE && check)
	{
		ft_bzero(cstr, BUFF_SIZE + 1);
		nb = read(fd, cstr, BUFF_SIZE);
		cstr[nb + 1] = '\0';
		if (ft_strchr(cstr, '\n'))
		{
			check = 0;
		}
		str = ft_strnjoin(str, cstr, fnd_n(cstr, 1));
	}
	str[ft_strlen(str) - 1] = '\0';
	*line = str;
	if (cstr[fnd_n(cstr, 1)] == '\n')
		ft_shift(cstr, fnd_n(cstr, 1));
	if (nb > 0)
		return (1);
	else if (nb == 0)
		return (0);
	else
		return (-1);
}

/*
**int		main()
**{
**	char *str;
**	int a;
**	int b;
**	b = 1;
**	a = open("txt.txt", O_RDONLY);
**	while (b)
**	{
**		b = get_next_line(a, &str);
**		printf("%s\n", str);
**	}
**}
*/
