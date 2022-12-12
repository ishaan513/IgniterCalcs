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

void sortByParam(vector<CEATest>& tests, int param){
    switch (param){
        case 1:
            for(int i = 0; i < tests.size() - 1; i++){
                for(int j = 0; j < tests.size() - 1 - i; j++){
                    if(tests.at(j).getVal("of") < tests.at(j+1).getVal("of")){
                        swap(tests.at(j), tests.at(j+1));
                    }
                }
            }
            cout << "Sorted by OF Ratio" << endl;
            break;
        case 2:
            for(int i = 0; i < tests.size() - 1; i++){
                for(int j = 0; j < tests.size() - 1 - i; j++){
                    if(tests.at(j).getVal("pressure") < tests.at(j+1).getVal("pressure")){
                        swap(tests.at(j), tests.at(j+1));
                    }
                }
            }
            cout << "Sorted by Pressure" << endl;
            break;
        case 3:
            for(int i = 0; i < tests.size() - 1; i++){
                for(int j = 0; j < tests.size() - 1 - i; j++){
                    if(tests.at(j).getVal("pressureRatio") < tests.at(j+1).getVal("pressureRatio")){
                        swap(tests.at(j), tests.at(j+1));
                    }
                }
            }
            cout << "Sorted by Pressure Ratio" << endl;
            break;
        case 4:
            for(int i = 0; i < tests.size() - 1; i++){
                for(int j = 0; j < tests.size() - 1 - i; j++){
                    if(tests.at(j).getVal("temp") < tests.at(j+1).getVal("temp")){
                        swap(tests.at(j), tests.at(j+1));
                    }
                }
            }
            cout << "Sorted by Temperature" << endl;
            break;
        case 5:
            for(int i = 0; i < tests.size() - 1; i++){
                for(int j = 0; j < tests.size() - 1 - i; j++){
                    if(tests.at(j).getVal("expanRatio") < tests.at(j+1).getVal("expanRatio")){
                        swap(tests.at(j), tests.at(j+1));
                    }
                }
            }
            cout << "Sorted by Expansion Ratio" << endl;
            break;
        case 6:
            for(int i = 0; i < tests.size() - 1; i++){
                for(int j = 0; j < tests.size() - 1 - i; j++){
                    if(tests.at(j).getVal("cStar") < tests.at(j+1).getVal("cStar")){
                        swap(tests.at(j), tests.at(j+1));
                    }
                }
            }
            cout << "Sorted by C*" << endl;
            break;
        case 7:
            for(int i = 0; i < tests.size() - 1; i++){
                for(int j = 0; j < tests.size() - 1 - i; j++){
                    if(tests.at(j).getVal("isp") < tests.at(j+1).getVal("isp")){
                        swap(tests.at(j), tests.at(j+1));
                    }
                }
            }
            cout << "Sorted by Isp" << endl;
            break;
    }
}

void CEATest::setValues1(){
    string strInput;
    double numInput;
    bool flag = false;
    cout << "SET YOUR PARAMETERS" << endl;
    cout << "Enter your fuel: ";
    cin >> strInput;
    setFuelOx("fuel", strInput);
    cout << "Enter your oxidizer: ";
    cin >> strInput;
    setFuelOx("oxidizer", strInput);
    while(strInput != "NO" && strInput!= "no"){
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
        cout << "Enter " << strInput << " value: ";
        cin >> numInput;
        cout << endl;
        setVal(strInput, numInput);
        cout << "Do you wish to enter another value? YES or NO: ";
        cin >> strInput;
        cout << endl;
        flag = false;
    }
}

void CEATest::setValues(){
    string strInput;
    int numInput;
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
    //cout << endl << endl;
    output.close();
}

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

void clearTest(){
    ofstream output;
    output.open("tests.txt");
    output.close();
}

void runTest1(){
    vector<CEATest> tests;
    string strInput;
    int numInput;
    readTest(tests);
    cout << "*** ROCKET THING ***" << endl;
    while(strInput != "STOP" && strInput != "stop"){
        cout << "Do you wish to enter a new test or view a completed test? Enter 'new' or 'view': ";
        cin >> strInput;
        cout << endl;
        if(strInput == "new" || strInput == "NEW"){
            CEATest test;
            test.setValues1();
            tests.push_back(test);
            test.saveTest(static_cast<int>(tests.size()));
        }
        else if(strInput == "view" || strInput == "VIEW"){
            if(tests.size() == 0){
                cout << "There no tests to view." << endl;
            }
            else{
                cout << "There are " << tests.size() << " tests. Which one would you like to view?" << endl;
                cout << "TEST: ";
                cin >> numInput;
                cout << "** TEST #" << numInput << " **" << endl;
                tests.at(numInput - 1).viewTest();
            }
        }
        cout << "Do you wish to continue? Enter 'stop' or 'go': ";
        cin >> strInput;
        cout << endl;
    }
    cout << "See ya later alligator" << endl;
}

void runTest(){
    vector<CEATest> tests;
    CEATest test;
    string strInput;
    int numInput;
    bool flag = false;
    readTest(tests);
    cout << "*** ROCKET THING ***" << endl;
    while(!flag){
        displayMenu();
        cin >> numInput;
        cout << endl;
        
        switch(numInput){
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
                
                cout << "View existing tests" << endl;
                cout << "************************" << endl;
                if(tests.size() == 0){
                    cout << "There are no tests to view." << endl;
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
            // Edit test
            case 3:
                
                cout << "Edit existing test" << endl;
                cout << "************************" << endl;
                cout << "This don't work yet..." << endl;
                
                break;
            // Sort tests
            case 4:
                
                cout << "Sort by parameter" << endl;
                cout << "************************" << endl;
                cout << "This don't work yet..." << endl;
                
                break;
            // Clear tests
            case 5:
                
                cout << "Are you sure you would like to clear all existing tests?" << endl;
                cout << "Enter 'yes' or 'no': ";
                cin >> strInput;
                if(strInput == "yes" || strInput == "YES"){
                    clearTest();
                    cout << "Tests cleared." << endl;
                }
                cout << endl;
                
                break;
            // Quit
            case 6:
                flag = true;
                break;
        }
        
        
    }
    
    cout << "See ya later alligator" << endl;
    
}

void displayMenu(){
    cout << "1) Create new test" << endl;
    cout << "2) View existing tests" << endl;
    cout << "3) Edit existing test" << endl;
    cout << "4) Sort by parameter" << endl;
    cout << "5) Clear existing tests" << endl;
    cout << "6) Quit" << endl;
    cout << "Enter command: ";
}
