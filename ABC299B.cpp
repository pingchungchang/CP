#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define fs first
#define sc second

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	int t;
	cin>>t;
	pii arr[n];
	bool flag = false;
	for(auto &i:arr){
		cin>>i.fs;
	}
	for(auto &i:arr)cin>>i.sc;
	for(auto &i:arr)if(i.fs == t)flag =true;
	pii ans = {0,0};
	if(flag){
		for(int i = 0;i<n;i++){
			if(arr[i].fs == t)ans = max(ans,make_pair(arr[i].sc,i));
		}
	}
	else{
		ans = {arr[0].sc,0};
		for(int i = 0;i<n;i++){
			if(arr[i].fs == arr[0].fs)ans = max(ans,make_pair(arr[i].sc,i));
		}
	}
	cout<<ans.sc+1;
}
