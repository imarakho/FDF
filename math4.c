/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imarakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 18:15:26 by imarakho          #+#    #+#             */
/*   Updated: 2017/02/13 20:44:29 by imarakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_shift(t_math *mth)
{
	int	i;
	int	j;

	i = 0;
	while (i < mth->y)
	{
		j = 0;
		while (j < mth->x)
		{
			mth->mx[i][j] = (mth->mx[i][j] - mth->x / 2) * mth->pzoom;
			mth->my[i][j] = (mth->my[i][j] - mth->y / 2) * mth->pzoom;
			j++;
		}
		i++;
	}
}

void	ft_plus_z(t_math *mth)
{
	int i;
	int j;

	i = 0;
	ft_zero(mth);
	while (i < mth->y)
	{
		j = 0;
		while (j < mth->x)
		{
			if (mth->mz[i][j] != 0)
				mth->mz[i][j] += (mth->plsz * mth->mz[i][j]);
			j++;
		}
		i++;
	}
	ft_middle(mth);
}

void	ft_minus_z(t_math *mth)
{
	int	i;
	int	j;

	i = 0;
	ft_zero(mth);
	while (i < mth->y)
	{
		j = 0;
		while (j < mth->x)
		{
			if (mth->mz[i][j] != 0)
				mth->mz[i][j] += mth->minz;
			j++;
		}
		i++;
	}
	ft_middle(mth);
}

double	**ft_arr_memalloc(t_math *mth)
{
	int		i;
	int		j;
	double	**res;

	j = -1;
	i = mth->y;
	if (!(res = (double**)malloc(sizeof(double*) * (i + 1))))
		return (NULL);
	res[i] = NULL;
	while (++j < i)
	{
		if (!(res[j] = (double*)malloc(sizeof(double) * (mth->x + 1))))
			return (NULL);
		res[j][mth->x] = '\0';
	}
	return (res);
}

void	ft_trans_cords(t_math *mth)
{
	int	i;
	int	j;

	i = 0;
	mth->mx = ft_arr_memalloc(mth);
	mth->my = ft_arr_memalloc(mth);
	mth->mz = ft_arr_memalloc(mth);
	while (i < mth->y)
	{
		j = 0;
		while (j < mth->x)
		{
			mth->mx[i][j] = j;
			mth->my[i][j] = i;
			mth->mz[i][j] = mth->sz[i][j];
			j++;
		}
		i++;
	}
}
