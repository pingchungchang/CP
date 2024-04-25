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

vector<int> v;
int n;
void dfs(){
	if(v.size() == n){
//		for(int i = 0;i<n;i++)cout<<i<<' '<<v[i]<<endl;
		for(int i = 0;i<n;i++){
			for(int j = 0;j<n;j++){
				if(j == v[i])cout<<'Q';
				else cout<<'*';
			}
			cout<<'\n';
		}
		cout<<'\n';
		return;
	}
	for(int i = 0;i<n;i++){
		bool use = true;
		for(int j = 0;j<v.size();j++){
			if(abs(v[j]-i) == abs(j-(int)v.size())||i == v[j])use = false;
		}
		if(use){
			v.push_back(i);
			dfs();
			v.pop_back();
		}
	}
	return;
}
int main(){
	io
	cin>>n;
	dfs();
}

