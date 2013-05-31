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


DebugSudokuFrame::DebugSudokuFrame(wxFrame *frame)
    : GUIFrame(frame)
{
	wxDateTime datetime;
	wxString dateStr;

	datetime.SetToCurrent();
	dateStr << _("Sudokusolver Debugger opened ");
	dateStr << datetime.Format();

	writetoLog(_("-------------------------------------------"), _("DebugSudoku.log"));
	writetoLog(dateStr, _("DebugSudoku.log"));
	writetoLog(_(""), _("DebugSudoku.log"));

	m_buttonSet->SetBackgroundColour(*wxBLUE);
    m_buttonSet->SetForegroundColour(*wxWHITE);

    mGuessGB = new GameBoard();
    mTrueGB = new GameBoard();

    numButtons[0] = m_button1;
    numButtons[1] = m_button2;
    numButtons[2] = m_button3;
    numButtons[3] = m_button4;
    numButtons[4] = m_button5;
    numButtons[5] = m_button6;
    numButtons[6] = m_button7;
    numButtons[7] = m_button8;
    numButtons[8] = m_button9;

	row = 9;
	col = 9;

	showChange = false;
}

DebugSudokuFrame::~DebugSudokuFrame()
{
}

