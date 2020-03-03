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
double Insert (int data[], int Size, int *kol_perest);

void PrintGrafik(Sorrt* func, COLORREF color);
void DrawGrafik (int x, int y, COLORREF color, int x0);
void FillArray (int data[], int Size);
void Plosk ();

//-----------------------------------------------------------------------------

int main ()
    {

       txCreateWindow (800, 600);

       txSetFillColor (TX_WHITE);
       //txSetColor (TX_GREEN);

       txClear();
       Plosk ();

       MButton Mas [7] = { {   5, 5, 100, 30, TX_GREEN,        "Buble"},
                            {115, 5, 210, 30, TX_LIGHTBLUE,     "Insert"},
                            {225, 5, 320, 30, TX_LIGHTGREEN,    "Selection"},
                            {335, 5, 430, 30, TX_LIGHTCYAN,     "3"},
                            {445, 5, 540, 30, TX_LIGHTMAGENTA,  "4"},
                            {555, 5, 650, 30, TX_LIGHTCYAN,     "Clear"},
                            {665, 5, 760, 30, TX_LIGHTMAGENTA,  "Выход"}
                            };

 //-----------------------------------------------------------------------------
    int num = 0;

    while (!(num == 6))
        {
         for  (int i = 0; i < 7; i ++)
                {
                Mas[i].DrawMButton();
                }

        num = MenuMButton(Mas, 7);

        switch (num)
            {
            case 0: {PrintGrafik(&Buble, TX_LIGHTBLUE); break;}
            case 1: {PrintGrafik(&Insert, TX_LIGHTGRAY); break;}
           // case 2: {PrintGrafik(&Selection, TX_LIGHTGREEN); break;}
           // case 3: {PrintGrafik(&Merge, TX_LIGHTCYAN); break;}
           // case 4: {PrintGrafik(&S5, TX_LIGHTMAGENTA); break;}
            case 5: {Plosk (); break;}
            };

            //printf ("%d\n", num);
            txSleep(75);


        }
     return 0;
    }

//-----------------------------------------------------------------------------

void MButton :: DrawMButton()
    {
     //txGetColor();
     txSetColor (color, 5);
     txRectangle (this->x1, this->y1, this->x2, this->y2);
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
        for(int j = 0; j <Size - 1; j++)
            {
            kol_srav ++;
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
double Insert (int data[], int Size, int *kol_perest)
    {
    int temp,
        item;
    int kol_srav = 0;
    for (int i = 0; i < Size - 1; i++)
        {
        int item = i + 1;
        temp = data[item];
        for (int j = i + 1; j > 0; j--)
                    {
                    kol_srav ++;
                    if (temp < data[j - 1])
                        {
                        data[j] = data[j - 1];
                        item = j - 1;
                        *kol_perest = *kol_perest + 1;
                        }
                    }
            data[item] = temp;

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

    while (Size < 650)
        {int data[Size];
        FillArray (data, Size);

        int kol_perest = 0;
        int kol_srav = (*func) (data, Size, &kol_perest);

        DrawGrafik (Size, kol_perest, color, 3);

        DrawGrafik (Size, kol_srav, color, 403);

        Size =Size + 5;

        txSleep(50);

        }
 }

//-----------------------------------------------------------------------------

void DrawGrafik (int x, int y, COLORREF color, int x0)
    {
    txSetColor (color);
    txSetFillColor (color);

    txCircle (x*0.5 + x0, 580 - y*0.005, 3);

    txSetFillColor (TX_WHITE);
}


//-----------------------------------------------------------------------------
void Plosk ()
    {
    txSetColor     (RGB ( 0, 255, 0), 3);
    txSetFillColor (RGB ( 0, 75, 75));

    txRectangle   (3, 40, 397, 597);
    txRectangle (403, 40, 797, 597);

    txSetFillColor (TX_WHITE);
    }



//-----------------------------------------------------------------------------




