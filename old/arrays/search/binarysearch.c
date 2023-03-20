/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binarysearch.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junehan <junehan.dev@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 01:42:40 by junehan           #+#    #+#             */
/*   Updated: 2022/04/09 01:42:41 by junehan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	binarysearch(int arr[], int size, int value)
{
	int	h;
	int	l;
	int	mid;

	l = 0;
	h = size - 1;
	mid	= h / 2;

	while (l < h) {
		if (arr[mid] == value)
			return mid;
		else if (arr[mid] > value)
			h = mid - 1;
		else
			l = mid + 1;
		mid = (l + h) / 2;
	}

	mid = arr[mid] == value ? mid : -1;

	return (mid);
}
