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
	int n;
	cin>>n;
	int arr[n];
	set<int> st;
	int s = 0;
	if(n == 2){
		cout<<"Lose";
		return 0;
	}
	else if(n == 1){
		cout<<"Win";
		return 0;
	}
	else if(n == 3){
		cout<<"Win";
		return 0;
	}
	for(auto &i:arr){
		cin>>i;
		s^= i;
		st.insert(i);
	}
	if(st.find(s) != st.end())cout<<"Win";
	else if(n&1)cout<<"Win";
	else cout<<"Lose";
}
