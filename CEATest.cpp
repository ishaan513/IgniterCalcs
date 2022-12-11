//
//  CEATest.cpp
//  IgniterCalcs
//
//  Created by Ishaan Patel on 12/10/22.
//

#include <stdio.h>
#include "CEATest.h"

CEATest::CEATest(){
    
//    string str;
//    input.open(file);
//    checkFile(input, file);
//    for(int i = 0; i < 16; i++){
//        getline(input, str);
//    }
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

string CEATest::getFuelOx(string str){
    string fuelOx = "NULL";
    bool flag = false;
    if(str == "fuel"){
        fuelOx = fuel;
        flag = true;
    }
    else if(str == "oxidizer"){
        fuelOx = oxidizer;
        flag = true;
    }
    if(!flag){
        cout << "GETFUELOX: *" << str << "* PARAMETER DOES NOT EXIST" << endl;
    }
    return fuelOx;
}

void CEATest::sortByParam(vector<CEATest>& tests, int param){
    switch (param){
        case 1:
            for(int i = 0; i < tests.size() - 1; i++){
                for(int j = 0; j < tests.size() - 1 - i; j++){
                    if(tests.at(j).of < tests.at(j+1).of){
                        swap(tests.at(j), tests.at(j+1));
                    }
                }
            }
            cout << "Sorted by OF Ratio" << endl;
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
    }
}

void CEATest::setValues(){
    string strInput;
    double numInput;
    bool flag = false;
    cout << "SET YOUR PARAMETERS" << endl;
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
    for(int i = 0; i < SIZE; i++){
        cout << params[i] << ": " << getVal(params[i]) << endl;
    }
}

void CEATest::saveTest(int num){
    ofstream output;
    output.open("tests.txt", fstream::app);
    output << "** TEST #" << num << " **" << endl;
    for(int i = 0; i < SIZE; i++){
        output << params[i] << ": " << getVal(params[i]) << endl;
    }
    cout << endl << endl;
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
        for(int i = 0; i < SIZE; i++){
            getline(input, str, ':');
            getline(input, empty, ' ');
            input >> num;
            getline(input, empty);
            test.setVal(str, num);
        }
        vector.push_back(test);
        getline(input, empty);
    }
}

//void checkFile(ifstream& input, string str){
//    if(input){
//        cout << "good file" << endl;
//    }
//    else{
//        cout << "bad file" << endl;
//    }
//}
