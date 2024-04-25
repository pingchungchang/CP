#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const int mxn = 2e5+10;
ll bit[mxn];
int val[mxn];
deque<int> dq;
int arr[mxn];
pii range[mxn];

void modify(int p,int v){
	for(;p<mxn;p+=p&-p)bit[p] += v;
}
ll getval(int s,int e){
	ll re = 0;
	for(;e>0;e-= e&-e)re += bit[e];
	s--;
	for(;s>0;s-= s&-s)re -= bit[s];
	return re;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,q;
	cin>>n>>q;
	for(int i = 1;i<=n;i++)cin>>arr[i];
	for(int i = 1;i<=n;i++)cin>>val[i];
	arr[0] = arr[n+1] = 1e9+10;
	dq.push_back(0);
	for(int i = 1;i<=n;i++){
		while(!dq.empty()&&arr[dq.back()]<=arr[i])dq.pop_back();
		range[i].fs = dq.back()+1;
		dq.push_back(i);
	}
	dq = {n+1};
	for(int i = n;i>=1;i--){
		while(!dq.empty()&&arr[dq.back()]<=arr[i])dq.pop_back();
		range[i].sc = dq.back()-1;
		dq.push_back(i);
	}
	for(int i = 1;i<=n;i++)modify(i,val[i]);
	while(q--){
		int tp;
		cin>>tp;
		if(tp == 2){
			int pos;
			cin>>pos;
			cout<<getval(range[pos].fs,range[pos].sc)<<'\n';
		}
		else{
			int p,v;
			cin>>p>>v;
			modify(p,v-val[p]);
			val[p] = v;
		}
	}
	return 0;
}
