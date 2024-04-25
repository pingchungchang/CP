#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	int n;
	cin>>n;
	vector<int> ev,od;
	int arr[n];
	for(int i= 0;i<n;i++){
		cin>>arr[i];
		if(arr[i]&1)od.push_back(i);
		else ev.push_back(i);
	}
	if(!ev.empty()){
		cout<<"1\n"<<ev[0]+1<<'\n';
		return;
	}
	if(od.size()>=2){
		cout<<"2\n"<<od[0]+1<<' '<<od[1]+1<<'\n';
		return;
	}
	cout<<"-1\n";
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
