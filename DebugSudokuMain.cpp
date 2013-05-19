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
	wxDateTime datetime;
	wxString dateStr;
	datetime.SetToCurrent();
	dateStr << _("Sudokusolver opened ");
	dateStr << datetime.Format();

    mGuessGB = new GameBoard();
    mTrueGB = new GameBoard();

	writetoLog(_("-------------------------------------------"), _("DebugSudoku.log"));
	writetoLog(dateStr, _("DebugSudoku.log"));
	writetoLog(_(""), _("DebugSudoku.log"));
}

DebugSudokuFrame::~DebugSudokuFrame()
{
}

void DebugSudokuFrame::OnClose(wxCloseEvent &event)
{
	writetoLog(_("Closing Sudokusolver"), _("DebugSudoku.log"));
    Destroy();
}

void DebugSudokuFrame::OnQuit(wxCommandEvent &event)
{
	writetoLog(_("Closing Sudokusolver"), _("DebugSudoku.log"));
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

	writetoLog(_("Repainting"), _("DebugSudoku.log"));

}

void DebugSudokuFrame::OnNewPuzzle( wxCommandEvent& event )
{
	mTrueGB->Binit();
	mGuessGB->Binit();

	writetoLog(_("Initialized boards"), _("DebugSudoku.log"));

    mTrueGB->GenBoard(0,0);
    writetoLog(_("Generated board"), _("DebugSudoku.log"));

    m_panelTrue->CopyBoard(*mTrueGB);
    Refresh();
    writetoLog(_("Copied board to True Panel"), _("DebugSudoku.log"));

    mGuessGB->Copy(*mTrueGB);
    writetoLog(_("Copied board to GuessGB"), _("DebugSudoku.log"));

    mGuessGB->RemoveSquares(EASY);
    writetoLog(_("Full puzzle generated"), _("DebugSudoku.log"));

    m_panelGuess->CopyBoard(*mGuessGB);
    writetoLog(_("Copied board to Guess Panel"), _("DebugSudoku.log"));

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
					writetoLog(dString, _("DebugSudoku.log"));
					m_panelGuess->CopyBoard(*mGuessGB);
					Refresh();
					return;
				}
				else
				{
					dString.clear();
					dString << _("Not found at row ") << i << _(" col ") << j;
					writetoLog(dString, _("DebugSudoku.log"));
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
					writetoLog(dString, _("DebugSudoku.log"));
					m_panelGuess->CopyBoard(*mGuessGB);
					Refresh();
					return;
				}
				else
				{
					dString.clear();
					dString << _("Not found at row ") << i << _(" col ") << j;
					writetoLog(dString, _("DebugSudoku.log"));
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

void DebugSudokuFrame::OnScrambleBoards( wxCommandEvent& event )
{
    mGuessGB->ScrambleBoard(*mTrueGB);
    mGuessGB->ResetCols();
    mGuessGB->ResetRows();
    mGuessGB->ResetSectors();
    mGuessGB->RemoveAllPossibles();
    m_panelTrue->CopyBoard(*mTrueGB);
    m_panelGuess->CopyBoard(*mGuessGB);


    Refresh();
}
