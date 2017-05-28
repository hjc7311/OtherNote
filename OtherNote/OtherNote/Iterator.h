#pragma once
//Iterator.h

#ifndef _ITERATOR_H
#define _ITERATOR_H

typedef signed long int Long;

class Contents;

template <class Item>
class Iterator {
public:
	Iterator();
	Iterator(const Iterator& source);
	virtual ~Iterator() = 0;
	Iterator& operator=(const Iterator& source);
	virtual void First() = 0;
	virtual void Next() = 0;
	virtual bool IsDone() const = 0;
	virtual Item CurrentItem() const = 0;
};

template <class Item>
Iterator<Item>::Iterator() {

}

template <class Item>
Iterator<Item>::Iterator(const Iterator& source) {

}

template <class Item>
Iterator<Item>::~Iterator() {

}

template <class Item>
Iterator<Item>& Iterator<Item>::operator=(const Iterator& source) {

}

template <class Item>
void Iterator<Item>::First() {

}

template <class Item>
void Iterator<Item>::Next() {

}

template <class Item>
bool Iterator<Item>::IsDone() const {

}

template <class Item>
Item Iterator<Item>::CurrentItem() const {

}

#endif	//_ITERATOR_H