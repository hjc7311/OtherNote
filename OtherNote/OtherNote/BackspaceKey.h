#pragma once
//BackspaceKey.h

#ifndef _BACKSPACEKEY_H
#define _BACKSPACEKEY_H
#include "KeyAction.h"

class BackspaceKey :public KeyAction {
public:
	BackspaceKey(OtherNoteForm *otherNoteForm = 0);
	BackspaceKey(const BackspaceKey& source);
	~BackspaceKey();
	BackspaceKey& operator=(const BackspaceKey& source);
	virtual void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
};

#endif	//_BACKSPACEARROWKEY_H