#include<iostream>
#include<algorithm>

using namespace std;

void Adjustdown(int heap[],int index,int size){
	if(index*2<=size){
		int min=index,lchild=index*2,rchild=index*2+1;
		if(lchild<=size&&heap[lchild]<heap[min])
			min=lchild;
		if(rchild<=size&&heap[rchild]<heap[min])
			min=rchild;
		if(min!=index){
			swap(heap[index],heap[min]);
			Adjustdown(heap,min,size);
		}
	}
}

void BuildHeap(int heap[],int size){
	for(int i=size/2;i>=1;i--){
		Adjustdown(heap,i,size);
	}
}

void HeapSort(int heap[],int size){
	BuildHeap(heap,size);
	for(;size>1;){
		swap(heap[1],heap[size]);
		Adjustdown(heap,1,--size);
	}
}

int main(){
	int heap[]={0,1,2,3,4,5,6,7,8,9};
	HeapSort(heap,9);
	for(int i=1;i<10;i++)
		cout<<heap[i]<<" ";
	cout<<endl;
	return 0;
}
