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


namespace V09DL{

/**
 *
 *  \class Element
 *  \@param T Type
 *  \brief     A template class definition. The class
 *  contains the value  of the item and two references.
 *  One refers to the preceding and to the next list element.
 *
 *  \author  aml
 *  \date   30.06.2018
 *
 */
template<typename T>
class Element;


/**
 *
 *  \class Element
 *  \@param T Type
 *  \brief     A template class definition. The class
 *  contains the value  of the item and two references.
 *  One refers to the preceding and to the next list element.
 *
 *  \author  m.huelse
 *  \date   30.06.2018
 *
 */
template<typename T>
class Element {
public:


	/**
	 *
	 *
	 * \brief Reference to the preceding list element
	 *
	 */
	Element<T> *pre_ = NULL;

	/**
	 *
	 *
	 * \brief Reference to the next list element
	 */
	Element<T> *post_ = NULL;

	/**
	 *
	 * The value of the list element.
	 *
	 */
	T value_;
};



/**
 *
 *  \class List
 *  \@param T Type
 *  \brief     A template class definition. The class
 *  contains the start and end element of the list.
 *  It implements a doubly linked list.
 *
 */
template<typename T>
class List {
public:

	/**
	 *
	 * \brief Adds a new list element before the current
	 * start element of the list. The new list element
	 * contains the given value.
	 *
	 * @param value Value of the new list element
	 *
	 *
	 */
	virtual void prepend(T value){
		Element<T> *tmp = new Element<T>;
		tmp->value_ = value;
		tmp->pre_   = NULL;
		tmp->post_  = NULL;

		if(isEmpty()){
			ptrStart_ = tmp;
			ptrEnd_   = tmp;
			return;
		}

		// neues element zeigt auf start
		// als Nachfolger
		tmp->post_  = ptrStart_;
		// ehemaliger start zeigt auf neues Element
		// als Vorgaenger
		ptrStart_->pre_ = tmp;

		// start zeigt auf neues Element
		ptrStart_ = tmp;
		return;
	}

	/**
	 *
	 * \brief Adds a new list element after the current
	 * end element of the list. The new list element
	 * contains the given value.
	 *
	 * @param value Value of the new list element
	 *
	 */
	virtual void append (T value){
		if(isEmpty()){
			prepend(value);
			return;
		}

		Element<T> *tmp = new Element<T>;
		tmp->value_ = value;
		tmp->pre_   = NULL;
		tmp->post_  = NULL;

		// neues element zeigt auf end
		// als vorgänger
		tmp->pre_  = ptrEnd_;
		// ehemaliges ende zeigt auf neues Element
		// als Nachfolger
		ptrEnd_->post_ = tmp;

		// end zeigt auf neues Element
		ptrEnd_ = tmp;
		return;
	}

	/**
	 *
	 * \brief Removes the start element of the list
	 * and returns the value of the element removed.
	 *
	 * @return T value of the list element removed.
	 *
	 * \throws string "list is empty" if list is empty
	 *
	 */
	virtual T removeFirst(){
		if (isEmpty()) {
			throw string("list is empty");
		}

		T tmp = ptrStart_->value_;

		if(ptrStart_ == ptrEnd_){ // nur ein Element in Liste
			delete ptrStart_;
			ptrStart_ = NULL;
			ptrEnd_   = NULL;
		}else{ // mehr als ein Element in Liste
			// start zeigt auf ehemaligen Nachfolger
			//  als neuen start
			ptrStart_ = ptrStart_->post_;

			// gebe Speicher des ehemaligen start Element
			// frei
			delete ptrStart_->pre_;
			ptrStart_->pre_ = NULL;

		}
		return tmp;
	};


	/**
	 *
	 * \brief Removes the end element of the list
	 * and returns the value of the element removed.
	 *
	 * @return T value of the list element removed.
	 *
	 * \throws string "list is empty" if list is empty
	 *
	 */
	virtual T removeLast (){
		if (isEmpty()) {
			throw string("list is empty");
		}

		T tmp = ptrEnd_->value_;

		if(ptrStart_ == ptrEnd_){ // nur ein Element in Liste
			delete ptrStart_;
			ptrStart_ = NULL;
			ptrEnd_   = NULL;
		}else{
			// ende zeigt auf ehemaligen Vorgaenger
			//  als neues ende
			ptrEnd_ = ptrEnd_->pre_;

			// gebe Speicher des ehemaligen end Elements
			// frei
			delete ptrEnd_->post_;
			ptrEnd_->post_ = NULL;
		};
		return tmp;
	};

