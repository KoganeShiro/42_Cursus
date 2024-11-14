/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:41:10 by cejin             #+#    #+#             */
/*   Updated: 2024/11/14 10:00:22 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../include/minirt.h"

bool	has_right_args_nb(char **tab, int args_nb)
{
	int	i;

	i = 0;
	while (tab[i] != NULL
		&& tab[i][0] != '\n')
	{
		i++;
	}
	if (i != args_nb)
		return (false);
	return (true);
}

bool	is_right_value(char *value, bool plus_flag,
			bool minus_flag, bool dot_flag)
{
	int		i;

	if (value[0] == '+')
		plus_flag = true;
	else if (value[0] == '-')
		minus_flag = true;
	else if (value[0] == '.'
		|| ((is_nb(value[0]) == false)
			|| ft_strlen(value) > 10))
		return (false);
	i = 1;
	while (value[i] != '\0')
	{
		if ((plus_flag == true || minus_flag == true)
			&& (value[i] == '+' || value[i] == '-'))
			return (false);
		if (dot_flag == true && value[i] == '.')
			return (false);
		if (value[i] == '.')
			dot_flag = true;
		else if (is_nb(value[i]) == false && value[i] != '\n')
			return (false);
		i++;
	}
	return (true);
}

//Scale coordinate [-1 to 1]
void	scale_viewport_to_canva(t_graphics *rt,
			t_vec3 *x_ray, t_vec3 *y_ray, char coord)
{
	const float	aspect_ratio = (float)rt->viewport->vw
		/ (float)rt->viewport->vh;
	float		center_to_zero;
	float		scaling;

	if (coord == 'x')
	{
		center_to_zero = 2.0 * rt->canva_x - rt->viewport->vw;
		scaling = center_to_zero / rt->viewport->vw;
		vec3_mult_by_val_to(x_ray,
			&rt->viewport->view_x, aspect_ratio * scaling);
	}
	else if (coord == 'y')
	{
		center_to_zero = 2.0 * rt->canva_y - rt->viewport->vh;
		scaling = center_to_zero / rt->viewport->vh;
		vec3_mult_by_val_to(y_ray,
			&rt->viewport->view_y, scaling);
	}
}

t_vec3	*conv_struct_color_to_vec3(t_vec3 *dest, t_color *color)
{
	dest->x = color->r;
	dest->y = color->g;
	dest->z = color->b;
	return (dest);
}

t_color	*conv_struc_vec3_to_color(t_color *dest, t_vec3 *vec)
{
	dest->r = vec->x;
	dest->g = vec->y;
	dest->b = vec->z;
	return (dest);
}
