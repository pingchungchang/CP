#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

vector<int> get(int n){
	vector<int> v(n);
	for(auto &i:v)cin>>i;
	return v;
}

void solve(){
	int n;
	cin>>n;
	auto v = get(n);
	int cnt[10] = {};
	for(auto &i:v)cnt[i]++;
	cout<<"- 0"<<endl;
	v = get(n);
	int cnt2[10] = {};
	for(auto &i:v)cnt2[i]++;
	int tar = 0;
	for(int i = 1;i<10;i++){
		if(cnt[i] < cnt2[i])tar = i;
	}
	if(!tar){
		memset(cnt2,0,sizeof(cnt2));
		cout<<"- 0"<<endl;
		v = get(n);
		for(auto &i:v)cnt2[i]++;
		for(int i = 1;i<10;i++){
			if(cnt[i] < cnt2[i])tar = i;
		}
	}
	vector<int> no;
	for(int i = 0;i<n;i++){
		if(v[i] != tar)no.push_back(i+1);
	}
	cout<<"- ";cout<<no.size()<<' ';for(auto i:no)cout<<i<<' ';cout<<endl;
	n -= no.size();
	v = get(n);
	for(int i = 0;i<v.size();i++){
		if(v[i] != tar){
			cout<<"! "<<i+1<<endl;
			return;
		}
	}
	cout<<"- 0"<<endl;
	v = get(n);
	for(int i = 0;i<n;i++){
		if(v[i] != tar){
			cout<<"! "<<i+1<<endl;
			return;
		}
	}
	assert(false);
}

int main(){
	int t;cin>>t;
	while(t--)solve();
}
