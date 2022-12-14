//
//  CEATest.cpp
//  IgniterCalcs
//
//  Created by Ishaan Patel on 12/10/22.
//

#include <stdio.h>
#include "CEATest.h"

CEATest::CEATest(){
}
/*----------------------------------------------------------------------------------------------------------------*/

void CEATest::setFuelOx(string str, string prop){
    bool flag = false;
    if(str == "fuel" || str == "FUEL"){
        fuel = prop;
        flag = true;
    }
    else if(str == "oxidizer" || "OXIDIZER"){
        oxidizer = prop;
        flag = true;
    }
    if(!flag){
        cout << "SETVALUE: *" << str << "* PARAMETER DOES NOT EXIST" << endl;
    }
}

string CEATest::getFuelOx(string str){
    string fuelOx = "NULL";
    bool flag = false;
    if(str == "fuel" || str == "FUEL"){
        fuelOx = fuel;
        flag = true;
    }
    else if(str == "oxidizer" || str == "OXIDIZER"){
        fuelOx = oxidizer;
        flag = true;
    }
    if(!flag){
        cout << "GETFUELOX: *" << str << "* PARAMETER DOES NOT EXIST" << endl;
    }
    return fuelOx;
}
/*----------------------------------------------------------------------------------------------------------------*/

void CEATest::setVal(string str, double val){
    bool flag = false;
    for(int i = 0; i < SIZE; i++){
        if(params[i] == str){
            values[i] = val;
            flag = true;
        }
    }
    if(!flag){
        cout << "SETVALUE: *" << str << "* PARAMETER DOES NOT EXIST" << endl;
    }
}

double CEATest::getVal(string str){
    double val = -1;
    bool flag = false;
    
    for(int i = 0; i < SIZE; i++){
        if(params[i] == str){
            val = values[i];
            flag = true;
        }
    }
    if(!flag){
        cout << "GETVALUE: *" << str << "* PARAMETER DOES NOT EXIST" << endl;
    }
    
    return val;
}
/*----------------------------------------------------------------------------------------------------------------*/

void CEATest::setValues(){
    string strInput;
    double numInput;
    cout << "Enter your fuel: ";
    cin >> strInput;
    setFuelOx("fuel", strInput);
    cout << "Enter your oxidizer: ";
    cin >> strInput;
    setFuelOx("oxidizer", strInput);
    cout << "Enter values for parameters (of, pressure, pressureRatio, temp, expanRatio, cStar, isp)" << endl;
    cout << "If you wish to omit any values, enter 0" << endl;
    cout << "Enter values: ";
    for(int i = 0; i < SIZE; i++){
        cin >> numInput;
        if(i == 6){
            numInput /= 9.8;
        }
        setVal(params[i], numInput);
    }
}

void CEATest::getValues(){
    string strInput;
    bool flag = false;
    cout << "RETREIVE YOUR PARAMETERS" << endl;
    while (strInput != "STOP" && strInput != "stop"){
        while(!flag){
            cout << "Enter parameter (of, pressure, pressureRatio, temp, expanRatio, cStar, isp): ";
            cin >> strInput;
            for(int i = 0; i < SIZE; i++){
                if(strInput == params[i]){
                    flag = true;
                    break;
                }
            }
            if(!flag){
                cout << strInput << " does not exist" << endl;
            }
        }
        cout << strInput << ": " << getVal(strInput) << endl;
        cout << endl;
        cout << "Enter STOP to stop retreiving values or GO to continue: ";
        cin >> strInput;
        cout << endl;
        flag = false;
    }
}
/*----------------------------------------------------------------------------------------------------------------*/

void CEATest::viewTest(){
    cout << "Fuel: " << fuel << endl;
    cout << "Oxidizer: " << oxidizer << endl;
    for(int i = 0; i < SIZE; i++){
        cout << params[i] << ": " << getVal(params[i]) << endl;
    }
    cout << endl;
}

void CEATest::saveTest(int num){
    ofstream output;
    output.open("tests.txt", fstream::app);
    output << "** TEST #" << num << " **" << endl;
    output << "Fuel: " << fuel << endl;
    output << "Oxidizer: " << oxidizer << endl;
    for(int i = 0; i < SIZE; i++){
        output << params[i] << ": " << getVal(params[i]) << endl;
    }
    output.close();
}

void CEATest::overwriteTest(int num){
    ofstream output;
    output.open("tests.txt");
    output << "** TEST #" << num << " **" << endl;
    output << "Fuel: " << fuel << endl;
    output << "Oxidizer: " << oxidizer << endl;
    for(int i = 0; i < SIZE; i++){
        output << params[i] << ": " << getVal(params[i]) << endl;
    }
    output.close();
}
/*----------------------------------------------------------------------------------------------------------------*/

string CEATest::getParam(int num){
    return params[num];
}
/*----------------------------------------------------------------------------------------------------------------*/

void CEATest::calc(){
    cout << "This don't work yet..." << endl;
    cout << endl;
}

