//
//  main.cpp
//  IgniterCalcs
//
//  Created by Ishaan Patel on 12/10/22.
//

#include "CEATest.h"


int main() {
    
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
            test.setValues();
            tests.push_back(test);
            test.saveTest(static_cast<int>(tests.size()));
        }
        else if(strInput == "view" || strInput == "VIEW"){
            if(tests.size() == 0){
                cout << "There no tests to view" << endl;
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
    

    return 0;
}

