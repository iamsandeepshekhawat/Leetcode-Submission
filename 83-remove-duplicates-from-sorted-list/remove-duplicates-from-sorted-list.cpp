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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode * node = head;
        while(node != nullptr && node->next != nullptr){
            if(node->val == node->next->val){
                ListNode * temp = node->next;
                node->next = node->next->next;
                delete temp;
            }else{
                node = node->next;
            }
        }

        return head;
    }
};

// TC = O(N)
// SC = O(1)