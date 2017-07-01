// Task-03: Count DNA Nucleotides
// Author: Pranta Sarker

#include<iostream>
#include<string>
#include<utility>
#include<algorithm>
#include<map>

using namespace std;

typedef map<char, int>mpci;

char DNA[]={'A', 'T', 'C', 'G'};

mpci countNucleotides;

void generateDNASequence(int limit)
{
    for(int i=0; i<limit; i++)
    {
        int indx = rand() % 4;

        cout << DNA[indx];

        countNucleotides[DNA[indx]]++;
    }

    cout << "\n\nNucleotides are:\n\n";

    cout << "     A=" << countNucleotides['A'] << "\n";
    cout << "     T=" << countNucleotides['T'] << "\n";
    cout << "     C=" << countNucleotides['C'] << "\n";
    cout << "     G=" << countNucleotides['G'] << "\n";
}

int main()
{
    int len;

    cout << "Enter Length to see Random DNA Sequence: ";

    while(cin >> len)
    {
        countNucleotides.clear();

        cout << "\nDNA Sequence is : ";

        generateDNASequence(len);

        cout << "\n\nEnter Length to see Random DNA Sequence: ";
    }

    return 0;
}
