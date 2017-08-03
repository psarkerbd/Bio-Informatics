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

vii L , X;
sii visited;
mpii mp , current;

int formula(int a , int b , int c)
{
    c = -c;
    int D = (b * b) - (4 * a * (c));
    int n = (-b + sqrt(D)) / (2 * a);
    return n;
}

void getFrequency()
{
    for(int i=0; i<L.size(); i++)
    {
        mp[L[i]]++;
    }
}

void PDP(int size)
{
    int i , j , k;
    int n = formula(1, -1, 2*size) , takeminimum = inf;
    //cout << n << "\n";
    for(i=1; i<L.size(); i++)
    {
        int element = L[i];
        takeminimum = inf;

        if(n == X.size())
        {
            break;
        }

        else
        {
            for(j=0; j<X.size(); j++)
            {
                int point = abs(element - X[j]);

                //cout << "element = " << element << " X = " << X[j] << " " << "point = " << point << "\n";

                if(mp[point] > 0)
                {
                    int cnt = 0;
                    current.clear();

                    for(k=0; k<X.size(); k++)
                    {
                        int diff2 = abs(point - X[k]);

                        //cout << "diff2 = " << diff2 << "\n";

                        if(mp[diff2] > 0)
                        {
                            current[diff2]+=1;

                            //cout << "diff2 frequency = " << current[diff2] << "\n";

                            if(mp[diff2] >= current[diff2])
                            {
                                cnt+=1;
                                //cout << "cnt = " << cnt << "\n";
                            }

                            else
                            {
                                continue;
                            }
                        }

                        else
                        {
                            continue;
                        }
                    }

                    if(cnt == X.size())
                    {
                        takeminimum = min(takeminimum , point);
                        //cout << "takeminimum = " << takeminimum << "\n";
                    }
                }

                else
                {
                    continue;
                }
            }

            if(takeminimum < inf)
            {
                X.push_back(takeminimum);
                mp[takeminimum]--;
                //cout << "final minimum = " << takeminimum << "\n";
            }
        }
    }
}

bool checkInX()
{
    for(int i=0; i<X.size(); i++)
    {
        for(int j=i+1; j<X.size(); j++)
        {
            int diff = abs(X[i] - X[j]);

            mp[diff]--;
        }
    }

    bool fl=true;

    for(int i=0; i<X.size(); i++)
    {
        if(mp[X[i]] > 0)
        {
            fl=false;
            break;
        }
    }

    if(fl) return true;

    return false;
}

int main()
{
    cout << ">>>> Start terminal <<<<\n";
    cout << "\nEnter Size(0 to end): ";
    int size;
    cin >> size;
    while(size)
    {
        visited.clear();
        L.clear();
        mp.clear();
        current.clear();
        X.clear();

        cout << "\nEnter " << size << " elements: ";

        while(size--)
        {
            int x;
            cin >> x;
            L.push_back(x);
        }

        sort(L.rbegin(), L.rend());
        //for(int i=0; i<L.size(); i++) cout << L[i] << "; ";

        getFrequency();

        X.push_back(0);
        X.push_back(L[0]);

        PDP(L.size());
        //for(int i=0; i<X.size(); i++) cout << X[i] << "; ";
        bool prove = checkInX();

        if(!prove) cout << "\nNo Solution\n";

        else
        {
            cout << "\nPartial Digest Points are: ";

            sort(X.begin() , X.end());

            for(int i=0; i<X.size(); i++)
            {
                cout << X[i] << " ";
            }

            cout << "\n";
        }

        cout << "\nEnter Size(0 to end): ";
        cin >> size;
    }

    cout << "\n<<<< End terminal >>>>\n";
    return 0;
}
