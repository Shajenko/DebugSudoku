#include "wx_pch.h"
#include "GamePanel.h"

#ifndef WX_PRECOMP
	//(*InternalHeadersPCH(GamePanel)
	//*)
#endif
//(*InternalHeaders(GamePanel)
//*)

//(*IdInit(GamePanel)
//*)

BEGIN_EVENT_TABLE(GamePanel,wxPanel)
	//(*EventTable(GamePanel)
	//*)
END_EVENT_TABLE()

GamePanel::GamePanel(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size, long style) : wxPanel(parent, id, pos, size, style)
{
	//(*Initialize(GamePanel)
	//*)

	bd = new GameBoard;
	row = 9;
	col = 9;
}

GamePanel::~GamePanel()
{
	//(*Destroy(GamePanel)
	//*)

	delete bd;
}


void GamePanel::OnPaint( wxPaintEvent& event )
{
}

void GamePanel::DrawBoardBackground(wxPaintDC &dc)
{
	unsigned int spSq = 0;
    unsigned int smallSide;
    unsigned int i,j;

    wxColour LGray;
    wxBrush LGrayBr;

    LGray.Set(210,210,210);
    LGrayBr.SetColour(LGray);

    wxSize sz = this->GetClientSize();
    if (sz.x < sz.y)
        smallSide = sz.x;
    else
        smallSide = sz.y;

    spSq = smallSide / 9;
    smallSide -= 10;

        // Set the Brush and Pen to red
    dc.SetBrush( LGrayBr );
    dc.SetPen(*wxBLACK_PEN );
    // Draw rectangle 40 pixels wide and 40 high
    // with upper left corner at 10 , 10.

    for(i=0;i<9;i++)
        for(j=0;j<9;j++)
        {
            if(i == col && j == row)
                dc.SetBrush(*wxBLUE_BRUSH);
            else
                dc.SetBrush(LGrayBr);
            dc.DrawRectangle( 0 + spSq*i, 0 + spSq*j, spSq - 5, spSq - 5 );
        }

    wxColor Black(0,0,0);
    wxPen myBlackPen(Black,5,wxSOLID);
    dc.SetPen(myBlackPen);

    // Section Borders
    dc.DrawLine( 0, smallSide/3 - 2, smallSide, smallSide/3 - 2);
    dc.DrawLine( 0, smallSide*2/3 - 1, smallSide, smallSide*2/3 - 1);
    dc.DrawLine( smallSide/3 - 2, 0, smallSide/3 - 2, smallSide);
    dc.DrawLine( smallSide*2/3 - 1, 0, smallSide*2/3 - 1, smallSide);

    // Edge Borders
    dc.DrawLine( 0, 0, smallSide, 0);
    dc.DrawLine( 0, 0, 0, smallSide);
    dc.DrawLine( 0, smallSide, smallSide, smallSide);
    dc.DrawLine( smallSide, 0, smallSide, smallSide);

}

void GamePanel::DrawBoardNumbers(wxPaintDC &dc)
{
	unsigned int spSq = 0;
    unsigned int smallSide;
    unsigned int i,j,k, pVal;
    wxString debugString;
    wxString pString;
    wxColour redC, greenC, blackC;

    redC.Set(200,0,0);
    greenC.Set(0,200,0);
    blackC.Set(0,0,0);

    wxSize sz = this->GetClientSize();
    if (sz.x < sz.y)
        smallSide = sz.x;
    else
        smallSide = sz.y;

    spSq = smallSide / 9;
    smallSide -= 10;

        // Create a 16 point, serif font, that is not bold,
    //   not italic, and not underlined.
    dc.SetPen(*wxBLACK_PEN );
    wxFont BigFont(spSq/2,wxFONTFAMILY_ROMAN,wxNORMAL,wxNORMAL,false);
    wxFont SmallFont(spSq/7,wxFONTFAMILY_ROMAN,wxNORMAL,wxNORMAL,false);

    // Tell dc to use this font
    dc.SetFont(BigFont);

    for(i=0;i < 9;i++)
    {
        for(j=0;j<9;j++)
        {
            if (bd->GetVal(i, j) != 0) // Show if there's a value
            {
                dc.SetFont(BigFont);

                pVal = 0;
                pVal = bd->GetVal(i, j);
                if(bd->GetShown(i, j))
                    dc.SetTextForeground(blackC);
/*                else if(mGuessGB->GetVal(i, j) == mMainGB->GetVal(i, j))
                    dc.SetTextForeground(greenC);
                else
                    dc.SetTextForeground(redC);*/


                pString.clear();
                pString << pVal;
                dc.DrawText(pString, 6 * spSq / 20 + ((j) * spSq), spSq / 6 + ((i) * spSq));
            }
            else // Draw all possibles
            {
                for(k=1;k<=9;k++)
                {
                    dc.SetFont(SmallFont);
                    pString.clear();
                    pString << k;
                    if(bd->GetPossibles(i, j, k))
                    switch (k)
                    {
                        case 1:
                            dc.DrawText(pString, spSq*j + spSq/12, spSq*i + spSq/12);
                            break;
                        case 2:
                            dc.DrawText(pString, spSq*j + spSq*5/12, spSq*i + spSq/12);
                            break;
                        case 3:
                            dc.DrawText(pString, spSq*j + spSq*9/12, spSq*i + spSq/12);
                            break;
                        case 4:
                            dc.DrawText(pString, spSq*j + spSq/12, spSq*i + spSq*9/24);
                            break;
                        case 5:
                            dc.DrawText(pString, spSq*j + spSq*5/12, spSq*i + spSq*9/24);
                            break;
                        case 6:
                            dc.DrawText(pString, spSq*j + spSq*9/12, spSq*i + spSq*9/24);
                            break;
                        case 7:
                            dc.DrawText(pString, spSq*j + spSq*1/12, spSq*i + spSq*8/12);
                            break;
                        case 8:
                            dc.DrawText(pString, spSq*j + spSq*5/12, spSq*i + spSq*8/12);
                            break;
                        case 9:
                            dc.DrawText(pString, spSq*j + spSq*9/12, spSq*i + spSq*8/12);
                            break;
                        default:
                            break;
                    }

                }
            }
        }
    }
}
