#ifndef __debugMainFrame__
#define __debugMainFrame__

/**
@file
Subclass of MainFrame, which is generated by wxFormBuilder.
*/

#include "DSudoku.h"
#include "enums.h"
#include "..\Solving and Generating\GameBoard.h"

//// end generated include

/** Implementing MainFrame */
class DebugSudokuMainFrame : public MainFrame
{
	protected:
		// Handlers for MainFrame events.
		virtual void OnQuit( wxCommandEvent& event );
		void OnChar( wxKeyEvent& event );
		void OnLeftUp( wxMouseEvent& event );
		void OnPaint( wxPaintEvent& event );
		void OnNumButtonClick( wxCommandEvent& event );
		void OnSetButtonClick( wxCommandEvent& event );
		void OnNoteButtonClick( wxCommandEvent& event );
		void OnClearButtonClick( wxCommandEvent& event );
		void OnSetFocus(wxFocusEvent& event);
	public:
		/** Constructor */
		DebugSudokuMainFrame( wxFrame *frame );
		virtual ~DebugSudokuMainFrame( );


    private:
		wxButton * numButtons[9];
        unsigned int row, col;
        Controls ctrlSelect;
        GameBoard * mGuessGB;
        GameBoard * mTrueGB;
        bool showChange;
	//// end generated class members

};

#endif // __debugMainFrame__
