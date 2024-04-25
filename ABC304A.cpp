#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	pair<int,string> arr[n*2];
	for(int i = 0;i<n;i++){
		cin>>arr[i].sc>>arr[i].fs;
	}
	for(int i = 0;i<n;i++)arr[i+n] =arr[i];
	pair<int,int> st = {arr[0].fs,0};
	for(int i = 0;i<n;i++){
		st = min(st,make_pair(arr[i].fs,i));
	}
	for(int i = 0;i<n;i++)cout<<arr[st.sc+i].sc<<'\n';
	return 0;
}
