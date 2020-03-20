//headers
#include <bits/stdc++.h>
#include <math.h>
#include <algorithm>
#include <string.h>
#include <climits>

using namespace std;


//functions
int josephus(int n, int k) 
{
    if(n == 1)
        return 1;
    return ((k + josephus(n-1,k) - 1) % n) + 1;
}

//driver
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int test;cin>>test;
    while(test--)
    {
        cout << josephus(a,b) << endl; 
    }    
}

