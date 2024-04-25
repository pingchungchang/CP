#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const int mxn = 2022;

int arr[mxn*10];
string s;
int n,k;

struct node{
	int childs[3];
	int fail;
};
vector<int> dfn;
int ppp;
node trie[mxn];

int newnode(){
	return ++ppp;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>k;
	string tmp;
	for(int i = 0;i<k;i++){
		int cost;
		cin>>tmp>>cost;
	}
}
