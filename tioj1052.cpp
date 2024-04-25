#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


void solve(){
	string s;
	ll line = 0,word = 0,ch = 0;
	while(getline(cin,s)){
		if(s == "=====")break;
		ch += s.size();
		for(auto &i:s){
			if(i == '\t')i = ' ';
		}
		stringstream ss(s);
		while(ss>>s)word++;
		line++;
	}
	cout<<line<<' '<<word<<' '<<ch<<'\n';
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	string ss;
	getline(cin,ss);
	int t = stoi(ss);
	while(t--)solve();
}
