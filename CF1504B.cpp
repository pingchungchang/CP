#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double

void solve(){
	int n;
	cin>>n;
	string a,b;
	cin>>a>>b;
	vector<int> v(n,0);
	for(int i = 0;i<n;i++){
		if(a[i] != b[i])v[i] = 1;
		else v[i] = 0;
	}
	vector<int> flip;
	int cnt = 0;
	for(int i = 0;i<n;i++){
		if(a[i] == '1')cnt++;
		else cnt--;
		if(cnt == 0)flip.push_back(i);
	}
	int times = 0;
	int p = flip.size();
	p--;
//	cout<<p<<' ';return;
	if(p<0&&a != b){
		cout<<"NO\n";
		return;
	}
	for(int i= n-1;i>=0;i--){
		while(p>0&&flip[p]>i)p--;
		if((times+v[i])%2 == 1){
			if(flip[p] == i)times++;
			else{
				cout<<"NO\n";
				return;
			}
		}
	}
	cout<<"YES\n";
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

