/*
 * Node.h
 *
 *  Created on: Aug 9, 2013
 *      Author: Corey Dixon
 */

#ifndef NODE_H_
#define NODE_H_

#include <cstdlib>

template<class T>
class Node
{
public:
	Node(void)
	{
		obj = NULL;
		next = NULL;
		prev = NULL;
	}
	;

	Node(T *_obj)
	{
		obj = _obj;
		next = NULL;
		prev = NULL;
	}
	;

	Node(T *_obj, Node<T> *_prev)
	{
		obj = _obj;
		prev = _prev;
		next = NULL;
	}
	;

	Node(T *_obj, Node<T> *_prev, Node<T> *_next)
	{
		obj = _obj;
		prev = _prev;
		next = _next;
	}

	~Node(void)
	{

	}

	T *obj;
	Node<T> *next;
	Node<T> *prev;
};

#endif /* NODE_H_ */