double CEATest::calcCF(){
    double cf = -1;
    
    return cf;
}
double CEATest::calcThroatArea(){
    double throatArea = -1;
    
    return throatArea;
}
double CEATest::calcMassFlow(){
    double massFlow = -1;
    
    return massFlow;
}
/*----------------------------------------------------------------------------------------------------------------*/

void sortByParam(vector<CEATest>& tests, int param){
    switch (param){
        case 0:
            for(int i = 0; i < tests.size() - 1; i++){
                for(int j = 0; j < tests.size() - 1 - i; j++){
                    if(tests.at(j).getVal("of") > tests.at(j+1).getVal("of")){
                        swap(tests.at(j), tests.at(j+1));
                    }
                }
            }
            cout << "Sorted by OF Ratio" << endl;
            break;
        case 1:
            for(int i = 0; i < tests.size() - 1; i++){
                for(int j = 0; j < tests.size() - 1 - i; j++){
                    if(tests.at(j).getVal("pressure") > tests.at(j+1).getVal("pressure")){
                        swap(tests.at(j), tests.at(j+1));
                    }
                }
            }
            cout << "Sorted by Pressure" << endl;
            break;
        case 2:
            for(int i = 0; i < tests.size() - 1; i++){
                for(int j = 0; j < tests.size() - 1 - i; j++){
                    if(tests.at(j).getVal("pressureRatio") > tests.at(j+1).getVal("pressureRatio")){
                        swap(tests.at(j), tests.at(j+1));
                    }
                }
            }
            cout << "Sorted by Pressure Ratio" << endl;
            break;
        case 3:
            for(int i = 0; i < tests.size() - 1; i++){
                for(int j = 0; j < tests.size() - 1 - i; j++){
                    if(tests.at(j).getVal("temp") > tests.at(j+1).getVal("temp")){
                        swap(tests.at(j), tests.at(j+1));
                    }
                }
            }
            cout << "Sorted by Temperature" << endl;
            break;
        case 4:
            for(int i = 0; i < tests.size() - 1; i++){
                for(int j = 0; j < tests.size() - 1 - i; j++){
                    if(tests.at(j).getVal("expanRatio") > tests.at(j+1).getVal("expanRatio")){
                        swap(tests.at(j), tests.at(j+1));
                    }
                }
            }
            cout << "Sorted by Expansion Ratio" << endl;
            break;
        case 5:
            for(int i = 0; i < tests.size() - 1; i++){
                for(int j = 0; j < tests.size() - 1 - i; j++){
                    if(tests.at(j).getVal("cStar") > tests.at(j+1).getVal("cStar")){
                        swap(tests.at(j), tests.at(j+1));
                    }
                }
            }
            cout << "Sorted by C*" << endl;
            break;
        case 6:
            for(int i = 0; i < tests.size() - 1; i++){
                for(int j = 0; j < tests.size() - 1 - i; j++){
                    if(tests.at(j).getVal("isp") > tests.at(j+1).getVal("isp")){
                        swap(tests.at(j), tests.at(j+1));
                    }
                }
            }
            cout << "Sorted by Isp" << endl;
            break;
    }
}
/*----------------------------------------------------------------------------------------------------------------*/

void readTest(vector<CEATest>& vector){
    ifstream input;
    string empty;
    string str;
    double num;
    CEATest test;
    input.open("tests.txt");
    while(getline(input, empty)){
        getline(input, str, ' ');
        getline(input, str);
        test.setFuelOx("fuel", str);
        getline(input, str, ' ');
        getline(input, str);
        test.setFuelOx("oxidizer", str);
        for(int i = 0; i < SIZE; i++){
            getline(input, str, ':');
            getline(input, empty, ' ');
            input >> num;
            getline(input, empty);
            test.setVal(str, num);
        }
        vector.push_back(test);
    }
    input.close();
}

void clearTest(vector<CEATest>& tests){
    ofstream output;
    output.open("tests.txt");
    output.close();
    tests.clear();
}
/*----------------------------------------------------------------------------------------------------------------*/

