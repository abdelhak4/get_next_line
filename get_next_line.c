/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 22:15:03 by ael-mous          #+#    #+#             */
/*   Updated: 2021/12/04 21:24:51 by ael-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	find(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (0);
}

char	*print_line(char **static_ptr)
{
	char	*tmp;
	char	*ptr;
	int		i;

	i = find(*static_ptr);
	ptr = ft_substr(*static_ptr, 0, i + 1);
	tmp = *static_ptr;
	*static_ptr = ft_substr(*static_ptr, i + 1, ft_strlen(*static_ptr));
	free(tmp);
	tmp = NULL;
	return (ptr);
}

char	*print_one_str(char **str)
{
	char	*str_tmp;

	if ((*str)[0] == '\0')
	{
		free(*str);
		*str = NULL;
		return (NULL);
	}
	else
	{
		str_tmp = *str;
		*str = NULL;
	}
	return (str_tmp);
}

char	*get_next_line(int fd)
{
	char		*tmp;
	ssize_t		b_fd;
	static char	*static_arr;
	char		store[BUFFER_SIZE + 1];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	if (!static_arr)
		static_arr = ft_strdup("");
	while (!find(static_arr) || b_fd != )
	{
		b_fd = read(fd, store, BUFFER_SIZE);
		if (b_fd == -1)
		{
			free(static_arr);
			static_arr = NULL;
			return (NULL);
		}
		if (b_fd == 0)
			break ;
		store[b_fd] = '\0';
		tmp = static_arr;
		free(static_arr);
		static_arr = ft_strjoin(tmp, store);
	}
	if (ft_strchr(static_arr, '\n') == -2)
		return (print_one_str(&static_arr));
	return (print_line(&static_arr));
}
