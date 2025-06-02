#include <bits/stdc++.h>
using namespace std;
 
long long lcm(long long a, long long b){ return (a*b)/gcd(a, b); }
 
int main()
{
	long long n, ans=0;
	cin>>n;
	vector<long long> a(n), pregcd(n);
	
	for(int i=0; i<n; i++)
		cin>>a[i];
	
	pregcd[n-2]=a[n-1];	
	for(int i=n-3; i>=0; i--)
		pregcd[i]=gcd(pregcd[i+1], a[i+1]);
	
	for(int i=0; i<n-1; i++)
		pregcd[i]=lcm(pregcd[i], a[i]);
	
	for(int i=0; i<n-1; i++)
		ans=gcd(ans, pregcd[i]);
	cout<<ans<<endl;	  
}