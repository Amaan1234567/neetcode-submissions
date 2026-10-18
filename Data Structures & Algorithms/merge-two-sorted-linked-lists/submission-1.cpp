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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == nullptr){
            if(list2 == nullptr){
                return nullptr;
            } else{
                return list2;
            }
        } else if(list2 == nullptr){
            if(list1 == nullptr){
                return nullptr;
            } else {
                return list1;
            }
        } else {
            ListNode* new_head=nullptr;
            ListNode* cur = nullptr;
            ListNode* ptr1 = list1;
            ListNode* ptr2 = list2;
            while(ptr1!=nullptr && ptr2!=nullptr){
                if(new_head == nullptr){
                    if(ptr1->val <=ptr2->val){
                        new_head = ptr1;
                        cur = ptr1;
                        ptr1= ptr1->next;
                    } else {
                        new_head = ptr2;
                        cur = ptr2;
                        ptr2= ptr2->next;
                    }
                } else {
                    if(ptr1->val <=ptr2->val){
                        cur ->next = ptr1;
                        ptr1 = ptr1->next;
                    } else {
                        cur ->next = ptr2;
                        ptr2 = ptr2->next;
                    }
                    cur = cur ->next;
                }
                // std::cout<<cur->val<<std::endl;
            }
            
            while(ptr1 !=nullptr){
                cur -> next = ptr1;
                ptr1 = ptr1->next;
                cur  = cur->next;
            }

            while(ptr2 !=nullptr){
                cur -> next = ptr2;
                ptr2 = ptr2->next;
                cur  = cur->next;
            }

            return new_head;
        }
    }
};
