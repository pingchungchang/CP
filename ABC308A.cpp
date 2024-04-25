#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int arr[8];
	for(auto &i:arr)cin>>i;
	for(int i = 1;i<8;i++){
		if(arr[i]<arr[i-1]){
			cout<<"No";
			return 0;
		}
	}
	for(int i = 0;i<8;i++){
		if(arr[i]%25 != 0){
			cout<<"No\n";
			return 0;
		}
		if(arr[i]>675||arr[i]<100){
			cout<<"No\n";
			return 0;
		}
	}
	cout<<"Yes\n";
	return 0;

}
