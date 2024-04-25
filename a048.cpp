#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
#define _all(T) T.begin(),T.end()
const int mxn = 2e5+10;
int bit[mxn];
void modify(int p,int v){
	for(;p<mxn;p += p&-p)bit[p] += v;
	return;
}
int getval(int s,int e){
	int re = 0;
	for(;e>0;e-= e&-e)re += bit[e];
	s--;
	for(;s>0;s -= s&-s)re-= bit[s];
	return re;
}
int main(){
	io
	int n,q;
	cin>>n>>q;
	int arr[mxn] = {};
	while(q--){
		int t;
		cin>>t;
		if(t == 1){
			int p;
			cin>>p;
			if(arr[p]){
				arr[p] = 0;
				modify(p,-1);
			}
			else{
				arr[p] = 1;
				modify(p,1);
			}
		}
		else{
			int s,e;
			cin>>s>>e;
			int total = getval(s,e);
			if(total&1){
				cout<<"1\n";
			}
			else cout<<"0\n";
		}
	}
	return 0;
}

