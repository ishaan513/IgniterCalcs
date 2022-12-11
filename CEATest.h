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
using namespace std;

const int SIZE = 7;

void checkFile(ifstream&, string);

class CEATest{
private:
    enum param {OF, PRESSURE, PRESSURERATIO, TEMP, EXPANRATIO, CSTAR, ISP};
    string file = "CEAOutput.txt";
    string fuel, oxidizer;
    double of, pressure, pressureRatio, temp, expanRatio, cStar, isp;
    string params[SIZE] = {"of", "pressure", "pressureRatio", "temp", "expanRatio", "cStar", "isp"};
    double values[SIZE];
public:
    CEATest();
    string getFuelOx(string);
    double getVal(string);
    void setVal(string, double);
    void sortByParam(vector<CEATest>&, int);
    void setValues();
    void getValues();
    void viewTest();
    void saveTest(int);
};

void readTest(vector<CEATest>&);

#endif /* CEATest_h */
