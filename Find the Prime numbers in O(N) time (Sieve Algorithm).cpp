/*
	Author :- Malav Gajjar
*/

#include<bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 1e7;

ll prime[N] = {0};

void sieve()
{
	for(ll i=2; i<=N; i++)
	{
		if(!prime[i])
		{
			for(ll j=i*i; j<=N; j++)
				prime[j] = 1;
		}
	}
}

int main()
{
	ll n;
	cin >> n;
	sieve();
	ll i, j, k;
	ll ans=0;
	
	if(n>=2)
	{
		for(i=2; i<=n; i++)
			if(!prime[i])
				ans += i;
	}
	
	cout << ans;
}
