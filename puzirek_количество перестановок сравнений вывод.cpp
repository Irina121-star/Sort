#include "TXLib.h"

void FillArray (int data[], int Size);

//-----------------------------------------------------------------------------

int main()
    {
    const int Size = 100;
    int data[Size] = {};

    int k = 20;

    while (k< Size)
        {
        assert (0 <= k && k < Size);

        FillArray (data, Size);

        k = k + 10;
        }

    return 0;
    }


//-----------------------------------------------------------------------------

void FillArray (int data[], int Size)
    {
    int kol_perest = 0;
    int kol_sravn = 0;

    for (int i = 0; i< Size; i++)
        {
        assert (0 <= i && i <Size);

        data[i] = rand() * 100 + i;
        }

    for (int i = 0; i < Size; i++)
        {
        kol_sravn ++;

        for(int j = 0; j <Size - 1; j++)
            {
            if (data[j] > data[j + 1])
                {
                int buf = data[j];
                data[j] = data[j + 1];
                data[j + 1] = buf;
                kol_perest = kol_perest + 1;
                }
            }
        }

    printf ("%d\n", kol_perest);
    printf ("%d\n", kol_sravn);
    }
