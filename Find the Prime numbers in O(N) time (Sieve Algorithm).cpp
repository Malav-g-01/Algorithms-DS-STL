/*
	Author :- Malav Gajjar
	
when prime[i] is 0 it means that i is the prime number.
First of all we will mark all the non prime numbers(as 1) in the array prime[]
Then count the number of prime numbers <= n.
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
			for(ll j=i*i; j<=N; j+=i)
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
