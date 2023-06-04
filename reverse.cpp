#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<ctime>
using namespace std;

char cth(char a,char b){
	char x=0;
	if(a>='0'&&a<='9'){
		x+=(a-'0')*16;
	}else if(a>='a'&&a<='f'){
		x+=(a-'a'+10)*16;
	}
	if(b>='0'&&b<='9'){
		x+=b-'0';
	}else if(b>='a'&&b<='f'){
		x+=b-'a'+10;
	}
	return x;
}

char x[16];
char a[8];
char p;
int main(){
	cout<<"请输入序列号:";
	for(int i=0;i<16;i+=2){
		cin>>x[i];
		cin>>x[i+1];
		a[i/2]=cth(x[i],x[i+1]);
		if(i!=14){
			cin>>p;
		}
	}
	unsigned s=unsigned(time(0));
	bool flag;
	cout<<endl<<"查找中..."<<endl;
	while(s--){
		flag=true;
		srand(s);
		for(int i=0;i<8;i++){
			if(rand()%0x100!=a[i]){
				flag=false;
				break;
			}
		}
		if(flag){
			cout<<endl<<"seed="<<s<<endl<<"密钥:";
			for(int i=0;i<8;i++){
				p=rand()%0x100;
				if(p<0x10){
					printf("0%x",p);
				}else{
					printf("%x",p);
				}
			}
			getchar();
			return 0;
		}
	}
	cout<<"查找失败。"<<endl;
	getchar();
	return 0;
}
