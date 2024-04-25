#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin>>n;
	int a[n];
	for(auto &i:a)cin>>i;
	int pref = 0,suf =0;
	for(int i =0;i<n;i++){
		if(a[i]<0)suf++;
	}
	bool inc[n] = {},dec[n] = {};
	dec[0] = true;
	for(int i = 1;i<n;i++){
		dec[i] = dec[i-1];
		if(abs(a[i])>abs(a[i-1]))dec[i] = false;
	}
	inc[n-1] = true;
	for(int i = n-2;i>=0;i--){
		inc[i] = inc[i+1];
		if(abs(a[i])>abs(a[i+1]))inc[i] = false;
	}
	if(inc[0]&&suf == pref){
		cout<<"YES\n";
		return;
	}
	for(int i = 0;i<n-1;i++){
		if(a[i]<0)suf--;
		else if(a[i]>0)pref++;
		if(inc[i+1]&&dec[i]&&pref == suf){
			cout<<"YES\n";
			return;
		}
	}
	if(a[n-1]<0)suf--;
	else if(a[n-1]>0)pref++;
	if(dec[n-1]&&pref == 0)cout<<"YES\n";
	else cout<<"NO\n";
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
}
