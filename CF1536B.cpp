#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double

string s;
int n;
vector<string> all;
bool f(string tmp){
	int k = tmp.size();
	for(int i = 0;i<=n-k;i++){
		if(s.substr(i,k) == tmp)return false;
	}
	return true;
}
void solve(){
	cin>>n;
	cin>>s;
	for(auto &i:all){
		if(f(i)){
			cout<<i<<'\n';
			return;
		}
	}
	cout<<"ERROR\n";
	return;
}
bool cmp(string a,string b){
	if(a.size() != b.size())return a.size()<b.size();
	else return a<b;
}
int main(){
	io
	for(char c = 'a';c <= 'z';c++){
		all.push_back(string(1,c));
		for(char d = 'a';d <= 'z';d++){
			all.push_back(string(1,c)+d);
			for(char e = 'a';e <= 'z';e++){
				all.push_back(string(1,c)+string(1,d)+e);
			}
		}
	}
	sort(all.begin(),all.end(),cmp);
//	for(int i = 0;i<10;i++)cout<<all[i]<<',';
//	cout<<endl;
	int t;
	cin>>t;
	while(t--)solve();
}

