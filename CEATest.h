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
const int PSIZE = 4;
enum param {OF, PRESSURE, PRESSURERATIO, TEMP, EXPANRATIO, CSTAR, ISP};
enum prop {NO2, ETH, LOX, METH};
void checkFile(ifstream&, string);
class CEATest{
private:
    string file = "CEAOutput.txt";
    string fuel, oxidizer;
    double of, pressure, pressureRatio, temp, expanRatio, cStar, isp;
    string params[SIZE] = {"of", "pressure", "pressureRatio", "temp", "expanRatio", "cStar", "isp"};
    double values[SIZE];
    string props[PSIZE] = {"nitrous", "ethanol", "lox", "methane"};
    double propRatio[PSIZE];
    double pNO2 = 0.04, pETH = 0.03; // lb/in^3
    double propDensity[PSIZE] = {pNO2, pETH};
    int thrust = 20; // lbf
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
    double calcMassFlow();
    double calcPropMassFlow(int);
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
