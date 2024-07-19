#include <iostream>
#include <vector>
using namespace std;

//最小区间

vector <vector<int> > nums;
vector <int> xiabiao;
int start,cur_end;
int final_min=100000;
int count_lists;
int cur_min, cur_max, cur_min_xiabiao;
void cal(int change);
bool daotou=false;

int main(){
    int m, value;
    cin>>count_lists;
    //cout<<"ok"<<count_lists<<endl;
    nums.resize(count_lists, std::vector<int>(0, 0));
    for (int i=0; i<count_lists; i++) xiabiao.push_back(0);
    for (int i=0; i<count_lists; i++){
        cin>>m;
        //cout<<m<<endl;
        for (int j=0; j<m; j++){
            cin>>value;
            nums[i].push_back(value);
        }
        //cout<<"111"<<endl;
    }
    cout<<"done input"<<endl;

    cur_min=1000000;
    cur_max=0;
    //最后由下标传到下一个循环-cur_min_xiabiao
    for (int i=0; i<count_lists; i++){
        if (nums[i][xiabiao[i]]<cur_min){
            cur_min=nums[i][xiabiao[i]];
            cur_min_xiabiao=i;
        } 
        if (nums[i][xiabiao[i]]>cur_max) cur_max=nums[i][xiabiao[i]];
    }
    //找一下区间大小，对比
    if (cur_max-cur_min<final_min){
        final_min=cur_max-cur_min;
        start=cur_min;
        cur_end=cur_max;
    }
    cal(cur_min_xiabiao);
    cout<<"start is "<<start<<", end is "<<cur_end<<", final min is "<<final_min<<endl;
}


void cal(int change){
    //cout<<"**************************************"<<endl;
    //cout<<change<<endl;
    xiabiao[change]=xiabiao[change]+1;
    if (xiabiao[change]==nums[change].size()) return;
    //考虑
    int cur_min, cur_max, cur_min_xiabiao;
    //最后由下标传到下一个循环-cur_min_xiabiao
    for (int i=0; i<count_lists; i++){
        if (nums[i][xiabiao[i]]<cur_min){
            cur_min=nums[i][xiabiao[i]];
            
            cur_min_xiabiao=i;
        } 
        if (nums[i][xiabiao[i]]>cur_max) cur_max=nums[i][xiabiao[i]];
    }
    //找一下区间大小，对比
    if (cur_max-cur_min<final_min){
        final_min=cur_max-cur_min;
        //cout<<"cur min= "<<cur_min<<"cur max is "<<cur_max;
        start=cur_min;
        cur_end=cur_max;
    }

    cal(cur_min_xiabiao);
}


/*
int cur_max=0;
vector <int> water;
void cal(int left, int right);

int main(){
    int num, cur;
    cin>>num;
    cout<<"ok"<<endl;
    for (int i=0; i<num; i++){
        cin>>cur;
        water.push_back(cur);
    }
    cal(0,8);
    cout<<cur_max;
}

void cal(int left, int right){
    cout<<right;
    cout<<"water left is "<<water[left]<<"water right is "<<water[right]<<endl;
    cout<<"cur_max "<<cur_max<<endl;
    if (water[left]<water[right]){
        if (water[left]*(right-left)>cur_max){
            cur_max=water[left]*(right-left);
            cout<<"************************************************"<<endl;
            cal(left+1, right);
        }
    } else {
        if (water[right]*(right-left)>cur_max){
            cur_max=water[right]*(right-left);
            cout<<"*************************************************"<<endl;
            cal(left, right-1);
        } 
    }
    return;
}
*/

/*
#include <iostream>
#include <vector>
using namespace std;





//1 8 6 2 5 4 8 3 7


int maxArea(vector<int>& height) {
    int i = 0, j = height.size() - 1, max_capacity = 0;
    while(i < j) {
        max_capacity = height[i] < height[j] ? 
            max(max_capacity, (j - i) * height[i++]): 
            max(max_capacity, (j - i) * height[j--]); 
    }
    return max_capacity;
}


int main(){
    int n,temp;
    cin>>n;
    vector<int> height={};
    for(int i = 0; i < n; i++)  {
        cin>>temp;
        height.push_back(temp);
    }
    int ans=maxArea(height);
    cout<<ans<<endl;
    return 0;
}

*/