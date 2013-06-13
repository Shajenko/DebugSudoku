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
#include "..\Solving and Generating\GameBoard.h"
#include <wx/file.h>
#include <wx/datetime.h>
#include <wx/tokenzr.h>
#include <wx/textfile.h>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

#include "GUIFrame.h"

void writetoLog( const wxString &text );

enum Controls { SET, NOTE, CLEAR};

class DebugSudokuFrame: public GUIFrame
{
    public:
        DebugSudokuFrame(wxFrame *frame);
        ~DebugSudokuFrame();
        void SetRow(unsigned int val) { row = val;}
        void SetCol(unsigned int val) { col = val;}
        void SaveBoard();
        void LoadBoard();
    private:
        virtual void OnClose(wxCloseEvent& event);
        virtual void OnQuit(wxCommandEvent& event);
        virtual void OnAbout(wxCommandEvent& event);
        virtual void OnPaint(wxPaintEvent& event);
        virtual void OnNewPuzzle( wxCommandEvent& event );
		virtual void OnNewBase( wxCommandEvent& event );
        virtual void OnSavePuzzle( wxCommandEvent& event );
		virtual void OnLoadPuzzle( wxCommandEvent& event );

		virtual void OnRemoveLayer( wxCommandEvent& event );
		virtual void OnResetPossibles( wxCommandEvent& event );
		virtual void OnRemovePossibles( wxCommandEvent& event );
		virtual void OnResetRowColSec( wxCommandEvent& event );
		virtual void OnGenPuzzles( wxCommandEvent& event );

        virtual void OnNumButtonClick( wxCommandEvent& event );
		virtual void OnSetButtonClick( wxCommandEvent& event );
		virtual void OnNoteButtonClick( wxCommandEvent& event );
		virtual void OnClearButtonClick( wxCommandEvent& event );
		virtual void OnSolve( wxCommandEvent& event );
		virtual void OnNakedSingle( wxCommandEvent& event );
		virtual void OnHiddenSingle( wxCommandEvent& event );
		virtual void OnNakedDouble( wxCommandEvent& event );
		virtual void OnHiddenDouble( wxCommandEvent& event );
		virtual void OnScrambleBoards( wxCommandEvent& event );

		virtual void OnGuessPanelEraseBG( wxEraseEvent& event );
		virtual void OnGuessPanelKeyUp( wxKeyEvent& event );
		virtual void OnGuessPanelLeftUp( wxMouseEvent& event );
		virtual void OnGuessPanelPaint( wxPaintEvent& event );

		virtual void OnTruePanelEraseBG( wxEraseEvent& event );
		virtual void OnTruePanelPaint( wxPaintEvent& event );

		GameBoard * mGuessGB;
		GameBoard * mTrueGB;
		Difficulty diff;
		Controls ctrlSelect;
        wxButton * numButtons[9];

		unsigned int row, col;

		bool showChange;
};

#endif // DEBUGSUDOKUMAIN_H
