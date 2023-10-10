/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pixel_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaito <rnaito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 11:42:37 by rnaito            #+#    #+#             */
/*   Updated: 2023/10/10 20:46:49 by rnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "mlx_utils.h"
#include "color.h"
#include "vector.h"
#include "calculator.h"
#include "config.h"	
#include "light.h"
#include "init.h"
#include "src.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int	get_pixel_color(
	t_ray *ray,
	const t_vector3d xyz,
	const t_scene scene)
{
	t_vector3d	normal_vector;

	set_closest_point_info_in_ray(ray, scene);
	if (ray->hit_object_index != NOT_HIT)
	{
		normal_vector
			= scene.objects[ray->hit_object_index]
			.fp_get_normal_vector_for_object(*ray,
				scene.objects[ray->hit_object_index].object);
		set_lighting_ratio(ray, xyz, scene, normal_vector);
		return (scene.objects[ray->hit_object_index]
			.fp_get_pixel_color_for_object(
				scene.objects[ray->hit_object_index].object,
				*ray,
				scene.ambient.lighting_ratio));
	}
	else
		return (BLACK);
}
