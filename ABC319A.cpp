#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	pair<string,int> p[] = {
		{"tourist", 3858},
		{"ksun48", 3679},
		{"Benq", 3658},
		{"Um_nik", 3648},
		{"apiad", 3638},
		{"Stonefeang", 3630},
		{"ecnerwala", 3613},
		{"mnbvmar", 3555},
		{"newbiedmy",3516},
		{"semiexp",3481}
	};
	string s;
	cin>>s;
	for(auto &i:p){
		if(i.fs == s)cout<<i.sc;
	}
}
