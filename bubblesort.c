#include<stdio.h>
int bubbleSort(int arr[5],int n)
{
	int i,j,temp,flag;
	for(i=0;i<(n-1);i++)
	{
		for(j=0;j<(n-1-i);j++)
		{
			flag=0;
			if(arr[j]>arr[j+1]){
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=arr[j];
				flag=1;
			}
		}
		if(flag==0)
		break;
	}
	return arr[5];
}
void main(){
	int i;
	int arr[5]={15,16,6,8,5};
	for(i=0;i<5;i++)
	{
		printf("%d, ",arr[i]);
	}
	bubble(arr[5],5);
	for(i=0;i<5;i++)
	{
		printf("%d, ",arr[i]);
	}
}
