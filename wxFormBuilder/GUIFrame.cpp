///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Sep  8 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "GamePanel.h"

#include "GUIFrame.h"

///////////////////////////////////////////////////////////////////////////

GUIFrame::GUIFrame( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	m_menubar1 = new wxMenuBar( 0 );
	m_menuFile = new wxMenu();
	wxMenuItem* m_menuItemQuit;
	m_menuItemQuit = new wxMenuItem( m_menuFile, wxID_ANY, wxString( wxT("Quit") ) , wxEmptyString, wxITEM_NORMAL );
	m_menuFile->Append( m_menuItemQuit );
	
	wxMenuItem* m_menuItemNewPuzzle;
	m_menuItemNewPuzzle = new wxMenuItem( m_menuFile, wxID_ANY, wxString( wxT("New Puzzle") ) , wxEmptyString, wxITEM_NORMAL );
	m_menuFile->Append( m_menuItemNewPuzzle );
	
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
	wxGridSizer* gSizer1;
	gSizer1 = new wxGridSizer( 3, 4, 0, 0 );
	
	m_buttonSolve = new wxButton( m_panelDebug, wxID_ANY, wxT("Solve"), wxDefaultPosition, wxDefaultSize, 0 );
	gSizer1->Add( m_buttonSolve, 0, wxALL, 2 );
	
	m_buttonNakedSingle = new wxButton( m_panelDebug, wxID_ANY, wxT("Naked Single"), wxDefaultPosition, wxDefaultSize, 0 );
	gSizer1->Add( m_buttonNakedSingle, 0, wxALL, 2 );
	
	m_buttonHiddenSingle = new wxButton( m_panelDebug, wxID_ANY, wxT("Hidden Single"), wxDefaultPosition, wxDefaultSize, 0 );
	gSizer1->Add( m_buttonHiddenSingle, 0, wxALL, 2 );
	
	m_buttonRemovePoss = new wxButton( m_panelDebug, wxID_ANY, wxT("Remove Possibles"), wxDefaultPosition, wxDefaultSize, 0 );
	gSizer1->Add( m_buttonRemovePoss, 0, wxALL, 2 );
	
	m_panelDebug->SetSizer( gSizer1 );
	m_panelDebug->Layout();
	gSizer1->Fit( m_panelDebug );
	fgSizer1->Add( m_panelDebug, 0, wxALL|wxEXPAND, 5 );
	
	this->SetSizer( fgSizer1 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	this->Connect( wxEVT_SET_FOCUS, wxFocusEventHandler( GUIFrame::OnSetFocus ) );
	this->Connect( m_menuItemQuit->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIFrame::OnQuit ) );
	this->Connect( m_menuItemNewPuzzle->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIFrame::OnNewPuzzle ) );
	this->Connect( m_menuItemAbout->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIFrame::OnAbout ) );
	m_panelGuess->Connect( wxEVT_CHAR, wxKeyEventHandler( GUIFrame::OnChar ), NULL, this );
	m_panelGuess->Connect( wxEVT_LEFT_UP, wxMouseEventHandler( GUIFrame::OnLeftUp ), NULL, this );
	m_panelGuess->Connect( wxEVT_PAINT, wxPaintEventHandler( GUIFrame::OnPaint ), NULL, this );
	m_panelTrue->Connect( wxEVT_CHAR, wxKeyEventHandler( GUIFrame::OnChar ), NULL, this );
	m_panelTrue->Connect( wxEVT_LEFT_UP, wxMouseEventHandler( GUIFrame::OnLeftUp ), NULL, this );
	m_panelTrue->Connect( wxEVT_PAINT, wxPaintEventHandler( GUIFrame::OnPaint ), NULL, this );
	m_button1->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::OnNumButtonClick ), NULL, this );
	m_button2->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::OnNumButtonClick ), NULL, this );
	m_button3->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::OnNumButtonClick ), NULL, this );
	m_button4->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::OnNumButtonClick ), NULL, this );
	m_button5->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::OnNumButtonClick ), NULL, this );
	m_button6->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::OnNumButtonClick ), NULL, this );
	m_button7->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::OnNumButtonClick ), NULL, this );
	m_button8->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::OnNumButtonClick ), NULL, this );
	m_button9->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::OnNumButtonClick ), NULL, this );
	m_buttonSet->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::OnSetButtonClick ), NULL, this );
	m_buttonNote->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::OnNoteButtonClick ), NULL, this );
	m_buttonClear->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::OnClearButtonClick ), NULL, this );
	m_buttonSolve->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::OnSolve ), NULL, this );
	m_buttonNakedSingle->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::OnNakedSingle ), NULL, this );
	m_buttonHiddenSingle->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::OnHiddenSingle ), NULL, this );
	m_buttonRemovePoss->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::OnRemovePossibles ), NULL, this );
}

GUIFrame::~GUIFrame()
{
	// Disconnect Events
	this->Disconnect( wxEVT_SET_FOCUS, wxFocusEventHandler( GUIFrame::OnSetFocus ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIFrame::OnQuit ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIFrame::OnNewPuzzle ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIFrame::OnAbout ) );
	m_panelGuess->Disconnect( wxEVT_CHAR, wxKeyEventHandler( GUIFrame::OnChar ), NULL, this );
	m_panelGuess->Disconnect( wxEVT_LEFT_UP, wxMouseEventHandler( GUIFrame::OnLeftUp ), NULL, this );
	m_panelGuess->Disconnect( wxEVT_PAINT, wxPaintEventHandler( GUIFrame::OnPaint ), NULL, this );
	m_panelTrue->Disconnect( wxEVT_CHAR, wxKeyEventHandler( GUIFrame::OnChar ), NULL, this );
	m_panelTrue->Disconnect( wxEVT_LEFT_UP, wxMouseEventHandler( GUIFrame::OnLeftUp ), NULL, this );
	m_panelTrue->Disconnect( wxEVT_PAINT, wxPaintEventHandler( GUIFrame::OnPaint ), NULL, this );
	m_button1->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::OnNumButtonClick ), NULL, this );
	m_button2->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::OnNumButtonClick ), NULL, this );
	m_button3->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::OnNumButtonClick ), NULL, this );
	m_button4->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::OnNumButtonClick ), NULL, this );
	m_button5->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::OnNumButtonClick ), NULL, this );
	m_button6->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::OnNumButtonClick ), NULL, this );
	m_button7->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::OnNumButtonClick ), NULL, this );
	m_button8->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::OnNumButtonClick ), NULL, this );
	m_button9->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::OnNumButtonClick ), NULL, this );
	m_buttonSet->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::OnSetButtonClick ), NULL, this );
	m_buttonNote->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::OnNoteButtonClick ), NULL, this );
	m_buttonClear->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::OnClearButtonClick ), NULL, this );
	m_buttonSolve->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::OnSolve ), NULL, this );
	m_buttonNakedSingle->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::OnNakedSingle ), NULL, this );
	m_buttonHiddenSingle->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::OnHiddenSingle ), NULL, this );
	m_buttonRemovePoss->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::OnRemovePossibles ), NULL, this );
	
}
