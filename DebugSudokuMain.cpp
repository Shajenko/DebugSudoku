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
    mTrueGB->GenBoard(0,0);
    mGuessGB->Copy(*mTrueGB);
    mGuessGB->RemoveSquares(EASY);
    mGuessGB->ResetCols();
    mGuessGB->ResetRows();
    mGuessGB->ResetSectors();
    mGuessGB->RemoveAllPossibles();

    m_panelGuess->CopyBoard(*mGuessGB);
    m_panelTrue->CopyBoard(*mTrueGB);

    Refresh();
}

void DebugSudokuFrame::OnNumButtonClick( wxCommandEvent& event )
{

}

void DebugSudokuFrame::OnSetButtonClick( wxCommandEvent& event )
{

}

void DebugSudokuFrame::OnNoteButtonClick( wxCommandEvent& event )
{

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

}

void DebugSudokuFrame::OnHiddenSingle( wxCommandEvent& event )
{

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
