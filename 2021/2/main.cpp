#include <iostream>
#include <fstream>

using namespace std;

struct Zuvis{
    string Pav;
    int Taskai;
    int BMase=0;
};

struct Zvejas{
    string VP;
    int Taskai = 0;
    int Zsk;
    Zuvis Zuvys[5];
};

void Skaitymas(Zvejas Zvejai[], Zuvis Zuvys[], int &n, int &m) {
    ifstream Df("U2.txt");
    char Name[20];
    int Zsk, Zmase;

    Df>>n;
    for (int i = 0; i<n; i++) {
        Df.ignore();
        Df.get(Name, 21);
        Zvejai[i].VP = Name;
        Df>>Zvejai[i].Zsk;
        for (int j = 0; j<Zvejai[i].Zsk; j++) {
            Df.ignore();
            Df.get(Name, 21);
            Zvejai[i].Zuvys[j].Pav = Name;
            Df>>Zmase;
            if (Zmase >= 200) Zvejai[i].Taskai += 30;
            else Zvejai[i].Taskai += 15;
            Zvejai[i].Zuvys[j].BMase = Zmase;
        }
        cout<<Zvejai[i].VP<<" "<<Zvejai[i].Taskai<<endl;
    }
    Df>>m;
    for (int i = 0; i<m; i++) {
        Df.ignore();
        Df.get(Name, 21);
        Zuvys[i].Pav = Name;
        Df>>Zuvys[i].Taskai;
    }
    Df.close();
}

int TaskuSkyrimas(Zuvis Zuvys[], int m, Zuvis Zuvis) {
    for (int i = 0; i<m; i++) {
        if (Zuvis.Pav == Zuvys[i].Pav) {
            Zuvys[i].BMase+=Zuvis.BMase;
            return Zuvys[i].Taskai;
        }
    }
    return 0;
}

void Rikiavimas(Zvejas Zvejai[], Zuvis Zuvys[], int n, int m) {
    for (int i = 0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            if (Zvejai[i].Taskai>Zvejai[j].Taskai) {
                Zvejas temp = Zvejai[i];
                Zvejai[i] = Zvejai[j];
                Zvejai[j] = temp;
            } else if (Zvejai[i].Taskai==Zvejai[j].Taskai){
                if (Zvejai[i].VP>Zvejai[j].VP) {
                    Zvejas temp = Zvejai[i];
                    Zvejai[i] = Zvejai[j];
                    Zvejai[j] = temp;
                }
            }
        }
    }

    for(int i = 0; i<m; i++) {
        for(int j=i+1; j<m; j++) {
            if (Zuvys[j].BMase>Zuvys[i].BMase) {
                Zuvis temp = Zuvys[i];
                Zuvys[i] = Zuvys[j];
                Zuvys[j] = temp;
            } else if (Zuvys[i].BMase==Zuvys[j].BMase){
                if (Zuvys[i].Pav>Zuvys[j].Pav) {
                    Zuvis temp = Zuvys[i];
                    Zuvys[i] = Zuvys[j];
                    Zuvys[j] = temp;
                }
            }
        }

    }
}


int main()
{
    Zvejas Zvejai[31];
    Zuvis Zuvys[31];
    int n, m;

    Skaitymas(Zvejai, Zuvys, n, m);

    for (int i = 0; i<n; i++) {
        for (int j = 0; j<Zvejai[i].Zsk; j++) {
            Zvejai[i].Taskai += TaskuSkyrimas(Zuvys, m, Zvejai[i].Zuvys[j]);
        }
    }

    Rikiavimas(Zvejai, Zuvys, n, m);

    cout<<"Dalyviai"<<endl;
    for (int i = 0; i<n; i++) {
        cout<<Zvejai[i].VP<<" "<<Zvejai[i].Taskai<<endl;
    }
    cout<<"Laimikis"<<endl;
    for (int i = 0; i<m; i++) {
        cout<<Zuvys[i].Pav<<" "<<Zuvys[i].BMase<<endl;
    }
    return 0;
}
