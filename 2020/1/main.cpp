#include <iostream>
#include <fstream>

using namespace std;

struct Gele {
    int ID;
    int pm, pday;
    int bm, bday;
};


int DaugiausiaGeliuDiena(Gele Geles[], int n) {
    int Dienos[92] = {0};
    int maxDiena, maxGeles = -1;
    for (int i =0; i<n; i++) {
        if (Geles[i].pm == 7) {
            Geles[i].pday+=30;
        }
        if (Geles[i].pm == 8) {
            Geles[i].pday+=61;
        }
        if (Geles[i].bm == 7) {
            Geles[i].bday+=30;
        }
        if (Geles[i].bm == 8) {
            Geles[i].bday+=61;
        }
        Dienos[Geles[i].pday]++;
    }
    for (int i = 0; i<92; i++) {
        if (Dienos[i]>maxGeles) {
            maxDiena = i;
            maxGeles = Dienos[i];
        }
    }
    return maxDiena;
}

int PirmasisIntervalas(Gele Geles[], int n, int day) {
     int maxGeles = 0;
     int MaxGelesSlot;
     for (int i = 0; i<n; i++) {
        if (Geles[i].pday >= day) {
            MaxGelesSlot = i;
        }
     }
     for (int i = 0; i<n; i++) {
        if (Geles[i].pday <= Geles[MaxGelesSlot].pday&&
            Geles[i].bday >= Geles[MaxGelesSlot].bday) {
            maxGeles++;
        }
     }
    if (Geles[MaxGelesSlot].pm == 7) {
        Geles[MaxGelesSlot].pday-=30;
    }
    if (Geles[MaxGelesSlot].pm == 8) {
        Geles[MaxGelesSlot].pday-=61;
    }
    if (Geles[MaxGelesSlot].bm == 7) {
        Geles[MaxGelesSlot].bday-=30;
    }
    if (Geles[MaxGelesSlot].bm == 8) {
        Geles[MaxGelesSlot].bday-=61;
    }
    cout<<maxGeles<<endl;
    cout<<Geles[MaxGelesSlot].pm<<" "<<Geles[MaxGelesSlot].pday<<endl;
    cout<<Geles[MaxGelesSlot].bm<<" "<<Geles[MaxGelesSlot].bday<<endl;
    return maxGeles;
}


int main()
{
    Gele Geles[31];
    int n, day;

    ifstream Df("U1.txt");
    Df>>n;
    for (int i = 0; i<n; i++) {
        Df>>Geles[i].ID>>Geles[i].pm>>Geles[i].pday;
        Df>>Geles[i].bm>>Geles[i].bday;
    }

    day = DaugiausiaGeliuDiena(Geles, n);
    PirmasisIntervalas(Geles, n, day);
    Df.close();

    return 0;
}