	/**
	 *
	 * \brief Tests whether or not the list is empty.
	 * It return true if the list is empty otherwise false.
	 *
	 * @return bool  true if list is empty otherwise false.
	 *
	 */
	virtual bool isEmpty(){
		return((ptrStart_ == NULL) && (ptrEnd_ == NULL));
	};

	/**
	 *
	 * \brief Prints the content of the list on the
	 * standard output.
	 *
	 * @return void
	 *
	 */
	virtual void print(){
		Element<T> *ptrElem;
		cout << "[";
		ptrElem = ptrStart_;
		while (ptrElem != NULL) {
			cout << ptrElem->value_;
			ptrElem = ptrElem->post_;
			if (ptrElem != NULL) {
				cout << ", ";
			}
		}
		cout << "]";
		cout.flush();
	};

protected:

	/**
	 *
	 * \brief Start element of the list.
	 *
	 */
	Element<T> *ptrStart_ = NULL;

	/**
	 *
	 * \brief End element of the list.
	 *
	 */
	Element<T> *ptrEnd_ = NULL;
};




/**
 *
 *  \class Stack
 *  \@param T Type
 *  \brief     A template class definition. The class
 *  implements a stack-container.
 *
 */
template<typename T>
class Stack: protected List<T> {
public:

	/**
	 *
	 * \brief Adds a new element to the stack.
	 * The new element has the given value.
	 *
	 * @param value Value of the new stack element.
	 *
	 */
	void push(T value){ List<T>::prepend(value);};

	/**
	 *
	 * \brief Removes one element from the stack.
	 * The last element added is removed.
	 * The value of the removed stack element
	 * is returned.
	 *
	 * @return T value of the stack element removed.
	 *
	 * \throws string "list is empty" if stack is empty
	 *
	 */
	T pop() { return (List<T>::removeFirst());};


	/**
	 *
	 * \brief Returns the value of the stack element
	 * to be removed next when calling method pop().
	 *
	 * @return T value of the element the be removed
	 * next when calling method pop().
	 *
	 * \throws string "list is empty" if stack is empty
	 *
	 */
	T peek(){
		T tmp;
		tmp = List<T>::removeFirst();
		prepend(tmp);
		return tmp;
	};


	/**
	 *
	 * \brief Tests whether or not the stack is empty.
	 * It return true if the stack is empty otherwise false.
	 *
	 * @return bool  true if stack is empty otherwise false.
	 *
	 */
	bool isEmpty(){return (List<T>::isEmpty());};

	/**
	 *
	 * \brief Prints the content of the stack on the
	 * standard output.
	 *
	 * @return void
	 *
	 */
	void print(){List<T>::print();};

};



/**
 *
 *  \class Queue
 *  \@param T Type
 *  \brief     A template class definition. The class
 *  implements a queue-container.
 *
 */
template<typename T>
class Queue: protected List<T> {
public:

	/**
	 *
	 * \brief Adds a new element to the queue.
	 * The new element has the given value.
	 *
	 * @param value Value of the new queue element.
	 *
	 */
	void enqueue(T value){ List<T>::prepend(value);};

	/**
	 *
	 * \brief Removes one element from the queue.
	 * The value of the removed queue element
	 * is returned.
	 *
	 * @return T value of the queue element removed.
	 *
	 * \throws string "list is empty" if queue is empty
	 *
	 */
	T    dequeue() { return (List<T>::removeLast());};

	/**
	 *
	 * \brief Returns the value of the queue element
	 * to be removed next when calling method dequeue().
	 *
	 * @return T value of the element the be removed
	 * next when calling method dequeue().
	 *
	 * \throws string "list is empty" if queue is empty
	 *
	 */
	T peek(){
		T tmp;
		tmp = List<T>::removeLast();
		append(tmp);
		return tmp;
	};

	/**
	 *
	 * \brief Prints the content of the queue on the
	 * standard output.
	 *
	 * @return void
	 *
	 */
	void print(){List<T>::print();};

	/**
	 *
	 * \brief Tests whether or not the queue is empty.
	 * It return true if the queue is empty otherwise false.
	 *
	 * @return bool  true if queue is empty otherwise false.
	 *
	 */
	bool isEmpty(){return (List<T>::isEmpty());};
};



}  // end namespace V09DL

#endif // V09_H_INCLUDED
