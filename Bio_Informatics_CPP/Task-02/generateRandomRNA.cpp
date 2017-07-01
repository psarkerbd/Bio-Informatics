// Task-02: Generate Random RNA Sequence for K length
// Author: Pranta Sarker

#include<iostream>
#include<string>
#include<utility>
#include<algorithm>

using namespace std;

char RNA[]={'A' , 'U', 'C', 'G'};

void generateRNASequence(int limit)
{
    while(limit--)
    {
        int indx = rand() % 4;

        cout << RNA[indx];
    }
}

int main()
{
    int len;

    cout << "Enter Length to see Random RNA Sequence: ";

    while(cin >> len)
    {
        cout << "\nRNA Sequence is : ";

        generateRNASequence(len);

        cout << "\n\nEnter Length to see Random RNA Sequence: ";
    }

    return 0;
}
