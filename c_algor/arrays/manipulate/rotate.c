/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junehan <junehan.dev@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 23:14:56 by junehan           #+#    #+#             */
/*   Updated: 2022/04/05 23:49:42 by junehan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_array.h"

void	rotate(int *arr, size_t size, int n)
{
	n %= size;
	reverse(arr, 0, n - 1);
	reverse(arr, n, size - 1);
	reverse(arr, 0, size - 1);
}


