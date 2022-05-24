#include <iostream>
#include <fstream>
#include <iomanip>


using namespace std;

struct Sportininkas {
    string ID;
    long Laikas;
    int Taskai;
    int Identifier = 0;
    bool ArFinisavo = false;
};

long LaikasISekundes(int h, int mins, int s) {
    long secs = 0;
    secs += h*3600;
    secs += mins*60;
    secs += s;
    return secs;
}

void SekundesILaika(long secs, int &h, int &mins, int &s) {
    h = secs/3600;
    secs%3600;
    mins = secs/60%60;
    s = secs%60;
}

void Skaitymas(Sportininkas SP[], int &n, int &m) {
    ifstream Df("U1.txt"); //Turi buti U2.txt
    char Name[20];
    int ID, h, mins, s, taskas;
    Df>>n;
    for (int i = 0; i<n; i++) {
        Df.ignore();
        Df.get(Name, 21);
        Df>>ID>>h>>mins>>s;
        SP[ID].ID = Name;
        SP[ID].Laikas = LaikasISekundes(h, mins, s);
    }
    Df>>m;
    for (int i = 0; i<m; i++) {
        Df>>ID>>h>>mins>>s;
        long startas = SP[ID].Laikas;
        long finisas = LaikasISekundes(h, mins, s);

        if (ID/100 == 1) {
            for (int j = 0; j<2; j++) {
                Df>>taskas;
                if (taskas<5) finisas+=(5-taskas)*60;
            }
        } else {
            for (int j = 0; j<4; j++) {
                Df>>taskas;
                if (taskas<5) finisas+=(5-taskas)*60;
            }
        }
        SP[ID].Identifier = ID;
        SP[ID].ArFinisavo = true;
        SP[ID].Laikas = finisas-startas;
    }
    Df.close();
}

void Rikiavimas(Sportininkas SP[]) {
    for (int i = 0; i<300; i++){
        for (int j = 0; j<i+1; j++){
            if (!SP[i].ArFinisavo) continue;
            if (!SP[j].ArFinisavo) continue;
            if (SP[j].Laikas > SP[i].Laikas) {
                Sportininkas temp = SP[i];
                SP[i] = SP[j];
                SP[j] = temp;
            } else if (SP[i].Laikas == SP[j].Laikas) {
                if (SP[i].ID < SP[j].ID) {
                    Sportininkas temp = SP[i];
                    SP[i] = SP[j];
                    SP[j] = temp;
                }
            }
        }
    }

}

void Isvedimas(Sportininkas SP[]) {
    int ID, h, mins, s;
    cout<<"Merginos"<<endl;
    for (int i = 0; i<300; i++) {
        if (SP[i].Identifier/100 == 1) {
            SekundesILaika(SP[i].Laikas, h, mins, s);
            cout<<SP[i].Identifier<<" "<<setw(20)<<SP[i].ID<<" "<<h<<" "<<mins<<" "<<s<<endl;
        }
    }
    cout<<"Vaikinai"<<endl;
    for (int i = 0; i<300; i++) {
        if (SP[i].Identifier/100 == 2) {
            SekundesILaika(SP[i].Laikas, h, mins, s);
            cout<<SP[i].Identifier<<" "<<setw(20)<<SP[i].ID<<" "<<h<<" "<<mins<<" "<<s<<endl;
        }
    }

}

int main()
{
    Sportininkas SP[300];
    int n, m;
    int ID, h, mins, s;

    Skaitymas(SP, n, m);
    Rikiavimas(SP);

    Isvedimas(SP);
    return 0;
}
