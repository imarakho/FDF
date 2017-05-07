/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imarakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 18:00:47 by imarakho          #+#    #+#             */
/*   Updated: 2017/02/13 21:51:20 by imarakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char		**ft_readbuf(t_math *mth)
{
	char	*res;
	int		ret;
	char	*str;

	mth->i = -1;
	mth->y = 1;
	mth->x = 0;
	ft_colrowcheck(mth->filename);
	mth->fd = open(mth->filename, O_RDONLY);
	ret = get_next_line(mth->fd, &res);
	while (res[++mth->i] != '\0')
	{
		if (((res[mth->i] <= '9' && res[mth->i] >= '0') ||
		res[mth->i] == '-') && (res[mth->i - 1] == ' ' || mth->i == 0))
			mth->x++;
	}
	while (get_next_line(mth->fd, &str) == 1)
	{
		res = ft_strjoin(res, "\n");
		res = ft_strjoin(res, str);
		mth->y++;
	}
	mth->arr = ft_strsplit(res, '\n');
	close(mth->fd);
	return (mth->arr);
}

static int	**intmemalloc(t_math *mth)
{
	int		i;
	int		j;
	int		**m;

	j = -1;
	i = mth->y;
	if (!(m = (int**)malloc(sizeof(int*) * (i + 1))))
		exit(1);
	while (++j < i)
		if (!(m[j] = (int*)malloc(sizeof(int) * (mth->x + 1))))
			exit(1);
	return (m);
}

int			**arr_to_matrix(t_math *mth)
{
	int		**m;
	int		k;
	int		i;
	int		j;

	m = intmemalloc(mth);
	k = 0;
	i = -1;
	j = 0;
	while (++i < mth->y)
	{
		j = 0;
		k = 0;
		while (mth->arr[i][j])
		{
			if (((mth->arr[i][j] <= '9' && mth->arr[i][j] >= '0') ||
			mth->arr[i][j] == '-') && (mth->arr[i][j - 1] == ' ' || j == 0))
			{
				m[i][k] = ft_atoi(&mth->arr[i][j]);
				k++;
			}
			j++;
		}
	}
	return (m);
}

int			**return_matrix(t_math *mth)
{
	int		**m;

	if (!mth->arr)
		mth->arr = ft_readbuf(mth);
	m = arr_to_matrix(mth);
	return (m);
}
