#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<ctime>

using namespace std;

int main(){
	srand(unsigned(time(0)));
	cout<<"序列号:";
	char a;
	for(int i=0;i<8;i++){
		a=rand()%0x100;
		if(a<0x10){
			printf("0%x",a);
		}else{
			printf("%x",a);
		}
		if(i!=7){
			printf("-");
		}else{
			printf("\n");
		}
	}
	cout<<"密钥:";
	for(int i=0;i<8;i++){
		a=rand()%0x100;
		if(a<0x10){
			printf("0%x",a);
		}else{
			printf("%x",a);
		}
	}
	cout<<endl;
	return 0;
}
