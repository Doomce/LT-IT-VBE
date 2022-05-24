#include <fstream>

using namespace std;

struct Pratimai{
    string Pavadinimas;
    int x; //x - kiek atlikta pratimu.
};

void Rikiavimas(Pratimai Manksta[], int n) {
    for (int i = 0; i<n; i++){
        if (Manksta[i].Pavadinimas!="") { //Rusiuojam tik tuos, kurie turi pavadinima
            for (int j = i; j<n; j++) {
                if (Manksta[j].Pavadinimas!="") { //Rusiuojam tik tuos, kurie turi pavadinima
                    if (Manksta[i].x<Manksta[j].x) {
                        Pratimai temp = Manksta[i];
                        Manksta[i] = Manksta[j];
                        Manksta[j] = temp;
                    }
                }
            }
        }
    }
}

int main()
{
    int n, Iv;
    bool found;
    char PratimoPav[21];
    Pratimai Manksta[101];
    ifstream Df("U2.txt");
    ofstream Rf("U2rez.txt");

    Df>>n;

    for (int i = 0; i<n; i++){
        Df.ignore();
        Df.get(PratimoPav, 21); //Cia nuskaitome pratimo pavadinima
        Df>>Iv; //Cia nuskaitome kiek kartu tas pratimas buvo padarytas
        found = false;
        for (int j = 0; j<n; j++){
            if (Manksta[j].Pavadinimas == PratimoPav) {
                Manksta[j].x+=Iv;
                found = true; //Kai found yra true, tai nekuriam atskiro pratimo.
            }
        }
        if (!found) { //Kai found yra false, itraukiam nauja pratima i masyva.
            Manksta[i].Pavadinimas = PratimoPav;
            Manksta[i].x = Iv;
        }
    }

    Rikiavimas(Manksta, n); //Rikiavimo funkcija;

    for (int i = 0; i<n; i++){
        if (Manksta[i].Pavadinimas!="") { //Isvedam tik tuos, kurie turi pavadinima
            Rf<<Manksta[i].Pavadinimas<<Manksta[i].x<<endl;
        }
    }
    Df.close();
    Rf.close();

    return 0;
}
