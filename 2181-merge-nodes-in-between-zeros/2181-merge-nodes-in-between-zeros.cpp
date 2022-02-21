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
    vector<int>v;
    ListNode* mergeNodes(ListNode* head) 
    {
        ListNode* ans = new ListNode();
        ListNode* temp = new ListNode();
        ans->next = temp;

        int sum = 0;
        while(head->next != NULL)
        {
            head = head->next;
            
            if(head->val == 0)
            {
                temp->next = new ListNode(sum);
                temp = temp->next;
                sum = 0;
            }
            else 
                sum += head->val;
        }
        
        return ans ->next->next;
    }
};