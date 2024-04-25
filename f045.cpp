#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main(){
	string s;
	cin>>s;
	priority_queue<int,vector<int>,less<int>> pq;
	for(auto i:s){
		pq.push(i-'0');
	}
	int a= pq.top();
	pq.pop();
	int b= pq.top();
	pq.pop();
	int total = a*a+b*b;
	if(total == stoi(s.substr(s.size()-3,3)))cout<<"Good Morning!";
	else cout<<"SPY!";
}

