/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imarakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 14:06:18 by imarakho          #+#    #+#             */
/*   Updated: 2017/02/15 17:38:56 by imarakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		minus_zoom(t_math *mth)
{
	int i;
	int j;

	i = 0;
	if (!mth->mzoom)
		mth->mzoom = 1.0;
	cords_to_zero(mth);
	while (i < mth->y)
	{
		j = 0;
		while (j < mth->x)
		{
			mth->mx[i][j] /= mth->mzoom;
			mth->my[i][j] /= mth->mzoom;
			mth->mz[i][j] /= mth->mzoom;
			j++;
		}
		i++;
	}
	cords_to_midle(mth);
}

void		plus_zoom(t_math *mth)
{
	int i;
	int j;

	i = 0;
	cords_to_zero(mth);
	while (i < mth->y)
	{
		j = 0;
		while (j < mth->x)
		{
			mth->mx[i][j] *= mth->pzoom;
			mth->my[i][j] *= mth->pzoom;
			mth->mz[i][j] *= mth->pzoom;
			j++;
		}
		i++;
	}
	cords_to_midle(mth);
}

void		cords_to_zero(t_math *mth)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	mth->shiftx = mth->wsize / 2;
	mth->shifty = mth->wsize / 2;
	while (i < mth->y)
	{
		j = 0;
		while (j < mth->x)
		{
			mth->mx[i][j] -= mth->shiftx;
			mth->my[i][j] -= mth->shifty;
			j++;
		}
		i++;
	}
	mth->midx = (mth->mx[mth->y - 1][mth->x - 1] + mth->mx[0][0]) / 2;
	mth->midy = (mth->my[mth->y - 1][mth->x - 1] + mth->my[0][0]) / 2;
}

void		cords_to_midle(t_math *mth)
{
	int		i;
	int		j;

	i = 0;
	while (i < mth->y)
	{
		j = 0;
		while (j < mth->x)
		{
			mth->mx[i][j] += mth->wsize / 2;
			mth->my[i][j] += mth->wsize / 2;
			j++;
		}
		i++;
	}
	mth->midx = (mth->mx[mth->y - 1][mth->x - 1]
	+ mth->mx[0][0]) / 2 - mth->wsize / 2;
	mth->midy = (mth->my[mth->y - 1][mth->x - 1]
	+ mth->my[0][0]) / 2 - mth->wsize / 2;
}

void		ft_math(t_math *mth)
{
	mth->sz = find_cord_z(return_matrix(mth), mth);
	ft_trans_cords(mth);
	ft_shift(mth);
	mth->midx = (mth->mx[mth->y - 1][mth->x - 1]
	+ mth->mx[0][0]) / 2 - mth->wsize / 2;
	mth->midy = (mth->my[mth->y - 1][mth->x - 1]
	+ mth->my[0][0]) / 2 - mth->wsize / 2;
	mth->anglex = GR;
	mth->angley = GR;
	mth->anglez = GR;
	mth->size = mth->wsize / 2;
	mth->shift = mth->wsize / 2;
	turn_z(mth);
	turn_x(mth);
	turn_y(mth);
	ft_projection(mth);
	ft_positive(mth);
	cords_to_midle(mth);
}
