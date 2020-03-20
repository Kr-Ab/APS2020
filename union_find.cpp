//headers
#include <bits/stdc++.h>
#include <math.h>
#include <algorithm>
#include <string>

using namespace std;
//functions
int root(vector<int> a,int i)
{
    while(a[i] != i)
    {
        i = a[i];
    }
    return i;
}

void w_union(vector<int> &a,vector<int> &size,int u,int v)
{
    int rootu = root(a,u),rootv = root(a,v);
    if(size[rootu] < size[rootv])
    {
        a[rootu] = a[rootv];
        size[rootv] += size[rootu];
    }
    else
    {
        a[rootv] = a[rootu];
        size[rootu] += size[rootv];
    }
}

int find(vector<int> a,int u,int v)
{
    if(root(a,u) == root(a,v)){return 1;}
    else{return 0;}
}

//driver
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    vector<int> a{0,1,2,3,4,5,6};
    vector<int> size(7,1);
    w_union(a,size,1,0);
    for(int i = 0;i<a.size();i++){cout << a[i] << " ";}
    cout << endl;
    w_union(a,size,0,2);
    for(int i = 0;i<a.size();i++){cout << a[i] << " ";}
    cout << endl;
    w_union(a,size,3,4);
    for(int i = 0;i<a.size();i++){cout << a[i] << " ";}
    cout << endl;
    return 0;
}
