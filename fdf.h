/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imarakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 15:31:13 by imarakho          #+#    #+#             */
/*   Updated: 2017/02/15 14:48:22 by imarakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include <mlx.h>
# include "get_next_line.h"
# include "libft/libft.h"
# define GR 3.1415926/360

typedef struct		s_math
{
	int				drx;
	int				dry;
	int				key;
	int				i;
	int				j;
	double			vermove;
	double			hormove;
	double			midy;
	double			midx;
	double			plsz;
	double			minz;
	int				fd;
	void			*mlx;
	void			*win;
	void			*img;
	char			*imbuf;
	int				bpp;
	double			shiftx;
	double			shifty;
	int				sizeline;
	int				endian;
	int				x;
	int				y;
	int				bgr[3];
	double			dx;
	double			dy;
	char			**arr;
	char			*filename;
	double			**mx;
	double			**my;
	double			**mz;
	double			**sz;
	double			mult;
	int				pix;
	double			chx;
	double			chy;
	double			chz;
	double			anglez;
	double			anglex;
	double			angley;
	double			size;
	double			wsize;
	double			shift;
	double			negx;
	double			negy;
	double			pzoom;
	double			mzoom;
	double			x1;
	double			y1;
}					t_math;

void				ft_colrowcheck(char *filename);
void				ft_firstcheck(char *str);
void				ft_zero(t_math *mth);
void				ft_middle(t_math *mth);
void				plus_zoom(t_math *mth);
void				minus_zoom(t_math *mth);
void				ft_plus_z(t_math *mth);
void				ft_minus_z(t_math *mth);
void				shifting(t_math *mth, int key);
void				cords_to_midle(t_math *mth);
void				ft_image(t_math *mth);
double				**ft_arr_memalloc(t_math *mth);
void				ft_trans_cords(t_math *mth);
void				ft_math(t_math *mth);
void				ft_positive(t_math *mth);
void				ft_shift(t_math *mth);
void				ft_projection(t_math *mth);
void				cords_size(t_math *mth);
void				turn_x(t_math *mth);
void				turn_y(t_math *mth);
void				turn_z(t_math *mth);
void				cords_to_zero(t_math *mth);
void				ft_draw_all(double **x, double **y, t_math *mth);
double				**find_cord_z(int **m, t_math *mth);
int					**return_matrix(t_math *mth);
char				**ft_readbuf(t_math *mth);

#endif
