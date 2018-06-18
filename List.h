#ifndef LIST_H
#define LIST_H
#include <iostream>
#include "Node.h"
template <class T> 
class List
{
public:
	List<T>()
	{
		head=NULL;
		tail=NULL;
	}
	
	List<T>(const T* pT,int size)
	{
		head=new Node<T>;
		tail=head;
		head->data=0;
		for(int i=1;i<size;++i)
		{
			Node<T>* p=tail;
			tail->next=new Node<T>;
			tail=tail->next;
			tail->prev=p;
			tail->next=NULL;
		}
	}
	
	Node<T>* Gethead()
	{
		return head;
	}
	Node<T>* Gettail()
	{
		return tail;
	}
	void Push_back(Node<T>* newnode)
	{
		if (!head)
		{
			head = newnode;
			tail = newnode;
			head->prev = NULL;
			head->next = NULL;
		}
		else
		{
			tail->next = newnode;
			newnode->prev = tail;
			tail = newnode;
			tail->next = NULL;
		}
	}
	void Push_back(const T& info)
	{
		if(!head)
		{
			head=new Node<T>;
			tail=head;
			head->prev=NULL;
			head->next=NULL;
			head->data=info;
		}
		else
		{
			Node<T>* p=tail;
			tail->next=new Node<T>;
			tail=tail->next;
			tail->data=info;
			tail->prev=p;
			tail->next=NULL;
		}
	}
	
	void Pop_back()
	{
		if(!head){}
		else
		{
			Node<T>* p=tail;
			tail=tail->prev;
			delete p;
			if(tail)
			{
				tail->next=NULL;
			}
		}
	}
	
	void Push_front(const T& info)
	{
		if(head)
		{
			head->prev=new Node<T>;
			head=head->prev;
			head->data=info;
			head->prev=NULL;
		}
		else
		{
			head=new Node<T>;
			tail=head;
			head->prev=NULL;
			head->next=NULL;
			head->data=info;
		}
	}
	
	void Pop_front()
	{
		if(!head){}
		else
		{
			Node<T>* p=head;
			head=head->next;
			delete p;
			if(head)
			{
				head->prev=NULL;
			}
		}
	}
	
	void Delete(Node<T>* target)
	{
		if (target == head)
		{
			this->Pop_front();
		}
		else if (target == tail)
		{
			this->Pop_back();
		}
		else
		{
			Node<T>* pprev = target->prev;
			Node<T>* pnext = target->next;
			pprev->next = pnext;
			pnext->prev = pprev;
			delete target;
		}
	}

	Node<T>* Apply(const int app_num)
	{
		Node<T>* p=tail;
		for(int i=0;i<=app_num;++i)
		{
			this->Push_back(0);
		}
		if(!p){
			p = head;
		}
		return p;
	}
	
	~List()
	{
		Node<T>* p=head;
		while(head!=tail)
		{
			head=head->next;
			p->next=NULL;
			head->prev=NULL;
			delete p;
			p=head;
		}
		delete head;
		head=NULL;
		tail=NULL;
	}

	Node <T> * Front(){
		return head;
	}

	Node <T> * Back(){
		return tail;
	}
	
protected:
	Node<T>* head;
	Node<T>* tail;		
};
#endif
