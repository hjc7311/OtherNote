// ArrayIterator.cpp

#include "ArrayIterator.h"


//template <class Item>
//ArrayIterator<Item>::ArrayIterator(Array<Contents*> *aArray)
//	: array(aArray), current(0) {
//}
//
//template <class Item>
//ArrayIterator<Item>::~ArrayIterator() {
//
//}
//
//template <class Item>
//void ArrayIterator<Item>::First() {
//	this->current = 0;
//}
//
//template <class Item>
//void ArrayIterator<Item>::Next() {
//	this->current++;
//}
//
//template <class Item>
//bool ArrayIterator<Item>::IsDone() const {
//	return (this->current >= this->array->GetLength());
//}
//
//template <class Item>
//Item ArrayIterator<Item>::CurrentItem() const {
//	if (this->IsDone()) {
//		throw IteratorOutOfBounds;
//	}
//	return static_cast<Item*>(this->array->GetAt(this->current));
//}

//
//template <class Item>
//ArrayIterator<Item>::ArrayIterator(const ArrayIterator& source)
//	:Iterator(source) {
//	this->_array = source._array;
//	this->current = source.current;
//}
//
//template <class Item>
//ArrayIterator<Item>::~ArrayIterator() {
//
//}
//
//template <class Item>
//ArrayIterator<Item>& ArrayIterator<Item>::operator=(const ArrayIterator& source) {
//	Iterator::operator=(source);
//	this->_array = source._array;
//	this->current = source.current;
//
//	return *this;
//}
//
//template <class Item>
//void ArrayIterator<Item>::First() {
//	this->current = 0;
//}
//
//template <class Item>
//void ArrayIterator<Item>::Next() {
//	this->current++;
//}
//
//template <class Item>
//bool ArrayIterator<Item>::IsDone() const {
//	return this->current >= _array->GetLength();
//}
//
//
////#include "Composite.h"
////
////bool ArrayIterator::IsDone() {
////	bool ret = false;
////	
////	if (dynamic_cast<Composite*>(this->contents)) {
////		if (this->current >= (dynamic_cast<Composite*>(this->contents))->GetLength()) {
////			ret = true;
////		}
////	}
////	return ret;
////}
//
//template <class Item>
//Item ArrayIterator<Item>::CurrentItem() const {
//	if (IsDone()) {
//		throw IteratorOutOfBounds;
//	}
//	return _array->GetAt(this->current);
//}
////Contents* ArrayIterator::GetCurrentItem() {
////	return this->contents->GetAt(this->current);
////}