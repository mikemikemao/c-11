
/*
 * @Author: pirate
 * @Function: function
 * @Return: 0--success others--failed
 */
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <list>
using namespace std;

//new delete 一个对象 基类析构函数不是析构函数 会造成内存泄漏
namespace BaseClassVirtualDestruct
{
    class Base
    {
    public:
        Base() { cout << "Constructing Base\n"; }
        // this is a destructor:
         ~Base() { cout << "Destroying Base\n"; }
    };
    class Derive : public Base
    {
    public:
        Derive() { cout << "Constructing Derive\n"; }
        ~Derive() { cout << "Destroying Derive\n"; }
    };
}
/*输入：nums = [2,7,11,15], target = 9
输出：[0,1]
解释：因为 nums[0] + nums[1] == 9 ，返回 [0, 1] 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/two-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         for (size_t i = 0; i < nums.size(); i++)
//             for (size_t j = i+1; j < nums.size(); j++)
//             {
//                 if (nums.at(j)==target-nums.at(i))
//                 {
//                     return {i,j};
//                 }
                
//             }
//         return {};
//     }
// };

// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         unordered_map<int, int> hashtable;
//         for (int i = 0; i < nums.size(); ++i) {
//             auto it = hashtable.find(target - nums[i]);
//             if (it != hashtable.end()) {
//                 return {it->second, i};
//             }
//             hashtable[nums[i]] = i;
//         }
//         return {};
//     }
// };


/////////////////////////////////////////////////////////////////////////
// 给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。

// 请你将两个数相加，并以相同形式返回一个表示和的链表。

// 你可以假设除了数字 0 之外，这两个数都不会以 0 开头。

//  

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/add-two-numbers
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
// 输入：l1 = [2,4,3], l2 = [5,6,4]
// 输出：[7,0,8]
// 解释：342 + 465 = 807.


 struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1->next!=NULL && l2->next!=NULL){
            l1->val=l1->val+l2->val;
            addTwoNumbers(l1->next, l2->next);
        }
        if (l1->next==NULL)
        {
            l1->next = l2->next;
        }
        if(l2->next==NULL){
            return l1;
        }
        return l1;
        
    }
};

int main()
{
    /////////////////////////////////////////////////////////////////////////
    //new delete 一个对象 基类析构函数不是析构函数 会造成内存泄漏
    //BaseClassVirtualDestruct::Base *basePtr = new BaseClassVirtualDestruct::Derive();
    //delete basePtr;
    /////////////////////////////////////////////////////////////////////////
    //看支不支持c++11
    //cout << __cplusplus << endl;
    /////////////////////////////////////////////////////////////////////////
    // vector<int> intVec ={2,7,11,15};
    // int target=9;
    // Solution msolution;
    // vector<int> resultVec=msolution.twoSum(intVec,target);
    // for (int i=0;i<resultVec.size();i++)
    //     cout<<resultVec.at(i)<<endl;
    /////////////////////////////////////////////////////////////////////////
    // list<int> l1;
    // list<int> l2;
    // l1.clear();
    // l2.clear();
    // l1.push_back(2);
    // l1.push_back(4);
    // l1.push_back(3);
    // l2.push_back(5);
    // l2.push_back(6);
    // l2.push_back(4);
    // for(auto ite : l1){
    //      cout << ite << endl;
    // }
    // list<int>::iterator ite;
    // for (ite=l1.begin(); ite!=l1.end(); ite++)
    // {
    //     cout << *ite << endl;
    // }
    ListNode* pListNodl1;
    ListNode* pListNodl2;
    int valel1[3] = {2,4,3};
    int valel2[3] = {5,6,4};
    for (size_t i = 0; i < 3; i++)
    {
        ListNod* pListNodl1 =(ListNode*)malloc(sizeof(ListNode));
        pListNodl1->val=valel1[i];
        pListNodl1->next=
    }
    
    
    Solution msolution;
    ListNode* l3=msolution.addTwoNumbers(&l1, &l2);
    cout << l3->val << endl;
    cout << l3->next->val << endl;
    cout << l3->next->next->val << endl;
    
    return 0;
}