/***************************************************************
 * Name:      DebugSudokuMain.h
 * Purpose:   Defines Application Frame
 * Author:    Tim Sonnier ()
 * Created:   2013-03-31
 * Copyright: Tim Sonnier ()
 * License:
 **************************************************************/

#ifndef DEBUGSUDOKUMAIN_H
#define DEBUGSUDOKUMAIN_H



#include "DebugSudokuApp.h"
#include "..\sudokusolver\src\GameBoard.h"
#include <wx/file.h>
#include <wx/datetime.h>
#include <iostream>
#include <fstream>

#include "GUIFrame.h"

void writetoLog( const wxString &text );

enum Controls { SET, NOTE, CLEAR};

class DebugSudokuFrame: public GUIFrame
{
    public:
        DebugSudokuFrame(wxFrame *frame);
        ~DebugSudokuFrame();
    private:
        virtual void OnClose(wxCloseEvent& event);
        virtual void OnQuit(wxCommandEvent& event);
        virtual void OnAbout(wxCommandEvent& event);
        virtual void OnPaint(wxPaintEvent& event);
        virtual void OnNewPuzzle( wxCommandEvent& event );
        virtual void OnNumButtonClick( wxCommandEvent& event );
		virtual void OnSetButtonClick( wxCommandEvent& event );
		virtual void OnNoteButtonClick( wxCommandEvent& event );
		virtual void OnClearButtonClick( wxCommandEvent& event );
		virtual void OnSolve( wxCommandEvent& event );
		virtual void OnNakedSingle( wxCommandEvent& event );
		virtual void OnHiddenSingle( wxCommandEvent& event );
		virtual void OnRemovePossibles( wxCommandEvent& event );
		virtual void OnScrambleBoards( wxCommandEvent& event );

		GameBoard * mGuessGB;
		GameBoard * mTrueGB;
		Difficulty diff;
		Controls ctrlSelect;
};

#endif // DEBUGSUDOKUMAIN_H
