//KeyActionCreator.cpp

#include "KeyActionCreator.h"
#include "OtherNoteForm.h"
#include "LeftArrowKey.h"
#include "UpArrowKey.h"
#include "DownArrowKey.h"
#include "RightArrowKey.h"
#include "CtrlLeftArrowKey.h"
#include "CtrlRightArrowKey.h"
#include "ShiftLeftArrowKey.h"
#include "ShiftUpArrowKey.h"
#include "ShiftDownArrowKey.h"
#include "ShiftRightArrowKey.h"
#include "CtrlShiftLeftArrowKey.h"
#include "CtrlShiftRightArrowKey.h"
#include "TabKey.h"
#include "ReturnKey.h"
#include "HomeKey.h"
#include "EndKey.h"
#include "CtrlHomeKey.h"
#include "CtrlEndKey.h"
#include "BackspaceKey.h"
#include "DeleteKey.h"

KeyActionCreator::KeyActionCreator() {

}

KeyActionCreator::KeyActionCreator(const KeyActionCreator& source) {

}

KeyActionCreator::~KeyActionCreator() {

}

KeyActionCreator& KeyActionCreator::operator=(const KeyActionCreator& source) {
	return *this;
}

KeyAction* KeyActionCreator::Create(OtherNoteForm *otherNoteForm, UINT nChar, UINT nRepCnt, UINT nFlags) {
	
	if (nChar == VK_LEFT && GetKeyState(VK_CONTROL) < 0) {
		return new CtrlLeftArrowKey(otherNoteForm);
	}
	else if (nChar == VK_RIGHT && GetKeyState(VK_CONTROL) < 0) {
		return new CtrlRightArrowKey(otherNoteForm);
	}

	else if (nChar == VK_LEFT && GetKeyState(VK_SHIFT) < 0) {
		return new ShiftLeftArrowKey(otherNoteForm);
	}

	else if (nChar == VK_HOME && GetKeyState(VK_CONTROL) < 0) {
		return new CtrlHomeKey(otherNoteForm);
	}
	else if (nChar == VK_END && GetKeyState(VK_CONTROL) < 0) {
		return new CtrlEndKey(otherNoteForm);
	}

	else if (nChar == VK_LEFT) {
		return new LeftArrowKey(otherNoteForm);
	}
	else if (nChar == VK_UP) {
		return new UpArrowKey(otherNoteForm);
	}
	else if (nChar == VK_DOWN) {
		return new DownArrowKey(otherNoteForm);
	}
	else if (nChar == VK_RIGHT) {
		return new RightArrowKey(otherNoteForm);
	}
	
	
	else if (nChar == VK_TAB) {
		return new TabKey(otherNoteForm);
	}
	else if (nChar == VK_RETURN) {
		return new ReturnKey(otherNoteForm);
	}
	else if (nChar == VK_BACK) {
		return new BackspaceKey(otherNoteForm);
	}
	else if (nChar == VK_DELETE) {
		return new DeleteKey(otherNoteForm);
	}
	
	return 0;
}