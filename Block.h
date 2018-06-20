#ifndef BLOCK_H
#define BLOCK_H
#define SIZE 16
#include <iostream>
#include "List.h"
using namespace std;

template<class T>
class Block//默认包含16个Node 
{
	public:
		Block(List <T> *l):L(l),next(NULL),free(SIZE){
			Node <T> *p = L->Apply(SIZE);
			first = p;
			int i;
			for(i = 0; i < SIZE; i++){
				pnode.Push_back(p++);
			}
		}
		
		~Block(){
			Node <Node <T> *> *i, *p;
			for(i = pnode.Front(); i != pnode.Back(); i = i->next){
				p = i;
				Return(p);
			}
			first = NULL;
		}
		
		Node<T>* First(){//返回第一个空闲节点
			if(Freespace()){	
				Node <T> *p = first;
				first = first->next;
				free--;
				return p;
			}
			else {
				return NULL;
			}
		}
		
		bool Remove(T *p){//从Block中移除指针p
			Node <Node <T> *> *i;
			for(i = pnode.Front(); i != pnode.Back(); i = i->next){
				if(&((i->data)->data) == p){
					Return(i);
					return true;
				}
			}
			return false;
		}
		
		int Freespace(){//返回当前Block的空闲节点数
			return free;
		}
		
		Block <T> * Next(){//返回当前Block的下一个Block的指针
			return next;
		}
		
	protected:
		List <T> *L;
		List <Node<T>*> pnode;
		Node <T> *first;
		Block <T> *next;
		int free;

	private:
		void Return(Node <Node <T> *> *i){//将某节点设定为空闲
			i->data->data = 0;
			pnode.Push_back(i->data);
			L->Push_back(i->data);
			pnode.Delete(i);
		}

		Node <T> * Search(T *p){//在当前Block中搜寻指针p
			Node <T> *i;
			for(i = first; i->next; i = i->next){
				if(&(i->data) == p){
					return i;
				}
			}
			return NULL;
		}
		
};
#endif
