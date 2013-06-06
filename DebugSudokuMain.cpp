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

void DebugSudokuFrame::OnSavePuzzle(wxCommandEvent& event)
{
    wxString text;
	wxFile save_file(_("savefile.gb"), wxFile::write );
	if(!save_file.IsOpened())
		save_file.Create(_("savefile.gb"));

    text.clear();

    // Write the board to the file, one square at a time
    for(int i = 0; i < 9; i++)
        for(int j=0; j < 9; j++)
        {
            text << mTrueGB->GetVal(i, j) << _(",") << mGuessGB->GetShown(i, j) << _(";");
        }
    text << _("\n");
    save_file.Write(text);
    save_file.Close();

}

void DebugSudokuFrame::OnLoadPuzzle(wxCommandEvent& event)
{
    wxString text, tok;
    wxStringTokenizer txtTok;
    unsigned int val, shown;
	wxFile save_file(_("savefile.gb"), wxFile::read );
	if(!save_file.IsOpened())
	{
		wxMessageBox(_("Error opening savefile.gb"));
		return;
	}
	text.clear();

	mTrueGB->Binit();
	mGuessGB->Binit();

	save_file.Read(&text, save_file.Length());
    save_file.Close();

    txtTok.SetString(text, _(",;"));

    // Write the board from the file, one square at a time
    for(int i = 0; i < 9; i++)
        for(int j=0; j < 9; j++)
        {
        	tok = txtTok.GetNextToken();
        	val = wxAtoi(tok);
        	if(val > 9 || val < 0)
        	{
        		wxMessageBox(_("Error writing to val"));
        		save_file.Close();
        		return;
        	}

        	tok = txtTok.GetNextToken();
			shown = wxAtoi(tok);
        	if(shown != 0 || shown != 1)
        	{
        		wxMessageBox(_("Error writing to shown"));
        		save_file.Close();
        		return;
        	}

            mTrueGB->SetVal(i, j, val);
            if(shown == 1)
			{
				mGuessGB->SetVal(i, j, val);
				mGuessGB->SetShown(i, j, true);
			}
        }
}
