//headers
#include <bits/stdc++.h>
#include <math.h>
#include <algorithm>
#include <string>

using namespace std;
//functions

int Longest_commmon_subsequence(string a,string b)
{
    int LCS[b.length()+1][a.length()+1] = { 0 };
    for(int i = 0;i < b.length()+1;i++)
    {
        for(int j = 0;j < a.length()+1;j++)
        {
            if(i == 0 || j == 0)
            {
                LCS[i][j] = 0;
            }
            else if(a[j-1] == b[i-1])
            {
                LCS[i][j] = LCS[i-1][j-1] + 1;
            }
            else
            {
                LCS[i][j] = max(LCS[i][j-1],LCS[i-1][j]);
            }
        }
    }
    for(int i = 0;i < b.length()+1;i++)
    {
        for(int j = 0;j < a.length()+1;j++)
        {
            cout << LCS[i][j] << " ";
        }
        cout << endl;
    }
    return LCS[b.length()][a.length()];
}


//driver
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    string a,b;
    cin >> a >> b;
    cout << Longest_commmon_subsequence(a,b);
    return 0;
}
