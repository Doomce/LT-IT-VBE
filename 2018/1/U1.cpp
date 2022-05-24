#include <iostream>
#include <fstream>

//2018 1 IT VBE UZD

using namespace std;

int main()
{
    int G=0, Z=0, R=0, n, Juosteles, Veliavos=0;
    char Iv;

    ifstream Df("U1.txt");
    ofstream Rf("U1rez.txt");

    Df>>n;

    for (int i = 0; i<n; i++) {
        Df>>Iv>>Juosteles;
        if (Iv == 'G') G += Juosteles;
        else if (Iv == 'R') R += Juosteles;
        else Z += Juosteles;
    }

    while (R>=2 && Z>=2 && G>=2) {
        R-=2;
        Z-=2;
        G-=2;
        Veliavos++;
    }

    Rf << Veliavos << endl;
    Rf << "G = " << G << endl;
    Rf << "Z = " << Z << endl;
    Rf << "R = " << R << endl;

    Df.close();
    Rf.close();

    return 0;
}
