#include <bits/stdc++.h>
using namespace std;

#define pi (3.14159265358979323846)
vector<double> sq(vector<double> &p){
	vector<double> v(2*p.size()-1);
	for(int i = 0;i<p.size();i++){
		for(int j = 0;j<p.size();j++){
			v[i+j] += (p[i]*p[j]);
		}
	}
	return v;
}
void solve(){
	int n;
	cin>>n;
	vector<double> p(n+1);
	for(int i = n;i>=0;i--)cin>>p[i];
	p = sq(p);
	double ans = 0;
	for(int i = 0;i<p.size();i++){
		p[i] = p[i]/(i+1);
	}
	double a,b;
	cin>>a>>b;
	for(int i = 0;i<p.size();i++){
		ans = ans + p[i]*(pow(b,i+1)-pow(a,i+1));
	}
	ans = ans*pi;
	cout<<fixed<<setprecision(2)<<ans<<'\n';
}
int main(){
	int t;
	cin>>t;
	for(int asd=0;asd<t;asd++){
		solve();
	}
}
