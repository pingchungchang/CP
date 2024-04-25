#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second


void solve(){
	int h,w;
	cin>>h>>w;
	vector<string> a,b;
	for(int i = 0;i<h;i++){
		string in;
		cin>>in;
		a.push_back(in);
	}
	for(int i = 0;i<h;i++){
		a[i] += a[i];
		a.push_back(a[i]);
	}
	for(int i = 0;i<h;i++){
		string in;
		cin>>in;
		b.push_back(in);
	}
	for(int i = 0;i<h;i++){
		for(int j = 0;j<w;j++){
			bool flag = true;
			for(int k = 0;k<h;k++){
				for(int l = 0;l<w;l++){
					//cout<<i<<j<<k<<l<<endl;
					if(a[i+k][j+l] != b[k][l])flag = false;
				}
			}
			if(flag){
				cout<<"Yes\n";
				return;
			}
		}
	}
	cout<<"No\n";
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t = 1;
	while(t--)solve();
}
