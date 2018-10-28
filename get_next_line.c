/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 01:35:11 by viforget          #+#    #+#             */
/*   Updated: 2018/10/28 10:13:59 by viforget         ###   ########.fr       */
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

static	size_t		ft_find_n(char *str, size_t n)
{
	size_t i;

	i = 0;
	while(n > 0 && str[i] != '\0')
		{
			if (str[i] == '\n')
				n--;
			i++;
		}
	return (i);
}

int					ft_min(int a, int b)
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
	int				a;
	int				check;
	int				fndn;
	int nperm = 0;

	//ft_putstr("\nA\n");
	//ft_putstr(cstr);
	//ft_putstr("\nB\n");
	//if (ft_find_n(cstr, 2) < ft_strlen(cstr))
	//	check = 0;
	//else
	if (nb < BUFF_SIZE)
		return (0);
	check = 1;
	fndn = ft_find_n(cstr, 1);

	str = ft_strsub(cstr, fndn, ft_find_n(cstr, 2) - fndn);
	if (ft_find_n(str, 1) == ft_strlen(str))
		while (nb == BUFF_SIZE && check)
		{
			ft_bzero(cstr, BUFF_SIZE + 1);
			nb = read(fd, cstr, BUFF_SIZE);
			cstr[nb + 1] = '\0';
			if (ft_strchr(cstr, '\n'))
			{
				//cstr[ft_find_n(cstr) + 1] = '\0';
				check = 0;
			}
			str = ft_strnjoin(str, cstr, ft_find_n(cstr, 1));
		}
	else
		ft_memcpy(cstr, str, ft_min(ft_strlen(str), BUFF_SIZE));


	str[ft_strlen(str) - 1] = '\0';
	*line = str;
	if (nb > 0)
		return (1);
	else if (nb == 0)
		return (0);
	else
		return (-1);
}

/*int		main()
**{
**	char *str;
**	int a;
**	int b;
**
**	b = 1;
**	a = open("txt.txt", O_RDONLY);
**	while (b != 0)
**	{
**		b = get_next_line(a, &str);
**		printf("%s\n", str);
**	}
**}
*/
