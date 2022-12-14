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
using namespace std;

const int SIZE = 7;
enum param {OF, PRESSURE, PRESSURERATIO, TEMP, EXPANRATIO, CSTAR, ISP};
void checkFile(ifstream&, string);
class CEATest{
private:
    string file = "CEAOutput.txt";
    string fuel, oxidizer;
    double of, pressure, pressureRatio, temp, expanRatio, cStar, isp;
    string params[SIZE] = {"of", "pressure", "pressureRatio", "temp", "expanRatio", "cStar", "isp"};
    double values[SIZE];
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
    void overwriteTest(int);
    
    string getParam(int);
    
    void calc();
    double calcCF();
    double calcThroatArea();
    double calcMassFlow();
};
void sortByParam(vector<CEATest>&, int);

void readTest(vector<CEATest>&);
void clearTest(vector<CEATest>&);

void runTest();

void displayMenu();

#endif /* CEATest_h */
