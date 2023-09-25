/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaito <rnaito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 21:37:00 by rnaito            #+#    #+#             */
/*   Updated: 2023/09/24 21:38:221 by rnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"

int	create_color(t_rgb rgb)
{
	int	color;

	color = (rgb.red << 16) | (rgb.green << 8) | rgb.blue;
	return (color);
}
