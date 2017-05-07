/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imarakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 18:09:51 by imarakho          #+#    #+#             */
/*   Updated: 2017/02/12 12:57:33 by imarakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		turn_z(t_math *mth)
{
	int i;
	int j;

	i = 0;
	if (mth->angley == 0)
		return ;
	cords_to_zero(mth);
	while (i < mth->y)
	{
		j = 0;
		while (j < mth->x)
		{
			mth->mx[i][j] = mth->mx[i][j] * cos(mth->anglez) +
			mth->my[i][j] * sin(mth->anglez);
			mth->my[i][j] = mth->my[i][j] * cos(mth->anglez) -
			mth->mx[i][j] * sin(mth->anglez);
			j++;
		}
		i++;
	}
	cords_to_midle(mth);
}

double		**find_cord_z(int **m, t_math *mth)
{
	int		i;
	int		j;
	double	**resz;

	resz = ft_arr_memalloc(mth);
	i = 0;
	j = 0;
	while (i < mth->y)
	{
		j = 0;
		while (j < mth->x)
		{
			resz[i][j] = m[i][j];
			j++;
		}
		resz[i][j] = '\0';
		i++;
	}
	resz[i] = NULL;
	return (resz);
}

void		turn_x(t_math *mth)
{
	int i;
	int j;

	i = 0;
	if (mth->anglex == 0)
		return ;
	cords_to_zero(mth);
	while (i < mth->y)
	{
		j = 0;
		while (j < mth->x)
		{
			mth->mx[i][j] = mth->mx[i][j] * cos(mth->anglex) -
			mth->my[i][j] * sin(mth->anglex);
			j++;
		}
		i++;
	}
	cords_to_midle(mth);
}

void		turn_y(t_math *mth)
{
	int i;
	int j;

	i = 0;
	if (mth->angley == 0)
		return ;
	cords_to_zero(mth);
	while (i < mth->y)
	{
		j = 0;
		while (j < mth->x)
		{
			mth->my[i][j] = mth->mx[i][j] * sin(mth->angley)
			+ mth->my[i][j] * cos(mth->angley);
			j++;
		}
		i++;
	}
	cords_to_midle(mth);
}
