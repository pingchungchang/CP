#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

bool check(int k){
	string s = to_string(k);
	int re= 0;
	for(auto &i:s){
		if(re&(1<<(i-'0'))){
			return false;
		}
		re|=(1<<(i-'0'));
	}
	return true;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int l,r;
	cin>>l>>r;
	for(int i = l;i<=r;i++){
		if(check(i)){
			cout<<i;
			return 0;
		}
	}
	cout<<-1;
	return 0;
}
