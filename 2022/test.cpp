#include <iostream>
#include <utility>
#include <queue>
using namespace std;
vector<int> nums;
int k;

int longestOnes_old() {
    queue<int> w;
    int max=0, ck=0, extra=0;
    for (int i=0; i<nums.size(); ++i){
        /*
        continue push into w until hit 0; 
        then we can push 0's and ck++, UNTIL (ck==k && nums[i]==0) OR (i==nums.size())
        RECORD
        pop until we hit zero and then w.front()==1
        NEXT LOOP
        */
        cout<<"hi";
        while ((ck<k || nums[i]==1) && i<nums.size()){
            cout<<"1";
            if(nums[i]==1) w.push(nums[i++]);
            else w.push(nums[i++]), ck++;
        }
        --i;
        cout<<"size: "<<w.size()<<"; "<<nums.size()<<"; ";
        if(w.size()==nums.size()) return nums.size();
        cout<<"i: "<<i<<"; ";
        if(i==nums.size()-1 && ck<k){
            cout<<"HEY!!!";
            extra=k-ck;
        }
        if(w.size()+extra>max){
            max=w.size()+extra;
            cout<<"new"<<max<<";";
        }
        while(w.front()!=0 && w.size()>0) w.pop(), cout<<"3";
        while(w.front()!=1 && w.size()>0) w.pop(), --ck, cout<<"4";
        cout<<"front:"<<w.front()<<';';
        if(w.size()==0) while(nums[i+1]!=1 && i<nums.size()) ++i, cout<<'5';
        cout<<'!'<<w.size()<<"next loop with"<<i+1<<endl;
    }
    return max; 
}




int longestOnes() {
    vector<pair<int, int> > in;
    queue<pair<int, int> > w;
    for (int i=0; i<nums.size(); ++i){
        in.push_back(make_pair(nums[i], 0));
        while (i<nums.size() && nums[i]==in[in.size()-1].first) ++in[in.size()-1].second, ++i;
        --i;
    }
    for(int i=0; i<in.size(); ++i) cout<<in[i].first<<", "<<in[i].second<<'\n';

    int ck=0, max=0, cmax=0;
    for (int i=0; i<in.size(); ++i){
        while((ck<k || in[i].first==1) && i<in.size()) {
            if(in[i].first==1){
                w.push(in[i++]);
                cmax+=w.back().second;
            }
            else if(in[i].first==0 && in[i].second+ck<=k && i<in.size()){
                w.push(in[i++]);
                cmax+=w.back().second;
                ck+=w.back().second;
            }
            else if (i<in.size()) {
                w.push(make_pair(0, k-ck));
                cmax+=w.back().second;
                ck+=w.back().second;
            }
        }
        --i;
        if (w.size()==in.size()) return cmax;
        if (i==in.size()-1 && ck<k) cmax+=(k-ck);
        if (cmax>max) max=cmax;
        if (i==in.size()-1) return max;

        if(!w.empty() && w.front().first==1) cmax-=w.front().second, w.pop();
        if(!w.empty() && w.front().first==0){
            cmax-=w.front().second;
            ck-=w.front().second;
            w.pop();
        }
    }
    return max;
}

int main(){
    int c, t;
    cin>>c;
    for(int i=0; i<c; i++) cin>>t, nums.push_back(t);
    cin>>k;
    cout<<'\n'<<longestOnes()<<endl;
}

/*
19
0 0 1 1 0 0 1 1 1 0 1 1 0 0 0 1 1 1 1
3

11
1 1 1 0 0 0 1 1 1 1 0
2

7
0 0 1 1 1 0 0 
6

*/