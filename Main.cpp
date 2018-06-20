#include <iostream>
#include "Pool.h"
#include <stdio.h>
using namespace std;
//以下仅为示范测试函数，具体使用请用户自便
int main(){
	Pool <int> pool_i;
	Pool<char> pool_c;
	/*------Allocating------*/
	int* test_ptr_i;
	test_ptr_i=pool_i.Alloc(666);//存储int测试
	cout<<"Outputing the first stored integer:"<<*test_ptr_i<<endl;
	char* carray[5];
	for(int i=0;i<5;++i)
	{
		carray[i]=pool_c.Alloc('%');//存储char测试
		printf("Location:%p\n", carray[i]);
		cout<<"Character:"<<*carray[i]<<endl;
	}
	/*------Deleting------*/
	pool_i.Delete(test_ptr_i);

	for(int i=0;i<5;++i)
	{
		pool_c.Delete(carray[i]);
	}
	cout<<"Deleting..."<<endl;
	return 0;
}
