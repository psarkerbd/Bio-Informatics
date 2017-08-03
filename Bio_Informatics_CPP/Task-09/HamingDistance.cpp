#include<iostream>
#include<string>
#include<cstring>
#include<map>
#include<vector>
#include<utility>
#include<random>
#include<set>

using namespace std;

typedef map<string, bool>mpsb;
typedef vector<string>vs;
typedef vector<char>vc;

char DNA[4] = {'A' , 'T' , 'C' , 'G'};
char RNA[4] = {'A' , 'U' , 'C' , 'G'};

string dna = "" , rna = "" , mutation="";

mpsb mp;
vc resDNA, resMutation;

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

//void takeRNASequence(int limit)
//{
//    int i=0;
//
//    for(i=0; i<limit; i++)
//    {
//        int range = (3 - 0) + 1;
//        int indx = ( rand() % range ) + 0;
//        rna += RNA[indx];
//    }
//}
//
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
//        }
//
//        mp[tmp] = 1;
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
//        }
//
//        mp[tmp] = 1;
//    }
//}
//
//void showDNA()
//{
//    cout << "\n***** DNA l-mar substrings ******\n";
//
//    for(int i=0; i<resDNA.size(); i++)
//    {
//        cout << resDNA[i] << "\n";
//    }
//}
//
//void showRNA()
//{
//    cout << "\n***** RNA l-mar substrings ******\n";
//
//    for(int i=0; i<resRNA.size(); i++)
//    {
//        cout << resRNA[i] << "\n";
//    }
//}

void DNAMutation(int length)
{
    for(int i=0; i<length; i++)
    {
        int range = (3 - 0) + 1;
        int indx = ( rand() % range ) + 0;
        mutation += DNA[indx];
    }
}

int Find_HamingDistance(string dna, string mutatedDNA)
{
    int i=0 , hamingDistance = 0;

    for(i=0; i<dna.length(); i++)
    {
        if(dna[i] == mutatedDNA[i])
        {
            resDNA.push_back(dna[i]);
            resMutation.push_back(mutatedDNA[i]);
            hamingDistance+=1;
        }
    }

    return hamingDistance;
}

void showHaming()
{
    for(int i=0; i<resDNA.size(); i++)
    {
        cout << resDNA[i] << " ";
    }

    cout << "\n";

    for(int i=0; i<resMutation.size(); i++)
    {
        cout << resMutation[i] << " ";
    }
}

int main()
{
    int length = 0 , lmar;
    cout << ">>>> Start terminal <<<<\n";
    cout << "\nEnter Sequence Length(0 to end): ";
    cin >> length;
    while(length)
    {
        dna = "";
        //rna = "";
        mutation = "";
        //mp.clear();
        resDNA.clear();
        //resRNA.clear();
        resMutation.clear();

        takeDNASequence(length);
        //takeRNASequence(length);
        DNAMutation(length);

        cout << "\nDNA sequence: " << dna << "\nMutated DNA sequence: " << mutation << "\n";

        int HamingDistance = Find_HamingDistance(dna, mutation);

        cout << "\nHaming Distance: " << HamingDistance << "\n\n";

        showHaming();

        cout << "\n\nEnter Sequence Length(0 to end): ";

        cin >> length;
    }

    cout << "\n<<<< End terminal >>>>\n";
    return 0;
}

