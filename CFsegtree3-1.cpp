#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double

vector<int> bit;
int n;
void modify(int p,int val){
	for(;p<=n;p += p&-p){
		bit[p] += val;
	}
	return;
}
int getval(int p){
	int re = 0;
	for(;p>0;p -= p&-p)re += bit[p];
	return re;
}
int main(){
	cin>>n;
	bit = vector<int>(n+1,0);
	vector<int> v(n+1);
	for(int i = 1;i<=n;i++)modify(i,1);
	for(int i = 1;i<=n;i++)cin>>v[i];
	for(int i = n;i>0;i--){
		modify(v[i],-1);
		v[i] = getval(n)-getval(v[i]);
	}
	for(int i = 1;i<=n;i++)cout<<v[i]<<' ';
}

