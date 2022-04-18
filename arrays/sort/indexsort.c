/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexsort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junehan <junehan.dev@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 11:21:20 by junehan           #+#    #+#             */
/*   Updated: 2022/04/18 12:12:09 by junehan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_array.h"

enum {EMPTY = -1};
void	indexsort(int *arr, size_t n)
{
	if (n < 2)
		return;

	int t;
	int i;
	int	empty_idx;

	t = -1;
	while (++t < (int)n) {
		i = t;
		empty_idx = t;
		while (i < (int)n && arr[i] != t) {
			empty_idx = (arr[i] == EMPTY) ? i : empty_idx;
			i++;
		}
		(i != (int)n) ? swap((arr + t), (arr + i)) : swap((arr + t), (arr + empty_idx));
	}
}

