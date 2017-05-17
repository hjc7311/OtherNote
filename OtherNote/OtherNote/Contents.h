#pragma once
//Contents.h

#ifndef _CONTENTS_H
#define _CONTENTS_H

#include "ArrayIterator.h"

typedef signed long int Long;

class Contents {
public:
	Contents();
	virtual ~Contents();
	virtual Long Add(Contents *contents) { return -1; }
	virtual Long Remove(Long index) { return -1; }
	virtual Contents* GetAt(Long index) { return 0; }
	virtual Contents* Clone() = 0;
	virtual ArrayIterator<Contents*>* CreateIterator() const = 0;
};

#endif	//_CONTENTS_H