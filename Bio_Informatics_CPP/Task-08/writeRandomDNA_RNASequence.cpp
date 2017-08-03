//#include<iostream>
//#include<string>
//#include<cstring>
//#include<map>
//#include<vector>
//#include<utility>
//#include<random>
//#include<set>
//#include<file>

#include<bits/stdc++.h>

using namespace std;

typedef map<string, int>mpsb;
typedef vector<string>vs;

char DNA[4] = {'A' , 'T' , 'C' , 'G'};
char RNA[4] = {'A' , 'U' , 'C' , 'G'};

string dna = "" , rna = "";

mpsb mp;
vs resDNA, resRNA;

void takeDNASequence(int limit)
{
    int i=0;

    for(i=0; i<limit; i++)
    {
        int range = (3 - 0) + 1;
        int indx = ( rand() % range ) + 0;
        dna += DNA[indx];
    }
}

void takeRNASequence(int limit)
{
    int i=0;

    for(i=0; i<limit; i++)
    {
        int range = (3 - 0) + 1;
        int indx = ( rand() % range ) + 0;
        rna += RNA[indx];
    }
}

//void DNAlmar(string dna , int limit)
//{
//    int i=0;
//
//    string tmp = "";
//
//    for(i=0; i<dna.length()-(limit-1); i++)
//    {
//        tmp = dna.substr(i , limit);
//
//        if(!mp.count(tmp))
//        {
//            resDNA.push_back(tmp);
//            mp[tmp] += 1;
//        }
//
//        else
//        {
//            mp[tmp]+=1;
//        }
//    }
//}
//
//void RNAlmar(string rna , int limit)
//{
//    int i=0;
//
//    string tmp = "";
//
//    for(i=0; i<rna.length()-(limit-1); i++)
//    {
//        tmp = rna.substr(i , limit);
//
//        if(!mp.count(tmp))
//        {
//            resRNA.push_back(tmp);
//
//            mp[tmp] += 1;
//        }
//
//        else
//        {
//            mp[tmp]+=1;
//        }
//    }
//}
//
//void showDNA()
//{
//    cout << "\n***** DNA l-mar substrings ******\n";
//
//    for(int i=0; i<resDNA.size(); i++)
//    {
//        cout << resDNA[i] << " " << mp[resDNA[i]] << "\n";
//    }
//}
//
//void showRNA()
//{
//    cout << "\n***** RNA l-mar substrings ******\n";
//
//    for(int i=0; i<resRNA.size(); i++)
//    {
//        cout << resRNA[i] << " " << mp[resRNA[i]] << "\n";
//    }
//}

int main()
{
    int length = 0 , lmar;
    cout << "Enter Sequence Length(0 to end): ";
    cin >> length;
    takeDNASequence(length);
    takeRNASequence(length);
    cout << "Done!\n";
    freopen("RandomSequence_of_DNA_and_RNA.txt" , "w" , stdout);
    cout << dna << "\n" << rna << "\n";
    return 0;
}


