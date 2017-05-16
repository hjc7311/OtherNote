#pragma once
// ArrayIterator.h

#ifndef _ARRAYITERATOR_H
#define _ARRATITERATOR_H

#include "Iterator.h"
#include "Array.h"

typedef signed long int Long;

template <class Item>
class ArrayIterator : public Iterator<Item> {
public:
	ArrayIterator(const Array<Item>* aArray);
	ArrayIterator(const ArrayIterator& source);
	virtual ~ArrayIterator();
	ArrayIterator& operator=(const ArrayIterator& source);

	virtual void First();
	virtual void Next();
	virtual bool IsDone() const;
	virtual Item CurrentItem() const;

	Array<Item>* GetArray() const;
	Long GetCurrent() const;
private:
	const Array<Item> *_array;
	Long current;
};

template <class Item>
inline Array<Item>* ArrayIterator<Item>::GetArray() const {
	sreturn const_cast<Array<Item>*>(this->array);
}

template <class Item>
inline Long ArrayIterator<Item>::GetCurrent() const {
	return this->current;
}

template <class Item>
ArrayIterator<Item>::ArrayIterator(const Array<Item> *aArray)
	:Iterator(), _array(aArray), current(0) {

}


template <class Item>
ArrayIterator<Item>::ArrayIterator(const ArrayIterator& source)
	:Iterator(source) {
	this->_array = source._array;
	this->current = source.current;
}

template <class Item>
ArrayIterator<Item>::~ArrayIterator() {

}

template <class Item>
ArrayIterator<Item>& ArrayIterator<Item>::operator=(const ArrayIterator& source) {
	Iterator::operator=(source);
	this->_array = source._array;
	this->current = source.current;

	return *this;
}

template <class Item>
void ArrayIterator<Item>::First() {
	this->current = 0;
}

template <class Item>
void ArrayIterator<Item>::Next() {
	this->current++;
}

template <class Item>
bool ArrayIterator<Item>::IsDone() const {
	return this->current >= _array->GetLength();
}


//#include "Composite.h"
//
//bool ArrayIterator::IsDone() {
//	bool ret = false;
//	
//	if (dynamic_cast<Composite*>(this->contents)) {
//		if (this->current >= (dynamic_cast<Composite*>(this->contents))->GetLength()) {
//			ret = true;
//		}
//	}
//	return ret;
//}

template <class Item>
Item ArrayIterator<Item>::CurrentItem() const {
	//if (IsDone()) {
	//	throw IteratorOutOfBounds;
	//}

	return const_cast<Array<Contents*>*>(this->_array)->GetAt(this->current);
	//Item item = const_cast<Array<Contents*>*>(this->_array)->GetAt(this->current);

	//return const_cast<Item>(item);
}

//Contents* ArrayIterator::GetCurrentItem() {
//	return this->contents->GetAt(this->current);
//}


//class Contents;
//class ArrayIterator :public Iterator {
//public:
//	ArrayIterator();
//	ArrayIterator(Contents *contents);
//	ArrayIterator(const ArrayIterator& source);
//	virtual ~ArrayIterator();
//	ArrayIterator& operator=(const ArrayIterator& source);
//	virtual void First();
//	virtual void Next();
//	virtual bool IsDone();
//	virtual Contents* GetCurrentItem();
//};

#endif // ARRAYITERATOR_H