#include <bits/stdc++.h>
using namespace std;

#define ld long double
#define cd complex<double>
#define PI acos(-1)

cd ei(ld theta){
	return cd(cos(theta),sin(theta));
}
vector<cd> FFT(vector<cd> f,int inv){
	int n = f.size();
	if(n == 1)return f;
	cd w = ei(inv*PI*2/n);
	vector<cd> odd,even;
	for(int i =0;i<n;i++){
		if(i&1)odd.push_back(f[i]);
		else even.push_back(f[i]);
	}
	vector<cd> ans(n);
	odd = FFT(odd,inv);even = FFT(even,inv);
	cd omega = 1;
	for(int i = 0;i<n/2;i++,omega *= w){
		ans[i] = odd[i]*omega+even[i];
		ans[i+n/2] = even[i]-omega*odd[i];
	}
	return ans;
}
cd getval(vector<cd> func,ld val){
	cd re = 0;
	cd x = 1;
	for(int i = 0;i<func.size();i++){
		re += x*func[i];
		x *= val;
	}
	return re;
}
int main(){
	vector<cd> a(1<<5,0);
	vector<cd> b(1<<5,0);
	a[0] = a[1] = b[0] = b[1] = 1;
	a = FFT(a,1),b = FFT(b,1);
	vector<cd> c;
	for(int i = 0;i<(1<<5);i++){
		c.push_back(a[i]*b[i]);
	}
	c = FFT(c,-1);
	for(int i = 0;i<(1<<5);i++)c[i] = c[i].real()/(1<<5);
	for(int i = 0;i<(1<<5);i++)cout<<fixed<<setprecision(5)<<c[i].real()<<' ';cout<<endl;
	cout<<getval(c,2).real()<<endl;
	return 0;
}

