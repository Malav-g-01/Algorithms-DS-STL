#include<bits/stdc++.h> 
using namespace std ; 
 
int main () {
	int n;
	cin >> n;
	int a[n];
	int i;
	
	for(i=0; i<n; i++)
		cin >> a[i];
	
	int j=a[0], k=a[0];
	
	for(i=1; i<n; i++)
	{
		j = max(a[i], a[i]+j);
		
		if(k<j)
			k = j;
	}
	
	cout << k;
}
