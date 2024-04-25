#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

string s,t;
vector<string> va,vb;
stringstream ss;
set<string> able;
set<string> ans;

void solve(){
	ans.clear();able.clear();va.clear();vb.clear();
	for(auto &i:s){
		if(i>='A'&&i<='Z')i = 'a'+(i-'A');
		if(!(i>='a'&&i<='z'))i = ' ';
	}
	ss = stringstream(s);
	while(ss>>s){
		va.push_back(s);
	}
	sort(va.begin(),va.end());
	for(int i = 1;i<va.size();i++){
		if(va[i] == va[i-1])able.insert(va[i]);
	}
	getline(cin,t);
	for(auto &i:t){
		if(i>='A'&&i<='Z')i = 'a'+(i-'A');
		if(!(i>='a'&&i<='z'))i = ' ';
	}
	ss = stringstream(t);
	while(ss>>t){
		vb.push_back(t);
	}
	sort(vb.begin(),vb.end());
	for(int i = 1;i<vb.size();i++){
		if(vb[i] == vb[i-1]&&able.find(vb[i]) != able.end())ans.insert(vb[i]);
	}
	if(ans.empty())cout<<"<NONE>\n";
	else for(auto &i:ans)cout<<i<<'\n';
	cout<<'\n';
	return;
}

int main(){
	while(getline(cin,s))solve();
}
