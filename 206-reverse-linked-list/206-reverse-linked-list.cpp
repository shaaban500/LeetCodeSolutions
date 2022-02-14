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
class Solution 
{
public:
    ListNode* reverseList(ListNode* head)
    {
        if(!head) return head;
        
        ListNode* ReversedList = new ListNode(head->val);
        head = head->next;
        
        while(head)
        {
            ListNode* curNode = new ListNode(head->val);
            curNode->next = ReversedList;
            ReversedList = curNode;
            head = head->next;
        }
        
        return ReversedList;   
    }
};
 
























