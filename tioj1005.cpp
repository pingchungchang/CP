#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>
using namespace std;
int judge(int a,int b){
    if(a<b){
        int c = b;
        b = a;
        a = c;
    }
    if(a==0||b==0) return 0;
    else if(a==b&&a==1) return 1;
    else if(a%b==1) return 1;
    else return judge(b, a % b);
}

int main(){
    float N;
    cin >> N;
    while(N!=0){
        vector<int> v;
        double count=0;
        for (int i = 0; i < N;i++){
            int k;
            cin >> k;
            v.push_back(k);
        }
        for (int i = 0; i < N;i++){
            for (int j = i+1; j < N;j++){
                count += judge(v[i], v[j]);
            }
        }
        if(count == 0) cout << "No estimate for this data set.";
        else
            cout << fixed << setprecision(6) << sqrt(3 * (double)N * ((double)N - 1) / count) << endl;
        cin >> N;
    }
}