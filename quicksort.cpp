#include<iostream>
#include<time.h>
using namespace std;
int RandomInRange(int start,int end){
	srand(time(NULL));
	return start+rand()%(end-start);
}
void Swap(int *a,int *b){
	int temp=*a;
	*a=*b;
	*b=temp;
}
int Partition(int sequence[],int length,int start,int end
	if(length<0||start<0||length<=0||end>=length)
		cout<<"error!"<<endl;
	exit(0);
	int index=RandomInRange(start,end);
	swap(sequence[index],sequence[end]);
	int small=start-1;
	for(index=start,index<end,index++){
		if(sequence[index]<sequence[end]){
			small++;
			if(small!=index)
				swap(sequence[small],sequence[index]);
		}
	}
	small++;
	swap(ssequence[small],sequence[end]);
	return small;
}
int QuickSort(int sequence[],int length,int start,int end){
	if(end==start)//if((end<start)||(length<0))
		return;				//	return -1;
	int middle=Partition(sequence,length,start,end);
	if(middle>start)
		QuickSort(sequence[],length,start,middle-1);//	QuickSort(sequence[],length,start,middle);
	if(middle<end)
		Quicksort(sequence[],length,middle+1,end);//	Quicksort(sequence[],length,middle,end);
}
int main(void){
int data[]={8,3,6,9,2,7,1,4,0,5};
QuickSort(data,10,0,9);
for(int i=0,i<10,++i)
	cout<<data[i]<<" ";
cout<<endl;
return 0;
}
