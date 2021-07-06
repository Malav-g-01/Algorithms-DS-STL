/* 	
	ENJOY CP !!!!!
	Author :- Malav Gajjar
*/
#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/trie_policy.hpp>
//using namespace __gnu_pbds;
using namespace std;
#define ll 				long long int
#define ld				long double
#define mod             1000000007
#define inf             1e18
#define endl			"\n"
#define pb 				push_back
#define vi              vector<ll>
#define vs				vector<string>
#define pii             pair<ll,ll>
#define ump				unordered_map
#define mp 				make_pair
#define pq_max          priority_queue<ll>
#define pq_min          priority_queue<ll,vi,greater<ll> >
#define all(n) 			n.begin(),n.end()
#define ff 				first
#define ss 				second
#define mid(l,r)        (l+(r-l)/2)
#define bitc(n) 		__builtin_popcount(n)
#define loop(i,a,b) 	for(int i=(a);i<=(b);i++)
#define looprev(i,a,b) 	for(int i=(a);i>=(b);i--)
#define iter(container, it) for(__typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define log(args...) 	{ string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define logarr(arr,a,b)	for(int z=(a);z<=(b);z++) cout<<(arr[z])<<" ";cout<<endl;	
template <typename T> T gcd(T a, T b){if(a%b) return gcd(b,a%b);return b;}
template <typename T> T lcm(T a, T b){return (a*(b/gcd(a,b)));}
vs tokenizer(string str,char ch) {std::istringstream var((str)); vs v; string t; while(getline((var), t, (ch))) {v.pb(t);} return v;}


void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cout << *it << " = " << a << endl;
	err(++it, args...);
}
//typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
//typedef trie<string,null_type,trie_string_access_traits<>,pat_trie_tag,trie_prefix_search_node_update> pbtrie;

void file_i_o()
{
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);
	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
}

struct node
{
	ll val;
	node *next;

	node(ll x){
		val = x;
		next = NULL;
	}
};

class linkedList
{
public:

	node *head;
	ll size, cap;

	linkedList(ll x){
		head = NULL;
		size = 0;
		cap = x;
	}
	//~linkedList();

	void insertAtTail(ll x){

		if(size == cap){
			cout << "Linked list is full !!\n";
			return;
		}

		size++;
		node *n = new node(x);

		if(!head){
			head = n;
			return;
		}

		node *tmp = head;

		while(tmp->next)
			tmp = tmp->next;

		tmp->next = n;
	}

	void insertAtHead(ll x){

		if(size == cap){
			cout << "Linked list is full !!\n";
			return;
		}

		node *n = new node(x);
		size++;

		if(!head){
			head = n;
			return;
		}

		n->next = head;
		head = n;
	}

	void print(){
		node *t = head;

		while(t){
			cout << t->val << ' ';
			t = t->next;
		}
		cout << '\n';
	}

	void deleteNode(ll x){
		if(head->val == x){
			node *t = head;
			head = head->next;
			free(t);
			return;
		}

		node *tmp = head;

		while(tmp->next->val != x)
			tmp = tmp->next;

		node *t = tmp->next;
		tmp->next = tmp->next->next;
		free(tmp);
	}

	ll getSize(){
		return size;
	}

	void reverse(){
		node *prevNode = NULL, *curNode = head, *nextNode = head;

		while(curNode){
			nextNode = nextNode->next;
			curNode->next = prevNode;
			prevNode = curNode;
			curNode = nextNode;
		}

		head = prevNode;
	}

	node* recursiveReverse(node* t){

		if(!t or t->next == NULL)
			return t;

		node *newHead = recursiveReverse(t->next);
		t->next->next = t;
		t->next = NULL;

		return newHead;
	}
};

int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....

	ll n;
	cin >> n;

	linkedList x(n);
	
	for(ll i=0; i<5; i++)
		x.insertAtTail(i);

	x.print();
	x.reverse();
	x.print();
	x.head = x.recursiveReverse(x.head);
	x.print();

	#ifndef ONLINE_JUDGE 
	  clock_t end = clock();
	  cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
	#endif 
	return 0;
}
