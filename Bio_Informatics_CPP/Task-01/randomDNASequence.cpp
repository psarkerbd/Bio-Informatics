// Task-01: Generate Random DNA Sequence for K length
// Author: Pranta Sarker

#include<iostream>
#include<string>
#include<utility>
#include<algorithm>

using namespace std;

char DNA[]={'A', 'T', 'C', 'G'};

void generateDNASequence(int limit)
{
    for(int i=0; i<limit; i++)
    {
        int range = (3 - 0) + 1;
        int num = ( rand() % range ) + 0;
        cout << DNA[num];
    }
}

int main()
{
    int len;

    cout << "Enter Length to see Random DNA Sequence: ";

    while(cin >> len)
    {
        cout << "\nDNA Sequence is : ";

        generateDNASequence(len);

        cout << "\n\nEnter Length to see Random DNA Sequence: ";
    }

    return 0;
}
