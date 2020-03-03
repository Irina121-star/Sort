#include "TXLib.h"

typedef double Sorrt (int data[], int Size, int *kol_perest);

struct MButton
    {
        int x1, y1;
        int x2, y2;
        COLORREF color;
        string text;
        void DrawMButton();
     };

//-----------------------------------------------------------------------------

int MenuMButton(MButton Mas[], int razmer);
double Buble (int data[], int Size, int *kol_perest);

void PrintGrafik(Sorrt* func, COLORREF color);
void DrawGrafik (int x, int y, COLORREF color, int x0);
void FillArray (int data[], int Size);

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

        switch (num)
            {
            case 0: {PrintGrafik(&Buble, TX_LIGHTGRAY); break;}
            //case 1: {PrintGrafik(&Insert, TX_LIGHTBLUE); break;}
           // case 2: {PrintGrafik(&Selection, TX_LIGHTGREEN); break;}
           // case 3: {PrintGrafik(&Merge, TX_LIGHTCYAN); break;}
           // case 4: {PrintGrafik(&S5, TX_LIGHTMAGENTA); break;}
           // case 5: {PrintGrafik(&S6, TX_LIGHTCYAN); break;}
           // case 6: {ClearScreen (0); ClearScreen (400); break;}
            }

            //printf ("%d\n", num);
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

double Buble (int data[], int Size, int *kol_perest)
    {
    int kol_srav = 0;

    for (int i = 0; i < Size; i++)
        {
        kol_srav ++;
        for(int j = 0; j <Size - 1; j++)
            {
            if (data[j] > data[j + 1])
                {
                 int buf = data[j];
                 data[j] = data[j + 1];
                 data[j + 1] = buf;
                 *kol_perest = *kol_perest + 1;
                }
            }

        }
return kol_srav;
}


//-----------------------------------------------------------------------------

void FillArray (int data[], int Size)
{
    for (int i = 0; i< Size; i++)
            {
            assert (0 <= i && i <Size);

            data[i]=rand() * 100 + i;

            }
}

 //-----------------------------------------------------------------------------

 void PrintGrafik(Sorrt* func, COLORREF color)
 {
 int Size = 10;
 while (Size < 1000)
 {int data[Size];
  FillArray (data, Size);
  int kol_perest = 0;
  int kol_srav = (*func) (data, Size, &kol_perest);
  DrawGrafik (Size, kol_perest, TX_RED, 0);
  DrawGrafik (Size, kol_srav, TX_RED, 400);
  Size =Size + 5;
  txSleep(50);
 }
 }

//-----------------------------------------------------------------------------

void DrawGrafik (int x, int y, COLORREF color, int x0)
{txSetColor (color);
txSetFillColor (color);
txCircle (x*0.37 + x0, y*0.004, 3);

}


//-----------------------------------------------------------------------------
