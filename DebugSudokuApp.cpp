/***************************************************************
 * Name:      DebugSudokuApp.cpp
 * Purpose:   Code for Application Class
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

#include "DebugSudokuApp.h"
#include "DebugSudokuMain.h"

IMPLEMENT_APP(DebugSudokuApp);

bool DebugSudokuApp::OnInit()
{
    DebugSudokuFrame* frame = new DebugSudokuFrame(0L);
    frame->SetIcon(wxICON(aaaa)); // To Set App Icon
    frame->Show();
    
    return true;
}
