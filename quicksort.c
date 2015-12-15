#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include<time.h>

int RandomInRange(int start,int end){
	srand(time(NULL));
	return start+rand()%(end-start+1);
}
void Swap(int *a,int *b){
	int temp=*a;
	*a=*b;
	*b=temp;
}
int Partition(int sequence[],int length,int start,int end){
	int small=start-1;
	int index=RandomInRange(start,end);
	Swap(&sequence[index],&sequence[end]);
	for(index=start;index<end;index++){
		if(sequence[index]<sequence[end]){
			small++;
			if(small!=index)
				Swap(&sequence[small],&sequence[index]);
		}
	}
	small++;
	Swap(&sequence[small],&sequence[end]);
	return small;
}
void QuickSort(int sequence[],int length,int start,int end){
	int middle;
	if(end==start)
		return;
	middle=Partition(sequence,length,start,end);
	if(middle>start)
		QuickSort(sequence,length,start,middle-1);
	if(middle<end)
		QuickSort(sequence,length,middle+1,end);
}
int main(){
	int i=0;
	int data[]={8,3,6,9,2,7,1,4,0,5};
	QuickSort(data,10,0,9);
	for(i=0;i<10;++i)
		printf("%d ", data[i]);
	printf("\n");
	return 0;
}
