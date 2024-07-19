





#include <iostream>
#include <cmath>
using namespace std;

int main(){
    long long n, tc, tm;
    cin>>n>>tc>>tm;
    long long max=0;
    for (int i=0; i<n; ++i) {
        long long a, b, c;
        cin>>a>>b>>c;
        double temp=((a-b)-(c-((b)*(tc+tm))))/b;
        long long w=ceil(temp);
        cout<<w<<'\n';
        if (w>max) max=w;
    }
    cout<<max<<'\n';
}
