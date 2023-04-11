#include <iostream>
#include <string>
#include <map>
using namespace std;

int numValeneceElectrons(char symbol[]);
void UpdateNumOfValElectrons(char element[3]);
int findInGroup(char symbol[], char group[][3], int size);
int numValeneceElectrons(char symbol[]);
int CalculateLonePairs();
int CalculateBondPairs();
string DetermineHybridization(int steric);
string DetermineShape(int steric, int bondPairs, int lonePairs);
int numOfHydrogen(vector<string> zwiazek);
bool is2Group(vector<string> zwiazek);

void UpdateNumOfValElectrons(char element[3])
{
    numOfValElectrons += numValeneceElectrons(element);
}

int findInGroup(char symbol[], char group[][3], int size)
{

    for (int i = 0; i < size; i++)
    {
        if (strcmpi(group[i], symbol) == 0)
        {
            return i;
        }
    }
    return -1;
}

int numValeneceElectrons(char symbol[])
{
    char group1[][3] = {"H", "Li", "Na", "K", "Rb", "Cs", "Fr"};
    char group2[][3] = {"Be", "Mg", "Ca", "Sr", "Ba", "Ra", "He"};
    char group3[][3] = {"La", "Ac", "Sc", "Y", "Lu", "Lr", "B", "Al", "Ga", "In", "Tl", "Nh"};
    char group4[][3] = {"Ce", "Th", "Ti", "Zr", "Hf", "Rf", "C", "Si", "Ge", "Sn", "Pb", "Fl"};
    char group5[][3] = {"Pr", "Pa", "V", "Nb", "Ta", "Db", "N", "P", "As", "Sb", "Bi", "Mc"};
    char group6[][3] = {"Nd", "U", "Cr", "Mo", "W", "Sg", "O", "S", "Se", "Te", "Po", "Lv"};
    char group7[][3] = {"Pm", "Np", "Mn", "Tc", "Re", "Bh", "F", "Cl", "Br", "I", "At", "Ts"};
    char group8[][3] = {"Sm", "Pu", "Fe", "Ru", "Os", "Hs", "Ne", "Ar", "Kr", "Xe", "Rn", "Og"};
    char group9[][3] = {"Eu", "Am", "Co", "Rh", "Ir", "Mt"};
    char group10[][3] = {"Gd", "Cm", "Ni", "Pd", "Pt", "Ds"};
    char group11[][3] = {"Tb", "Bk", "Cu", "Ag", "Au", "Rg"};
    char group12[][3] = {"Dy", "Cf", "Zn", "Cd", "Hg", "Cn"};
    char group13[][3] = {"Ho", "Es"};
    char group14[][3] = {"Er", "Fm"};
    char group15[][3] = {"Tm", "Md"};
    char group16[][3] = {"Yb", "No"};
    int y;

    y = findInGroup(symbol, group1, 7);
    if (y >= 0)
        return 1;

    y = findInGroup(symbol, group2, 7);
    if (y >= 0)
        return 2;
    y = findInGroup(symbol, group3, 12);
    if (y >= 0)
        return 3;
    y = findInGroup(symbol, group4, 12);
    if (y >= 0)
        return 4;
    y = findInGroup(symbol, group5, 12);
    if (y >= 0)
        return 5;
    y = findInGroup(symbol, group6, 12);
    if (y >= 0)
        return 6;
    y = findInGroup(symbol, group7, 12);
    if (y >= 0)
        return 7;
    y = findInGroup(symbol, group8, 12);
    if (y >= 0)
        return 8;
    y = findInGroup(symbol, group9, 6);
    if (y >= 0)
        return 9;
    y = findInGroup(symbol, group10, 6);
    if (y >= 0)
        return 10;
    y = findInGroup(symbol, group11, 6);
    if (y >= 0)
        return 11;
    y = findInGroup(symbol, group12, 6);
    if (y >= 0)
        return 12;
    y = findInGroup(symbol, group13, 2);
    if (y >= 0)
        return 13;
    y = findInGroup(symbol, group14, 2);
    if (y >= 0)
        return 14;
    y = findInGroup(symbol, group15, 2);
    if (y >= 0)
        return 15;
    y = findInGroup(symbol, group16, 2);
    if (y >= 0)
        return 16;

    return -100000;
}

