/**
 * stack: stack<int>st; pop, top, push, size, empty
 * 动态数组：vector, vector<int> vec; push_back, pop_back, front, back
 */


/**
 * 贪心 + 二分算法策略：
 * 对于第1个栈的底部元素，小于第i+1个栈的顶部元素。
 * 将这个问题就转换成为，第1个元素的操作是什么？是直接添加到某一个栈呢？还是怎么样？
 * 
 * 分为3种情况：
 * 如果当前这个元素(x)如果要小于已经放置在 Elsie 拿走的元素，则直接输出答案，元素左边所有元素；
 * 如果当前这个元素(x)比最后一个栈的元素还要大，那么此时一定要新建一个栈；
 * 不满足以上2个条件的元素的情况下，我们需要用二分查找算法去查询当前元素(e)应该放置于哪个栈之内；然后将栈内的所有比它小的元素都删掉直到目标数组之中，然后将当前元素添加到栈之内。
 * 
 * 
 * 栈：
 * stack, stack<int> st; pop, top, push, size, empty
 * 
 * 动态数组：
 * vector, vector<int> vec; push_back, pop_back, front, back
 * 
 * 实际上，很多人将 vector 结构看作是一种理想层面的栈结构，在 vector 的尾部添加（push_back）或者弹出（pop_back）元素；那么此时的 back 可以看作是栈结构的顶部元素，此时的 front
 */

#include <bits/stdc++.h>

using namespace std;
vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    multiset<int> s;
    vector<int> ret;

    for (int i = 0; i < k; i++) { s.insert(nums[i]); }

    for (int i = k; i < nums.size(); i++) {
        ret.push_back(*s.rbegin()); //逆向迭代器
        s.erase(s.find(nums[i - k]));
        s.insert(nums[i]);
    }

    ret.push_back(*s.rbegin());
    return ret;
}