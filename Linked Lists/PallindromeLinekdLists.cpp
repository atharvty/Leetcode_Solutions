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
    ListNode* reverseList(ListNode* head){
        ListNode* pre = NULL;
        ListNode* next = NULL;
        
        while(head!=NULL){
            next = head->next;
            head->next = pre;
            pre = head;
            head = next;
        }
        return pre;
    }
    
    
    
    bool isPalindrome(ListNode* head) {
        //Edge case
        if(head == NULL || head->next == NULL) return true;
        
        ListNode *slow = head;
        ListNode *fast = head;
        
        //finding middle of the link list for both odd linklist or even linklist
        while(fast->next != NULL  && fast->next->next !=NULL){
            slow = slow->next;
            fast = fast->next->next;
            
        }
        //slow points on middle of the element 
        //So you reverse the list from slow->next
        slow->next = reverseList(slow->next);
        slow = slow ->next;
        
        while(slow!=NULL){
            if(head->val !=slow->val)
                return false;
            head = head->next;
            slow = slow->next;
        }
        return true;
        
        
    }
};