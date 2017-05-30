#pragma once
//CtrlShiftRightArrowKey.h

#ifndef _CTRLSHIFTRIGHTARROWKEY_H
#define _CTRLSHIFTRIGHTARROWKEY_H

#include "KeyAction.h"

class CtrlShiftRightArrowKey :public KeyAction {
public:
	CtrlShiftRightArrowKey(OtherNoteForm *otherNoteForm = 0);
	CtrlShiftRightArrowKey(const CtrlShiftRightArrowKey& source);
	~CtrlShiftRightArrowKey();
	CtrlShiftRightArrowKey& operator=(const CtrlShiftRightArrowKey& source);
	virtual void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
};

#endif	//_CTRLSHIFTRIGHTARROWKEY_H