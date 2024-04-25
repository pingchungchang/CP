#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int k;
	cin>>k;
	int arr[2][3];
	int s = 18;
	arr[0][0] = 1<<s;
	arr[0][0]--;
	arr[0][1] = arr[1][1] = arr[1][2] = k;
	arr[1][0] = arr[0][2] = 1<<(s-1);
	arr[1][1]|=1<<(s-1);
	cout<<2<<' '<<3<<'\n';
	for(auto &i:arr){
		for(auto &j:i)cout<<j<<' ';cout<<'\n';
	}
	return 0;
}
