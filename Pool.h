#ifndef POOL_H
#define POOL_H
#include <iostream>
#include "Block.h"

template<class T>
class Pool
{
public:	
	Pool<T>(){
		L = new List <T>;
		head = new Block <T> (L);
		tail = head;
		totalblock = 1;
		usedblock = 0;
	}

	~Pool(){
		Block <T> *i = head, *j = head->Next();
		do{
			i->~Block();
			i = j;
		}while(j = j->Next());
		tail->~Block();
		L->~List();
	}
	
	T* Alloc(){//用户用于预申请存储空间的函数
		Block<T>* cursor = head;
		while (!cursor->Freespace())
		{
			cursor = cursor->Next();
			if (cursor == NULL)
			{
				this->Expand();
			}
		}
		Node<T>* rec = cursor->First();
		return &(rec->data);
	}
	
	T* Alloc(T info)//用户用于存储某数值的函数（不支持数组等允许指针遍历的数据类型）
	{
		Block<T>* cursor = head;
		while (!cursor->Freespace())
		{
			cursor = cursor->Next();
			if (cursor == NULL)
			{
				this->Expand();
			}
		}
		Node<T>* rec = cursor->First();
		rec->data = info;
		return &(rec->data);
	}
	bool Delete(T *p){//用户用于删除所存储数据的函数
		Block <T> *i = head;
		bool isfound = false;
		while(!isfound && i->Next()){
			isfound = i->Remove(p);
			i = i->Next();
		}
		if(!isfound && !i->Next()){
			isfound = i->Remove(p);
		}
		if(!isfound){
			return false;
		}
		return true;
	}
	
protected:
	Block <T> *head;
	Block <T> *tail;
	List <T> *L;
	unsigned int totalblock;
	unsigned int usedblock;

private:
	void Expand()//当内存池不够大时用于扩大内存池
	{
		Block <T> * p = tail->Next();
		p = new Block<T>(L);
		tail = tail->Next();
	}
};
#endif
