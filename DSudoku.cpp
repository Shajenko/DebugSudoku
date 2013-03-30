///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Sep  8 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "GamePanel.h"

#include "DSudoku.h"

///////////////////////////////////////////////////////////////////////////

MainFrame::MainFrame( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxGridSizer* gSizer1;
	gSizer1 = new wxGridSizer( 2, 2, 0, 0 );
	
	m_panelGuess = new GamePanel( this, wxID_ANY, wxDefaultPosition, wxSize( 300,300 ), wxTAB_TRAVERSAL );
	m_panelGuess->SetMinSize( wxSize( 300,300 ) );
	
	gSizer1->Add( m_panelGuess, 2, wxEXPAND | wxALL, 5 );
	
	m_panelTrue = new GamePanel( this, wxID_ANY, wxDefaultPosition, wxSize( 300,300 ), wxTAB_TRAVERSAL );
	m_panelTrue->SetMinSize( wxSize( 300,300 ) );
	
	gSizer1->Add( m_panelTrue, 2, wxEXPAND | wxALL, 5 );
	
	m_panelControls = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );
	
	m_panelNumbers = new wxPanel( m_panelControls, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
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
	bSizer1->Add( m_panelNumbers, 0, wxEXPAND | wxALL, 5 );
	
	m_panelSettings = new wxPanel( m_panelControls, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
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
	bSizer1->Add( m_panelSettings, 0, wxEXPAND|wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_panelControls->SetSizer( bSizer1 );
	m_panelControls->Layout();
	bSizer1->Fit( m_panelControls );
	gSizer1->Add( m_panelControls, 0, wxEXPAND | wxALL, 5 );
	
	m_panelDebug = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	gSizer1->Add( m_panelDebug, 0, wxEXPAND | wxALL, 5 );
	
	this->SetSizer( gSizer1 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( MainFrame::OnClose ) );
	m_panelGuess->Connect( wxEVT_CHAR, wxKeyEventHandler( MainFrame::OnChar ), NULL, this );
	m_panelGuess->Connect( wxEVT_LEFT_UP, wxMouseEventHandler( MainFrame::OnLeftUp ), NULL, this );
	m_panelGuess->Connect( wxEVT_PAINT, wxPaintEventHandler( MainFrame::OnPaint ), NULL, this );
	m_panelTrue->Connect( wxEVT_CHAR, wxKeyEventHandler( MainFrame::OnChar ), NULL, this );
	m_panelTrue->Connect( wxEVT_LEFT_UP, wxMouseEventHandler( MainFrame::OnLeftUp ), NULL, this );
	m_panelTrue->Connect( wxEVT_PAINT, wxPaintEventHandler( MainFrame::OnPaint ), NULL, this );
	m_button1->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnNumButtonClick ), NULL, this );
	m_button2->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnNumButtonClick ), NULL, this );
	m_button3->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnNumButtonClick ), NULL, this );
	m_button4->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnNumButtonClick ), NULL, this );
	m_button5->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnNumButtonClick ), NULL, this );
	m_button6->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnNumButtonClick ), NULL, this );
	m_button7->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnNumButtonClick ), NULL, this );
	m_button8->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnNumButtonClick ), NULL, this );
	m_button9->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnNumButtonClick ), NULL, this );
	m_buttonSet->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnSetButtonClick ), NULL, this );
	m_buttonNote->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnNoteButtonClick ), NULL, this );
	m_buttonClear->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnClearButtonClick ), NULL, this );
}

MainFrame::~MainFrame()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( MainFrame::OnClose ) );
	m_panelGuess->Disconnect( wxEVT_CHAR, wxKeyEventHandler( MainFrame::OnChar ), NULL, this );
	m_panelGuess->Disconnect( wxEVT_LEFT_UP, wxMouseEventHandler( MainFrame::OnLeftUp ), NULL, this );
	m_panelGuess->Disconnect( wxEVT_PAINT, wxPaintEventHandler( MainFrame::OnPaint ), NULL, this );
	m_panelTrue->Disconnect( wxEVT_CHAR, wxKeyEventHandler( MainFrame::OnChar ), NULL, this );
	m_panelTrue->Disconnect( wxEVT_LEFT_UP, wxMouseEventHandler( MainFrame::OnLeftUp ), NULL, this );
	m_panelTrue->Disconnect( wxEVT_PAINT, wxPaintEventHandler( MainFrame::OnPaint ), NULL, this );
	m_button1->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnNumButtonClick ), NULL, this );
	m_button2->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnNumButtonClick ), NULL, this );
	m_button3->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnNumButtonClick ), NULL, this );
	m_button4->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnNumButtonClick ), NULL, this );
	m_button5->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnNumButtonClick ), NULL, this );
	m_button6->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnNumButtonClick ), NULL, this );
	m_button7->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnNumButtonClick ), NULL, this );
	m_button8->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnNumButtonClick ), NULL, this );
	m_button9->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnNumButtonClick ), NULL, this );
	m_buttonSet->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnSetButtonClick ), NULL, this );
	m_buttonNote->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnNoteButtonClick ), NULL, this );
	m_buttonClear->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnClearButtonClick ), NULL, this );
	
}
