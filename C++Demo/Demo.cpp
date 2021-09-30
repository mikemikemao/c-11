
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
namespace two_sum
{
/*输入：nums = [2,7,11,15], target = 9
输出：[0,1]
解释：因为 nums[0] + nums[1] == 9 ，返回 [0, 1] 。
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/two-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
class SolutionTraverse {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++)
            for (int j = i+1; j < nums.size(); j++)
            {
                if (nums.at(j)==target-nums.at(i))
                {
                    return {i,j};
                }
                
            }
        return {};
    }
};

class SolutionHash {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashtable;
        for (int i = 0; i < nums.size(); ++i) {
            auto it = hashtable.find(target - nums[i]);
            if (it != hashtable.end()) {
                return {it->second, i};
            }
            hashtable[nums[i]] = i;
        }
        return {};
    }
};
int test(){
    vector<int> intVec ={2,7,11,15};
    int target=9;
    SolutionTraverse solutionTraverse;
    vector<int> resultVec=solutionTraverse.twoSum(intVec,target);
    cout<<"SolutionTraverse Result:\n"<<endl;
    for (auto &vect :resultVec)
        cout<<vect<<endl;
    cout<<"SolutionHash Result:\n"<<endl;
    SolutionHash solutionHash;
    resultVec=solutionHash.twoSum(intVec,target);
    for (auto &vect :resultVec)
        cout<<vect<<endl;
}
} // namespace name




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
namespace add_two_numbers{
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
        ListNode* dummy = new ListNode();
        ListNode* curr = dummy;
        int carry = 0;
        while (l1 || l2) {
            int x = l1 ? l1->val : 0;
            int y = l2 ? l2->val : 0;

            int sum = x + y + carry;
            curr->next = new ListNode(sum % 10);
             // bug 修复：视频中忘了移动 curr 指针了
            curr = curr->next;
            carry = sum / 10;

            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }
        if (carry != 0) curr->next = new ListNode(carry);
        return dummy->next;
    }
};    
void test(){
    ListNode* pListNodl1=NULL;
    ListNode* pend=NULL;
    ListNode* pnew=NULL;
    ListNode* pListNodl2=NULL;
    int valel1[7] = {9,9,9,9,9,9,9};
    int valel2[4] = {9,9,9,9};
    for (size_t i = 0; i < 7; i++)
    {
        pnew =(ListNode*)malloc(sizeof(ListNode));
        pnew->val=valel1[i];
        pnew->next=NULL;
        if(pListNodl1==NULL){
            pListNodl1=pnew;
            pend=pListNodl1;
        }else{
            pend->next=pnew;
            pend=pnew;
        }
    }
    for (size_t i = 0; i < 4; i++)
    {
        pnew =(ListNode*)malloc(sizeof(ListNode));
        pnew->val=valel2[i];
        pnew->next=NULL;
        if(pListNodl2==NULL){
            pListNodl2=pnew;
            pend=pListNodl2;
        }else{
            pend->next=pnew;
            pend=pnew;
        }
    }
        
    Solution msolution;
    ListNode* l3=msolution.addTwoNumbers(pListNodl1, pListNodl2);
    for (size_t i = 0; i < 9; i++)
    {
        if(l3!=NULL){
            cout << l3->val << endl;
            l3=l3->next;
        }
       
    }
}
}

namespace testLeetCode{
    void test_LeetCode(){
    int choice;
    long value;  
        cout << "\n\ntest_leetcode()......... \n";
        cout << "select: \n";
        cout << "       (1)twoSum (2)twoSumHash (3)add_two_numbers \n";
        cout << "       (7)multimap (8)unordered_multiset (9)unordered_multimap (10)slist \n";
        cout << "       (11)hash_multiset (12)hash_multimap (13)set (14)map (15)unordered_set \n";
        cout << "       (16)unordered_map (17)stack (18)queue \n";	
        cout << " (2),(3),(5),(6),(8) will test also moveable elements. \n"; 
        switch (choice) 
        {
            case 1 : two_sum::test();		
                break;
            case 2 : add_two_numbers::test();		
                break;
            default:
                break;
        }
}
}


int main()
{
    /////////////////////////////////////////////////////////////////////////
    //new delete 一个对象 基类析构函数不是析构函数 会造成内存泄漏
    //BaseClassVirtualDestruct::Base *basePtr = new BaseClassVirtualDestruct::Derive();
    //delete basePtr;
    /////////////////////////////////////////////////////////////////////////
    //看支不支持c++11
    //cout << __cplusplus << endl;
    testLeetCode::test_LeetCode();
    return 0;
}