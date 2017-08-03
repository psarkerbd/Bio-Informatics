#include<bits/stdc++.h>
using namespace std;

const int high = 100;

char DNA[4] = {'A' , 'T' , 'C' , 'G'};

vector<char>motif[high];
vector<string>getmotifs;

int check[high];

void clr(int length)
{
    for(int i=0; i<length; i++)
    {
        motif[i].clear();
        check[i] = 0;
    }
}

void takeDNAsequence(int row , int col)
{
    int i=0 , j=0;

    for(i=0; i<row; i++)
    {
        for(j=0; j<col; j++)
        {
            int indx = (rand() % 4);
            char ch = DNA[indx];
            motif[i].push_back(ch);
        }
    }

    cout << "\nDNA Sequences:\n";

    for(i=0; i<row; i++)
    {
        //cout << "for " << i << ":\n";

        for(j=0; j<motif[i].size(); j++)
        {
            cout << motif[i][j] << " ";
        }

        cout << "\n";
    }
}

void Motif_Finding(int row, int col , int lmar)
{
    int i=0 , j=0 , k=0, l=0, p=0;
    string s = "";
    bool fl=true;

    for(i=0; i<motif[0].size()-lmar+1; i++)
    {
        s = "";

        for(j=i; j<lmar+i; j++)
        {
            s += motif[0][j];
        }

        //cout << " s = " << s << "\n";

        string instring = "";

        for(k=1; k<row; k++)
        {
            instring = "";

            for(l=0; l<motif[k].size()-lmar+1; l++)
            {
                instring = "";

                for(p=l; p<lmar+l; p++)
                {
                    instring+=motif[k][p];
                }

                //cout << " instring = " << instring << "\n";

                if(s == instring)
                {
                    //cout << "find motif = " << s << "\n";

                    getmotifs.push_back(instring);

                    check[k] = 1;
                    //cout << "k = " << k << "\n";
                }

                else
                {
                    continue;
                }
            }

            fl=true;

            for(int x=1; x<row; x++)
            {
                if(!check[x])
                {
                    fl=false;
                    break;
                }
            }

            if(fl)
            {
               break;
            }

            else
            {
                getmotifs.clear();

                for(int h=0; h<high; h++) check[h] = 0;
            }
        }

        if(fl) break;
    }

    if(fl)
    {
        cout << "\n>> Motif:\n";

        for(i=0; i<getmotifs.size(); i++) cout << getmotifs[i] << "\n";
    }

    else
    {
        cout << "\n<< Motif did not found\n";
    }
}

int main()
{
    int length, lmar , sample;
    cout << "Enter Sample(0 to end terminal): ";
    cin >> sample;
    cout << "\nEnter DNA Sequence Length: ";
    cin >> length;
    while(sample)
    {
        clr(max(sample , length));
        getmotifs.clear();

        takeDNAsequence(sample , length);

        cout << "\nEnter l-mar: ";
        cin >> lmar;

        Motif_Finding(sample , length , lmar);

        cout << "\n\nEnter Sample(0 to end terminal): ";
        cin >> sample;
        if(!sample) break;
        cout << "\nEnter DNA Sequence Length(0 to end terminal): ";
        cin >> length;
        if(!length) break;
    }

    cout << "\n<<<< End terminal >>>>>\n";

    return 0;
}
