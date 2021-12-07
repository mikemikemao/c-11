
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
/////////////////////////////////////////////////////////////////////////////////////////////////////leetcode///////////////////////////////////////////////////////////////////////////////
namespace two_sum
{
    /*输入：nums = [2,7,11,15], target = 9
输出：[0,1]
解释：因为 nums[0] + nums[1] == 9 ，返回 [0, 1] 。
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/two-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
    class SolutionTraverse
    {
    public:
        vector<int> twoSum(vector<int> &nums, int target)
        {
            for (int i = 0; i < nums.size(); i++)
                for (int j = i + 1; j < nums.size(); j++)
                {
                    if (nums.at(j) == target - nums.at(i))
                    {
                        return {i, j};
                    }
                }
            return {};
        }
    };

    class SolutionHash
    {
    public:
        vector<int> twoSum(vector<int> &nums, int target)
        {
            unordered_map<int, int> hashtable;
            for (int i = 0; i < nums.size(); ++i)
            {
                auto it = hashtable.find(target - nums[i]);
                if (it != hashtable.end())
                {
                    return {it->second, i};
                }
                hashtable[nums[i]] = i;
            }
            return {};
        }
    };
    int test()
    {
        vector<int> intVec = {2, 7, 11, 15};
        int target = 9;
        SolutionTraverse solutionTraverse;
        vector<int> resultVec = solutionTraverse.twoSum(intVec, target);
        cout << "SolutionTraverse Result:\n"
             << endl;
        for (auto &vect : resultVec)
            cout << vect << endl;
        cout << "SolutionHash Result:\n"
             << endl;
        SolutionHash solutionHash;
        resultVec = solutionHash.twoSum(intVec, target);
        for (auto &vect : resultVec)
            cout << vect << endl;
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
namespace add_two_numbers
{
    struct ListNode
    {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };
    class Solution
    {
    public:
        ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
        {
            ListNode *dummy = new ListNode();
            ListNode *curr = dummy;
            int carry = 0;
            while (l1 || l2)
            {
                int x = l1 ? l1->val : 0;
                int y = l2 ? l2->val : 0;

                int sum = x + y + carry;
                curr->next = new ListNode(sum % 10);
                // bug 修复：视频中忘了移动 curr 指针了
                curr = curr->next;
                carry = sum / 10;

                if (l1)
                    l1 = l1->next;
                if (l2)
                    l2 = l2->next;
            }
            if (carry != 0)
                curr->next = new ListNode(carry);
            return dummy->next;
        }
    };
    void test()
    {
        ListNode *pListNodl1 = NULL;
        ListNode *pend = NULL;
        ListNode *pnew = NULL;
        ListNode *pListNodl2 = NULL;
        int valel1[7] = {9, 9, 9, 9, 9, 9, 9};
        int valel2[4] = {9, 9, 9, 9};
        for (size_t i = 0; i < 7; i++)
        {
            pnew = (ListNode *)malloc(sizeof(ListNode));
            pnew->val = valel1[i];
            pnew->next = NULL;
            if (pListNodl1 == NULL)
            {
                pListNodl1 = pnew;
                pend = pListNodl1;
            }
            else
            {
                pend->next = pnew;
                pend = pnew;
            }
        }
        for (size_t i = 0; i < 4; i++)
        {
            pnew = (ListNode *)malloc(sizeof(ListNode));
            pnew->val = valel2[i];
            pnew->next = NULL;
            if (pListNodl2 == NULL)
            {
                pListNodl2 = pnew;
                pend = pListNodl2;
            }
            else
            {
                pend->next = pnew;
                pend = pnew;
            }
        }

        Solution msolution;
        ListNode *l3 = msolution.addTwoNumbers(pListNodl1, pListNodl2);
        for (size_t i = 0; i < 9; i++)
        {
            if (l3 != NULL)
            {
                cout << l3->val << endl;
                l3 = l3->next;
            }
        }
    }
}
/*
给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度。
示例 1:
输入: s = "abcabcbb"
输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
示例 2:
输入: s = "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
示例 3:
输入: s = "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
示例 4:
输入: s = ""
输出: 0
提示：
0 <= s.length <= 5 * 104
s 由英文字母、数字、符号和空格组成
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-substring-without-repeating-characters
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
//---------------------------------------------------
#include <set>
#include <stdexcept>
#include <string>
#include <cstdlib> //abort()
#include <cstdio>  //snprintf()
#include <iostream>
#include <ctime>
namespace lengthOfLongestSubstring
{
    class Solution
    {
    public:
        int lengthOfLongestSubstring(string s)
        {
            set<char> current;
            set<char> present;
            int presentsize = 0;
            int currentsize = 0;
            int times = 0;
            for (int i = 0; i < s.size(); i++)
            {
                presentsize = current.size();
                cout << "presentsize=" << presentsize << endl;
                current.insert(s[i]);
                currentsize = current.size();
                cout << "currentsize=" << currentsize << endl;
                if (currentsize == presentsize)
                {
                    if (times == 0)
                    {
                        for (auto temp : current)
                        {
                            present.insert(temp);
                        }
                        current.clear();
                        current.insert(s[i]);
                    }
                    else
                    {
                        //碰到相同的字符 判断前后set的数量 数量小的抛弃
                        if (current.size() >= present.size())
                        {
                            present.clear();
                            for (auto temp : current)
                            {
                                present.insert(temp);
                            }
                        }
                        current.clear();
                        current.insert(s[i]);
                    }
                    times++;
                }
            }
            if (current.size() >= present.size())
            {
                return current.size();
            }

            return present.size();
        }
    };
    int test()
    {
        string s = " ";
        Solution solution;
        int num = solution.lengthOfLongestSubstring(s);
        cout << "num=" << num << endl;
    }

}

/////////////////////////////////////////////////////////////////////////////////////////////////////C++primer///////////////////////////////////////////////////////////////////////////////
#include <iomanip>
namespace temporaryObject
{
    class VECTOR3
    {
    public:
        VECTOR3() : x(0.0f), y(0.0f), z(0.0f)
        {
            cout << "VECTOR3 Default Constructor " << setiosflags(ios_base::hex) << this << endl; //以hex形式打印
        }
        VECTOR3(float fx, float fy, float fz) : x(0.0f), y(0.0f), z(0.0f)
        {
            cout << "VECTOR3 Parameter Constructor " << setiosflags(ios_base::hex) << this << endl;
        }
        VECTOR3(const VECTOR3 &rht) : x(rht.x), y(rht.y), z(rht.z)
        {
            cout << "VECTOR3 Copy Constructor "<< setiosflags(ios_base::hex) << this<< " from rht : "
                 << setiosflags(ios_base::hex) << &rht
                 << endl;
        }
        ~VECTOR3()
        {
            cout << "VECTOR3 Destructor " << setiosflags(ios_base::hex) << this << endl;
        }
        VECTOR3 &operator=(const VECTOR3 &rht)
        {
            if (&rht == this)
                return *this;
            x = rht.x;
            y = rht.y;
            z = rht.z;
            std::cout << "VECTOR3 operator = left oper : "
                      << setiosflags(ios_base::hex) << this
                      << " right oper : "
                      << setiosflags(ios_base::hex) << &rht
                      << endl;
            return *this;
        }

    public:
        float x;
        float y;
        float z;
    };

    VECTOR3 Func1()
    {
        return VECTOR3(1.0f, 1.0f, 1.0f);
    }

    VECTOR3 Func2()
    {
        VECTOR3 ret;
        ret.x = 2.0f;
        ret.y = 2.0f;
        ret.z = 2.0f;
        return ret;
    }
    void test()
    {
        //1>. 在 Func1() 中构造一个无名对象
        //2>. 由 Func1() 中的无名对象拷贝构造调用表达式处的临时对象
        //3>. 再由临时对象拷贝构造v1
        //4>. Func1() 返回，析构无名对象
        //5>. 整个语句结束，析构临时对象
        //但是c++ 会优化上述过程，省略了 1>. 2>. 处的临时对象创建，直接以1.0f, 1.0f, 1.0f 为参数构造v1，这样只会有一次构造函数的调用。
        //结果：
            //VECTOR3 Parameter Constructor 0x65fd94
        VECTOR3 v1 = Func1();
        //1>. 在 Func1() 中构造一个无名对象
        //2>. 由 Func1() 中的无名对象拷贝构造调用表达式处的临时对象
        //3>. 再由临时对象赋值给v1 (赋值运算符)
        //4>. Func1() 返回，析构无名对象
        //5>. 整个语句结束，析构临时对象
        //但是c++ 会优化上述过程，省略了 1>. 处的无名临时对象创建，直接以1.0f, 1.0f, 1.0f 为参数构造调用表达式处的临时对象，因为是赋值，所以这个临时对象是无法被优化的，赋值完毕后，表达式结束，临时对象被析构。
        //结果：
            //VECTOR3 Parameter Constructor 0x65fd84
            //VECTOR3 operator = left oper : 0x65fd78 right oper : 0x65fd84
            //VECTOR3 Destructor 0x65fd84
        v1 = Func1();
        //但是c++ 会优化上述过程，省略了创建临时对象这一步，直接由ret拷贝构造v2。
        VECTOR3 v2 =Func2();
        //拷贝构造
        VECTOR3 v21(v2);
        VECTOR3 v3;
        //拷贝赋值
        v3 = Func2();
    }

} // namespace temporaryObject

namespace lamdaTest
{
    void test()
    {
        size_t v1 = 42;
        auto f = [v1]() mutable
        { return ++v1; }; //mutabel能够改变捕获局部变量的值
        v1 = 0;
        auto j = f();
        cout << j << endl;
    }
}

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
    void test(){
        //new delete 一个对象 基类析构函数不是析构函数 会造成内存泄漏
        BaseClassVirtualDestruct::Base *basePtr = new BaseClassVirtualDestruct::Derive();
        delete basePtr;
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////Test///////////////////////////////////////////////////////////////////////////////

namespace testLeetCode
{
    void test_LeetCode()
    {
        int choice;
        long value;
        cout << "\n\ntest_leetcode()......... \n";
        cout << "select: \n";
        cout << "       (1)twoSum (2)twoSumHash (3)add_two_numbers \n";
        cout << "       (7)multimap (8)unordered_multiset (9)unordered_multimap (10)slist \n";
        cout << "       (11)hash_multiset (12)hash_multimap (13)set (14)map (15)unordered_set \n";
        cout << "       (16)unordered_map (17)stack (18)queue \n";
        cout << " (2),(3),(5),(6),(8) will test also moveable elements. \n";
        cin >> choice;
        cout << choice;
        switch (choice)
        {
        case 1:
            two_sum::test();
            break;
        case 2:
            add_two_numbers::test();
            break;
        case 3:
            lengthOfLongestSubstring::test();
            break;
        default:
            break;
        }
    }
}

namespace testHouJieCpp
{

    void test_HouJieCpp()
    {
        int choice;
        long value;
        cout << "\n\ntest_containers()......... \n";
        cout << "select: \n";
        cout << "       (1)array (2)vector (3)list (4)forward_list (5)deque (6)multiset \n";
        cout << "       (7)multimap (8)unordered_multiset (9)unordered_multimap (10)slist \n";
        cout << "       (11)hash_multiset (12)hash_multimap (13)set (14)map (15)unordered_set \n";
        cout << "       (16)unordered_map (17)stack (18)queue \n";
        cout << " (2),(3),(5),(6),(8) will test also moveable elements. \n";
        cin >> choice;
        cout << choice;
        if (choice != 1)
        { //1 ==> array, use ASIZE
            cout << "how many elements: ";
            cin >> value;
        }

        switch (choice)
        {
        case 1:
            temporaryObject::test();
        default:
            break;
        }
    }
}

namespace testCppPrime
{

    void test_CppPrime()
    {
        int choice;
        long value;
        cout << "\n\ntest_containers()......... \n";
        cout << "select: \n";
        cout << "       (1)temporary object (2)lamda表达式 (3)虚析构函数\n";
        cin >> choice;
        cout << "输入"<<choice<<endl;
        switch (choice)
        {
            case 1:
                temporaryObject::test();
            case 2:
                lamdaTest::test();
            case 3:
                BaseClassVirtualDestruct::test();
            default:
                break;
        }
    }
}

int main()
{
    /////////////////////////////////////////////////////////////////////////
    //看支不支持c++11
    //cout << __cplusplus << endl;
    int choice;
    long value;
    cout << "\n\ntest......... \n";
    cout << "select: \n";
    cout << "       (1)LeetCode \n";
    cout << "       (2)HouJieCpp\n";
    cout << "       (3)CppPrime \n";
    cin >> choice;
    cout << choice;
    switch (choice)
    {
        case 1:
            testLeetCode::test_LeetCode();
        case 2:
            testHouJieCpp::test_HouJieCpp();
        case 3:
            testCppPrime::test_CppPrime();
        default:
            break;
    }
    return 0;
}