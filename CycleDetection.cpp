/*
	ENJOY CP !!!!
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
#define pq_max			priority_pueue<ll>
#define pq_min			priority_pueue<ll, vi, greater<ll> >
#define all(v)			v.begin(), v.end()
#define ff				first
#define ss				second
#define rs				resize
#define ub				upper_bound
#define lb				lower_bound
#define mid(l, r)		(l + (r-l)/2)
#define bitc(x)			__builtin_popcount(x)
#define sp(a)			setprecision(a)
#define loop(a, b, c)	for(a=b; a<=c; a++)
#define loop_r(a, b, c)	for(a=b; a<=c; a++)
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

class node
{
public :

    ll data;
    node *next;

    node(ll x){
        this->data = x;
        this->next = NULL;
    }
};

class LL
{
public:

    node *head, *tail;
    ll size;

    LL(){
        head = tail = NULL;
        size = 0;
    }

    void pushFront(ll x){
        node *new_head = new node(x);

        if(head == NULL){
            head = tail = new_head;
        }

        else{
            new_head->next = head;
            head = new_head;
        }

        size++;
    }

    void pushBack(ll x){
        node *new_tail = new node(x);

        if(tail == NULL){
            head = tail = new_tail;
        }

        else{
            tail->next = new_tail;
            tail = new_tail;
        }

        size++;
    }

    void print(node *tmp){
        //node *tmp = head;

        while(tmp){
            cout << tmp->data << ' ';
            tmp = tmp->next;
        }
    }

    bool isPalindrome(){
        node *tmp = head;

        stack<ll> st;

        while(tmp){
            st.push(tmp->data);
            tmp = tmp->next;
        }

        node *tmp1 = head;

        while(tmp1){
            //cout << st.top() << ' ';
            if(st.top() != tmp1->data)
                return false;
            st.pop();
            tmp1 = tmp1->next;
        }

        return true;
    }

    bool CycleDetection(node *tmp){
        unordered_set<node*>m;

        while(tmp){
            if(m.find(tmp) != m.end())
                return true;

            m.insert(tmp);
            tmp = tmp->next;
        }
        return false;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    fio;
    file_i_o();

    LL linkedList;

    for(ll i=1; i<=5; i++)
        linkedList.pushBack(i);

    linkedList.head->next->next->next->next = linkedList.head;
    cout << linkedList.CycleDetection(linkedList.head);
    
    return 0;
}
