int	subarray_max(int *arr, int size)
{
	int	i;
	int	cur;
	int	max;
	int	end;
//	int	start;

	i = 0;
	end = 0;
	max = 0;
	while (i < size)
		max += *(arr + i++);

	cur = max;
	while (i-- >= 1) {
		cur -= *(arr + i);
		if (max < cur) {
			max = cur;
			end = i;
		}
	}
	
	cur = max;
	while (++i <= end) {
		cur -= *(arr + i);
		if (max < cur) {
			max = cur;
			//start = i;
		}
	}

	return (max);
}

