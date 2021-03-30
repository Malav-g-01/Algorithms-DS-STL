/*
        Author :- Malav Gajjar
*/
#include<bits/stdc++.h>
#define ll long long

using namespace std;

ll power(ll a, ll b)
{
        if(b == 0)
                return 1;
        
        if(b == 1)
                return a;
        
        ll tmp = power(a, b/2);
        ll result = tmp*tmp;
        
        if(b%2 == 1)
                result *= a;
        
        return result;
}
                

int main()
{
        ll a, b;
        cin >> a >> b; // a = base, b = exponent
        
        cout << power(a, b);
}
