#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n;
	cin>>n;
	ll arr[n];
	for(auto &i:arr)cin>>i;
	if(n == 1){
		cout<<"1 1\n0\n1 1\n0\n1 1\n"<<-arr[0]<<'\n';
		return 0;
	}
	cout<<"1 "<<n<<'\n';
	for(auto &i:arr){
		cout<<-n*(i%(n-1))<<' ';
		i -= n*(i%(n-1));
	}
	cout<<'\n';
	cout<<"1 "<<n-1<<'\n';
	for(int i = 0;i<n-1;i++){
		cout<<-arr[i]<<' ';
	}
	cout<<'\n';
	cout<<n<<' '<<n<<'\n';
	cout<<-arr[n-1];
}
