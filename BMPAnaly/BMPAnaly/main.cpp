
#define Trace(m) //cout<<(#m)<<"="<<(m)<<endl;
#include<iomanip>
#include<iostream>
#include<fstream>
using namespace std;
#include<windows.h>
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



unsigned char m[128];
bool getBit(unsigned char *str,int p){
	return (str[p/8]&(1<<(8-p)%8))==1;
}
int main(){
	FILE * t=fopen("a.bmp","rd");
	fread((unsigned char *)m,1,128,t);
	for(int i=0;i<32;i++){
		for(int j=0;j<32;j++){
			int row=i;
			int col=j;
			row=32-row;
			if(getBit(m,row*32+col)){
				cout<<'*';
			}else{
				cout<<' ';
			}
		}
		cout<<endl;
	}/**/
	system("pause");
	return 0;
}
