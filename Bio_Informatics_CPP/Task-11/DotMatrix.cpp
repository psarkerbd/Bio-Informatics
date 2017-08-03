#include<iostream>
#include<string>
#include<cstring>
#include<map>
#include<vector>
#include<utility>
#include<random>
#include<set>
#include<algorithm>
#include<cmath>

using namespace std;

typedef map<string, bool>mpsb;
typedef vector<string>vs;
typedef vector<char>vc;
typedef vector<int>vii;
typedef set<int>sii;
typedef map<int, int>mpii;

const int inf = 1e5;

int main()
{
    int i=0 , j=0;

    string first_dna = "ATGGT";
    string second_dna = "CTATGTC";

    int high = max(first_dna.length() , second_dna.length());
    int len1 = first_dna.length(), len2 = second_dna.length();

    char DotMatrix[high][high];

    for(i=0; i<len1; i++)
    {
        DotMatrix[0][i] = first_dna[i];
    }

    for(i=1; i<=len2; i++)
    {
        DotMatrix[i][0] = second_dna[i-1];
    }

    for(i=1; i<=len2; i++)
    {
        for(j=1; j<=len1; j++)
        {
            DotMatrix[i][j] = 'D';
        }
    }

    for(i=1; i<=len2; i++)
    {
        for(j=0; j<len1; j++)
        {
            if(DotMatrix[i][0] == DotMatrix[0][j])
            {
                DotMatrix[i][j+1] = '.';
            }
        }
    }

    for(i=0; i<len1; i++) cout << "   " << DotMatrix[0][i] << " ";
    cout << "\n";

    for(i=1; i<=len2; i++)
    {
        cout << DotMatrix[i][0] << "  ";

        for(j=1; j<=len1; j++)
        {
            //DotMatrix[i][j] = 'D';
            cout << DotMatrix[i][j] << "    ";
        }

        cout << "\n";
    }

    return 0;
}
