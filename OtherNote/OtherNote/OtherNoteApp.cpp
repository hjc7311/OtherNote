//OtherNoteApp.cpp

#include "OtherNoteApp.h"
#include "OtherNoteForm.h"

BOOL OtherNoteApp::InitInstance() {
	OtherNoteForm *otherNoteForm = new OtherNoteForm;
	otherNoteForm->Create(NULL, "OtherNote");
	otherNoteForm->ShowWindow(SW_SHOWMAXIMIZED);
	otherNoteForm->UpdateWindow();
	this->m_pMainWnd = otherNoteForm;
	
	return TRUE;
}

OtherNoteApp otherNoteApp;
