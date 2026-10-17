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
    ListNode* reverseList(ListNode* head) {
        
        if(head == nullptr){
            return head;
        }
        if(head->next == nullptr){
            return head;
        }

        ListNode* prev = head;
        ListNode* cur = head->next;
        prev->next = nullptr;
        while(cur->next!=nullptr){
            ListNode* temp = cur->next;
            std::cout<<temp->val<<std::endl;
            cur->next = prev;
            prev = cur;
            cur=temp;
        }
        cur->next = prev;
        return cur;
    }
};
