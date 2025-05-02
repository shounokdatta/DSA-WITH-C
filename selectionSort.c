#include<stdio.h>
void main(){
	int arr[]={100,12,14,1000,16,20,50,55,34,1},i,j,temp,N,min;
	N=sizeof(arr)/sizeof(arr[0]);
	for(i=0;i<N;i++)
	{
		printf("%d\n",arr[i]);
	}
	for(i=0;i<N-1;i++)
	{
		min=i;
		for(j=0;j<N-i-1;j++)
		{
			if(arr[j]<arr[min])
			{
				min=j;
			}
			if(min!=i)
			{
				temp=arr[j];
				arr[j]=arr[min];
				arr[min]=temp;
			}
		}
	}
	for(i=0;i<N;i++)
	{
		printf("\n%d, ",arr[i]);
	}
}
