#include <bits/stdc++.h>

using namespace std;

void print(const std::vector<int>& v)
{
    for (int e : v) {
        std::cout << " " << e;
    }
}

int main()
{
    std::vector<int> v = {1,2,3,4,5,6,7,8};
    int a = 0, b = 0, c = 0, d=0;

    do {
        //print(v); 
        
        int q = 0;
        for(int i=1; i<7; i++){
            if (v[i-1]<v[i] && v[i]> v[i+1]) q++;
        }
        if (q==0) a++;
        else if (q==1) b++;
        else if (q==2) c++;
        else if (q==3) d++;
        else {
            print(v);
            cout<<"err "<<q<<endl;
        }
        //cout<<"  "<<q<<endl;
    } while (std::next_permutation(v.begin(), v.end()));



    cout<<a<<endl<<b<<endl<<c<<endl<<d<<endl;

}