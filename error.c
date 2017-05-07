/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imarakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 15:08:52 by imarakho          #+#    #+#             */
/*   Updated: 2017/02/15 13:50:32 by imarakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		colcheck(char *s1, char *s2)
{
	int		i;
	int		x1;
	int		x2;

	i = -1;
	x1 = 0;
	x2 = 0;
	while (s1[++i] != '\0')
	{
		if (((s1[i] <= '9' && s1[i] >= '0') ||
		s1[i] == '-') && (s1[i - 1] == ' ' || i == 0))
			x1++;
	}
	i = -1;
	while (s2[++i] != '\0')
	{
		if (((s2[i] <= '9' && s2[i] >= '0') ||
		s2[i] == '-') && (s2[i - 1] == ' ' || i == 0))
			x2++;
	}
	if (x1 != x2)
	{
		ft_putstr("Error!Wrong amount of numbers in column!\n");
		exit(1);
	}
}

void			ft_zero(t_math *mth)
{
	int		i;
	int		j;

	i = 0;
	while (i < mth->y)
	{
		j = 0;
		while (j < mth->x)
		{
			mth->mx[i][j] -= mth->midx;
			mth->my[i][j] -= mth->midy;
			j++;
		}
		i++;
	}
}

void			ft_firstcheck(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] <= '9' && str[i] >= '0') &&
			!(str[i] <= 'F' && str[i] >= 'A') && str[i] != ' '
			&& str[i] != 'x' && str[i] != ','
			&& str[i] != '-' && str[i] != '\n' &&
			!(str[i] <= 'f' && str[i] >= 'a') && str[i] != '\0')
		{
			ft_putstr("Wrong symbol!Error!\n");
			exit(1);
		}
		i++;
	}
}

void			ft_colrowcheck(char *filename)
{
	int		fd;
	char	*s1;
	char	*s2;

	if ((fd = open(filename, O_RDONLY)) == -1)
	{
		ft_putstr("Wrong file!\n");
		exit(1);
	}
	while (get_next_line(fd, &s1) == 1 && get_next_line(fd, &s2) == 1)
	{
		ft_firstcheck(s1);
		ft_firstcheck(s2);
		colcheck(s1, s2);
	}
	close(fd);
}
