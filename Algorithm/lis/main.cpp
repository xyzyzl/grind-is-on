int lis(void) {
	int arr[N];
	for(int i = 0; i < N; i++){
		scanf("%d", &arr[i]);
	}
	int longest[N+1]; //longest with N numbers
	for(int i = 0; i < N; i++){
		longest[i] = 1;
	}
	longest[N] = 1; // longest[N] will be the max, I wanted to keep compact
	for(int i = 1; i < N; i++){
		for(int j = 0; j < i; j++){
			if(arr[j] < arr[i] && longest[i] <= longest[j]){
				longest[i] = max(longest[j] + 1, longest[i]);
				// printf("%d\n", i);
				if(longest[i] >= longest[N]){
					longest[N] = longest[i];
				}
			}
		}
	}
	return longest[N];
}


