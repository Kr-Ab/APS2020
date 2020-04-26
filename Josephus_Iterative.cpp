#include <bits/stdc++.h>
#include <string.h>

using namespace std;

int josephus(int n,int k)
{
  int res = 0;
  for(int i = 1;i <= n;i++)
  {
    res = (res + k) % i;
  }
  return res + 1;
}

int main()
{
  cout << josephus(5,2) << endl;
  return 0;
}
