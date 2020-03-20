//headers
#include <bits/stdc++.h>
#include <math.h>
#include <algorithm>
#include <string>

using namespace std;
//functions

int BIT[1000];
int a[1000];
int n = 10;

void update(int index, int val)
{
    for(int i = index;i <= n;i = i + (i & -i))
    {
        BIT[i] += val;
    }
}

int query(int x)
{
    int query_sum = 0;
    for(int i = x;i > 0;i = i - (i & (-i)))
    {
        query_sum += BIT[i];
    }
    return query_sum;
}

//driver
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    for(int i = 1;i < 10;i++)
    {
        update(i,i);
        for(int i = 1 ;i < 10;i++){cout << BIT[i] << " ";}
        cout << endl;
    }
    for(int i = 1;i < 10;i++)
    {
        cout << query(i) << endl;
    }

    return 0;
}
