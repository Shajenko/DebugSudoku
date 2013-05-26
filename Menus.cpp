/***************************************************************
 * Name:      Menus.cpp
 * Purpose:   Code for Menus in Application Frame
 * Author:    Tim Sonnier ()
 * Created:   2013-05-25
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

void DebugSudokuFrame::OnNewPuzzle( wxCommandEvent& event )
{
	wxDateTime start, finish;
	wxTimeSpan totaltime;
	wxString timestr;

	start.SetToCurrent();

    mGuessGB->Copy(*mTrueGB);
    writetoLog(_("Copied board to GuessGB"), _("DebugSudoku.log"));

    mGuessGB->RemoveSquares(EASY);
    writetoLog(_("Full puzzle generated"), _("DebugSudoku.log"));

    finish.SetToCurrent();

    totaltime = finish - start;
    timestr << _("Total time taken - ") << totaltime.GetSeconds() << _(" seconds ") << totaltime.GetMilliseconds() << _(" milliseconds");

    writetoLog( timestr, _("DebugSudoku.log"));

    m_panelGuess->CopyBoard(*mGuessGB);
    writetoLog(_("Copied board to Guess Panel"), _("DebugSudoku.log"));

    Refresh();
}

void DebugSudokuFrame::OnNewBase( wxCommandEvent& event )
{
	wxDateTime start, finish;
	wxTimeSpan totaltime;
	wxString timestr;

	mTrueGB->Binit();
	mGuessGB->Binit();


	start.SetToCurrent();

	writetoLog(_("Initialized boards"), _("DebugSudoku.log"));

    mTrueGB->GenBoard(0,0);
    writetoLog(_("Generated board"), _("DebugSudoku.log"));

    m_panelTrue->CopyBoard(*mTrueGB);
    Refresh();

    finish.SetToCurrent();

    totaltime = finish - start;
    timestr << _("Total time taken - ") << totaltime.GetSeconds() << _(" seconds ") << totaltime.GetMilliseconds() << _(" milliseconds");

    writetoLog( timestr, _("DebugSudoku.log"));
    writetoLog(_("Copied board to True Panel"), _("DebugSudoku.log"));

    Refresh();

}


void DebugSudokuFrame::OnRemovePossibles( wxCommandEvent& event )
{
    mGuessGB->RemoveAllPossibles();
    m_panelGuess->CopyBoard(*mGuessGB);

    Refresh();
}

void DebugSudokuFrame::OnResetPossibles( wxCommandEvent& event)
{

	Refresh();
}

void DebugSudokuFrame::OnResetRowColSec(wxCommandEvent& event)
{
	mGuessGB->ResetCols();
	mGuessGB->ResetRows();
	mGuessGB->ResetSectors();

	Refresh();
}




void DebugSudokuFrame::OnRemoveLayer( wxCommandEvent& event )
{

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
