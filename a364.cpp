#include <iostream>

using namespace std;

int main(){
    int n;
    cin>>n;
    for(int i  =0;i<n;i++){
        int k;
        cin>>k;
        int a = 2;
        int b = 1;
        int c = 0;
        while(a*(a-1)*(a-2)/6+(a-2)*(a-1)/2+a-2<k){
            a++;
        }
        k -= a*(a-1)*(a-2)/6;
        while(b*(b-1)/2+b-1 <k){
            b++;
        }
        k -= b*(b-1)/2;
        c = k;
        cout<<a<<b<<c<<endl;
    }
}
