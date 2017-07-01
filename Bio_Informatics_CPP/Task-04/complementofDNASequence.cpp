// Task-04: Complement of DNA Sequence
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

        cout << DNA[indx];
    }

    cout << "\n";


    for(int i=0; i<DNAsequence.length(); i++)
    {
        cout << "|";
    }

    cout << "\n";

    for(int i=0; i<DNAsequence.length(); i++)
    {
        if(DNAsequence[i] == 'A') cout << "T";
        else if(DNAsequence[i] == 'T') cout << "A";
        else if(DNAsequence[i] == 'C') cout << "G";
        else if(DNAsequence[i] == 'G') cout << "C";
    }
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
