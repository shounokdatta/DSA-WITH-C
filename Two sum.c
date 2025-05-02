#include<stdio.h>
#include<math.h>
void main(){
	int nums[]={3,2,4},returnSize;
	int numsSize,target=6,i,j;
	numsSize=(sizeof(nums)/sizeof(nums[0]));
    for(i=0;i<numsSize;i++){
        for(j=i+1;j<numsSize;j++){
            if(target==(nums[i]+nums[j]))
           {
    			 printf("%d %d",i,j);
           }
        }
    }
}
