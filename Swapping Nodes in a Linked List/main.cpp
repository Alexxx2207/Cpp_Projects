
///// CODE PROBLEM IS ON THIS LINK: https://leetcode.com/problems/swapping-nodes-in-a-linked-list/

#include <iostream>

// Definition for singly-linked list.
struct ListNode {
   int val;
   ListNode *next;
   ListNode() : val(0), next(nullptr) {}
   ListNode(int x) : val(x), next(nullptr) {}
   ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    public:
        ListNode* swapNodes(ListNode* head, int k) {
            
            ListNode base = ListNode(0, head);

            ListNode* explorer = &base;

            while(k > 1)
            {
                explorer = explorer->next;

                k--;
            }

            ListNode* leftParent = explorer;
            ListNode* rightParent = &base;

            explorer = explorer->next;
            
            while(explorer != nullptr && explorer->next != nullptr)
            {
                explorer = explorer->next;

                rightParent = rightParent->next;
            }

            std::swap(leftParent->next, rightParent->next);
            std::swap(leftParent->next->next, rightParent->next->next);

            return base.next;
        }
};