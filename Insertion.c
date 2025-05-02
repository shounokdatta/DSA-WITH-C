#include<stdio.h>
void main(){
	int arr[]={100,12,14,1000,16,20,50,55,34,1},i,j,temp;
	int N=sizeof(arr)/sizeof(arr[0]);
	for(i=0;i<N;i++)
	{
		printf("%d\n",arr[i]);
	}
	for(i=1;i<=N-1;i++)
	{
		temp=arr[i];
		for(j=i-1;j>=0 && arr[j]>temp;j--)
		{
			arr[j+1]=arr[j];
		}
		arr[j+1]=temp;
	}
	for(i=0;i<N;i++)
	{
		printf("%d, ",arr[i]);
	}
}
