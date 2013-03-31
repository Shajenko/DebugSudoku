#include "debugMainFrame.h"

DebugSudokuMainFrame::DebugSudokuMainFrame( wxWindow* parent )
:
MainFrame( parent )
{

    numButtons[0] = m_button1;
    numButtons[1] = m_button2;
    numButtons[2] = m_button3;
    numButtons[3] = m_button4;
    numButtons[4] = m_button5;
    numButtons[5] = m_button6;
    numButtons[6] = m_button7;
    numButtons[7] = m_button8;
    numButtons[8] = m_button9;

	m_buttonSet->SetBackgroundColour(*wxBLUE);
    m_buttonSet->SetForegroundColour(*wxWHITE);

    mGuessGB = new GameBoard();
    mTrueGB = new GameBoard();

    row = 9;
    col = 9;

    Refresh();
    m_panelTrue->Refresh();

}

void DebugSudokuMainFrame::OnClose( wxCloseEvent& event )
{
// TODO: Implement OnClose
    m_panelNumbers->Destroy();
    m_panelSettings->Destroy();
    m_panelDebug->Destroy();
    m_panelControls->Destroy();
    m_panelTrue->Destroy();
    m_panelGuess->Destroy();
    Destroy();
}

void DebugSudokuMainFrame::OnChar( wxKeyEvent& event )
{
// TODO: Implement OnChar
}

void DebugSudokuMainFrame::OnLeftUp( wxMouseEvent& event )
{
// TODO: Implement OnLeftUp
}

void DebugSudokuMainFrame::OnPaint( wxPaintEvent& event )
{
// TODO: Implement OnPaint
    wxPaintDC dc1( m_panelGuess );
    wxPaintDC dc2( m_panelTrue);

    m_panelGuess->DrawBoardBackground(dc1);
    m_panelGuess->DrawBoardNumbers(dc1);

    m_panelTrue->DrawBoardBackground(dc2);
    m_panelTrue->DrawBoardNumbers(dc2);
}

void DebugSudokuMainFrame::OnNumButtonClick( wxCommandEvent& event )
{
// TODO: Implement OnNumButtonClick

    unsigned int i;
    wxString defaultStr;

    defaultStr.clear();
    for(i=0;i<9;i++)
    {
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
            numButtons[i]->SetBackgroundColour(wxNullColour);
            numButtons[i]->SetForegroundColour(wxNullColour);
        }
    }
    Refresh();
}

void DebugSudokuMainFrame::OnSetButtonClick( wxCommandEvent& event )
{
// TODO: Implement OnSetButtonClick
}

void DebugSudokuMainFrame::OnNoteButtonClick( wxCommandEvent& event )
{
// TODO: Implement OnNoteButtonClick
}

void DebugSudokuMainFrame::OnClearButtonClick( wxCommandEvent& event )
{
// TODO: Implement OnClearButtonClick
}

void DebugSudokuMainFrame::OnSetFocus(wxFocusEvent& event)
{
    Update();
}
