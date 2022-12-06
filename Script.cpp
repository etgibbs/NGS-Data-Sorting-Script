// Script.cpp contains main function

#include "Script.h"
#include <fstream>
using namespace std;

int main()
{
    cout << "NGS Data Sorting Script - Find Mutations in Target Sequences\n";
    cout << "Data must be formatted READS > PCT > INDEL > TARGET > REFERENCE > TYPE\n";
    cout << "Submit in order INPUT_FILE (.txt) >> OUTPUT_FILE (.csv)\n\n";

    ifstream ins;
    ofstream outs;
    string inputFileName = getFile();
    string outputFileName = getFile();

    ins.open(inputFileName);
    outs.open(outputFileName);
    readFile(ins, outs);

    return 0;
}