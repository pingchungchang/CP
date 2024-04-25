#include <bits/stdc++.h>
using namespace std;

int ask(int x,int y){
	cout<<"? "<<x<<' '<<y<<endl;
	int re;
	cin>>re;
	return re;
}

void solve(){
	int n,m;
	cin>>n>>m;
	int l1 = ask(1,1);
	int l2 = ask(n,m);
	if(l1 + l2 == n-1){
		int d = ask(l1+1,1);
		cout<<"! "<<l1+1<<' '<<d+1<<endl;
		return;
	}
	else if(l1 + l2 == m-1){
		int d = ask(1,l1+1);
		cout<<"! "<<d+1<<' '<<l1+1<<endl;
		return;
	}
	set<pair<int,int>> v;
	v.insert(make_pair(l1+1,m-l2));
	v.insert(make_pair(n-l2,l1+1));
	vector<pair<int,int>> inc;
	for(auto &i:v){
		if(i.first>n||i.first<1||i.second>m||i.second<1)inc.push_back(i);
	}
	for(auto &i:inc)v.erase(i);
	assert(!v.empty());
	int d = ask(v.begin()->first,v.begin()->second);
	if(d == 0)cout<<"! "<<(v.begin()->first)<<' '<<v.begin()->second<<endl;
	else cout<<"! "<<(v.rbegin()->first)<<' '<<v.rbegin()->second<<endl;
	return;
}

int main(){
	int t;
	cin>>t;
	while(t--)solve();
}
