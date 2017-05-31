#pragma once
//DeleteKey.h

#ifndef _DELETE_KEY_H
#define _DELETE_KEY_H
#include "KeyAction.h"

class DeleteKey : public KeyAction {
public:
	DeleteKey(OtherNoteForm *otherNoteForm = 0);
	DeleteKey(const DeleteKey& source);
	~DeleteKey();
	DeleteKey& operator=(const DeleteKey& source);
	virtual void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
};

#endif //_DELETE_KEY_H