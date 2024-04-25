#include <bits/stdc++.h>
using namespace std;

vector<int> w;
vector<int> p;
bool f(int k){
	int p1 = 0;
	int pref = 0;
	for(int i = 0;i<w.size();i++){
		if(w[i]<k){
			pref = 0;
		}
		else{
			pref++;
		}
		if(pref >=p[p1]){
			pref -= p[p1];
			p1++;
		}
		if(p1 == p.size())return true;
	}
	return false;
}
int main(){
	int n,k;
	cin>>n>>k;
	w = vector<int>(n);
	p = vector<int>(k);
	vector<int> all;
	for(int i = 0;i<n;i++){
		cin>>w[i];
		all.push_back(w[i]);
	}
	for(int i = 0;i<k;i++){
		cin>>p[i];
	}
	sort(all.begin(),all.end());
	all.erase(unique(all.begin(),all.end()),all.end());
	int l = 0,r = all.size()-1;
	while(l != r){
		if(r == l+1){
			if(f(all[r]) == true){
				cout<<all[r];
			}
			else cout<<all[l];
			return 0;
		}
		int mid = (l+r)/2;
		if(f(all[mid]) == true){
			l = mid;
		}
		else r = mid-1;
	}
	cout<<all[l];
}
