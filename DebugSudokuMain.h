/***************************************************************
 * Name:      DebugSudokuMain.h
 * Purpose:   Defines Application Frame
 * Author:    Tim Sonnier ()
 * Created:   2013-03-29
 * Copyright: Tim Sonnier ()
 * License:
 **************************************************************/

#ifndef DEBUGSUDOKUMAIN_H
#define DEBUGSUDOKUMAIN_H



#include "DebugSudokuApp.h"


#include "GUIFrame.h"

class DebugSudokuFrame: public GUIFrame
{
    public:
        DebugSudokuFrame(wxFrame *frame);
        ~DebugSudokuFrame();
    private:
        virtual void OnClose(wxCloseEvent& event);
        virtual void OnQuit(wxCommandEvent& event);
        virtual void OnAbout(wxCommandEvent& event);
};

#endif // DEBUGSUDOKUMAIN_H
