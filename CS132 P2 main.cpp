////
// Name: Josh Matyas
// Section: B
// Program Name: p2 MYString v1 
// th
// Description: MyString program takes strings from a file and sorts them from smallest to largest. This is done by creating the myString class vector words
// and reading in strings from a file. It is then bubble sorted through a function and outputtec to a file in columns of 6
////

/*
#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include "MYString.h"

using namespace std;

int main() {

    vector<MYString> words(100);        // calls default constructor 100 times
    ifstream fin("infile3.txt");
    ofstream fout("outfile.txt");

    // READ
    if (fin.fail()) {
        cout << "Couldn't open infile3.txt" << endl;
        system("pause");
        exit(1);
    }

    int wordCnt = 0;
    for (;(fin) >> words[wordCnt]; ++wordCnt) {       // empty loop
  
    }

    vector<MYString> combo(1);
    int cnt = 0;
    
    MYString temp, empty;
    temp = words[0] + words[1];
  
    for (int k = 2; k < wordCnt; k++) {

        temp = temp + words[k];
      

       if (k % 5 == 4) {
        
          combo.push_back(temp);
          temp = empty;
       }
    }
 
      bool notDone = true;             //sort
    while (notDone == true) {
        notDone = false;
        
     MYString temp;
        for (int i = 1; i < combo.size(); i++) {
            if (combo[i - 1] > (combo[i])) {
                temp = combo[i - 1];
                combo[i - 1] = combo[i];
                combo[i] = temp;
                notDone = true;
            }
        }
    }
    

    
    for (int i = 0; i < combo.size(); i++) {      //output
        fout << combo[i];
        fout << endl;
       
    }


    fout << "MYStrings Currently alive: " << MYString::getCurrentCount() << endl;
   fout << "MYString Created: " << MYString::getCreatedCount() << endl;
    return 0;
}

/*

Ibegantocomparethe
Ifeltwasimpossible.Or
Theyseemedamazinglybusy.I
andrulesinhisbody?
anironcladorasteam
asaman'sbrainsits
askmyselfforthefirst
begantoaskmyselfwhat
didaMartiansitwithin
each,ruling,directing,using,much
enginewouldseemtoan
intelligentmechanisms?Suchathing
theycouldbe.Werethey
thingstohumanmachines,to
timeinmylifehow
MYStrings Currently alive: 118
MYString Created: 322

*/