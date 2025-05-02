#include<stdio.h>
void main(){
	int arr[]={1,12,14,16,20,34,50,55,100,1000},i,j,temp;
	int N=sizeof(arr)/sizeof(arr[0]);
	int l,r,mid;
	l=0;
	r=N-1;
	printf("Enter your data want to find ");
	scanf("%d",&temp);
	while(l<=r){
	mid=(l+r)/2;
	if(temp==arr[mid])
	{
		printf("your value at %d index",mid+1);
		break;
	}
	else if(temp>arr[mid])
	{
		l=mid+1;
	}
	else{
		r=mid-1;
	}
//	printf("%d %d",l,r);
//	break;
}
printf("value not found in array");

}
