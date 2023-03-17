// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int count = 0;
	for (int i = 0; i < len - 1; i++) {
		for (int j = i + 1; j < len; j++) {
			if (arr[i] + arr[j] == value)
				count++;
		}
	}
	return count;
}
int countPairs2(int *arr, int len, int value) {
  int count = 0;
	for (int i = 0; i < len; i++) {
		for (int j = len - 1; j > i; j--) {
			if (arr[i] + arr[j] == value)
				count++;
		}
	}
	return count;
}
int countPairs3(int *arr, int len, int value) {
  int count = 0;
    for (int i = 0; i < (len - 1); i++) {
        int start = i;
        int stop = len - 1;
        while (start < stop) {
            int mid = (start + stop) / 2;
            if (arr[i] + arr[mid] == value) {
                count++;
                for (int j = mid + 1; (j < stop) && (arr[i] + arr[j] == value); j++) {
                    count++;
                }
                for (int j = mid - 1; (j > start) && (arr[i] + arr[j] == value); j--) {
                    count++;
                }
                break;
            }
            if (arr[i] + arr[mid] > value) stop = i;
            else 
				start = mid;
        }
    }
    return count;
}
