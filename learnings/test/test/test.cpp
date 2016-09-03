// test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	int i=0;
	i++;//1
	cout<<((++i)++)<<endl;//4
	cout<<i<<endl;//3
	system("pause");
	return 0;
}

