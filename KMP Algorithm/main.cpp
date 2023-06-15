
///// CODE PROBLEM IS ON THIS LINK: https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/

#include <iostream>
#include <string>
#include <vector>


class Solution {
public:
    int strStr(std::string haystack, std::string needle)
        {
            int hayStackSize = haystack.size();
            int needleSize = needle.size();

            std::vector<int> lps(needleSize);
        
            computeLPS(needle, needleSize, lps);

            int indexNeedle = 0, indexHaystack = 0;

            while (indexHaystack < hayStackSize)
            {
                if(haystack[indexHaystack] == needle[indexNeedle])
                {
                    indexNeedle++;
                    indexHaystack++;

                    if(indexNeedle == needleSize)
                    {
                        break;
                    }
                }
                else 
                {
                    if(indexNeedle != 0)
                    {
                        indexNeedle = lps[indexNeedle - 1];
                    }
                    else
                    {
                        indexHaystack++;
                    }
                }
            }

            return indexNeedle == needleSize ? indexHaystack - needleSize : - 1;
        }

        void computeLPS(std::string needle, int needleSize, std::vector<int>& lps)
        {
            int len = 0;
            int index = 1;

            lps[0] = 0;

            while(index < needle.size())
            {
                if(needle[index] == needle[len])
                {
                    lps[index++] = ++len;
                }
                else 
                {
                    if(len == 0)
                    {
                        lps[index++] = 0;
                    }
                    else
                    {
                        len = lps[len - 1];
                    }
                }
            }
        }
};

int main()
{
    Solution solution;

    std::cout << "\nIndex: " << solution.strStr("mississippi", "issip");
    return 0;
}