/***************************************************************
 * Name:      KeyboardInput.cpp
 * Purpose:   Code for Input to the Application Frame and components
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

void DebugSudokuFrame::OnGuessPanelKeyUp(wxKeyEvent &event)
{
    unsigned int keyUp, inNum;
    wxString debugStr;

    keyUp = event.GetKeyCode();


    if(keyUp >= '0' && keyUp <= '9')
        inNum = keyUp -'0';
    else if(keyUp >= 324 && keyUp <=333)  // Numpad values for 0 - 9
        inNum = keyUp-324;
    if(!mGuessGB->GetShown(row, col) && inNum >= 0 && inNum <=9)
    {
        if(ctrlSelect==SET)
        {
            mGuessGB->SetVal(row, col, inNum);
            m_panelGuess->CopyBoard(*mGuessGB);
        }
        else if (ctrlSelect==NOTE)
        {
            mGuessGB->SetPossibles(row, col, inNum);
            m_panelGuess->CopyBoard(*mGuessGB);
        }
    }



    if((keyUp == WXK_LEFT || keyUp == WXK_NUMPAD_LEFT) && col > 0)
        col--;
    if((keyUp == WXK_RIGHT || keyUp == WXK_NUMPAD_RIGHT) && col < 8)
        col++;
    if((keyUp == WXK_UP || keyUp == WXK_NUMPAD_UP) && row > 0)
        row--;
    if((keyUp == WXK_DOWN || keyUp == WXK_NUMPAD_DOWN) && row < 8)
        row++;

	m_panelGuess->SetRow(row);
	m_panelGuess->SetCol(col);

    Refresh();
}

void DebugSudokuFrame::OnGuessPanelLeftUp(wxMouseEvent &event)
{
 	long xpos, ypos;
	unsigned int r, c;
	wxString pString;
	unsigned int spSq = 0;
    unsigned int smallSide;

    event.GetPosition(&xpos, &ypos);

    wxSize sz = m_panelGuess->GetClientSize();
    if (sz.x < sz.y)
        smallSide = sz.x;
    else
        smallSide = sz.y;

    spSq = smallSide / 9;
    r = ypos / spSq;
    c = xpos / spSq;


	/*pString << _("Row ") << row << _(" Col ") << col;
	wxMessageBox(pString);*/

	SetRow(r);
	SetCol(c);
	m_panelGuess->SetRow(r);
	m_panelGuess->SetCol(c);



	Refresh();
}
