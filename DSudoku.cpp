///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Sep  8 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "GamePanel.h"

#include "DSudoku.h"

///////////////////////////////////////////////////////////////////////////

BEGIN_EVENT_TABLE( MainFrame, wxFrame )
	EVT_PAINT( MainFrame::_wxFB_OnPaint )
	EVT_SET_FOCUS( MainFrame::_wxFB_OnSetFocus )
	EVT_MENU( wxID_ANY, MainFrame::_wxFB_OnQuit )
	EVT_MENU( wxID_ANY, MainFrame::_wxFB_OnAbout )
	/*#error wxKeyEvent does not propogate, so wxEVT_CHAR from m_panelGuess can only be handled with Connect()
	#error wxMouseEvent does not propogate, so wxEVT_LEFT_UP from m_panelGuess can only be handled with Connect()
	#error wxPaintEvent does not propogate, so wxEVT_PAINT from m_panelGuess can only be handled with Connect()
	#error wxKeyEvent does not propogate, so wxEVT_CHAR from m_panelTrue can only be handled with Connect()
	#error wxMouseEvent does not propogate, so wxEVT_LEFT_UP from m_panelTrue can only be handled with Connect()
	#error wxPaintEvent does not propogate, so wxEVT_PAINT from m_panelTrue can only be handled with Connect()*/
	EVT_BUTTON( wxID_ANY, MainFrame::_wxFB_OnNumButtonClick )
	EVT_BUTTON( wxID_ANY, MainFrame::_wxFB_OnNumButtonClick )
	EVT_BUTTON( wxID_ANY, MainFrame::_wxFB_OnNumButtonClick )
	EVT_BUTTON( wxID_ANY, MainFrame::_wxFB_OnNumButtonClick )
	EVT_BUTTON( wxID_ANY, MainFrame::_wxFB_OnNumButtonClick )
	EVT_BUTTON( wxID_ANY, MainFrame::_wxFB_OnNumButtonClick )
	EVT_BUTTON( wxID_ANY, MainFrame::_wxFB_OnNumButtonClick )
	EVT_BUTTON( wxID_ANY, MainFrame::_wxFB_OnNumButtonClick )
	EVT_BUTTON( wxID_ANY, MainFrame::_wxFB_OnNumButtonClick )
	EVT_BUTTON( wxID_ANY, MainFrame::_wxFB_OnSetButtonClick )
	EVT_BUTTON( wxID_ANY, MainFrame::_wxFB_OnNoteButtonClick )
	EVT_BUTTON( wxID_ANY, MainFrame::_wxFB_OnClearButtonClick )
END_EVENT_TABLE()

