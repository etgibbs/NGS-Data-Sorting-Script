// Script.h contains function definitions

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/*
EXTRACTS FILENAME FROM INPUT
.TXT INPUT - .CSV OUTPUT FILE FOR BEST RESULTS
TIME COMPLEXITY O(1)
*/
string getFile() 
{
	string input = "";
	char disc;
	cout << "Drag & Drop .txt/.csv onto the Command Line!\n";
	cin >> disc;
	getline(cin, input);
	input.pop_back();

	return input;
}

/*
READS FROM FILE >> OUTPUT STREAM TO NEW.CSV
TIME COMPLEXITY O(n)
*/
void readFile(ifstream& ins, ofstream& outs) 
{
	string targetAmino = "", referenceAmino = "", type = "";
	int reads = 0, indel = 0, sampleID = 1;
	double pct = 0;

	outs << "SampleID, Reads, PCT, t-SEQ\n";

	while (ins >> reads)
	{
		// READS DATA IN FORMAT READ > PCT > INDEL > TARGET > REFERENCE
		ins >> pct >> indel >> targetAmino >> referenceAmino;
		
		// TYPE MUST BE FINAL COLUMN
		getline(ins, type);
		int found = type.find('I');
		bool run = found >= type.length();

		// READS MUST BE ABOVE 10, NO INSERTIONS OR DELETIONS
		if (reads >= 11 && indel == 0 && run)
		{
			outs << sampleID << ",";
			outs << reads << ",";
			outs << pct << ",";
			outs << "Target: " << targetAmino << ",";

			// IF ANY DIFFERENCE IN TARGET/REF, APPEND OUTPUT DIFF
			for (int i = 0; i < targetAmino.length(); ++i)
			{
				if (targetAmino[i] != referenceAmino[i]) {

					outs << targetAmino[i] << (i + 1) << referenceAmino[i] << ",";
				}
			}
			// END OF ROW, INDENT
			outs << endl;

		}
		// TRACK SAMPLE NUMBER IN ORIGINAL FILE
		sampleID++;
	}
	return;
}