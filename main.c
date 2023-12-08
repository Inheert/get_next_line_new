/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 18:58:11 by tclaereb          #+#    #+#             */
/*   Updated: 2023/12/08 22:19:25 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "get_next_line.h"

int	main(void)
{
	int fd = open("./test.txt", O_RDONLY);
	char	*line;

	line = get_next_line(fd);
	if (line)
	{
		free(line);
	}
	line = get_next_line(fd);
	if (line)
	{
		free(line);
	}	
	line = get_next_line(fd);
	if (line)
	{
		free(line);
	}
	line = get_next_line(fd);
	if (line)
	{
		free(line);
	}
	close(fd);
	return (0);
}