void runTest(){
    vector<CEATest> tests;
    CEATest test;
    string strInput;
    double numInput;
    int apple, orange;
    bool flag = false;
    bool edit = false;
    readTest(tests);
    
    cout << "*** ROCKET THING ***" << endl;
    while(!flag){
        displayMenu();
        cin >> apple;
        cout << endl;
        
        switch(apple){
                
            // Create test
            case 1:
                cout << "Create a new test" << endl;
                cout << "************************" << endl;
                test.setValues();
                tests.push_back(test);
                test.saveTest(static_cast<int>(tests.size()));
                cout << "Test created!" << endl;
                cout << endl;
                break;
                
            // View tests
            case 2:
                
                cout << "View existing test" << endl;
                cout << "************************" << endl;
                if(tests.size() == 0){
                    cout << "There are no existing tests to view." << endl;
                    cout << endl;
                    break;
                }
                else{
                    cout << "There are " << tests.size() << " tests." << endl;
                    cout << "Which test would you like to view?" << endl;
                    cout << "Enter test number: ";
                    cin >> numInput;
                    cout << endl;
                    cout << "** TEST #" << numInput << " **" << endl;
                    tests.at(numInput - 1).viewTest();
                }
                
                break;
                
            // View all existing tests
            case 3:
                
                cout << "View all existing tests" << endl;
                cout << "************************" << endl;
                cout << "There are " << tests.size() << " tests." << endl;
                cout << endl;
                for(int i = 0; i < tests.size(); i++){
                    cout << "** TEST #" << i + 1 << " **" << endl;
                    tests.at(i).viewTest();
                }
                
                break;
                
            // Edit test
            case 4:
                
                cout << "Edit existing test" << endl;
                cout << "************************" << endl;
                if(tests.size() == 0){
                    cout << "There are no existing tests to edit." << endl;
                    cout << endl;
                    break;
                }
                cout << "There are " << tests.size() << " tests." << endl;
                cout << "Which test would you like to edit?" << endl;
                cout << "Enter test number: ";
                cin >> orange;
                cout << endl;
                tests.at(orange - 1).viewTest();
                cout << "What parameter would you like to edit?" << endl;
                cout << "Enter the parameter: ";
                cin >> strInput;
                do{
                    cout << "Enter new value: ";
                    cin >> numInput;
                    if(strInput == "isp"){
                        numInput /= 9.8;
                    }
                    tests.at(orange - 1).setVal(strInput, numInput);
                    cout << "If you would like to edit another parameter, enter it now: ";
                    cin >> strInput;
                    for(int i = 0; i < SIZE; i++){
                        if(strInput == test.getParam(i)){
                            flag = true;
                            break;
                        }
                    }
                    if(!flag){
                        edit = true;
                        break;
                    }
                }while(!edit);
                
                tests.at(0).overwriteTest(1);
                for(int i = 1; i < tests.size(); i++){
                    tests.at(i).saveTest(i + 1);
                }
                cout << endl;
                
                break;
                
            // Sort tests
            case 5:
                
                cout << "Sort by parameter" << endl;
                cout << "************************" << endl;
                if(tests.size() == 0){
                    cout << "There are no existing tests to sort." << endl;
                    cout << endl;
                    break;
                }
                cout << "What parameter would you like to sort by?" << endl;
                cout << "Avaliable parameters: of, pressure, pressureRatio, temp, expanRatio, cStar, isp" << endl;
                cout << "Enter parameter: ";
                cin >> strInput;
                if(strInput == "of"){
                    sortByParam(tests, OF);
                }
                else if(strInput == "pressure"){
                    sortByParam(tests, PRESSURE);
                }
                else if(strInput == "pressureRatio"){
                    sortByParam(tests, PRESSURERATIO);
                }
                else if(strInput == "temp"){
                    sortByParam(tests, TEMP);
                }
                else if(strInput == "expanRatio"){
                    sortByParam(tests, EXPANRATIO);
                }
                else if(strInput == "cStar"){
                    sortByParam(tests, CSTAR);
                }
                else if(strInput == "isp"){
                    sortByParam(tests, ISP);
                }
                else{
                    cout << strInput << " is not a recognized parameter.";
                    cout << endl;
                }

                tests.at(0).overwriteTest(1);
                for(int i = 1; i < tests.size(); i++){
                    tests.at(i).saveTest(i + 2);
                }
                cout << endl;
                
                break;
                
            case 6:
                
                cout << "Perform calculations" << endl;
                cout << "************************" << endl;
                if(tests.size() == 0){
                    cout << "There are no existing tests to use for the calculations." << endl;
                    cout << endl;
                    break;
                }
                cout << "There are " << tests.size() << " tests." << endl;
                cout << "Which test would you like to use for the calculations?" << endl;
                cout << "Enter test number: ";
                cin >> orange;
                cout << endl;
                tests.at(orange - 1).viewTest();
                tests.at(orange - 1).calc();
                
                break;
                
            // Clear tests
            case 7:
                
                cout << "Are you sure you would like to clear all existing tests?" << endl;
                cout << "Enter 'yes' or 'no': ";
                cin >> strInput;
                if(strInput == "yes" || strInput == "YES"){
                    clearTest(tests);
                    cout << "Tests cleared." << endl;
                }
                cout << endl;
                
                break;
                
            // Quit
            case 8:
                
                flag = true;
                
                break;
        }
    }
    
    cout << "See ya later alligator" << endl;
    
}
/*----------------------------------------------------------------------------------------------------------------*/

void displayMenu(){
    cout << "1) Create new test" << endl;
    cout << "2) View existing test" << endl;
    cout << "3) View all existing tests" << endl;
    cout << "4) Edit existing test" << endl;
    cout << "5) Sort by parameter" << endl;
    cout << "6) Perform calculations" << endl;
    cout << "7) Clear existing tests" << endl;
    cout << "8) Quit" << endl;
    cout << "Enter command: ";
}
