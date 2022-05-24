#include <iostream>
#include <fstream>

using namespace std;

struct Slid
{
    string ID;
    long PrLaikas;
    long Laikas;
};

long LaikasISekundes(int h, int mins, int s)
{
    long Secs = 0;
    Secs += h*3600;
    Secs += mins*60;
    Secs += s;
    return Secs;
}

void LaikasFormatuotas(long secs, int &h, int &mins, int &s)
{
    h = secs/3600;
    secs/3600;
    mins = secs/60;
    secs/60;
    s = secs%60;
}

void Skaitymas(Slid sl[], int &n, int &m)
{
    ifstream Df("U2.txt");
    char Iv[20];
    int h, mins, s;
    Df>>n;
    for (int i = 0; i<n; i++)
    {
        Df.ignore();
        Df.get(Iv, 21);
        Df>>h>>mins>>s;
        sl[i].ID = Iv;
        sl[i].PrLaikas = LaikasISekundes(h, mins, s);
    }

    Df>>m;
    for (int i = 0; i<m; i++)
    {
        Df.ignore();
        Df.get(Iv, 21);
        for (int j = 0; j<n; j++)
        {
            if (sl[j].ID == Iv)
            {
                Df>>h>>mins>>s;
                sl[j].Laikas = LaikasISekundes(h, mins, s);
            }
        }
    }
}

void Rikiavimas(Slid Slidininkai[], int n)
{
    for (int i = 0; i<n; i++)
    {
        for (int j=i+1; j<n; j++)
        {
            if (Slidininkai[i].Laikas>Slidininkai[j].Laikas)
            {
                Slid temp = Slidininkai[j];
                Slidininkai[j] = Slidininkai[i];
                Slidininkai[i] = temp;
            }
            else if (Slidininkai[i].Laikas==Slidininkai[j].Laikas)
            {
                if (Slidininkai[i].ID>Slidininkai[j].ID)
                {
                    Slid temp = Slidininkai[j];
                    Slidininkai[j] = Slidininkai[i];
                    Slidininkai[i] = temp;
                }
            }
        }
    }
}

void Isvedimas(Slid Slidininkai[], int n)
{
    for (int i = 0; i<n; i++)
    {
        if (Slidininkai[i].Laikas<=0)
        {
            continue;
        }
        int h, mins, s;
        LaikasFormatuotas(Slidininkai[i].Laikas, h, mins, s);
        cout << Slidininkai[i].ID<<" "<<h<<" "<<mins<<" "<<s<<endl;
    }
}

int main()
{
    Slid Slidininkai[20];
    int n, m;

    Skaitymas(Slidininkai, n, m);

    for (int i = 0; i<n; i++)
    {
        long diff = Slidininkai[i].Laikas - Slidininkai[i].PrLaikas;
        Slidininkai[i].Laikas = diff;
    }

    Rikiavimas(Slidininkai, n);
    Isvedimas(Slidininkai, n);
    return 0;
}
