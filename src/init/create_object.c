/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_object.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 15:04:01 by yshimoma          #+#    #+#             */
/*   Updated: 2023/10/22 20:29:36 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"

t_object	create_object(
	const void *object,
	double (*fp_hit_object)(const t_ray, const void *),
	t_vector3d (*fp_get_normal_vector_for_object)(const t_ray, const void *),
	int (*fp_get_pixel_color_for_object)(const void *, const t_ray))
{
	t_object	ret;

	ret.object = (void *)object;
	ret.fp_hit_object = fp_hit_object;
	ret.fp_get_normal_vector_for_object = fp_get_normal_vector_for_object;
	ret.fp_get_pixel_color_for_object = fp_get_pixel_color_for_object;
	return (ret);
}
