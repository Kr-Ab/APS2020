//Solution for https://www.codechef.com/problems/CNOTE
// Libraries
#include <iostream>
#include <iomanip>
#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp> 
#include <algorithm>
#include <cmath>
#include <cctype>
#include <string>
// scope
using namespace boost::multiprecision; 
using namespace std;
//function

//Driver
int main() {
	int iter;cin>>iter;
	while(iter--)
	{
	    int x,y,k,n;cin >> x >> y >> k >> n;
	    int req = x-y;string ans = "UnluckyChef";
	    for(int i = 0;i<n;i++)
	    {
	        int a,b;cin >> a >> b;
	        if(a >= req && b <= k)
	        {
	            ans = "LuckyChef";
	        }
	    }
	    cout << ans << endl;
	}
	return 0;
}
