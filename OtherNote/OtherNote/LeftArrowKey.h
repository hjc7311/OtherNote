#pragma once
//LeftArrowKey.h

#ifndef _LEFTARROWKEY_H
#define _LEFTARROWKEY_H

#include "KeyAction.h"

class LeftArrowKey :public KeyAction {
public:
	LeftArrowKey(OtherNoteForm *otherNoteForm = 0);
	LeftArrowKey(const LeftArrowKey& source);
	~LeftArrowKey();
	LeftArrowKey& operator=(const LeftArrowKey& source);
	virtual void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
};

#endif	//_LEFTARROWKEY_H