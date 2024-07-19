#include<iostream>
#include<vector>
using namespace std;
struct pack {vector <int> vec; long long num=0;};
vector<int> check(vector<int>nums, int k);
pack check_vec(vector<int> vec, int start);
pack combine(vector<int> a, vector<int> b);
pack process(vector<int>a, vector<int>b, int k);

pack final;

int main(){
    //input format (输入格式)
        //size first array（a数组大小）, size second array （b数组大小）, k for length of the desired number（k）,
        //first array（a数组）, second array（b数组）
    int an, bn, c, k;
    vector<int>a, b;
    cin>>an>>bn>>k;
    for (int i=0; i<an; i++) cin>>c, a.push_back(c);
    for (int i=0; i<bn; i++) cin>>c, b.push_back(c);
    cout<<endl;
    cout<<process(a, b, k).num;
    return 0;
}

pack process(vector<int>a, vector<int>b, int k){
        cout<<"2";
        int i=-1;
        pack cur_max;
        while(i<=k){
            i++;
            if (i>a.size() || k-i>b.size()) continue;
            pack temp=combine(check(a, i), check(b, k-i));
            if(temp.num>cur_max.num) cur_max=temp;
        }
        return cur_max;
}

bool cmp(vector<int> a, vector<int> b, int i, int j){
    int as=a.size(), bs=b.size();
    //check whether to push_back a[i] or b[j], if a[i] larger, return true, vise versa
    if(j>=bs || (a[i]>b[j])) return true;
    if (i>=as || (a[i]<b[j])) return false;
    //meaning a[i]==b[j]
    while(a[i]==b[j] && i<as && j<bs) i++, j++;
    if((i<as && j<bs)) return cmp(a, b, i, j);
    if(i==as) return false;
    return true;

}

pack combine(vector<int> a, vector<int> b){
    pack temp;
    if(a.size()==0) temp.vec=b;
    else if (b.size()==0) temp.vec==a;
    else {
        int i=0, j=0;
        for (int z=0; z<a.size()+b.size(); z++){
            if (cmp(a, b, i, j)==true){
                temp.vec.push_back(a[i]), i++;
            } else {
                temp.vec.push_back(b[j]), j++;
            }
        }
    }

    //--------
    for (auto d : temp.vec) temp.num = temp.num * 10 + d;
    return temp;
}

vector<int> check(vector<int>nums, int k) {
    pack sol;
    if (k==0) return sol.vec;
    for (int i=0; i<k; i++) sol.vec.push_back(nums[i]);
    int last_changed=1;
    for (int i=k; i<nums.size(); i++) {
        sol.vec.push_back(nums[i]);
        pack temp=check_vec(sol.vec,last_changed);
        sol.vec=temp.vec;
        last_changed=temp.num;
    }
    for (auto d: sol.vec) sol.num = sol.num*10+d;
    return sol.vec;
}

pack check_vec(vector<int> vec, int start){//从头=从
    pack temp;
    if (start<=0) start=1;
    for (int i=start; i<vec.size(); i++){
        if (vec[i-1]<vec[i]){
            vec.erase(vec.begin()+i-1);
            temp.num= (i-1);
            break;
        } else if (i==vec.size()-1) {
            vec.erase(vec.end()-1);
            temp.num=vec.size();
            break;
        }
    }
    temp.vec=vec;
    return temp;
}