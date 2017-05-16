#pragma once
//Composite.h

#ifndef _COMPOSITE_H
#define _COMPOSITE_H

#include "Contents.h"
#include "Array.h"

class Composite :public Contents {
public:
	Composite(Long capacity);
	Composite(const Composite& source);
	virtual ~Composite() = 0;
	virtual Long Add(Contents *contentsLink);
	virtual Long Remove(Long index);
	virtual Contents* GetAt(Long index);
	Composite& operator=(const Composite& source);
	Contents* operator[](Long index);
	Long GetCapacity() const;
	Long GetLength() const;
	virtual ArrayIterator<Contents*>* CreateIterator() const;
protected:
	Array<Contents*> contents;
	Long capacity;
	Long length;
};

inline Long Composite::GetCapacity() const {
	return this->capacity;
}

inline Long Composite::GetLength() const {
	return this->length;
}

#endif	//_COMPOSITE_H