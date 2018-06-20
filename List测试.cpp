#include<iostream>
#include "List.h"
#include "Node.h"
using namespace std;

int main()
{
	List<int> l;
	for(int i=1;i<99;++i)
	{
		l.push_back(i);
	}
	Node<int>* p=l.gethead();
	for(;p!=l.gettail();p=p->next)
	{
		cout<<p->data<<endl;
	}
	return 0;
}
