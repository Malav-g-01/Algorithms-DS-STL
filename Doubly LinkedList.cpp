// By Malav Gajjar
#include<bits/stdc++.h>
//#include<ext/pd_ds/assoc_container.hpp>
//#include<ext/pd_ds/tree_policy.hpp>
//#include<ext/pd_ds/trie_policy.hpp>
using namespace std;

#define fio             ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll              long long int 
#define ld              long double
#define mod             1000000009
#define inf             1e18
#define endl            "\n"
#define pb              push_back
#define vi              vector<ll>
#define vs              vector<string>
#define pii             pair<ll, ll>
#define ump             unordered_map
#define mp              make_pair
#define pq_max          priority_pueue<ll>
#define pq_min          priority_pueue<ll, vi, greater<ll> >
#define all(v)          v.begin(), v.end()
#define ff              first
#define ss              second
#define rs              resize
#define ub              upper_bound
#define lb              lower_bound
#define mid(l, r)       (l + (r-l)/2)
#define bitc(x)         __builtin_popcount(x)
#define sp(a)           setprecision(a)
#define loop(a, b, c)       for(ll i=(a); i<=(b); i+=c)
#define loop_r(a, b, c) for(ll i=(a); i>=(b); i-=c)
#define itr(c)          for(auto it=c.begin(); it!=c.end(); it++)
#define log(x)          cout << #x << ' ' << x;
#define out(arr, a, b)  for(ll i=(a); i<=(b); i++)  cout << arr[i] << ' ';  cout << '\n';
#define MAX(a, b, c) max(a, max(b, c))

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
public:

    ll data;
    node *next, *prev;

    node(ll d){
        this->data = d;
        this->next = NULL;
        this->prev = NULL;
    }   
};

class linkedList
{
public:

    node *head, *tail;
    ll size;

    linkedList()    
    {
        head = tail = NULL;
        size=0;
    }

    void pushFront(ll d)
    {
        node *new_head = new node(d);

        if(head == NULL)
            head = tail = new_head;

        else{
            new_head->next = head;
            head->prev = new_head;
            head = new_head;
        }

        size++;
    }

    void pushBack(ll d)
    {
        node *new_node = new node(d);

        if(head == NULL)
            head = tail = new_node;

        else{
            tail->next = new_node;
            new_node->prev = tail;
            tail = new_node;
        }

        size++;
    }

    void getsize()
    {
        cout << size << '\n';
    }

    void print()
    {
        node *tmp = head;

        while(tmp != NULL){
            cout << tmp->data << ' ';
            tmp = tmp->next;
        }

        cout << '\n';
    }

    void insertNode(node *cur, ll d)
    {
        node *new_node = new node(d);

        new_node->next = cur->next;
        new_node->prev = cur;
        cur->next = new_node;

        if(new_node->next)
            new_node->next->prev = new_node;

        else
            tail = new_node;

        size++;
    }

    void insertPos(ll pos, ll n)
    {
        if(pos > size || pos < 0){
            cout << "Insertion is not possible !!\n";
            return;
        }

        if(pos == 0)
            pushFront(n);

        else if(pos == size)
            pushBack(n);

        else{
            node *tmp = head;
            node *new_node = new node(n);

            for(ll i=0; i<pos-1; i++){
                tmp = tmp->next;
            }

            new_node->next = tmp->next;
            new_node->prev = tmp;
            tmp->next = new_node;
            size++;
        }
    }

    void print_kth(ll pos)
    {
        if(pos>=size || pos<0){
            cout << "Out of bound index !!\n";
            return;
        }

        node *tmp = head;

        for(ll i=1; i<=pos; i++)
            tmp = tmp->next;

        cout << tmp->data << '\n';
    }

    void deleteFront()
    {
        if(!head){
            cout << "Deletion is not possible !!\n";
            return;
        }

        if(!(head->next)){
            delete head;
            head = tail = NULL;
        }

        else{
            node *new_node = head->next;
            new_node->prev = NULL;
            delete head;
            head = new_node;
        }
        size--;
    }

    void deleteBack()
    {

        if(!tail){
            cout << "Deletion is not possible !!\n";
            return;
        }

        node *tmp = head;

        if(head == tail){
            delete head;
            head = tail = NULL;
        }

        else{
            node *new_node = tail->prev;
            new_node->next = NULL;
            delete tail;
            tail = new_node;
        }
        size--;
    }

    void deleteKth(ll pos)
    {
        if(pos>=size || pos < 0){
            cout << "Deletion is not possible !!\n";
            return;
        }

        if(pos == 0)
            deleteFront();

        else if(pos == size-1)
            deleteBack();

        else{
            node *tmp = head;

            for(ll i=0; i<pos-1; i++)
                tmp = tmp->next;

            node *t = tmp->next;
            tmp->next = t->next;
            delete t;
        }
    }

    void deleteNode(node *cur)
    {
        if(cur == head)
            deleteFront();

        else if(cur == tail)
            deleteBack();

        else{
            cur->prev->next = cur->next;
            cur->next->prev = cur->prev;
            delete cur;
            size--;
        }
    }
};

int main(int argc, char const *argv[])
{
    fio;
    file_i_o();
    /* code */

    linkedList l;

    loop(1, 5, 1)
        l.pushBack(i);

    l.print();
    l.getsize();

    /*l.insertPos(0, 1);
    l.print();
    l.getsize();*/
    
    /*l.deleteFront();
    l.print();

    l.deleteBack();
    l.print();*/

    l.deleteKth(2);
    l.print();

    return 0;
}
