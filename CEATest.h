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
const int PSIZE = 6;
const int MSIZE = 4;
enum param {OF, PRESSURE, PRESSURERATIO, TEMP, EXPANRATIO, CSTAR, ISP};
enum prop {NO2, ETH, ETHH2O, IPA};
enum tank {OX, FUEL};
void checkFile(ifstream&, string);
class CEATest{
private:
    string file = "CEAOutput.txt";
    string fuel, oxidizer;
    // pressure - psi
    // temp - K
    // cStar - ft/s
    // isp - s
    double of, pressure, pressureRatio, temp, expanRatio, cStar, isp;
    string params[SIZE] = {"of", "pressure", "pressureRatio", "temp", "expanRatio", "cStar", "isp"};
    double values[SIZE];
    string props[PSIZE] = {"nitrous", "ethanol", "ethh2o", "ipa"};
    double propRatio[PSIZE];
    double pNO2 = 0.04, pETH = 0.03, pEH2O = 0.033, pIPA = 0.028; // lb/in^3
    double propDensity[PSIZE] = {pNO2, pETH, pEH2O, pIPA};
    double steel = 1510, copper = 1084, brass = 930, aluminum = 660; // degrees C
    string materials[MSIZE] = {"steel", "copper", "brass", "aluminum"};
    double matProp[MSIZE] = {steel, copper, brass, aluminum};
    int thrust = 10; // lbf
    double cd = 0.88; // accepted value
    double tankPressure[2] = {200, 200}; // psi
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
    double calcPropMassFlow(double);
    double calcOrificeArea(int, int);
    double calcThroatArea();
    string tempAnalysis(string);
    double fuelTankSize(double, double, int);
    double calcPropVolFlow(int);
    string optimalTankSize(double, int); // calculate the optimal tank size (volume, then height and diameter)
    // unit conversion function, input what value you want to convert and what you want to convert it to
    // lb/s -> kg/s
    // lb -> kg
    // in^3/s -> m^3/s, gal/min
    // in -> m
    // parameters: value (string), new unit (string)
    string unitConvert(string, string);
    
    
    bool checkParam(string);
};

void sortByParam2(vector<CEATest>&, string);
void sortByParam(vector<CEATest>&, int);

void readTest(vector<CEATest>&);
void clearTest(vector<CEATest>&);

void runTest();

void displayMenu();

#endif /* CEATest_h */
