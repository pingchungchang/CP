#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin>>n;
	int a[n],b[n];
	for(auto &i:a)cin>>i;
	for(auto &i:b)cin>>i;
	for(int i = 0;i<n;i++){
		if(a[i]>b[i]){
			cout<<"NO\n";
			return;
		}
	}
	int k = *min_element(b,b+n);
	for(int i = 0;i<n;i++)a[i] = max(a[i],k);
	for(int i = 0;i<n;i++){
		if(a[i] == b[i]){
			int now = i-1;
			int pre = i;
			if(now<0)now += n;
			while(a[now] != b[now]){
				/*
				if(now == 1){
					cout<<a[now]<<' '<<b[now]<<' '<<a[pre]<<",\n";
				}
				*/
				if(b[now]<=a[pre]+1){
					a[now] = b[now];
					pre = now;
					now--;
					if(now<0)now += n;
				}
				else{
					cout<<"NO\n";
					return;
				}
			}
		}
	}
	cout<<"YES\n";
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
}
