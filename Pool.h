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
	
	T* Alloc(){//�û�����Ԥ����洢�ռ�ĺ���
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
	
	T* Alloc(T info)//�û����ڴ洢ĳ��ֵ�ĺ�������֧�����������ָ��������������ͣ�
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
	bool Delete(T *p){//�û�����ɾ�����洢���ݵĺ���
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
	void Expand()//���ڴ�ز�����ʱ���������ڴ��
	{
		Block <T> * p = tail->Next();
		p = new Block<T>(L);
		tail = tail->Next();
	}
};
#endif
