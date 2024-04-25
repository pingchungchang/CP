#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double

int n;
void modify(vector<int> &tmp,int p,int v){
	for(;p<=n;p += p&-p)tmp[p] += v;
}
int getval(vector<int> &tmp,int s,int e){
	int re = 0;
	for(;e>0;e -= e&-e)re += tmp[e];
	s--;
	for(;s>0;s -= s&-s)re -= tmp[s];
	return re;
}
int main(){
	io
	cin>>n;
	vector<int> vals(n+1,0);
	vector<int> odd(n+1,0),even(n+1,0);
	for(int i = 1;i<=n;i++){
		int k;
		cin>>k;
		vals[i] = k;
		if(i&1)modify(odd,i,k);
		else modify(even,i,k);
	}
	int q;
	cin>>q;
	while(q--){
		int t;
		cin>>t;
		if(t == 0){
			int i,j;
			cin>>i>>j;
			if(i&1){
				modify(odd,i,j-vals[i]);
			}
			else modify(even,i,j-vals[i]);
			vals[i] = j;
		}
		else{
			int l,r;
			cin>>l>>r;
			int tmp = getval(odd,l,r)-getval(even,l,r);
			if(l%2 == 0)tmp = -tmp;
			cout<<tmp<<'\n';
		}
	}
}

