// Solution for https://www.codechef.com/problems/LECANDY
// Libraries
#include <iostream>
#include <iomanip>
#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp> 
#include <algorithm>
#include <cmath>
#include <cctype>
// scope
using namespace boost::multiprecision; 
using namespace std;
//function

//Driver
int main() {
	int iter;cin>>iter;
	while(iter--)
	{
	    int x,y,tot=0;cin >> x >> y;
	    for(int i = 0;i<x;i++)
	    {
	        int a;cin>>a;tot+=a;
	    }
	    if(tot <= y)
	    {
	        cout << "Yes"<< endl;
	    }
	    else
	    {
	        cout << "No"<< endl;
	    }
	}
	return 0;
}
