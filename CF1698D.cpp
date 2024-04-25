#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double

bool f(int s,int e){
	cout<<"? "<<s<<' '<<e<<endl;
	int cnt = 0;
	for(int i = s;i<=e;i++){
		int k;
		cin>>k;
		if(k>=s&&k<=e)cnt++;
	}
	if(cnt%2 != 0)return true;
	else return false;
}
void solve(){
	int n;
	cin>>n;
	int l = 1,r = n;
	while(r-l>1){
		int mid = (l+r)/2;
		if(f(l,mid)){
			r = mid;
		}
		else l = mid;
	}
	if(f(l,l))cout<<"! "<<l<<endl;
	else cout<<"! "<<r<<endl;
	return;
}
int main(){
	int t;
	cin>>t;
	while(t--)solve();
}

