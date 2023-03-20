/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_min.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junehan <junehan.dev@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 11:06:38 by junehan           #+#    #+#             */
/*   Updated: 2022/04/25 11:20:36 by junehan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_array.h"

int		find_min(int *arr, size_t n)
{
	int ret;

	ret = *arr;
	while (n)
		ret = ret > *(arr + --n) ? *(arr + n) : ret;

	return (ret);
}

