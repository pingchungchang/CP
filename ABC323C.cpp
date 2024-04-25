#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>



int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
	int arr[m];
	for(auto &i:arr)cin>>i;
	int score[n] = {};
	string solved[n];
	for(int i = 0;i<n;i++){
		score[i] = i+1;
		cin>>solved[i];
		for(int j = 0;j<m;j++){
			if(solved[i][j] == 'o')score[i] += arr[j];
		}
	}
	for(int i = 0;i<n;i++){
		int big = 0;
		priority_queue<int,vector<int>,less<int>> pq;
		for(int j = 0;j<n;j++){
			if(i == j)continue;
			big = max(big,score[j]);
		}
		for(int j = 0;j<m;j++){
			if(solved[i][j] == 'x')pq.push(arr[j]);
		}
		int now = score[i];
		int ans = 0;
		while(!pq.empty()&&now<big){
			now += pq.top();
			pq.pop();
			ans++;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
