#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
	int arr[n];
	int total = 0;
	for(auto &i:arr)cin>>i,total += i;
	int cnt = 0;
	for(auto &i:arr){
		if(i*4*m<total)continue;
		cnt++;
	}
	cout<<(cnt>=m?"Yes":"No");
	return 0;
}
