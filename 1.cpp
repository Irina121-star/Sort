#include "TXLib.h"

struct MButton
    {
        int x1, y1;
        int x2, y2;
        COLORREF color;
        string text;

        void DrawMButton();
     };


int MenuMButton(MButton Mas[], int razmer);

//-----------------------------------------------------------------------------

int main ()
    {

       txCreateWindow (800, 600);

       txSetFillColor (TX_WHITE);

       txClear();

        MButton Mas [7] = { {  5, 5, 100, 30, TX_LIGHTGRAY,     "Selection"},
                            {115, 5, 210, 30, TX_LIGHTBLUE,     "Bubble"},
                            {225, 5, 320, 30, TX_LIGHTGREEN,    "Insert"},
                            {335, 5, 430, 30, TX_LIGHTCYAN,     "3"},
                            {445, 5, 540, 30, TX_LIGHTMAGENTA,  "4"},
                            {555, 5, 650, 30, TX_LIGHTCYAN,     "Qiuck"},
                            {665, 5, 760, 30, TX_LIGHTMAGENTA,  "Clear"}
                            };
    while (!(GetAsyncKeyState (VK_ESCAPE)))
        {
         for  (int i = 0; i < 7; i ++)
                {
                Mas[i].DrawMButton();
                }

            int num = MenuMButton(Mas, 7);

            printf ("%d\n", num);
            txSleep(75);


        }
     return 0;
    }

//-----------------------------------------------------------------------------

void MButton :: DrawMButton()
    {
     txRectangle (this->x1, this->y1, this->x2, this->y2);
     txSetColor  (color, 3);
     txTextOut (x1 + 15, y1 + 7, this->text.c_str());
    }

//-----------------------------------------------------------------------------

int MenuMButton(MButton Mas[], int razmer)
    {
    while (1)
        {

        for  (int i = 0; i < razmer; i ++)
                {
                if ((txMouseButtons() & 1) && ( txMouseX() > Mas[i].x1) && (txMouseX() < Mas[i].x2)
                 && (Mas[i].y1 < txMouseY()) && (txMouseY( ) < Mas[i].y2))
                     return i;
                }

        }

    //return -1;
     }

//-----------------------------------------------------------------------------




