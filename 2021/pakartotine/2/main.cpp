#include <iostream>
#include <fstream>

using namespace std;

struct Kategorija{
    string catName;
    int percent;
};

struct Portalas{
    string name;
    Kategorija kat[31];
    int katCount;
};

void skaitymas(Portalas port[], int &n) {

    ifstream Df("U2.txt");
    Df>>n;
    Df.ignore();

    string name, catName;
    int all, fake, portalsCount = 0;
    char sState;
    for (int i = 0; i<n; i++) {
        Df>>name>>catName>>all;
        fake = 0;
        for (int j = 0; j<all; j++) {
            Df>>sState;
            if (sState == 'M') fake++;
        }
        if ((double) fake/all >= 0.75 ) {
            bool isFound = false;
            for (int j = 0; j<portalsCount; j++) {
                if (port[j].name == name) {
                    port[j].kat[port[j].katCount].catName = catName;
                    port[j].kat[port[j].katCount].percent = 100*((double)fake/all);
                    port[j].katCount++;
                    isFound = true;
                }
            }
            if (isFound) continue;
            port[portalsCount].katCount = 1;
            port[portalsCount].name = name;
            port[portalsCount].kat[0].catName = catName;
            port[portalsCount].kat[0].percent = 100*((double)fake/all);
            portalsCount++;
        }
    }
    n = portalsCount;
    Df.close;
}

int main()
{
    int n;
    Portalas port[31];

    skaitymas(port, n);

    for (int i = 0; i<n; i++) {
        for (int j=i; j<n; j++) {
            if (port[i].katCount < port[j].katCount) swap(port[i], port[j]);
            else if (port[i].katCount == port[j].katCount) {
                if (port[i].name > port[j].name) swap(port[i], port[j]);
            }
        }
    }

    if (n == 0) {
        cout<<"Neatitinka reikalavimo";
        return 0;
    }

    for (int i = 0; i<n; i++) {
        cout<<port[i].name<<" "<<port[i].katCount<<endl;
        for(int j = 0; j<port[i].katCount; j++) {
            cout<<port[i].kat[j].catName<<" "<<port[i].kat[j].percent<<endl;
        }
    }
    return 0;
}
