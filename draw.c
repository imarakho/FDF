/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imarakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 15:44:28 by imarakho          #+#    #+#             */
/*   Updated: 2017/02/13 20:19:37 by imarakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		*ft_color2(t_math *mth)
{
	if (mth->sz[mth->i][mth->j] < 0)
	{
		mth->bgr[0] = 240;
		mth->bgr[1] = 32;
		mth->bgr[2] = 160;
	}
	else if (mth->sz[mth->i][mth->j] > 0 && mth->sz[mth->i][mth->j] <= 5.0)
	{
		mth->bgr[0] = 255;
		mth->bgr[1] = 191;
		mth->bgr[2] = 1;
	}
	else if (mth->sz[mth->i][mth->j] > 5.0 && mth->sz[mth->i][mth->j] <= 20.0)
	{
		mth->bgr[0] = 1;
		mth->bgr[1] = 255;
		mth->bgr[2] = 1;
	}
	else if (mth->sz[mth->i][mth->j] > 20.0 && mth->sz[mth->i][mth->j] <= 50.0)
	{
		mth->bgr[0] = 255;
		mth->bgr[1] = 1;
		mth->bgr[2] = 1;
	}
	return (mth->bgr);
}

int		*ft_color(t_math *mth)
{
	if (mth->key == 18)
	{
		mth->bgr[0] = 255;
		mth->bgr[1] = 0;
		mth->bgr[2] = 0;
		return (mth->bgr);
	}
	else if (mth->key == 19)
	{
		mth->bgr[0] = 0;
		mth->bgr[1] = 255;
		mth->bgr[2] = 0;
		return (mth->bgr);
	}
	else if (mth->key == 20)
	{
		mth->bgr[0] = 0;
		mth->bgr[1] = 0;
		mth->bgr[2] = 255;
		return (mth->bgr);
	}
	else
		return (ft_color2(mth));
	return (mth->bgr);
}

void	ft_draw_pixel(int x, int y, int *bgr, t_math *mth)
{
	int		a;

	if (x <= 0 || y <= 0 || x >= mth->wsize || y >= mth->wsize)
		return ;
	if (mth->sz[mth->i][mth->j] == 0 && mth->key != 18
		&& mth->key != 19 && mth->key != 20)
	{
		mth->bgr[0] = 255;
		mth->bgr[1] = 255;
		mth->bgr[2] = 255;
	}
	mth->bpp = 0;
	mth->sizeline = 0;
	mth->endian = 0;
	mth->imbuf = mlx_get_data_addr(mth->img, &mth->bpp,
	&mth->sizeline, &mth->endian);
	a = (y * mth->sizeline / 4 + x) * 4;
	mth->imbuf[a] = bgr[0];
	mth->imbuf[a + 1] = bgr[1];
	mth->imbuf[a + 2] = bgr[2];
}

void	ft_draw_line(int x1, int y1, t_math *mth)
{
	int		er;
	int		signx;
	int		signy;

	signx = mth->drx < x1 ? 1 : -1;
	signy = mth->dry < y1 ? 1 : -1;
	mth->dx = abs(x1 - mth->drx);
	mth->dy = abs(y1 - mth->dry);
	er = mth->dx - mth->dy;
	ft_draw_pixel(x1, y1, ft_color(mth), mth);
	while (mth->drx != x1 || mth->dry != y1)
	{
		ft_draw_pixel(mth->drx, mth->dry, ft_color(mth), mth);
		mth->endian = er * 2;
		if (mth->endian > -mth->dy)
		{
			er -= mth->dy;
			mth->drx += signx;
		}
		if (mth->endian < mth->dx)
		{
			er += mth->dx;
			mth->dry += signy;
		}
	}
}

void	ft_draw_all(double **x, double **y, t_math *mth)
{
	int i;
	int j;

	i = -1;
	while (++i < mth->y)
	{
		j = -1;
		while (++j < mth->x)
		{
			mth->i = i;
			mth->j = j;
			if (x[i][j + 1] && y[i][j + 1])
			{
				mth->drx = (int)x[i][j];
				mth->dry = (int)y[i][j];
				ft_draw_line((int)x[i][j + 1], (int)y[i][j + 1], mth);
			}
			if (i < mth->y - 1)
			{
				mth->drx = (int)x[i][j];
				mth->dry = (int)y[i][j];
				ft_draw_line((int)x[i + 1][j], (int)y[i + 1][j], mth);
			}
		}
	}
}
