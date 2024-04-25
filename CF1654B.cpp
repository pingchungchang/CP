#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
void solve(){
	string s;
	cin>>s;
	int arr[26] = {};
	for(auto i:s)arr[i-'a']++;
	queue<char> q;
	for(auto i:s)q.push(i);
	while(arr[q.front()-'a'] != 1){
		arr[q.front()-'a']--;
		q.pop();
	}
	while(!q.empty()){
		cout<<q.front();
		q.pop();
	}
	cout<<'\n';
	return;
}
int main(){
	io
	int t;
	cin>>t;
	for(int i = 0;i<t;i++)solve();
}

