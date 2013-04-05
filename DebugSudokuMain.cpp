/***************************************************************
 * Name:      DebugSudokuMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Tim Sonnier ()
 * Created:   2013-03-31
 * Copyright: Tim Sonnier ()
 * License:
 **************************************************************/

#ifdef WX_PRECOMP
#include "wx_pch.h"
#endif

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__

#include "DebugSudokuMain.h"

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__WXMAC__)
        wxbuild << _T("-Mac");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}


DebugSudokuFrame::DebugSudokuFrame(wxFrame *frame)
    : GUIFrame(frame)
{
    mGuessGB = new GameBoard();
    mTrueGB = new GameBoard();
}

DebugSudokuFrame::~DebugSudokuFrame()
{
}

void DebugSudokuFrame::OnClose(wxCloseEvent &event)
{
    Destroy();
}

void DebugSudokuFrame::OnQuit(wxCommandEvent &event)
{
    Destroy();
}

void DebugSudokuFrame::OnAbout(wxCommandEvent &event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void DebugSudokuFrame::OnPaint(wxPaintEvent& event)
{
    wxPaintDC dc1( m_panelGuess );
    wxPaintDC dc2( m_panelTrue );

	m_panelGuess->DrawBoardBackground(dc1);
	m_panelGuess->DrawBoardNumbers(dc1);

    m_panelTrue->DrawBoardBackground(dc2);
	m_panelTrue->DrawBoardNumbers(dc2);

}

void DebugSudokuFrame::OnNewPuzzle( wxCommandEvent& event )
{
	mTrueGB->Binit();
	mGuessGB->Binit();

    mTrueGB->GenBoard(0,0);
    m_panelTrue->CopyBoard(*mTrueGB);
    Refresh();

    mGuessGB->Copy(*mTrueGB);
    mGuessGB->RemoveSquares(EASY);
    m_panelGuess->CopyBoard(*mGuessGB);
    Refresh();
}

void DebugSudokuFrame::OnNumButtonClick( wxCommandEvent& event )
{
}

void DebugSudokuFrame::OnSetButtonClick( wxCommandEvent& event )
{
	m_buttonSet->SetBackgroundColour(*wxBLUE);
    m_buttonSet->SetForegroundColour(*wxWHITE);
    m_buttonNote->SetBackgroundColour(wxNullColour);
    m_buttonNote->SetForegroundColour(*wxBLACK);
    m_buttonClear->SetBackgroundColour(wxNullColour);
    m_buttonClear->SetForegroundColour(*wxBLACK);

	ctrlSelect = SET;
}

void DebugSudokuFrame::OnNoteButtonClick( wxCommandEvent& event )
{
	m_buttonSet->SetBackgroundColour(wxNullColour);
    m_buttonSet->SetForegroundColour(*wxBLACK);
    m_buttonNote->SetBackgroundColour(*wxBLUE);
    m_buttonNote->SetForegroundColour(*wxWHITE);
    m_buttonClear->SetBackgroundColour(wxNullColour);
    m_buttonClear->SetForegroundColour(*wxBLACK);

	ctrlSelect = NOTE;
}

void DebugSudokuFrame::OnClearButtonClick( wxCommandEvent& event )
{

}

void DebugSudokuFrame::OnSolve( wxCommandEvent& event )
{
    mGuessGB->Solve();
    m_panelGuess->CopyBoard(*mGuessGB);

    Refresh();
}

void DebugSudokuFrame::OnNakedSingle( wxCommandEvent& event )
{
	unsigned int i,j, val;
	bool found=false;
	wxString dString;

	dString.clear();

	for(i=0;i<9;i++)
		for(j=0;j<9;j++)
		{
			val = mGuessGB->GetVal(i,j);
			if( val == 0)
			{
				found = mGuessGB->NakedSingle(i,j);
				if(found)
				{
					dString.clear();
					dString << _("Found at row ") << i << _(" col ") << j;
					//wxMessageBox(dString);
					m_panelGuess->CopyBoard(*mGuessGB);
					Refresh();
					return;
				}
			}
		}
}

void DebugSudokuFrame::OnHiddenSingle( wxCommandEvent& event )
{
	unsigned int i,j, val;
	bool found=false;
	wxString dString;

	dString.clear();

	for(i=0;i<9;i++)
		for(j=0;j<9;j++)
		{
			val = mGuessGB->GetVal(i,j);
			if( val == 0)
			{
				found = mGuessGB->HiddenSingle(i,j);
				if(found)
				{
					dString.clear();
					dString << _("Found at row ") << i << _(" col ") << j;
					//wxMessageBox(dString);
					m_panelGuess->CopyBoard(*mGuessGB);
					Refresh();
					return;
				}
			}
		}
}

void DebugSudokuFrame::OnRemovePossibles( wxCommandEvent& event )
{
    mGuessGB->ResetCols();
    mGuessGB->ResetRows();
    mGuessGB->ResetSectors();
    mGuessGB->RemoveAllPossibles();
    m_panelGuess->CopyBoard(*mGuessGB);

    Refresh();
}
