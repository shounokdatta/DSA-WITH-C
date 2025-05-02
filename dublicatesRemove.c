int removeDuplicates(int* nums, int numsSize) {
    int i,j,e,k=numsSize;
    for(i=0;i<numsSize;i++)
    {
        for(j=i+1;j<numsSize;j++){
            if(nums[i]==nums[j])
            {
				for(e=j;e<numsSize;e++)
				{
                	nums[e]=nums[e+1];
            	}
                	k--;
            }
        }
    }
    printf("arry size-->%d\n",k);
    for (i=0;i<numsSize;i++)
    {
    	printf("%d\n",nums[i]);
	}
    // return &nums;
    return k;
}
void main(){
	int nums[]={1,1,2}; // Input array
	int expectedNums[]= {1,2}; // The expected answer with correct length
	int k =	removeDuplicates(nums,(sizeof(nums)/sizeof(nums[0]))); // Calls your implementation
//	printf("%d\n",k);
//	 if(k == sizeof(expectedNums)/sizeof(expectedNums[0])) printf("true\n"); else printf("false\n");
	int i;
	for (i = 0; i < k; i++) {
//    assert nums[i] == expectedNums[i];
//    printf("-->%d, ",nums[i]);
}
}
