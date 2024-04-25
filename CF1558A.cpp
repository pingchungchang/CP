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
	ll a,b;
	cin>>a>>b;
	int n = a+b;
	if(a<b)swap(a,b);
	int arr[a+b] = {};
	int na = a,nb = b;
	for(int i = 0;i<a+b;i+=2){
		arr[i] = 1;
		na--;
	}
	for(int i = 0;i<n;i++){
		if(arr[i] == 0&&na){
			na--;
			arr[i] = 1;
		}
	}
	int big = 0,small = 0;
	for(int i = 0;i<n;i++){
		if(i%2 == 0&&arr[i] == 1){
			big++;
		}
		else if(i%2 == 1&&arr[i] == 0){
			big++;
		}
		else small++;
	}
	vector<int> ans;
	int dx = ((a+b)%2==0?2:1);
	for(int i = small;i<=big;i+=dx)ans.push_back(i);
	cout<<ans.size()<<'\n';
	for(auto i:ans)cout<<i<<' ';cout<<'\n';
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

