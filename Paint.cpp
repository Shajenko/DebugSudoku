/***************************************************************
 * Name:      Paint.cpp
 * Purpose:   Code for Painting the Application Frame and components
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
#include "wx/dcbuffer.h"

void DebugSudokuFrame::OnPaint(wxPaintEvent& event)
{




}



void DebugSudokuFrame::OnGuessPanelEraseBG(wxEraseEvent &event)
{

}

void DebugSudokuFrame::OnTruePanelEraseBG(wxEraseEvent &event)
{

}

void DebugSudokuFrame::OnGuessPanelPaint(wxPaintEvent &event)
{
    wxPaintDC dc( m_panelGuess );
    wxBufferedDC bdc( &dc );

    m_panelGuess->DrawBoardBackground(bdc);
	m_panelGuess->DrawBoardNumbers(bdc);

    writetoLog(_("Repainting Guess Panel"), _("DebugSudoku.log"));

}

void DebugSudokuFrame::OnTruePanelPaint(wxPaintEvent &event)
{
    wxPaintDC dc( m_panelTrue );
    wxBufferedDC bdc( &dc );

    m_panelTrue->DrawBoardBackground(bdc);
	m_panelTrue->DrawBoardNumbers(bdc);

    writetoLog(_("Repainting True Panel"), _("DebugSudoku.log"));
}
