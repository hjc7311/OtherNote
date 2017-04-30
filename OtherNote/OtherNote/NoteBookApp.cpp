// NoteBookApp.cpp

#include "NoteBookApp.h"
#include "NoteBookForm.h"

BOOL NoteBookApp::InitInstance() {
	NoteBookForm *noteBookForm = new NoteBookForm;
	noteBookForm->Create(NULL, "Other Note");
	noteBookForm->ShowWindow(SW_SHOWMAXIMIZED);
	noteBookForm->UpdateWindow();
	this->m_pMainWnd = noteBookForm;
	
	return TRUE;
}

NoteBookApp noteBookApp;
