/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 01:37:54 by viforget          #+#    #+#             */
/*   Updated: 2018/10/30 20:47:12 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#define BUFF_SIZE 28

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "libft/libft.h"

int		get_next_line(const int fd, char **line);

#endif
