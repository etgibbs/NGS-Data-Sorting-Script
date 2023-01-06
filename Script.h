// Script.h contains function definitions
#ifndef SCRIPT_H
#define SCRIPT_H

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
EXTRACTS FILENAME FROM INPUT
.TXT INPUT - .CSV OUTPUT FILE FOR BEST RESULTS
TIME COMPLEXITY O(1)
*/
inline string getFile() 
{
	string input;
	char disc;
	cout << "Drag & Drop .txt/.csv onto the Command Line!\n";
	cin >> disc;
	getline(cin, input);
	input.pop_back();

	return input;
}

inline double calcNewTotal(ifstream& ins) {

	int reads = 0, indel = 0;
	string discs, type;
	double discd = 0, newTotal = 0;

	while (ins >> reads) {

		ins >> discd >> indel >> discs >> discs;
		getline(ins, type);
		int found = type.find('I');
		bool run = found >= type.length();

		if (reads >= 10 && indel == 0 && run) {

			newTotal += reads;

		}
	}

	return newTotal;
}

/*
READS FROM FILE >> OUTPUT STREAM TO NEW.CSV
TIME COMPLEXITY O(n)
*/
inline void readFile(ifstream& ins, ofstream& outs, int newTotal) 
{
	vector<string> culled;
	vector<int> culledID;
	string targetAmino, referenceAmino, type, reason;
	double reads = 0, indel = 0;
	double pct = 0;
	int sampleID = 2;

	outs << "Reads, NEW PCT, t-SEQ, Mutations\n";

	ins.clear();
	while (ins >> reads)
	{
		// READS DATA IN FORMAT READ > PCT > INDEL > TARGET > REFERENCE
		ins >> pct >> indel >> targetAmino >> referenceAmino;
		
		// TYPE MUST BE FINAL COLUMN
		getline(ins, type);
		int found = type.find('I');
		bool run = found >= type.length();

		// READS MUST BE ABOVE 10, NO INSERTIONS OR DELETIONS
		if (reads >= 10 && indel == 0 && run)
		{
			pct = reads / newTotal;

			outs << reads << ",";
			outs << pct << ",";
			outs << "Target: " << targetAmino << ",";

			// IF ANY DIFFERENCE IN TARGET/REF, APPEND OUTPUT DIFF
			for (int i = 0; i < targetAmino.length(); ++i)
			{
				if (targetAmino[i] != referenceAmino[i]) {

					outs << referenceAmino[i] << (i + 1) << targetAmino[i] << " ";
				}
			}
			// END OF ROW, INDENT
			outs << endl;

		}
		else {

			// store removed target in array of strings
			culled.push_back(targetAmino);
			culledID.push_back(sampleID);
		}
		sampleID++;
	}

	outs << endl << "REMOVED " << "," << "INDEX IN ORIGINAL SHEET\n";

	for (int i = 0; i < culled.size(); ++i) {

		outs << culled[i] << "," << culledID[i] << endl;
	}
}
#endif // SCRIPT_H
