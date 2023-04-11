int numOfValElectrons = 0;

#define functions "func.h"

#include <iostream>
#include <cstdio>
#include <fstream>
#include <vector>
#include <cstring>
#include <string>
#include <locale.h>
#include <map>
#include functions
using namespace std;

void ZwiazekSumarycznieNaGraf(string zwiazekSumarycznie, vector<string> &zwiazek)
{

    for (int i = 0; i < zwiazekSumarycznie.length();)
    {

        string s;
        char c;
        int ileLiter = 0;
        c = zwiazekSumarycznie[i];
        s += c;
        string ilosc = "";
        char sC[3];
        while (true)
        {
            i++;
            c = zwiazekSumarycznie[i];
            if (c >= '0' && c <= '9')
            {

                zwiazek.push_back(s);
                ilosc += c;
                while (zwiazekSumarycznie[i + 1] >= '0' && zwiazekSumarycznie[i + 1] <= '9')
                {
                    i++;
                    c = zwiazekSumarycznie[i];
                    ilosc += c;
                }

                int iloscInt = stoi(ilosc);

                for (int k = 1; k < iloscInt - 1; k++)
                {

                    zwiazek.push_back(zwiazek.back());
                }
                if (iloscInt == 1)
                {
                    zwiazek.pop_back();
                }

                continue;
            }

            if (c == toupper(c))
            {

                break;
            }
            else
            {
                s += c;
            }
        }

        // cout<<s<<endl;n

        // cout<<symbolNaIndex(s)<<endl;

        zwiazek.push_back(s);
    }
}

int main()
{
    setlocale(LC_CTYPE, "Polish");
    string zwiazek;
    cout << "Podaj wzor zwiazku: " << endl;
    cin >> zwiazek;
    vector<string> zwiazekLadnie;

    ZwiazekSumarycznieNaGraf(zwiazek, zwiazekLadnie);
    for (int i = 0; i < zwiazekLadnie.size(); i++)
    {
        char a[3];
        strcpy(a, zwiazekLadnie[i].c_str());
        UpdateNumOfValElectrons(a);
    }

    if (!(numOfValElectrons % 2))
    {
        // cout << "Nieparzysta liczba elektronow walencyjnych!!!\n Wychodzi to poza wiedze tego programu";
        // e tam gupoty gadasz XD
    }

    int bondPairs = CalculateBondPairs();
    int lonePairs = CalculateLonePairs();
    int steric = bondPairs + lonePairs;

    int numOfH = numOfHydrogen(zwiazekLadnie);
    if (numOfH)
    {
        bondPairs = numOfH;
        lonePairs = steric - bondPairs;
    }

    cout << "Hybrydyzacja: " << DetermineHybridization(steric) << endl;
    cout << "Geometria moleku³y: " << DetermineShape(steric, bondPairs, lonePairs);
    cout << "\n\n";
    // system("pause");

    return 0;
}
