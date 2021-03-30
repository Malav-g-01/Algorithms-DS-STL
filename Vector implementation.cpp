#include<bits/stdc++.h>
#define fio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long

using namespace std;

class vec
{
	int *a;
	int size, cap;
	
	public :
		vec()
		{
			a = NULL;
			size=0;
			cap = 0;
		}
		
		void push_back(int n)
		{
			if(size < cap)
			{
				a[size] = n;
				size++;
			}
			
			else
			{
				int *b;
				
				if(cap)
					b = new int[2*cap], cap *= 2;
				
				else
					b = new int[1], cap = 1;
				
				for(int i=0; i<size; i++)
					b[i] = a[i];
				
				delete[] a;
				
				a = b;
				a[size] = n;
				size++;
			}
		}
		
		int sz()
		{
			return size;
		}
		
		int capacity()
		{
			return cap;
		}
		
		int & back()
		{
			return a[size-1];
		}
		
		int operator [](int i)
		{
			if(i>=0 && i<size)
				return a[i];
			
			else
				return -1;
		}
		
		void pop()
		{
			if(size)
				size--;
		}
		
		void print()
		{
			for(int i=0; i<size; i++)
				cout << a[i] << " ";
		}
};

int main()
{
	fio;
	
	vec v;
	
	for(int i=1; i<=10; i++)
		v.push_back(i);
		
	v.print();
	cout << "\n";
	
	cout << v.sz() << " " << v.capacity() << "\n";
	v.pop();
	v.print();
	
}
