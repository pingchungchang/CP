#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main(){
	string s;
	string t;
	for(int i = 0;i<3;i++){
		char c;
		cin>>c;
		s += c;
	}
	for(int i = 0;i<3;i++){
		char c;
		cin>>c;
		t += c;
	}
	int n = 0;
	for(int i = 0;i<3;i++){
		if(t[i] == s[0]){
			swap(t[i],t[0]);
			if(i != 0){
				n++;
			}
		}
	}
	if(t[1] != s[1])n++;
	if((n&1) ==0)cout<<"Yes";
	else cout<<"No";
	return 0;
}

