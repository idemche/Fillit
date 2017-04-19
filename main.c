/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idemchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 18:52:47 by idemchen          #+#    #+#             */
/*   Updated: 2017/04/19 18:52:49 by idemchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fillit.h"

int		main(int argc, char **argv)
{
	int		fd;
	t_tmino	**tmino_arr;
	char	*res;
	int		sq_size;

	if (argc != 2)
		return (ft_puterr("usage: ./fillit file\n"));
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		return (ft_puterr("Couldn't open file!\n"));
	if (((tmino_arr = (t_tmino **)malloc(sizeof(*tmino_arr) * MAX_TMINO + 1))
				== NULL))
		return (ft_puterr("Failed to allocate mem in main!"));
	if (build_arr(fd, &tmino_arr) == -1)
		return (-1);
	else
	{
		res = pack_shapes(tmino_arr, &sq_size);
		display_sq(res, sq_size);
	}
	return (0);
}

int		build_arr(int fd, t_tmino ***build_arr)
{
	char	*buffer;
	int		i;
	int		shape;

	i = 0;
	if ((buffer = (char *)malloc(sizeof(*buffer) * BLK_SZ)) == NULL)
		return (ft_puterr("in build_arr: memalloc error\n"));
	while (read(fd, buffer, BLK_SZ) > 0)
	{
		if (check_block(buffer) == -1)
			return (-1);
		buffer = strip_nl(buffer);
		buffer = norm_shape(buffer);
		if ((shape = find_tmino(buffer)) == -1)
			return (ft_puterr("error\n"));
		(*build_arr)[i] = build_tmino(buffer);
		i++;
		read(fd, buffer, 1);
	}
	if (i == 0 || buffer[0] == '\n')
		return (ft_puterr("error\n"));
	(*build_arr)[i] = 0;
	return (0);
}
