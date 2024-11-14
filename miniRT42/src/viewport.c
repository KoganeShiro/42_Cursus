/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewport.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:35:52 by cejin             #+#    #+#             */
/*   Updated: 2024/11/12 16:35:55 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/minirt.h"

// CREATE VIEWPORT
// cross product for the up-y and right-x (produit vectoriel)
// cross product of dir of camera with tmp_up-y
// right-x = normalize (vect --> length == 1)	
// cross product of dir of camera with right-x
// up-y = normalize
// calcule distance	
// convert plan to camera as origin pixel by pixel

void	create_viewport(t_graphics *rt)
{
	rt->viewport->dist_view_cam = 1.
		/ (tanf(((M_PI * rt->camera->fov) / 360.)));
	cross_product(&rt->viewport->view_x,
		&rt->camera->direction, &((t_vec3){0., 1., 0.}));
	cross_product(&rt->viewport->view_y,
		&rt->camera->direction, &rt->viewport->view_x);
	normalized(&rt->viewport->view_x);
	normalized(&rt->viewport->view_y);
}
