#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	int arr[n];
	for(auto &i:arr)cin>>i;
	int small = arr[0]-1;
	cout<<arr[0]-1<<'\n';
	for(int i = 1;i<n;i++){
		if(arr[i]-i-1>small){
			small = arr[i]-i-1;
			cout<<arr[i]-i-1<<'\n';
		}
		else{
			cout<<small+1<<'\n';
			small++;
		}
	}
	return 0;
}
