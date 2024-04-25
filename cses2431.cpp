#include <bits/stdc++.h>
using namespace std;
#define ll long long


ll rec(ll now,ll len,ll k){
	if(len*(now*9)<k){
		return rec(now*10,len+1,k-len*now*9);
	}
//	cout<<now<<' '<<k<<'\n'<<'\n';
	ll j = k/len;
	now += j-1;
	if(k%len != 0)now++;
	j = k%len;
	if(j == 0)j=len;
	string s = to_string(now);
	return (s[j-1]-'0');
}
void solve(){
	ll k;
	cin>>k;
	cout<<rec(1,1,k)<<'\n';
}

int main(){
	ll t;
	cin>>t;
	for(ll i =0;i<t;i++){
		solve();
	}
}



//12345678910111213141516171819202122232425
