/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putstr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-vri <jode-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 03:44:49 by jode-vri          #+#    #+#             */
/*   Updated: 2023/12/06 03:45:07 by jode-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libk.h>

void	putstr(const char *s) {
	while (*s)
		putchar(*s++);
}