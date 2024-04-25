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
int main(){
	io
	string s;
	int k;
	cin>>s>>k;
	vector<string> all;
	bool flag = false;
	for(int len = 1;len<=min(5,(int)s.size());len++){
		for(int i = 0;i<s.size()+1-len;i++){
			all.push_back(s.substr(i,len));
		}
	}
	sort(_all(all));
	all.erase(unique(_all(all)),all.end());
//	for(auto &i:all)cout<<i<<' ';cout<<endl;
	cout<<all[k-1];
}

