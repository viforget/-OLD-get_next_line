/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Get2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 20:13:15 by viforget          #+#    #+#             */
/*   Updated: 2018/10/30 21:16:16 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	int	findn(char *str)
{
	int i;

	i = 0;
	while(str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (i);
}

int			ft_ret(int nb)
{
	if (nb == 0)
		return (0);
	else if (nb > 0)
		return (1);
	else
		return (-1);
}


int			get_next_line(const int fd, char **line)
{
	static	char	*buf[BUFF_SIZE + 1];
	static	int		a = BUFF_SIZE;
	//ft_putchar('A');
	char			*str;
	static	int		nb;

	nb = BUFF_SIZE;
	str = ft_memalloc(ft_strlen(*line));
	//ft_putchar('B');
	if (a != nb)
	{
		ft_putchar('D');
		//ft_putnbr(findn((char *)buf + a + 1));
		ft_strncpy(str, (char *)buf + a + 1, findn((char *)buf + a + 1));
		//ft_putstr((char *)buf);
		a += findn((char *)buf + a + 1) + 1;
		//ft_putnbr(a);
	}
	if ((char)buf[BUFF_SIZE] != '\n')
	{
		while(nb == BUFF_SIZE && a == BUFF_SIZE)
		{
			nb = read(fd, buf, BUFF_SIZE);
			ft_putstr((char *)buf);
			a = findn((char *)buf);
			str = ft_strnjoin(str, (char *)buf, a);
		}
	}
	*line = str;
	return (ft_ret(nb));
}

#include <stdio.h>

int		main()
{
	char *str;
	int a;
	int b;
	int c = 6;
	b = 1;
	a = open("txt.txt", O_RDONLY);
	while (c--)
		b = get_next_line(a, &str);
		printf("%s\n", str);
}
