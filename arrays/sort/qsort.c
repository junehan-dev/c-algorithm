/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qsort.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junehan <junehan.dev@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 11:12:43 by junehan           #+#    #+#             */
/*   Updated: 2022/04/16 12:04:17 by junehan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_array.h"

void	qsort_dfs(int *arr, int left, int right);
void	qsort(int *arr, size_t n)
{
	qsort_dfs(arr, 0, n - 1);
}

void	qsort_dfs(int *arr, int left, int right)
{
	int cur;
	int last;

	swap((arr + left), (arr + (left + right) / 2));
	last = left;
	cur = left + 1;
	while (cur < right + 1) {
		if (arr[left] > arr[cur]) {
			last++;
			swap((arr + last), (arr + cur));
		}
		cur++;
	}
	swap((arr + last), (arr + left));
	if ((last - left) > 1)
		qsort_dfs(arr, left, last - 1);
	if ((right - last) > 1)
		qsort_dfs(arr, last + 1, right);
}

