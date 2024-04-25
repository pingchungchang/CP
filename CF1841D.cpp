#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define pii pair<int,int>

const int mxn = 4040;
int bit[mxn];

void modify(int p,int v){
	for(;p<mxn;p+= p&-p){
		bit[p] = max(bit[p],v);
	}
	return;
}
int getval(int p){
	int re = 0;
	for(;p>0;p-=p&-p)re = max(re,bit[p]);
	return re;
}


void solve(){
	int n;
	cin>>n;
	vector<int> all;
	pii arr[n];
	for(auto &i:arr){
		cin>>i.sc>>i.fs;
		all.push_back(i.fs);
		all.push_back(i.sc);
	}
	sort(all.begin(),all.end());
	all.resize(unique(all.begin(),all.end())-all.begin());
	sort(arr,arr+n);
	memset(bit,0,sizeof(bit));
	for(auto &i:arr){
		i.fs = lower_bound(all.begin(),all.end(),i.fs)-all.begin()+1;
		i.sc = lower_bound(all.begin(),all.end(),i.sc)-all.begin()+1;
	}
	for(int i = 0;i<n;i++){
		for(int j = i-1;j>=0;j--){
			if(arr[i].sc<=arr[j].fs){
				modify(arr[i].fs,getval(min(arr[i].sc,arr[j].sc)-1)+2);
			}
		}
	}
	cout<<n-getval(all.size())<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
