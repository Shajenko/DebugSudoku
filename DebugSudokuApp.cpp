/***************************************************************
 * Name:      DebugSudokuApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Timothy Sonnier (tisonnier2000@gmail.com)
 * Created:   2013-03-30
 * Copyright: Timothy Sonnier ()
 * License:
 **************************************************************/

#ifdef WX_PRECOMP
#include "wx_pch.h"
#endif

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__

#include "DebugSudokuApp.h"
#include "debugMainFrame.h"

IMPLEMENT_APP(DebugSudokuApp);

bool DebugSudokuApp::OnInit()
{
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if(wxOK)
    {
        DebugSudokuMainFrame* frame = new DebugSudokuMainFrame(0L);
        frame->SetIcon(wxICON(aaaa)); // To Set App Icon
        frame->Show();
        SetTopWindow(frame);
        frame->Update();

    }


    return wxsOK;
}
