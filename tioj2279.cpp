#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
#define _all(T) T.begin(),T.end()
const int mxn = 1e9;
int* arr;
#define SIZE (50*1024*1024) // 50 MiB
char *c,*d;
char a[SIZE]
int x;
int main(){
	int n;
	cin>>n;
	if(n != 8)cout<<n<<endl;
	if(n == 0)return 0;
	else if(n == 1){
		cout<<"asdf";
		return 0;
	}
	else if(n == 2){
		while(1);
	}
	else if(n == 3){
		c = new char[SIZE];
		d = (char*)calloc(SIZE, 1);
		// reading bss section won't load pages into physical memory
		// reading data section, however, will load pages into physical memory; thus if you change a[i] to b.x[i], this will add 50 MiB to RSS
		for (int i = 0; i < SIZE; i++) x += a[i];
		// memset is aware of newly-allocated pages and avoids writing into them
		// if you change d to c or just swap Line 23/24, this will add 50 MiB to RSS
		memset(d, 0, SIZE);
		return 0;
	}
	else if(n == 4){
		arr = new int[mxn];
		fill(arr,arr+mxn,99);
		int k = 0;
		for(int i = 0;i<mxn;i++)k += arr[i];
		return 0;	
	}
	else if(n == 5){
		while(1)cout<<" ";
	}
	else if(n == 6){
		int arr[1000] = {};
		return 99;
	}
	else if(n == 7){
		arr = new int(mxn);
		cout<<arr[mxn-1];
		return 0;
	}
	else if(n == 8){
		char cc[1024*1024*24];
		for(auto &i:cc)i = 'X';
		return 0;
	}
	else if(n == 9){
		sleep(1);
		return 0;
	}
}

