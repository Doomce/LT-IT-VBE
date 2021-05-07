#include <iostream>
#include <fstream>

using namespace std;

int L1 = 0, L3 = 0, L5 = 0;
int Lik1 = 0, Lik3 = 0, Lik5 = 0;
int n1, n3, n5, k, N0 = 0;

void Lcalc(int i) {
    while (i > 0) {

        if (i % 5 == 0 && n5 >= 1) {
            n5--;
            L5++;
            i -= 5;
        }
        else if (i % 3 == 0 && n3 >= 1) {
            n3--;
            L3++;
            i -= 3;
        }
        else if (i % 1 == 0 && n1 >= 1) {
            n1--;
            L1++;
            i--;
        }
        else {
            if (i % 5 == 0) {
                Lik5++;
                i -= 5;
            }
            else if (i % 3 == 0) {
                Lik3++;
                i -= 3;
            }
            else {
                Lik1++;
                i--;
            }
        }
    }
}

int main()
{
    ifstream RFile("Read1.txt");
    ofstream OFile("Out1.txt"); 

    int cM, c1, c3, c5;

    RFile >> n1;
    RFile >> n3;
    RFile >> n5;
    RFile >> k;

    RFile >> cM;
    RFile >> c1;
    RFile >> c3;
    RFile >> c5;

    Lcalc(k);
    N0 = k - (L1 + (L3 * 3) + (L5 * 5));

    OFile << L1 << " " << L3 << " " << L5 << " " << N0 << endl;
    OFile << n1 << " " << n3 << " " << n5 << endl;
    OFile << Lik1 << " " << Lik3 << " " << Lik5 << endl;
    OFile << (c1*(L1+Lik1)) + (c3*(L3+Lik3)) + (c5*(L5+Lik5))-cM << endl;
}