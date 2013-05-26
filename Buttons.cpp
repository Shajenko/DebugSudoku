/***************************************************************
 * Name:      Buttons.cpp
 * Purpose:   Code for Buttons in Application Frame
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

void DebugSudokuFrame::OnNumButtonClick( wxCommandEvent& event )
{
    unsigned int i;
    wxString defaultStr;

    defaultStr.clear();
    for(i=0;i<9;i++)
        if(numButtons[i]->GetId() == event.GetId())
        {
            if(ctrlSelect==SET)
            {
                if(row<9&&row>=0&&col<9&&col>=0&&!mGuessGB->GetShown(row, col))
                {
                    mGuessGB->SetVal(row, col, i+1);
                    // todo - remove possibles from other squares
                }



            }
            else if (ctrlSelect==NOTE)
            {
                if(mGuessGB->GetPossibles(row, col, i+1))
                    mGuessGB->RemovePossibles(row, col, i+1);
                else
                    mGuessGB->SetPossibles(row, col, i+1);
            }
        }
    Refresh();
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
