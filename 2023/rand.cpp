#include <utility>
#include <cmath>
#include <random>
#include <iostream>
using namespace std;

int main(){
    int total=0, n;
    std::random_device rd;
    mt19937_64 eng(rd());
    uniform_int_distribution<unsigned long long> distr(1,6);
    cin>>n;
    for (int i=0; i<n; ++i){
        int sum=0;
        for (int j=0; j<7; ++j) sum+=distr(eng);
        if(sum%3==0) ++total;
    }
    double prob = total;
    prob=prob/n;
    cout<<'\n'<<prob<<'\n';
    return 0;

}