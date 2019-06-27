#ifndef V09_H_INCLUDED
#define V09_H_INCLUDED

#include <cstddef>
#include <iostream>

using namespace std;


void demoV09();


/*
    Implementation of a list with single reference

*/

namespace V09 {

template<typename T>
class Element;

template<typename T>
class Element {
public:
	Element<T> *nextElem_ = NULL;
	T value_;
};


template<typename T>
class List {
public:

	virtual void prepend(T value){
		Element<T> *tmp = new Element<T>;
		tmp->value_ = value;
		tmp->nextElem_ = ptrHead_;
		ptrHead_ = tmp;
		return;
	}

	virtual void append (T value){
		if(isEmpty()){
			prepend(value);
			return;
		}

		Element<T> *ptrElem = ptrHead_;
		Element<T> *tmp = new Element<T>;
		tmp->nextElem_ = NULL;
		tmp->value_ = value;

		// go to the end
		while ((ptrElem->nextElem_) != NULL) {
			ptrElem = ptrElem->nextElem_;
		}
		ptrElem->nextElem_ = tmp;

		return;
	}


	virtual T removeFirst(){
		if (isEmpty()) {
			throw string("list is empty");
		}
		Element<T> *ptrElem = ptrHead_;
		T tmp;
		ptrHead_ = ptrElem->nextElem_;
		tmp = ptrElem->value_;
		delete ptrElem;
		return tmp;
	};

	virtual T removeLast (){
		// 1st case queue empty
		if (ptrHead_ == NULL) {
			throw string("list is empty");
		}

		T tmp;
		// 2nd case queue contains only one element
		if ((ptrHead_)->nextElem_ == NULL) {
			tmp = (ptrHead_)->value_;
			delete (ptrHead_);
			ptrHead_ = NULL;
			return tmp;
		}

		Element<T> *ptrElem = ptrHead_;
		Element<T> *ptrLast;

		// go to the end
		while ((ptrElem->nextElem_)->nextElem_ != NULL) {
			ptrElem = ptrElem->nextElem_;
		}
		// ptrElement refers to the element before the last
		ptrLast = ptrElem->nextElem_;
		tmp = ptrLast->value_;
		delete ptrLast;
		ptrElem->nextElem_ = NULL;
		return tmp;
	};

	virtual bool isEmpty(){
		return(ptrHead_ == NULL);
	};

	void print(){
		Element<T> *ptrElem;
		cout << "[";
		ptrElem = ptrHead_;
		while (ptrElem != NULL) {
			cout << ptrElem->value_;
			ptrElem = ptrElem->nextElem_;
			if (ptrElem != NULL) {
				cout << ", ";
			}
		}
		cout << "]";
		cout.flush();
	};

protected:
	Element<T> *ptrHead_ = NULL;
};


} // end namespace V09

#endif // V09_H_INCLUDED
