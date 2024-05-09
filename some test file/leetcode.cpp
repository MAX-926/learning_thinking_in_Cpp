// #include<iostream>
// #include<vector>
// using namespace std;

// class Solution {
// public:
//     vector<long> twoSum(vector<long>& nums, int target) {
//         for(int i = 0; i < nums.capacity(); i++)
//             for(int j = i+1; j < nums.capacity(); j++)
//             {
//                 if(nums[i]+nums[j] == target)
//                     return {i, j};
//             }
//         return {};
//     }
//     void showRe();
// private:
//     vector<long> re;
// };
// void Solution::showRe()
// {
//     for(int i = 0; i < re.capacity(); i++)
//         cout << re[i] << " ";
// }

// int main()
// {
//     vector<long> test;
//     test.push_back(-1);
//     test.push_back(-2);
//     test.push_back(-3);
//     test.push_back(-4);
//     test.push_back(-5);
//     // vector<int> re;
//     // for(int i = 0; i < test.capacity(); i++)
//     //     for(int j = i+1; j < test.capacity(); j++)
//     //     {
//     //         if(test[i]+test[j] == 9)
//     //         {
//     //             re.push_back(i);
//     //             re.push_back(j);
//     //         }
//     //     }    
//         // for(int i = 0; i < re.capacity(); i++)
//         //     cout << re[i];

//     Solution s;
//     s.twoSum(test, -8);
//     s.showRe();
// }

// #include<iostream>
// #include<vector>
// using namespace std;
// class Solution {
// public:
//     bool isPalindrome(int x) {
//         if(x<0) return false;
//         vector<int> list;
//         int p;
//         while(x/10 != 0)
//         {
//             p = x%10;
//             x -= p;
//             x /= 10;
//             list.push_back(p);
//         }
//         list.push_back(x);
//         for(int i = 0; i < list.size()/2; i++)
//             if(list[i] != list[list.size()-i-1])
//                 return false;
//         return true;
//     }
// };

// int main()
// {
//     Solution s;
//     cout << s.isPalindrome(121);
//     // cout << s.isPalindrome(121);
// }

// #include<iostream>
// using namespace std;

// class Solution {
// public:
//     int romanToInt(string s) {
//         int re = 0;
//         for(int i = s.length()-1; i >= 0; i--)
//         {
//             // I V C L X D M
//             // 1 5 10 50 100 500 1000
//             //MCMXCIV
//             //5-1+100-10+1000-100+1000
//             switch(s[i])
//             {
//                 case 'I':
//                     if(i+1 < s.length())
//                         if(s[i+1] == 'V' || s[i+1] == 'X'){ re -= 1;break;}
//                     re += 1;
//                     break;
//                 case 'V': re += 5; break;
//                 case 'X': 
//                     if(i+1 < s.length())
//                         if(s[i+1] == 'L' || s[i+1] == 'C'){ re -= 10;break;}
//                         re += 10;
//                         break;
//                     // else re += 10; break;
//                 case 'L': re += 50; break;
//                 case 'C': 
//                     if(i+1 < s.length())
//                         if(s[i+1] == 'D' || s[i+1] == 'M'){ re -= 100;break;}
//                     re += 100;
//                     break;
//                     // else re += 100; break;
//                 case 'D': re += 500; break;
//                 case 'M': re += 1000; break;                
//             }
//         }
//     return re;
//     }
// };

// int main()
// {
//     Solution s;
//     cout << s.romanToInt("MCMXCIV");
// }

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

bool compare(string a, string b)
{
    return a.length()<b.length();
}

// class Solution {
// public:
//     string longestCommonPrefix(vector<string>& strs) {
//         if(strs.size() == 1) return strs[0];
//         sort(strs.begin(), strs.end());
//         if(strs[0] == "")return "";
//         string s = "";
//         bool tag = 0;
//         int len = 0;
//         if(strs[0][0] != strs[1][0]) return "";
//         else
//         {
//             for(int j = 0; j < strs[0].size(); j++)
//                 {
//                     for(int i = 1; i < strs.size(); i++)
//                         {
//                             if(strs[0][j] == strs[i][j])
//                                 tag = 1;
//                             else
//                             {
//                                 tag = 0;
//                                 break;
//                             }
//                         }
//                     if(tag == 0) break;
//                     if(tag == 1) ++len;
//                 }
//             for(int i = 0; i < len; i++)
//                 s += strs[0][i];
//             return s;
//         }
//     }
// };

// bool compare(string a, string b)
// {
//     return a.length()<b.length();
// }

// int main()
// {
//         vector<string> strs;
        // strs.push_back("AAAAAAAAA");
        // strs.push_back("dog");
        // strs.push_back("racecar");
        // strs.push_back("car");

        // strs.push_back("flow");
        // strs.push_back("flower");
        // strs.push_back("flight");
        // strs.push_back("");
//         strs.push_back("a");
//         Solution s;
//         cout << s.longestCommonPrefix(strs);
// }

