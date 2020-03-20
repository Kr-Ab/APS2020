// Libraries
#include <iostream>
#include <iomanip>
#include <bits/stdc++.h>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <climits>
// scope
using namespace std;
//function

int mid(int l,int r)
{
    return (l + (r-l)/2);
}
vector<int> build(vector<vector<int>> segments, int l, int r, vector<vector<int>> &tree, int c) 
{
    if (l == r) 
    { 
        tree[c] = segments[l];
        return tree[c]; 
    }
    vector<int> a = build(segments, l, mid(l, r), tree, c*2+1);
    vector<int> b = build(segments, mid(l, r)+1, r, tree, c*2+2);
    for(int i = 0;i<a.size();i++){
        tree[c][i] = a[i] + b[i];
    }
    return tree[c]; 
}
int query(vector<vector<int>> tree, int range_s, int range_e, int l, int r, int c,int h) 
{
    if (l <= range_s && range_e <= r)
        return tree[c][h];
    if (range_s > r || range_e < l)
        return 0;
    return query(tree, range_s, mid(range_s, range_e), l, r, 2*c+1,h)+query(tree, mid(range_s, range_e)+1, range_e, l, r, 2*c+2,h); 
}

//Driver
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int iter;cin>>iter;
    while(iter--)
    {
        int N,Q,maximum = INT_MIN;cin>>N>>Q;
        vector<int> arr(N,0);
        for(int i = 0;i < N;i++){
            cin>>arr[i];
            if(arr[i] >= maximum){maximum = arr[i];}
        }//input max and min
        vector<vector<int>> segments(N,vector<int>(maximum+1,0));
        vector<vector<int>> tree((2*N),vector<int>(maximum+1,0));
        for(int i = 0;i<N-1;i++)
        {
            if(arr[i] <= arr[i+1])
            {
                vector<int> temp(maximum+1,0);
                for(int j = arr[i];j <= arr[i+1];j++){temp[j] = 1;}
                segments[i] = temp;
            }
            else
            {
                vector<int> temp(maximum+1,0);
                for(int j = arr[i+1];j <= arr[i];j++){temp[j] = 1;}
                segments[i] = temp;
            }
        }
        build(segments,0,N-1,tree,0);
        // for(int i = 0;i<tree.size();i++)
        // {
        //     for(int j = 0;j<tree[i].size();j++)
        //     {
        //         cout << tree[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << endl;
        for(int i = 0;i < Q;i++)
        {
            int l,r,h;cin >> l >> r >> h;
            cout << query(tree,0,N-1,l-1,r-2,0,h) << endl;
        }
    }
    return 0;
}
