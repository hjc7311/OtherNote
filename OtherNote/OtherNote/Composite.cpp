//Composite.cpp

#include "Composite.h"

Composite::Composite(Long capacity)
	:contents(capacity) {
	this->capacity = capacity;
	this->length = 0;
}

Composite::Composite(const Composite& source)
	: contents(source.capacity) {
	Long i = 0;
	while (i < source.capacity) {
		this->contents.Store(i, (const_cast<Composite&>(source)).contents.GetAt(i)->Clone());
		i++;
	}
	this->capacity = source.capacity;
	this->length = source.length;
}

Composite::~Composite() {
	Long i = 0;
	while (i < this->length) {
		if (this->contents.GetAt(i) != 0) {
			delete this->contents.GetAt(i);
		}
		i++;
	}
}

Contents* Composite::GetAt(Long index) {
	return this->contents.GetAt(index);
}

Contents* Composite::operator[](Long index) {
	return this->contents[index];
}

Composite& Composite::operator=(const Composite& source) {
	Long i = 0;
	while (i < this->length) {
		delete this->contents.GetAt(i);
		i++;
	}

	this->contents = source.contents;
	i = 0;
	while (i < source.length) {
		this->contents.Modify(i, (const_cast<Composite&>(source)).contents.GetAt(i)->Clone());
		i++;
	}
	return *this;
}

Long Composite::Add(Contents *contentsLink) {
	Long index;
	if (this->capacity > this->length) {
		index = this->contents.Store(this->length, contentsLink);
	}
	else {
		index = this->contents.AppendFromRear(contentsLink);
		this->capacity++;
	}
	this->length++;

	return index;
}

Long Composite::Remove(Long index) {
	if (this->contents[index] != 0) {
		delete this->contents[index];
	}
	index = this->contents.Delete(index);
	this->capacity--;
	this->length--;
	return index;
}

Iterator<Contents*>* Composite::CreateIterator() const {
	return 0;
}	//????????????????????????????

//ArrayIterator<Contents*>* Composite::CreateIterator() const {
//	
//	//return const_cast<ArrayIterator<Contents*>*>(new ArrayIterator<Contents*>(const_cast<ArrayIterator<Contents*>>(&this->contents)));
//	
//	//ArrayIterator<Item>::ArrayIterator(Array<Item> *aArray);
//
//	return const_cast<ArrayIterator<Contents*>*>(new ArrayIterator<Contents*>(&this->contents));
//
//	//return new ArrayIterator<Contents*>(const_cast<Contents*>(&this->contents));
//}