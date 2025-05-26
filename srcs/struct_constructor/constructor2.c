/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructor2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktintim- <ktintim-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 10:17:36 by ktintim-          #+#    #+#             */
/*   Updated: 2025/05/26 15:01:21 by ktintim-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	key_constructor(t_key *key)
{
	key->w = false;
	key->s = false;
	key->a = false;
	key->d = false;
	key->left = false;
	key->right = false;
}
