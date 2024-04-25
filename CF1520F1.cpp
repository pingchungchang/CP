#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double

int n;
int ask(int s,int e){
	cout<<"? "<<s<<' '<<e<<endl;
	int tmp;
	cin>>tmp;
	return tmp;
}
void solve(){
	int k;
	cin>>k;
	int l = 1,r = n;
	while(l != r){
		int mid = (l+r)/2;
		int total = ask(1,mid);
		if(mid-total < k)l = mid+1;
		else r = mid;
	}
	cout<<"! "<<l<<endl;
}
int main(){
	io
	int t;
	cin>>n>>t;
	while(t--)solve();
}

