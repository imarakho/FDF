/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imarakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 17:40:46 by imarakho          #+#    #+#             */
/*   Updated: 2017/03/08 17:20:53 by imarakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		key_func(int key, void *par)
{
	t_math	*mth;

	mth = (t_math *)par;
	mth->key = key;
	if (key == 7 || key == 16 || key == 6 || (key >= 123 && key <= 126)
		|| key == 24 || key == 27 || key == 116 || key == 121 ||
		key == 50 || key == 32 || key == 8 || (key <= 20 && key >= 18))
		ft_image(mth);
	
	if (key == 53)
	{
		printf("Exit program\n");
		exit(1);
	}
	return (0);
}

void	check_key(t_math *mth, int key)
{
	key == 124 ? mth->hormove += 5.0 : 0;
	key == 123 ? mth->hormove -= 5.0 : 0;
	key == 126 ? mth->vermove += 5.0 : 0;
	key == 125 ? mth->vermove -= 5.0 : 0;
	key == 121 ? mth->pzoom -= 0.5 : 0;
	key == 8 ? mth->anglex -= GR * 5 : 0;
	key == 32 ? mth->angley -= GR * 5 : 0;
	key == 50 ? mth->anglez -= GR * 5 : 0;
	key == 6 ? mth->anglez += GR * 5 : 0;
	key == 7 ? mth->anglex += GR * 5 : 0;
	key == 16 ? mth->angley += GR * 5 : 0;
	key == 24 ? mth->plsz += 0.5 : 0;
	key == 27 ? mth->plsz -= 0.5 : 0;
	key == 116 ? mth->pzoom += 0.5 : 0;
}

void	ft_image(t_math *mth)
{
	int a;

	check_key(mth, mth->key);
	ft_trans_cords(mth);
	ft_shift(mth);
	cords_to_zero(mth);
	ft_plus_z(mth);
    ft_minus_z(mth);
	turn_z(mth);
	turn_x(mth);
	turn_y(mth);
	plus_zoom(mth);
	minus_zoom(mth);
	ft_plus_z(mth);
	ft_minus_z(mth);
	ft_projection(mth);
	ft_positive(mth);
	cords_to_midle(mth);
	shifting(mth, mth->key);
	ft_zero(mth);
	mth->img = mlx_new_image(mth->mlx, mth->wsize, mth->wsize);
	ft_draw_all(mth->mx, mth->my, mth);
	a = mlx_put_image_to_window(mth->mlx, mth->win, mth->img, 0, 0);
	mlx_destroy_image(mth->mlx, mth->img);
}

int		main(int argc, char **argv)
{
	t_math	mth;
	int		a;

	if (argc != 2)
	{
		ft_putstr("Wrong number of arguments!\n");
		exit(1);
	}
	mth.filename = ft_strdup(argv[1]);
	mth.wsize = 1000;
	ft_math(&mth);
	mth.mlx = mlx_init();
	mth.win = mlx_new_window(mth.mlx, mth.wsize, mth.wsize, "fdf");
	mth.img = mlx_new_image(mth.mlx, mth.wsize, mth.wsize);
	ft_draw_all(mth.mx, mth.my, &mth);
	a = mlx_put_image_to_window(mth.mlx, mth.win, mth.img, 0, 0);
	mlx_destroy_image(mth.mlx, mth.img);
	mlx_hook(mth.win,2, 0, key_func, &mth);
	mlx_loop(mth.mlx);
	return (0);
}
