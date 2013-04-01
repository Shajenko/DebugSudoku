///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Sep  8 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __DSudoku__
#define __DSudoku__

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
/// Class MainFrame
///////////////////////////////////////////////////////////////////////////////
class MainFrame : public wxFrame
{
	DECLARE_EVENT_TABLE()
	private:

		// Private event handlers
		void _wxFB_OnPaint( wxPaintEvent& event ){ OnPaint( event ); }
		void _wxFB_OnSetFocus( wxFocusEvent& event ){ OnSetFocus( event ); }
		void _wxFB_OnQuit( wxCommandEvent& event ){ OnQuit( event ); }
		void _wxFB_OnAbout( wxCommandEvent& event ){ OnAbout( event ); }
		void _wxFB_OnChar( wxKeyEvent& event ){ OnChar( event ); }
		void _wxFB_OnLeftUp( wxMouseEvent& event ){ OnLeftUp( event ); }
		void _wxFB_OnNumButtonClick( wxCommandEvent& event ){ OnNumButtonClick( event ); }
		void _wxFB_OnSetButtonClick( wxCommandEvent& event ){ OnSetButtonClick( event ); }
		void _wxFB_OnNoteButtonClick( wxCommandEvent& event ){ OnNoteButtonClick( event ); }
		void _wxFB_OnClearButtonClick( wxCommandEvent& event ){ OnClearButtonClick( event ); }


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

		// Virtual event handlers, overide them in your derived class
		virtual void OnPaint( wxPaintEvent& event ) { event.Skip(); }
		virtual void OnSetFocus( wxFocusEvent& event ) { event.Skip(); }
		virtual void OnQuit( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnAbout( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnChar( wxKeyEvent& event ) { event.Skip(); }
		virtual void OnLeftUp( wxMouseEvent& event ) { event.Skip(); }
		virtual void OnNumButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSetButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnNoteButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClearButtonClick( wxCommandEvent& event ) { event.Skip(); }


	public:

		MainFrame( wxWindow* parent, wxWindowID id = ID_GUIFRAME, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 732,511 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		~MainFrame();

};

#endif //__DSudoku__
