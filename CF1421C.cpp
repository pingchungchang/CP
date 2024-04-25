#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

vector<pii> ans;
bool check(string s){
	for(int i = 0;i<s.size();i++){
		if(s[i] != s[s.size()-1-i])return false;
	}
	return true;
}

string s;
void add(int dir,int len){
	if(!dir){
		ans.push_back({dir,len+1});
		string tmp;
		for(int i = 0;i<len;i++)tmp += s[1+i];
		reverse(tmp.begin(),tmp.end());
		s = tmp+s;
		return;
	}
	else{
		ans.push_back({dir,(int)s.size()-len});
		string tmp;
		for(int i = 0;i<len;i++)tmp += s[s.size()-2-i];
		s += tmp;
		return;
	}
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>s;
	if(check(s)){
		cout<<"0";
		return 0;
	}
	add(1,1);
	add(0,s.size()-2);
	add(0,1);
	cout<<ans.size()<<'\n';
	for(auto &i:ans){
		if(!i.fs)cout<<"L ";
		else cout<<"R ";
		cout<<i.sc<<'\n';
	}
	//cout<<s<<endl;
	return 0;
}
