#ifndef V10_H_INCLUDED
#define V10_H_INCLUDED

#include <iostream>

using namespace std;

void demoV10();


namespace V10{ // implementation of array based list with fixed storage


template <typename T>
class List{
   protected:

        int  firstElmIdx_     = 0;  // Idx of the first element in der List
        int  nextFreeCellIdx_ = 0;  // Idx of cell where the next element is stored during append
        int  size_            = 32;
        T   *dataField_;
        int  amountElements_  = 0;

    public:
                     List();
        virtual     ~List();
        virtual void prepend(T value);
        virtual void append(T value);
        virtual T removeFirst();
        virtual T removeLast();
        virtual bool isEmpty();
        virtual void print();
                int  amountElem();

    protected:
        virtual bool isFull();
};


template <typename T>
List<T>::List(){
    size_            = 32;
    firstElmIdx_     = 0;  // list is empty if both indexes have the same value
    nextFreeCellIdx_ = 0;
    amountElements_  = 0;
    try{
        dataField_ = new T[size_];
    }catch(...){
        throw string("NO MEMORY AVAILABLE");
    }
}

template <typename T>
List<T>::~List(){
    delete [] dataField_;
}

template <typename T>
int  List<T>::amountElem(){
    return amountElements_;
}

template <typename T>
void List<T>::prepend(T value){
    if(isFull()) throw string ("BUFFERR FULL - NO PREPEND DONE");

    int idx = firstElmIdx_ - 1;
    if(idx < 0){
        idx = size_ - 1;
    }
    firstElmIdx_ = idx;
    dataField_[firstElmIdx_] = value;
    amountElements_++;
    return;
}

template <typename T>
void List<T>::append(T value){
    if(isFull()) throw string ("BUFFERR FULL - NO APPEND DONE");
    dataField_[nextFreeCellIdx_] = value;
    nextFreeCellIdx_ = (nextFreeCellIdx_ + 1) % size_;
    amountElements_++;
    return;
}

template <typename T>
T List<T>::removeFirst(){
    if(isEmpty()) throw string ("BUFFERR EMPTY - NO REMOVE FIRST DONE");

    T  tmp = dataField_[firstElmIdx_];
    firstElmIdx_ = (firstElmIdx_ + 1) % size_;
    amountElements_--;
    return tmp;
}


template <typename T>
T List<T>::removeLast(){
    if(isEmpty()) throw string ("BUFFERR EMPTY - NO REMOVE LAST DONE");

    int idxLastElm = nextFreeCellIdx_ - 1;
    if(idxLastElm < 0){
        idxLastElm = size_ - 1;
    }

    T  tmp = dataField_[idxLastElm];
    nextFreeCellIdx_ = idxLastElm;
    amountElements_--;
    return tmp;
}


template <typename T>
bool List<T>::isEmpty(){
    if(firstElmIdx_ == nextFreeCellIdx_){
        return true;
    }else{
        return false;
    }
}


template <typename T>
bool List<T>::isFull(){
    int idx = firstElmIdx_ - 1;
    if(idx < 0){
        idx = size_ - 1;
    }
    if(idx == nextFreeCellIdx_){
        return true;
    }else{
        return false;
    }
}

template <typename T>
void List<T>::print(){
    cout << "[";
    int i = firstElmIdx_;
    while(i != nextFreeCellIdx_){
        if(i != firstElmIdx_){
            cout << ", ";
        };
        cout << dataField_[i];
        i = (i + 1) % size_;
    }
    cout << "]";
    return;
}



} // end namespace V10


namespace V10DL{  // implementation of array based list with flexible storage


template <typename T>
class List : public V10::List<T>{

    public:
                     List();
        virtual void prepend(T value);
        virtual void append(T value);

    protected:
        virtual void addStorage(int amountOfAddStorage);
};


template <typename T>
List<T>::List() : V10::List<T>(){
    ;
}



template <typename T>
void List<T>::prepend(T value){

    if(V10::List<T>::isFull()){
        this->addStorage(V10::List<T>::size_);
    }

    int idx = V10::List<T>::firstElmIdx_ - 1;
    if(idx < 0){
        idx = V10::List<T>::size_ - 1;
    }
    V10::List<T>::firstElmIdx_ = idx;
    V10::List<T>::dataField_[V10::List<T>::firstElmIdx_] = value;

    V10::List<T>::amountElements_++;
    return;
}

template <typename T>
void List<T>::append(T value){
    if(V10::List<T>::isFull()){
        this->addStorage(this->size_);
    }
    V10::List<T>::dataField_[V10::List<T>::nextFreeCellIdx_] = value;
    V10::List<T>::nextFreeCellIdx_ = (V10::List<T>::nextFreeCellIdx_ + 1) % V10::List<T>::size_;

    V10::List<T>::amountElements_++;
    return;
}



template <typename T>
void List<T>::addStorage(int amountOfAddStorage){
    T *tmpList;

    try{
        tmpList = new T[V10::List<T>::size_ + amountOfAddStorage];
    }catch(...){
        throw string("BUFFER FULL - NO NEW MEMORY AVAILABLE");
    }

    // copy data to the new field
    int i = V10::List<T>::firstElmIdx_;
    int iIdx = 0;
    while(i != V10::List<T>::nextFreeCellIdx_){
        tmpList[iIdx] = V10::List<T>::dataField_[i];
        i = (i + 1) % V10::List<T>::size_;
        iIdx++;
    }

    V10::List<T>::firstElmIdx_ = 0;
    V10::List<T>::nextFreeCellIdx_ = iIdx;

    delete [] V10::List<T>::dataField_;
    V10::List<T>::dataField_ = tmpList;
    V10::List<T>::size_ = V10::List<T>::size_ + amountOfAddStorage;
    return;
}


}

#endif // V10_H_INCLUDED
