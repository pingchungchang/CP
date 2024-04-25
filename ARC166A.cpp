#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


void solve(){
	string a,b;
	int n;
	cin>>n;
	cin>>a>>b;
	vector<int> v;
	for(int i = 0;i<n;i++){
		if(b[i] == 'C'&&a[i] != 'C'){
			cout<<"No\n";
			return;
		}
		else if(b[i] == 'C'){
			v.push_back(i);
		}
	}
	v.push_back(n);
	int pre = -1;
	for(auto &now:v){
		int pl = pre+1,pr = now-1;
		int ca = 0;
		vector<int> v1,v2;
		for(int i = pl;i<=pr;i++){
			if(a[i] == 'A')v1.push_back(i);
			if(b[i] == 'A')v2.push_back(i);
		}
		for(int i = pl;i<=pr;i++){
			if(a[i] == 'C'&&v1.size()<v2.size())v1.push_back(i);
		}
		sort(v1.begin(),v1.end());
		sort(v2.begin(),v2.end());
		if(v1.size() != v2.size()){
			cout<<"No\n";
			return;
		}
		for(int j = 0;j<v1.size();j++){
			if(v1[j]>v2[j]){
				cout<<"No\n";
				return;
			}
		}
		pre = now;
	}
	cout<<"Yes\n";
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
