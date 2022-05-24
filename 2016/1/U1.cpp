#include <fstream>

using namespace std;

int Sunkiausia() {
    ifstream Df("U1.txt");
    int Iv, x, MaxMase = 0;

    Df>>x;
    for (int i = 0; i<x; i++) { //Duomenu failas vietoje masyvo.
        Df>>Iv;
        if (Iv>MaxMase) {
            MaxMase = Iv;
        }
    }
    Df.close();
    return MaxMase;
}

int LengvesnesKuprines(int MaxMase) {
    ifstream Df("U1.txt");
    int Iv, x, N=0; //N - lengvesniu kupriniu skaicius.
    Df>>x;
    for (int i = 0; i<x; i++) { //Duomenu failas vietoje masyvo.
        Df>>Iv;
        if (Iv<=MaxMase*0.5) { //Vietoj dalybos panaudojam daugybą.
            N++;
        }
    }
    Df.close();
    return N;
}

int main()
{
    int MaxMase, N; //N - lengvesnių kuprinių skaičius.
    ofstream Rf("U1rez.txt");
    MaxMase = Sunkiausia();
    N = LengvesnesKuprines(MaxMase);

    Rf << MaxMase <<" "<< N << endl;
    Rf.close();
    return 0;
}
