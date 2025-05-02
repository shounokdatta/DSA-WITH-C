#include<stdio.h>
void main(){
	int arr[]={100,12,14,1000,16,20,50,55,34,1},i,j,temp;
	for(i=0;i<(sizeof(arr)/sizeof(arr[0]));i++)
	{
		printf("%d\n",arr[i]);
	}
	for(i=0;i<((sizeof(arr)/sizeof(arr[0]))-1);i++)
	{
		for(j=0;j<((sizeof(arr)/sizeof(arr[0]))-i-1);j++)
		{
			if(arr[j]>arr[j+1]){
			temp=arr[j];
			arr[j]=arr[j+1];
			arr[j+1]=temp;
			}
		}
	}
	for(i=0;i<(sizeof(arr)/sizeof(arr[0]));i++)
	{
		printf("%d, ",arr[i]);
	}
}
