// https://neetcode.io/problems/is-anagram/question

#include <iostream>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        unordered_map<char, int> mp1, mp2;

        for (int i = 0; i < s.size(); i++)
            mp1[s[i]] += 1;

        for (int i = 0; i < t.size(); i++)
            mp2[t[i]] += 1;

        if (mp1 != mp2)
            return false;

        return true;
    }
};
