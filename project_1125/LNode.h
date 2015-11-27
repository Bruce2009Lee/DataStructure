#ifndef _LNODE_H_
#define _LNODE_H_

template<typename T>
struct LNode
{
	T data;
	LNode<T> *next;
};
#endif