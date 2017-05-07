/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imarakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 16:31:22 by imarakho          #+#    #+#             */
/*   Updated: 2017/02/11 18:17:24 by imarakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			shifting(t_math *mth, int key)
{
	int		i;
	int		j;

	i = 0;
	if (key == 125)
		mth->midy -= 10.0;
	if (key == 126)
		mth->midy += 10.0;
	if (key == 123)
		mth->midx -= 10.0;
	if (key == 124)
		mth->midx += 10.0;
	while (i < mth->y)
	{
		j = 0;
		while (j < mth->x)
		{
			if (key == 125 || key == 126)
				mth->my[i][j] += mth->vermove;
			if (key == 123 || key == 124)
				mth->mx[i][j] += mth->hormove;
			j++;
		}
		i++;
	}
}

void			ft_middle(t_math *mth)
{
	int		i;
	int		j;

	i = 0;
	while (i < mth->y)
	{
		j = 0;
		while (j < mth->x)
		{
			mth->mx[i][j] += mth->midx;
			mth->my[i][j] += mth->midy;
			j++;
		}
		i++;
	}
}

void			ft_projection(t_math *mth)
{
	int		i;
	int		j;

	i = 0;
	while (i < mth->y)
	{
		j = 0;
		while (j < mth->x)
		{
			mth->mx[i][j] = (mth->mx[i][j] * sqrt(3) / sqrt(6))
			- (mth->mz[i][j] * sqrt(3) / sqrt(6));
			mth->my[i][j] = mth->mx[i][j] / sqrt(6) + 2 * mth->my[i][j] /
			sqrt(6) + mth->mz[i][j] / sqrt(6);
			j++;
		}
		i++;
	}
}

static void		positive(t_math *mth)
{
	int i;
	int j;

	i = 0;
	while (i < mth->y)
	{
		j = 0;
		while (j < mth->x)
		{
			mth->mx[i][j] -= mth->negx;
			mth->my[i][j] -= mth->negy;
			j++;
		}
		i++;
	}
}

void			ft_positive(t_math *mth)
{
	int		i;
	int		j;

	i = 0;
	mth->negx = mth->mx[0][0];
	mth->negy = mth->my[0][0];
	while (i < mth->y)
	{
		j = 0;
		while (j < mth->x)
		{
			mth->negx > mth->mx[i][j] ? mth->negx = mth->mx[i][j] : 0;
			mth->negy > mth->my[i][j] ? mth->negy = mth->my[i][j] : 0;
			j++;
		}
		i++;
	}
	positive(mth);
}
