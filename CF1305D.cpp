#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 1010;
set<int> tree[mxn];

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	for(int i = 1;i<n;i++){
		int a,b;
		cin>>a>>b;
		tree[a].insert(b);
		tree[b].insert(a);
	}
	set<int> st;
	for(int i = 1;i<=n;i++)st.insert(i);
	while(st.size()>1){
		vector<int> v;
		for(auto &i:st){
			if(tree[i].size() == 1)v.push_back(i);
		}
		cout<<"? "<<v[0]<<' '<<v[1]<<endl;
		int re;
		cin>>re;
		if(re == v[0]){
			cout<<"! "<<v[0]<<endl;
			return 0;
		}
		else if(re == v[1]){
			cout<<"! "<<v[1]<<endl;
			return 0;
		}
		st.erase(v[0]);
		st.erase(v[1]);
		for(auto &i:st){
			if(tree[i].find(v[0]) != tree[i].end())tree[i].erase(v[0]);
			if(tree[i].find(v[1]) != tree[i].end())tree[i].erase(v[1]);
		}
	}
	cout<<"! "<<*st.begin()<<endl;
	return 0;
}
