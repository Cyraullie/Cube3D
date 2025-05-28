/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktintim- <ktintim-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 13:50:46 by cgoldens          #+#    #+#             */
/*   Updated: 2025/05/28 11:02:01 by ktintim-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../minilibx/mlx.h"
# include "structs.h"
# include "functions.h"
# include "../libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# define _USE_MATH_DEFINES
# include <math.h>

# define PIXEL 64

# define NORTH 270.0
# define EAST 0.0
# define SOUTH 90.0
# define WEST 180.0

# define VIEW_SPEED 3
# define MOOVE_SPPED 5

# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif

# define KEY_W        119
# define KEY_A        97
# define KEY_S        115
# define KEY_D        100

# define KEY_UP       65362
# define KEY_DOWN     65364
# define KEY_LEFT     65361
# define KEY_RIGHT    65363

# define KEY_ESC      65307
# define KEY_SPACE    32

# define MAX_DATA 6

#endif