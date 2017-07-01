// Task-05: DNA to RNA
// Author: Pranta Sarker

#include<iostream>
#include<string>
#include<utility>
#include<algorithm>
#include<map>

using namespace std;

char DNA[]={'A', 'T', 'C', 'G'};
string DNAsequence;

void generateDNASequence(int limit)
{
    DNAsequence="";

    cout << "\n";

    for(int i=0; i<limit; i++)
    {
        int indx = rand() % 4;

        DNAsequence += DNA[indx];

        //cout << DNA[indx];
    }

    cout << DNAsequence << "--> DNA";

    cout << "\n";


    cout << "(CONVERT)";

    cout << "\n";

    for(int i=0; i<DNAsequence.length(); i++)
    {
        if(DNAsequence[i] == 'T') cout << "U";

        else
        {
            cout << DNAsequence[i];
        }
    }

    cout << "--> RNA";
}

int main()
{
    int len;

    cout << "Enter Length to see Random DNA Sequence: ";

    while(cin >> len)
    {
        //cout << "\nDNA Sequence is : ";

        generateDNASequence(len);

        cout << "\n\nEnter Length to see Random DNA Sequence: ";
    }

    return 0;
}

