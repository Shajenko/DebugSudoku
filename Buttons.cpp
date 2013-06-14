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
    unsigned int i, inNum;
    wxString defaultStr;

    defaultStr.clear();
    for(i=0;i<9;i++)
        if(numButtons[i]->GetId() == event.GetId())
            inNum = i+1;
    if(ctrlSelect==SET)
    {
        if(row<9&&row>=0&&col<9&&col>=0&&!mGuessGB->GetShown(row, col))
        {
            mGuessGB->SetVal(row, col, inNum);
            // todo - remove possibles from other squares
        }
    }
    else if (ctrlSelect==NOTE)
    {
        if(mGuessGB->GetPossibles(row, col, inNum))
            mGuessGB->RemovePossibles(row, col, inNum);
        else
            mGuessGB->SetPossibles(row, col, inNum);
    }

    m_panelGuess->CopyBoard(*mGuessGB);
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
    mGuessGB->ClearPossibles(row, col);
    mGuessGB->SetSquare(0, row, col);
    m_panelGuess->CopyBoard(*mGuessGB);

    Refresh();
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
	wxString dString;
	std::vector<GameSquare> vec;
	std::vector<GameSquare>::iterator it;
	GameSquare sq, *tempsq;

	dString.clear();

	if(showChange)  // already found the next square, implement it
	{
		vec = m_panelGuess->GetGreenSquares();
		it = vec.begin();
		sq.Copy(*it);
		i = sq.GetRow();
		j = sq.GetCol();
		val = sq.GetVal();
		mGuessGB->SetVal(i,j,val);
		m_panelGuess->CopyBoard(*mGuessGB);
		Refresh();
		m_panelGuess->ClearGreenSquares();
		showChange = false;
		return;

	}


	for(i=0;i<9;i++)
		for(j=0;j<9;j++)
		{
			val = mGuessGB->GetVal(i,j);
			if( val == 0)
			{
				tempsq = mGuessGB->NakedSingle(i,j);
				sq.Copy(*tempsq);
				if(sq.GetVal() != 0)
				{
					m_panelGuess->PushGreenSquares(sq);
					dString.clear();
					dString << _("Found at row ") << i << _(" col ") << j;
					writetoLog(dString, _("DebugSudoku.log"));
					m_panelGuess->CopyBoard(*mGuessGB);
					Refresh();
					showChange = true;
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
	wxString dString;

	std::vector<GameSquare> vec;
	std::vector<GameSquare>::iterator it;
	GameSquare sq, *tempsq;

	dString.clear();

	if(showChange)  // already found the next square, implement it
	{
		vec = m_panelGuess->GetGreenSquares();
		it = vec.begin();
		sq.Copy(*it);
		i = sq.GetRow();
		j = sq.GetCol();
		val = sq.GetVal();
		mGuessGB->SetVal(i,j,val);
		m_panelGuess->CopyBoard(*mGuessGB);
		Refresh();
		m_panelGuess->ClearGreenSquares();
		showChange = false;
		return;

	}

	for(i=0;i<9;i++)
		for(j=0;j<9;j++)
		{
			val = mGuessGB->GetVal(i,j);
			if( val == 0)
			{
				tempsq = mGuessGB->HiddenSingle(i,j);
				sq.Copy(*tempsq);
				if(sq.GetVal() != 0)
				{
					m_panelGuess->PushGreenSquares(sq);
					dString.clear();
					dString << _("Found at row ") << i << _(" col ") << j;
					writetoLog(dString, _("DebugSudoku.log"));
					m_panelGuess->CopyBoard(*mGuessGB);
					Refresh();
					showChange = true;
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

void DebugSudokuFrame::OnNakedDouble( wxCommandEvent& event )
{
	unsigned int i,j, val;
	wxString dString;

	std::vector<GameSquare> * vec;
	std::vector<GameSquare> vec2;
	std::vector<GameSquare>::iterator it;
	GameSquare * sq;

	dString.clear();

	sq = new GameSquare;

	if(showChange)  // already found the next square, implement it
	{
		// todo - implement

		vec2 = m_panelGuess->GetRedSquares();
		sq->Copy(vec2.back());

		i = sq->GetRow();
		j = sq->GetCol();
		val = sq->GetVal();

		mGuessGB->RemovePossibles(i, j, val);
		m_panelGuess->CopyBoard(*mGuessGB);

		// Remove the value from the red squares, clear red and green square lists
		m_panelGuess->ClearGreenSquares();
		m_panelGuess->ClearRedSquares();
		showChange = false;

		delete sq;
		Refresh();
		return;
	}

	// Find the showChange and let it be shown on the board

	for(i=0;i<9;i++)
		for(j=0;j<9;j++)
		{
			val = mGuessGB->GetVal(i,j);
			if( val == 0)
			{
				vec = mGuessGB->NakedPair(i,j);
				if(vec->size() > 0)
				{
					dString.clear();
					dString << _("Pushing to colored rectangles from button \n");

					m_panelGuess->ClearGreenSquares();
					m_panelGuess->ClearRedSquares();
					for(it = vec->begin(); it != vec->end(); ++it)
					{
						sq->Copy(*it);
						if(it + 1 == vec->end())
						{
							m_panelGuess->PushRedSquares(*sq);
							dString << _("Pushing red ") << _("Row ") << sq->GetRow() << _(" col ") << sq->GetCol() << _(" val ") << sq->GetVal() << _("\n");
						}
						else
						{
							m_panelGuess->PushGreenSquares(*sq);
							dString << _("Pushing green ") << _("Row ") << sq->GetRow() << _(" col ") << sq->GetCol() << _(" val ") << sq->GetVal() << _("\n");
						}
					}

					writetoLog(dString, _("ColoredRect.log"));

					dString.clear();
					dString << _("Naked Pair found at row ") << i << _(" col ") << j;
					writetoLog(dString, _("DebugSudoku.log"));
					m_panelGuess->CopyBoard(*mGuessGB);
					Refresh();
					showChange = true;
					delete sq;
					return;
				}
				else
				{

				}
			}
		}
	dString.clear();
	dString << _("No Naked Pair found");
	writetoLog(dString, _("DebugSudoku.log"));

	delete sq;
}

void DebugSudokuFrame::OnHiddenDouble( wxCommandEvent& event )
{

}
