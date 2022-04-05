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
