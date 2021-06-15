/* 	
	ENJOY CP !!!!!
	Author :- Malav Gajjar
*/
#include<bits/stdc++.h>
//#include<ext/pd_ds/assoc_container.hpp>
//#include<ext/pd_ds/tree_policy.hpp>
//#include<ext/pd_ds/trie_policy.hpp>
using namespace std;
 
#define fio 			ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll	 			long long int 
#define ld 				long double
#define mod 			1000000007
#define inf 			1e18
#define endl 			"\n"
#define pb 				push_back
#define vi 				vector<ll>
#define vs 				vector<string>
#define pii 			pair<ll, ll>
#define ump				unordered_map
#define mp 				make_pair
#define pq_max			priority_queue<ll>
#define pq_min			priority_queue<ll, vi, greater<ll> >
#define all(v)			v.begin(), v.end()
#define ff				first
#define ss				second
#define rs				resize
#define ub				upper_bound
#define lb				lower_bound
#define mid(l, r)		(l + (r-l)/2)
#define bitc(x)			__builtin_popcount(x)
#define sp(a)			setprecision(a)
#define loop(a, b, c)		for(ll i=(a); i<=(b); i+=c)
#define loop_r(a, b, c)	for(ll i=(a); i>=(b); i-=c)
#define itr(c)			for(auto it=c.begin(); it!=c.end(); it++)
#define log(x) 			cout << #x << ' ' << x;
#define out(arr, a, b)	for(ll i=(a); i<=(b); i++)	cout << arr[i] << ' ';	cout << '\n';
 
template <typename T> T gcd(T a, T b) { if(a%b) return gcd(b, a%b); return b; }
template <typename T> T lcm(T a, T b) { return (a*b/gcd(a, b)); }
 
void file_i_o()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
}

int main(int argc, char const *argv[])
{
	fio;
	file_i_o();
	/* code */
 
	ll n;
	cin >> n;
	vi a(n);
	stack<ll> st;
	vi ans(n);

	for(ll i=0; i<n; i++)
		cin >> a[i];

	for(ll i=n-1; i>=0; i--){
		if(st.empty())
			ans[i] = -1;

		else{
			while(!st.empty() and st.top() <= a[i])
				st.pop();

			if(st.empty())
				ans[i] = -1;

			else
				ans[i] = st.top();
		}

		st.push(a[i]);
	}

	for(auto it:ans)
		cout << it << ' ';

	return 0;
}
