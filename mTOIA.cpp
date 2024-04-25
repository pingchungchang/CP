#include <bits/stdc++.h>
using namespace std;

string s;
int n;
vector<pair<int,int>> v;
bool f(int now){
	s = "";
	for(int i = n-1;i>=0;i--){
		if((now&(1<<i))==0){
			s += '<';
		}
		else s += '>';
	}
	bool used[n] = {};
	for(int i = 0;i<n;i++){
		if(s[i] == '<'){
			if(used[v[i].second])return false;
			used[v[i].second] = true;
		}
		else{
			if(used[v[i].first])return false;
			used[v[i].first] = true;
		}
	}
	return true;
}
void solve(){
	cin>>n;
	v = vector<pair<int,int>>(n);
	for(int i=0;i<n;i++){
		cin>>v[i].first>>v[i].second;
		v[i].first--;
		v[i].second--;
	}
	for(int i = 0;i<(1<<n);i++){
		if(f(i)){
			cout<<s<<'\n';
			return;
		}
	}
	cout<<"Impossible\n";
	return;
}
int main(){
	int t;
	cin>>t;
	for(int i = 0;i<t;i++)solve();
}
