//
//  CEATest.h
//  IgniterCalcs
//
//  Created by Ishaan Patel on 12/10/22.
//

#ifndef CEATest_h
#define CEATest_h
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <cmath>
using namespace std;

const int SIZE = 7;
enum param {OF, PRESSURE, PRESSURERATIO, TEMP, EXPANRATIO, CSTAR, ISP};
enum prop {OX, FUEL};
void checkFile(ifstream&, string);
class CEATest{
private:
    string file = "CEAOutput.txt";
    string fuel, oxidizer;
    double of, pressure, pressureRatio, temp, expanRatio, cStar, isp;
    string params[SIZE] = {"of", "pressure", "pressureRatio", "temp", "expanRatio", "cStar", "isp"};
    double values[SIZE];
    double propVals[2];
    int thrust = 20; // lbf
    double pNO2 = 0.04, pETH = 0.03; // lb/in^3
    double density[2] = {pNO2, pETH};
    double cd = 0.82; // accepted value
public:
    CEATest();
    
    void setFuelOx(string, string);
    string getFuelOx(string);
    
    void setVal(string, double);
    double getVal(string);
    
    void setValues();
    void getValues();
 
    void viewTest();
    void saveTest(int);
    void saveTestCSV(int);
    void overwriteTest(int);
    
    string getParam(int);
    
    void calc();
    double calcMassFlow(int);
    double calcOrificeArea(int);
    double calcOrificeDiameter();
    double calcThroatArea();
    
    bool checkParam(string);
};

void sortByParam2(vector<CEATest>&, string);
void sortByParam(vector<CEATest>&, int);

void readTest(vector<CEATest>&);
void clearTest(vector<CEATest>&);

void runTest();

void displayMenu();

#endif /* CEATest_h */
