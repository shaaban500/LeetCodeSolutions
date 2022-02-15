/**
 * Definition for singly-linked list.
 * struct ListNode {
 
 
 *     int val;
 *     ListNode *next;
 
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    
    void solve(ListNode* head)
    {
        if(head && head->next != nullptr)
        {
            int x = head->val;
            int y = head->next->val;
            head->val = y;
            head->next->val = x;
            solve(head->next->next);
        }
    }
    
    
    ListNode* swapPairs(ListNode* head) 
    {
        solve(head);
        return head;
    }
};




















