#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const int mxn = 3e5+10;
pll arr[mxn];
ll ans,tar,n;
priority_queue<tlll,vector<tlll>,greater<tlll>> pq;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>tar;
	for(int i = 0;i<n;i++){
		cin>>arr[i].fs>>arr[i].sc;
	}
}