int CalculateLonePairs()
{
    int e;
    if (numOfValElectrons <= 56)
    {
        if (numOfValElectrons <= 8)
        {
            e = 2;
        }
        else
        {
            e = 8;
        }
    }
    else
    {
        e = 18;
    }

    return (numOfValElectrons % e) / 2;
}

int CalculateBondPairs()
{
    int e;
    if (numOfValElectrons <= 56)
    {
        if (numOfValElectrons <= 8)
        {
            e = 2;
        }
        else
        {
            e = 8;
        }
    }
    else
    {
        e = 18;
    }

    return (numOfValElectrons) / e;
}

string DetermineHybridization(int steric)
{
    switch (steric)
    {
    case 2:
        return "sp";
        break;
    case 3:
        return "sp2";
        break;
    case 4:
        return "sp3";
        break;
    case 5:
        return "sp3d";
        break;
    case 6:
        return "sp3d2";
        break;
    case 7:
        return "sp3d3";
        break;

    default:
        cout << "\n\n\n----------Something is not yes----------\n\n\n";

        break;
    }
    return "asd";
}

string DetermineShape(int steric, int bondPairs, int lonePairs)
{
    switch (steric)
    {
    case 2:
        return "linia";
        // return "linia (AX2E0) ";
        break;
    case 3:
    {
        if (bondPairs == 3 && lonePairs == 0)
            return "trojkat rownoboczny";
        // return "trojkat rownoboczny (AX3E0)";
        if (bondPairs == 2 && lonePairs == 1)
            return "ksztalt litery V";
        // return "ksztalt litery V (AX3E1)";
        break;
    }
    case 4:
    {
        if (bondPairs == 4 && lonePairs == 0)
            return "tetraedr";
        // return "tetraedr (AX4E0)";
        if (bondPairs == 3 && lonePairs == 1)
            return "piramida trygonalna";
        // return "piramida trygonalna (AX4E1)";
        if (bondPairs == 2 && lonePairs == 2)
            return "Ksztalt litery V";
        // return "Ksztalt litery V (AX4E2)";
        break;
    }
    case 5:
    {
        if (bondPairs == 5 && lonePairs == 0)
            return "bipiramida trygonalna";
        // return "bipiramida trygonalna (AX5E0)";
        if (bondPairs == 4 && lonePairs == 1)
            return "zdeformowany tetraedr";
        // return "zdeformowany tetraedr (AX5E1)";
        if (bondPairs == 3 && lonePairs == 2)
            return "ksztalt litery T";
        // return "ksztalt litery T (AX5E2)";
        if (bondPairs == 2 && lonePairs == 3)
            return "liniowy";
        // return "liniowy (AX5E3)";
        break;
    }
    case 6:
    {
        if (bondPairs == 6 && lonePairs == 0)
            return "oktaedr";
        // return "oktaedr (AX6E0)";
        if (bondPairs == 5 && lonePairs == 1)
            return "piramida kwadratowa";
        // return "piramida kwadratowa (AX6E1)";
        if (bondPairs == 4 && lonePairs == 2)
            return "kwadrat, plaski (AX6E2)";
        // return "kwadrat, plaski (AX6E2)";
        break;
    }
    case 7:
    {
        if (bondPairs == 7 && lonePairs == 0)
            return "bipiramida pentagonalna";
        // return "bipiramida pentagonalna (AX7E0)";
        if (bondPairs == 6 && lonePairs == 1)
            return "piramida pentagonalna";
        // return "piramida pentagonalna (AX7E1)";
        break;
    }
    default:
        cout << "\n\n\n----------Something is not yes----------\n\n\n";
    }

    return "dsa";
}

int numOfHydrogen(vector<string> zwiazek)
{
    int numH = 0;
    for (int i = 0; i < zwiazek.size(); i++)
    {
        if (zwiazek[i] == "H")
            numH++;
    }
    return numH;
}

bool is2Group(vector<string> zwiazek)
{

    char group2[][3] = {"Be", "Mg", "Ca", "Sr", "Ba", "Ra"};

    for (int i = 0; i < zwiazek.size(); i++)
    {
        char sC[3];
        strcpy(sC, zwiazek[i].c_str());
        if (findInGroup(sC, group2, 8) >= 0)
        {
            return true;
        }
    }

    return false;
}
