///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Sep  8 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __GUIFrame__
#define __GUIFrame__

#include <wx/string.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/menu.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/panel.h>
#include <wx/button.h>
#include <wx/sizer.h>
#include <wx/frame.h>
#include "GamePanel.h"

///////////////////////////////////////////////////////////////////////////

#define ID_GUIFRAME 1000

///////////////////////////////////////////////////////////////////////////////
/// Class GUIFrame
///////////////////////////////////////////////////////////////////////////////
class GUIFrame : public wxFrame
{
	private:

	protected:
		wxMenuBar* m_menubar1;
		wxMenu* m_menuFile;
		wxMenu* m_menuAbout;
		GamePanel* m_panelGuess;
		GamePanel* m_panelTrue;
		wxPanel* m_panelControls;
		wxPanel* m_panelNumbers;
		wxButton* m_button1;
		wxButton* m_button2;
		wxButton* m_button3;
		wxButton* m_button4;
		wxButton* m_button5;
		wxButton* m_button6;
		wxButton* m_button7;
		wxButton* m_button8;
		wxButton* m_button9;
		wxPanel* m_panelSettings;
		wxButton* m_buttonSet;
		wxButton* m_buttonNote;
		wxButton* m_buttonClear;
		wxPanel* m_panelDebug;
		wxButton* m_buttonSolve;
		wxButton* m_buttonNakedSingle;
		wxButton* m_buttonHiddenSingle;
		wxButton* m_buttonRemovePoss;
		wxButton* m_buttonScramble;

		// Virtual event handlers, overide them in your derived class
		virtual void OnSetFocus( wxFocusEvent& event ) { event.Skip(); }
		virtual void OnNewPuzzle( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnQuit( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnAbout( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnChar( wxKeyEvent& event ) { event.Skip(); }
		virtual void OnLeftUp( wxMouseEvent& event ) { event.Skip(); }
		virtual void OnPaint( wxPaintEvent& event ) { event.Skip(); }
		virtual void OnNumButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSetButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnNoteButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClearButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSolve( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnNakedSingle( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnHiddenSingle( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnRemovePossibles( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnScrambleBoards( wxCommandEvent& event ) { event.Skip(); }


	public:

		GUIFrame( wxWindow* parent, wxWindowID id = ID_GUIFRAME, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 727,511 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		~GUIFrame();

};

#endif //__GUIFrame__
