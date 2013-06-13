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
	redSquares.clear();
	greenSquares.clear();
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

void GamePanel::DrawBoardBackground(wxBufferedDC &dc)
{
	unsigned int spSq = 0;
    unsigned int smallSide;
    unsigned int i,j;

    wxColour LGray, White, Blue;
    wxBrush LGrayBr, WhiteBr, BlueBr;

    LGray.Set(210,210,210);
    LGrayBr.SetColour(LGray);

    White.Set(255,255,255);
    WhiteBr.SetColour(White);

    Blue.Set(0,150,255);
    BlueBr.SetColour(Blue);

    wxSize sz = this->GetClientSize();

    dc.SetBrush( WhiteBr );
    dc.SetPen(*wxWHITE_PEN );

    dc.DrawRectangle( 0, 0, sz.x, sz.y );

    if (sz.x < sz.y)
        smallSide = sz.x;
    else
        smallSide = sz.y;

    spSq = smallSide / 9;
    smallSide -= 10;

        // Set the Brush and Pen to red
    dc.SetBrush( LGrayBr );
    dc.SetPen(*wxBLACK_PEN );


    for(i=0;i<9;i++)
        for(j=0;j<9;j++)
        {
            if(i == col && j == row)
                dc.SetBrush(BlueBr);
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

void GamePanel::DrawBoardNumbers(wxBufferedDC &dc)
{
	unsigned int spSq = 0;
    unsigned int smallSide;
    unsigned int i,j,k, pVal;
    wxString debugString;
    wxString pString, dString;
    wxColour redC, greenC, blackC;
    std::vector<GameSquare> testColor;
    std::vector<GameSquare>::iterator it;
    GameSquare sq;

	wxColour Green, Red;
    wxBrush GreenBr, RedBr;
    wxPen GreenPn, RedPn;

    Green.Set(0,200,0);
    GreenBr.SetColour(Green);
    GreenPn.SetColour(Green);

    Red.Set(200,0,0);
    RedBr.SetColour(Red);
    RedPn.SetColour(Red);

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

    if(guess)
    {
		debugString.clear();
		debugString << _("Pushing from drawing algorithm \n");
		writetoLog(debugString, _("ColoredRect.log"));

        // draw red and green squares according to greenSquare and redSquare
        testColor = greenSquares;


		debugString.clear();
		debugString << _("Green squares \n");
        for(it = testColor.begin(); it != testColor.end(); ++it)
        {
            // draw a rectangle over each possibility in each square in this vector
            sq.Copy(*it);
            i = sq.GetRow();
            j = sq.GetCol();
            k = sq.GetVal();
            dc.SetBrush( GreenBr );
            dc.SetPen(GreenPn);
            debugString << _("Row ") << i << _(" col ") << j << _(" val ") << k << _("\n");
            switch (k) // Draw rectanbles over each possible in the correct position
            {
                case 1:
                    dc.DrawRectangle(spSq*j + spSq/12 -1, spSq*i + spSq/12 -1, spSq/6, spSq/3-2);
                    break;
                case 2:
                    dc.DrawRectangle(spSq*j + spSq*5/12 -1, spSq*i + spSq/12-1, spSq/6, spSq/3-2);
                    break;
                case 3:
                    dc.DrawRectangle( spSq*j + spSq*9/12-2, spSq*i + spSq/12-1, spSq/6, spSq/3-2);
                    break;
                case 4:
                    dc.DrawRectangle( spSq*j + spSq/12-1, spSq*i + spSq*9/24-1, spSq/6, spSq/3-2);
                    break;
                case 5:
                    dc.DrawRectangle( spSq*j + spSq*5/12-1, spSq*i + spSq*9/24-1, spSq/6, spSq/3-2);
                    break;
                case 6:
                    dc.DrawRectangle( spSq*j + spSq*9/12-2, spSq*i + spSq*9/24-1, spSq/6, spSq/3-2);
                    break;
                case 7:
                    dc.DrawRectangle( spSq*j + spSq*1/12-1, spSq*i + spSq*8/12-1, spSq/6, spSq/4-1);
                    break;
                case 8:
                    dc.DrawRectangle( spSq*j + spSq*5/12-1, spSq*i + spSq*8/12-1, spSq/6, spSq/4-1);
                    break;
                case 9:
                    dc.DrawRectangle( spSq*j + spSq*9/12-2, spSq*i + spSq*8/12-1, spSq/6, spSq/4-1);
                    break;
                default:
                    break;
            }

        }

        writetoLog(debugString, _("ColoredRect.log"));

        testColor = redSquares;

		debugString.clear();
		debugString << _("Red squares \n");
        for(it = testColor.begin(); it != testColor.end(); ++it)
        {
            // draw a rectangle over each possibility in each square in this vector
            sq.Copy(*it);
            i = sq.GetRow();
            j = sq.GetCol();
            k = sq.GetVal();
            dc.SetBrush( RedBr );
            dc.SetPen(RedPn);
            debugString << _("Row ") << i << _(" col ") << j << _(" val ") << k << _("\n");
            switch (k) // Draw rectanbles over each possible in the correct position
            {
                case 1:
                    dc.DrawRectangle(spSq*j + spSq/12 -1, spSq*i + spSq/12 -1, spSq/6, spSq/3-2);
                    break;
                case 2:
                    dc.DrawRectangle(spSq*j + spSq*5/12 -1, spSq*i + spSq/12-1, spSq/6, spSq/3-2);
                    break;
                case 3:
                    dc.DrawRectangle( spSq*j + spSq*9/12-2, spSq*i + spSq/12-1, spSq/6, spSq/3-2);
                    break;
                case 4:
                    dc.DrawRectangle( spSq*j + spSq/12-1, spSq*i + spSq*9/24-1, spSq/6, spSq/3-2);
                    break;
                case 5:
                    dc.DrawRectangle( spSq*j + spSq*5/12-1, spSq*i + spSq*9/24-1, spSq/6, spSq/3-2);
                    break;
                case 6:
                    dc.DrawRectangle( spSq*j + spSq*9/12-2, spSq*i + spSq*9/24-1, spSq/6, spSq/3-2);
                    break;
                case 7:
                    dc.DrawRectangle( spSq*j + spSq*1/12-1, spSq*i + spSq*8/12-1, spSq/6, spSq/4-1);
                    break;
                case 8:
                    dc.DrawRectangle( spSq*j + spSq*5/12-1, spSq*i + spSq*8/12-1, spSq/6, spSq/4-1);
                    break;
                case 9:
                    dc.DrawRectangle( spSq*j + spSq*9/12-2, spSq*i + spSq*8/12-1, spSq/6, spSq/4-1);
                    break;
                default:
                    break;
            }
        }

        writetoLog(debugString, _("ColoredRect.log"));
    }

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
                {
                    dc.SetPen(*wxBLACK_PEN );
                    dc.SetTextForeground(blackC);
                }
                else if(bd->GetVal(i, j) == trueBd.GetVal(i, j))
                    dc.SetTextForeground(greenC);
                else
                    dc.SetTextForeground(redC);


                pString.clear();
                pString << pVal;
                dc.DrawText(pString, 6 * spSq / 20 + ((j) * spSq), spSq / 6 + ((i) * spSq));
            }
            else // Draw all possibles
            {
                dc.SetTextForeground(blackC);

                dString.clear();
                dString << _("Possibles for i = ") << i << _(" j = ") << j << _(" ");
                for(k=1;k<=9;k++)
                {
                    dc.SetFont(SmallFont);
                    pString.clear();
                    pString << k;

                    if(bd->GetPossibles(i, j, k))
                    {
                        dString << k << _(" ");
                        switch (k) // Draw each possible in the correct position
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
}

void GamePanel::CopyBoard(GameBoard &gb)
{
    bd->Copy(gb);
}

void GamePanel::CopyToTrue()
{
    trueBd.Copy(*bd);
}

void GamePanel::WriteBoard(GameBoard &gb)
{
    gb.Copy(*bd);
}
