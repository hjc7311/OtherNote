#pragma once
//CtrlShiftLeftArrowKey.h

#ifndef _CTRLSHIFTLEFTARROWKEY_H
#define _CTRLSHIFTLEFTARROWKEY_H

#include "KeyAction.h"

class CtrlShiftLeftArrowKey :public KeyAction {
public:
	CtrlShiftLeftArrowKey(OtherNoteForm *otherNoteForm = 0);
	CtrlShiftLeftArrowKey(const CtrlShiftLeftArrowKey& source);
	~CtrlShiftLeftArrowKey();
	CtrlShiftLeftArrowKey& operator=(const CtrlShiftLeftArrowKey& source);
	virtual void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
};

#endif	//_CTRLSHIFTLEFTARROWKEY_H