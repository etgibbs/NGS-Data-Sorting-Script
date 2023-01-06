// Script.cpp contains main function

#include "Script.h"
#include <fstream>
#include <string>
using namespace std;

int main()
{
    bool run = true;
    char choice;
    cout << "NGS Data Sorting Script - Find Mutations in Target Sequences\n";
    cout << "Data must be formatted READS > PCT > INDEL > TARGET > REFERENCE > TYPE\n";

    while (run) {

        cout << "Submit in order INPUT_FILE (.txt) >> OUTPUT_FILE (.csv)\n\n";

        ifstream ins, calc;
        ofstream outs;
        string inputFileName = getFile();
        string outputFileName = getFile();
        
        // sep stream to calc new total
        calc.open(inputFileName);
        double nt = calcNewTotal(calc);

        ins.open(inputFileName);
        outs.open(outputFileName);
        readFile(ins, outs, nt);

        cout << "Continue? (y/n)\n";
        cin >> choice;

        if (choice == 'n' || choice == 'N') {

            run = false;
        }
    }

    return 0;
}