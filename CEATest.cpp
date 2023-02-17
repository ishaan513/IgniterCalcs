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

// Parameters: propellant type (string), propellant (string)
// Sets propellant to specified propellant type
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
        cout << "SETFUELOX: *" << str << "* PARAMETER DOES NOT EXIST" << endl;
    }
}

// Parameters: propellant type (string)
// Returns the propellant of the specified propellant type
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

// Parameters: parameter (string), value (double)
// Sets the value to the specified parameter
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

// Parameters: parameter (string)
// Returns the value of the specified parameter
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

// Parameters: none
// Sets values to each parameter according to user input
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
        if(i == 5){
            numInput *= 3.281;
        }
        setVal(params[i], numInput);
    }
    getline(cin, strInput);
}

//void CEATest::getValues(){
//    string strInput;
//    bool flag = false;
//    cout << "RETREIVE YOUR PARAMETERS" << endl;
//    while (strInput != "STOP" && strInput != "stop"){
//        while(!flag){
//            cout << "Enter parameter (of, pressure, pressureRatio, temp, expanRatio, cStar, isp): ";
//            cin >> strInput;
//            for(int i = 0; i < SIZE; i++){
//                if(strInput == params[i]){
//                    flag = true;
//                    break;
//                }
//            }
//            if(!flag){
//                cout << strInput << " does not exist" << endl;
//            }
//        }
//        cout << strInput << ": " << getVal(strInput) << endl;
//        cout << endl;
//        cout << "Enter STOP to stop retreiving values or GO to continue: ";
//        cin >> strInput;
//        cout << endl;
//        flag = false;
//    }
//}
/*----------------------------------------------------------------------------------------------------------------*/

// Parameters: none
// Prints the data for a particular test in the saved vector of test objects
void CEATest::viewTest(){
    cout << "Fuel: " << fuel << endl;
    cout << "Oxidizer: " << oxidizer << endl;
    for(int i = 0; i < SIZE; i++){
        cout << params[i] << ": " << getVal(params[i]) << endl;
    }
    cout << endl;
}

// Parameters: test number (int)
// Saves a test to the text file under the specified test number
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

//void CEATest::saveTestCSV(int num){
//    ofstream output;
//    output.open("calcs.csv", fstream::app);
//    output << "** TEST #" << num << " **, \n";
//    output << "Fuel: " << fuel << endl;
//    output << "Oxidizer: " << oxidizer << endl;
//    for(int i = 0; i < SIZE; i++){
//        output << params[i] << ": " << getVal(params[i]) << endl;
//    }
//    output.close();
//}

// Parameters: test number (int)
// Overwrites the text file with the particular test
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

// Parameters: parameter (int)
// Returns the parameter name
string CEATest::getParam(int num){
    return params[num];
}
/*----------------------------------------------------------------------------------------------------------------*/

// Parameters: none
// Calls the sub-calculation functions and prints the results
void CEATest::calc(){
    propVals[OX] = getVal("of");
    propVals[FUEL] = 1;
    cout << "Total Mass Flow: " << calcMassFlow() << " lb/s" << endl;
    cout << "Fuel Mass Flow: " << calcPropMassFlow(propVals[FUEL]) << " lb/s" << endl;
    cout << "Oxidizer Mass Flow: " << calcPropMassFlow(propVals[OX]) << " lb/s" << endl;
    cout << "Fuel Orifice Diameter: " << 2 * sqrt(calcOrificeArea(FUEL) / 3.14) << " in" << endl;
    cout << "Oxidizer Orifice Diameter: " << 2 * sqrt(calcOrificeArea(OX) / 3.14) << " in" << endl;
    cout << "Throat Area: " << calcThroatArea() << " in^2" << endl;
    cout << "Throat Diameter: " << (2 * sqrt(calcThroatArea() / 3.14)) / 12.0 << " in" << endl;
    //cout << "This don't work yet..." << endl;
    cout << endl;
}

// Parameters: none
// Calculates the total mass flow
double CEATest::calcMassFlow(){
    double massFlow = -1;
    
    massFlow = thrust / values[ISP];
    
    return massFlow;
}

// Parameters: propellant type (int)
// Calculates the mass flow for the specified propellant
double CEATest::calcPropMassFlow(int prop){
    double propMassFlow = -1;
    
    propMassFlow = calcMassFlow() / (propVals[OX] + 1);
    propMassFlow *= prop;
    
    return propMassFlow;
}

// Parameters: propellant type (int)
// Calculates the injection orifice area for the specified propellant
double CEATest::calcOrificeArea(int prop){
    double orificeArea = -1;
    
    orificeArea = calcPropMassFlow(propVals[prop]) / (cd * sqrt(2.0 * density[prop] * getVal("pressure")));
    
    return orificeArea;
}

