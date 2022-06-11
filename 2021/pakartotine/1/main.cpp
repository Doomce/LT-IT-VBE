#include <iostream>
#include <fstream>

using namespace std;



int laiko_skaiciavimas(int time[4]) {
    int pradzia = (time[0]*60)+time[1];
    int pabaiga = (time[2]*60)+time[3];

    return pabaiga - pradzia;
}

int suv_rusys(int suv[5]) {
    int rusys = 0;
    for (int i=0; i<5; i++) {
        if (suv[i]>0) rusys++;
    }
    return rusys;
}

int suv_bendrai(int suv[5]) {
    int all = 0;
    for (int i=0; i<5; i++) {
        all+=suv[i];
    }
    return all;
}

int main()
{
    int dienos[32][4]; //0 - diena; 1 - laikas; 2 - suvenyru rusys; 3 - bendras suvenyru skaicius;
    int n, time[4], suv[5], day;
    int maxSk = 0, maxRusys = 0;

    ifstream Df("U1.txt");
    Df>>n;
    for (int i = 0; i<n; i++) {
        Df>>day>>time[0]>>time[1]>>time[2]>>time[3]
        >>suv[0]>>suv[1]>>suv[2]>>suv[3]>>suv[4];

        dienos[i][0] = day;
        dienos[i][1] = laiko_skaiciavimas(time);
        dienos[i][2] = suv_rusys(suv);
        dienos[i][3] = suv_bendrai(suv);

        if (dienos[i][2] > maxRusys) {
            maxRusys = dienos[i][2];
            if (dienos[i][3] > maxSk) {
                maxSk = dienos[i][3];
            }
        }
    }

    for (int i = 0; i<n; i++) {
        if (dienos[i][2] == maxRusys && dienos[i][3] == maxSk) {
            cout<<dienos[i][0]<<" "<<dienos[i][1]<<endl;
        }
    }

    Df.close();

    return 0;
}