MainFrame::MainFrame( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	m_menubar1 = new wxMenuBar( 0 );
	m_menuFile = new wxMenu();
	wxMenuItem* m_menuItemQuit;
	m_menuItemQuit = new wxMenuItem( m_menuFile, wxID_ANY, wxString( wxT("Quit") ) , wxEmptyString, wxITEM_NORMAL );
	m_menuFile->Append( m_menuItemQuit );

	m_menubar1->Append( m_menuFile, wxT("&File") );

	m_menuAbout = new wxMenu();
	wxMenuItem* m_menuItemAbout;
	m_menuItemAbout = new wxMenuItem( m_menuAbout, wxID_ANY, wxString( wxT("About...") ) , wxEmptyString, wxITEM_NORMAL );
	m_menuAbout->Append( m_menuItemAbout );

	m_menubar1->Append( m_menuAbout, wxT("&About") );

	this->SetMenuBar( m_menubar1 );

	wxFlexGridSizer* fgSizer1;
	fgSizer1 = new wxFlexGridSizer( 2, 2, 0, 0 );
	fgSizer1->SetFlexibleDirection( wxBOTH );
	fgSizer1->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_panelGuess = new GamePanel( this, wxID_ANY, wxDefaultPosition, wxSize( 350,350 ), wxFULL_REPAINT_ON_RESIZE|wxSIMPLE_BORDER );
	m_panelGuess->SetMinSize( wxSize( 350,350 ) );

	fgSizer1->Add( m_panelGuess, 0, wxALL, 5 );

	m_panelTrue = new GamePanel( this, wxID_ANY, wxDefaultPosition, wxSize( 350,350 ), wxFULL_REPAINT_ON_RESIZE|wxSIMPLE_BORDER );
	m_panelTrue->SetMinSize( wxSize( 350,350 ) );

	fgSizer1->Add( m_panelTrue, 0, wxALL, 5 );

	m_panelControls = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );

	m_panelNumbers = new wxPanel( m_panelControls, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_panelNumbers->SetExtraStyle( wxWS_EX_PROCESS_UI_UPDATES );

	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxHORIZONTAL );

	m_button1 = new wxButton( m_panelNumbers, wxID_ANY, wxT("1"), wxDefaultPosition, wxSize( 25,25 ), 0 );
	bSizer2->Add( m_button1, 0, wxALL, 5 );

	m_button2 = new wxButton( m_panelNumbers, wxID_ANY, wxT("2"), wxDefaultPosition, wxSize( 25,25 ), 0 );
	bSizer2->Add( m_button2, 0, wxALL, 5 );

	m_button3 = new wxButton( m_panelNumbers, wxID_ANY, wxT("3"), wxDefaultPosition, wxSize( 25,25 ), 0 );
	bSizer2->Add( m_button3, 0, wxALL, 5 );

	m_button4 = new wxButton( m_panelNumbers, wxID_ANY, wxT("4"), wxDefaultPosition, wxSize( 25,25 ), 0 );
	bSizer2->Add( m_button4, 0, wxALL, 5 );

	m_button5 = new wxButton( m_panelNumbers, wxID_ANY, wxT("5"), wxDefaultPosition, wxSize( 25,25 ), 0 );
	bSizer2->Add( m_button5, 0, wxALL, 5 );

	m_button6 = new wxButton( m_panelNumbers, wxID_ANY, wxT("6"), wxDefaultPosition, wxSize( 25,25 ), 0 );
	bSizer2->Add( m_button6, 0, wxALL, 5 );

	m_button7 = new wxButton( m_panelNumbers, wxID_ANY, wxT("7"), wxDefaultPosition, wxSize( 25,25 ), 0 );
	bSizer2->Add( m_button7, 0, wxALL, 5 );

	m_button8 = new wxButton( m_panelNumbers, wxID_ANY, wxT("8"), wxDefaultPosition, wxSize( 25,25 ), 0 );
	bSizer2->Add( m_button8, 0, wxALL, 5 );

	m_button9 = new wxButton( m_panelNumbers, wxID_ANY, wxT("9"), wxDefaultPosition, wxSize( 25,25 ), 0 );
	bSizer2->Add( m_button9, 0, wxALL, 5 );

	m_panelNumbers->SetSizer( bSizer2 );
	m_panelNumbers->Layout();
	bSizer2->Fit( m_panelNumbers );
	bSizer1->Add( m_panelNumbers, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );

	m_panelSettings = new wxPanel( m_panelControls, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_panelSettings->SetExtraStyle( wxWS_EX_PROCESS_UI_UPDATES );

	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxHORIZONTAL );

	m_buttonSet = new wxButton( m_panelSettings, wxID_ANY, wxT("Set"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( m_buttonSet, 0, wxALL, 5 );

	m_buttonNote = new wxButton( m_panelSettings, wxID_ANY, wxT("Note"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( m_buttonNote, 0, wxALL, 5 );

	m_buttonClear = new wxButton( m_panelSettings, wxID_ANY, wxT("Clear"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( m_buttonClear, 0, wxALL, 5 );

	m_panelSettings->SetSizer( bSizer3 );
	m_panelSettings->Layout();
	bSizer3->Fit( m_panelSettings );
	bSizer1->Add( m_panelSettings, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	m_panelControls->SetSizer( bSizer1 );
	m_panelControls->Layout();
	bSizer1->Fit( m_panelControls );
	fgSizer1->Add( m_panelControls, 0, wxALIGN_CENTER_HORIZONTAL|wxALL|wxEXPAND, 5 );

	m_panelDebug = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	fgSizer1->Add( m_panelDebug, 0, wxALL|wxEXPAND, 5 );

	this->SetSizer( fgSizer1 );
	this->Layout();

	this->Centre( wxBOTH );
}

MainFrame::~MainFrame()
{
}
