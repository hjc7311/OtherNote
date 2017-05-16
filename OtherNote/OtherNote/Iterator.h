#pragma once
//Iterator.h

#ifndef _ITERATOR_H
#define _ITERATOR_H

//template <class Item>
//class Iterator {
//public:
//	Iterator();
//	Iterator(const Iterator& source);
//	virtual ~Iterator()=0;
//	Iterator& operator=(const Iterator& source);
//	virtual void First()=0;
//	virtual void Next()=0;
//	virtual bool IsDone()=0;
//	virtual Item CurrentItem()=0;
//};

typedef signed long int Long;
class Contents;

template <class Item>
class Iterator {
public:
	Iterator();
	//Iterator(Item *contents);
	Iterator(const Iterator& source);
	virtual ~Iterator() = 0;
	Iterator& operator=(const Iterator& source);
	virtual void First() = 0;
	virtual void Next() = 0;
	virtual bool IsDone() const = 0;
	virtual Item CurrentItem() const = 0;
	//Contents* GetContents() const;
	//Long GetCurrent() const;
//protected:
	//Contents *contents;
	//Long current;
};

template <class Item>
Iterator<Item>::Iterator() {}

template <class Item>
Iterator<Item>::Iterator(const Iterator& source) {}

template <class Item>
Iterator<Item>::~Iterator() {}

template <class Item>
void Iterator<Item>::First() {}

template <class Item>
void Iterator<Item>::Next() {}

template <class Item>
bool Iterator<Item>::IsDone() const {}

template <class Item>
Item Iterator<Item>::CurrentItem() const {}

template <class Item>
Iterator<Item>& Iterator<Item>::operator=(const Iterator& source) {}




//
//template <class Item>
//inline Contents* Iterator<Item>::GetContents() const {
//	return const_cast<Contents*>(this->contents);
//}
//
//template <class Item>
//inline Long Iterator<Item>::GetCurrent() const {
//	return this->current;
//}

#endif	//_ITERATOR_H