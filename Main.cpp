#include <iostream>
#include "Pool.h"
using namespace std;

int main(){
	Pool <int> pool;
	int a;
	cin >> a;
	int *i = pool.Alloc(a);
	pool.Delete(i);
	return 0;
}
