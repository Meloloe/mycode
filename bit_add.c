#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

int bit_add(int a, int b){
	return (a&b)==0 ? a^b : bit_add(a^b, (a&b)<<1);
}

int main(){
	int a, b, c;
	printf("input two numbers:\n");
	scanf("%d %d",&a, &b);
	c=bit_add(a, b);
	printf("sum:%d\n",c);
	return 0;
}