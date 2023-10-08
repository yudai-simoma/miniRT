/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pixel_color_for_tube.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naitorino <naitorino@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:06:39 by rnaito            #+#    #+#             */
/*   Updated: 2023/10/06 20:38:41 by naitorino        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "vector.h"
#include "color.h"
#include "object.h"

int	get_pixel_color_for_tube(
	const void *object,
	const t_ray ray,
	const double ambient_lighting_ratio)
{
	t_tube	*tube;

	tube = (t_tube *)object;
	return (get_pixel_color_for_object(tube->color, 
			ray.rgb,
			ambient_lighting_ratio,
			ray.lighting_ratio));
}