// Parameters: none
// Calculates the throat area
double CEATest::calcThroatArea(){
    double throatArea = -1;
    
    throatArea = (calcMassFlow() * getVal("cStar")) / getVal("pressure");
    
    return throatArea;
}
/*----------------------------------------------------------------------------------------------------------------*/

// Parameters: parameter (string)
// Checks if the passed parameter is a valid parameter
bool CEATest::checkParam(string str){
    bool flag = false;
    
    for(int i = 0; i < SIZE; i++){
        if(params[i] == str){
            flag = true;
        }
    }
    if(!flag){
        cout << str << " is not a recognized parameter." << endl;
        //cout << endl;
    }
    
    return flag;
}
/*----------------------------------------------------------------------------------------------------------------*/

// Parameters: saved tests (vector), parameter (string)
// Sorts the saved tests by the specified parameter in ascending order
void sortByParam2(vector<CEATest>& tests, string param){
    CEATest test;
    if(test.checkParam(param)){
        for(int i = 0; i < tests.size() - 1; i++){
            for(int j = 0; j < tests.size() - 1 - i; j++){
                if(tests.at(j).getVal(param) > tests.at(j+1).getVal(param)){
                    swap(tests.at(j), tests.at(j+1));
                }
            }
        }
        cout << "Sorted by " << param << endl;
    }
}
/*----------------------------------------------------------------------------------------------------------------*/

// Parameters: saved tests (vector)
// Reads the tests in the text file into the vector of saved test objects
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

// Parameters: saved tests (vector)
// Clears the tests in the text file and in the vector of saved test objects
void clearTest(vector<CEATest>& tests){
    ofstream output;
    output.open("tests.txt");
    output.close();
    tests.clear();
}
/*----------------------------------------------------------------------------------------------------------------*/

// Parameters: none
// Uses a switch statement to allow the user to access the functionality they wish to access
void runTest(){
    vector<CEATest> tests;
    CEATest test;
    string strInput, prop;
    double numInput;
    int apple, orange;
    bool flag = false, edit = false, grape = false, melon = false;
//    bool edit = false;
//    bool grape = false, melon = false;
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
                    if(numInput > tests.size() || numInput <= 0){
                        cout << "TEST #" << numInput << " does not exist." << endl;
                        cout << endl;
                        break;
                    }
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
                if(orange > tests.size() || orange <= 0){
                    cout << "TEST #" << orange << " does not exist." << endl;
                    cout << endl;
                    break;
                }
                cout << endl;
                tests.at(orange - 1).viewTest();
                cout << "What parameter would you like to edit?" << endl;
                cout << "Enter the parameter: ";
                cin >> strInput;
                
                if(strInput == "fuel" || strInput == "oxidizer"){
                    melon = true;
                }
                if(!melon){
                    
                    // integrate checkParam()
                    for(int i = 0; i < SIZE; i++){
                        if(test.getParam(i) == strInput){
                            grape = true;
                        }
                    }
                    if(!grape){
                        cout << strInput << " is not a recognized parameter." << endl;
                        cout << endl;
                        break;
                    }
                }
                
                // pretty sure this is broken. needs to not go into loop if param is not recognized
                // ok. it might not be broken. not sure. figure out how to integrate checkParam() everywhere it needs to be ;)
                
                do{
                    cout << "Enter new value: ";
                    if(melon){
                        cin >> prop;
                        tests.at(orange - 1).setFuelOx(strInput, prop);
                    }
                    else{
                        cin >> numInput;
                        if(strInput == "isp"){
                            numInput /= 9.8;
                        }
                        tests.at(orange - 1).setVal(strInput, numInput);
                    }
                    cout << "If you would like to edit another parameter, enter it now: ";
                    cin >> strInput;
                    melon = flag = edit = false;

                    if(strInput == "fuel" || strInput == "oxidizer"){
                        melon = true;
                    }
                    if(!melon){
                        for(int i = 0; i < SIZE; i++){
                            if(test.getParam(i) == strInput){
                                flag = true;
                                break;
                            }
                        }
                    }
                    
                    if(!melon && !flag){
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
                
                sortByParam2(tests, strInput);

                tests.at(0).overwriteTest(1);
                for(int i = 1; i < tests.size(); i++){
                    tests.at(i).saveTest(i + 1);
                }
                cout << endl;
                
                break;
                
            // Perform calculations
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
                if(orange > tests.size() || orange <= 0){
                    cout << "TEST #" << orange << " does not exist." << endl;
                    cout << endl;
                    break;
                }
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

// Parameters: none
// Prints the menu
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
