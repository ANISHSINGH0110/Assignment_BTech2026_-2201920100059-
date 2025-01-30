/*
Approach

This problem involves adding two non-negative integers represented by two linked lists, where the digits are stored in reverse order. 
Each node contains a single digit, and the task is to return the sum as a linked list.

Key Observations
Both linked lists can have different lengths.
We must handle any carry-over during the addition.
The addition stops when both linked lists are exhausted, and no carry remains.

The iterative() function solves the problem using a while loop.

Steps:
Create a dummy node ans to simplify list manipulation and maintain a reference to the head of the result list.
Initialize a carry variable to store the carry-over during addition.
Traverse the linked lists l1 and l2 until all nodes are processed:
Extract the values from l1 and l2 (0 if the list is already exhausted).
Compute the sum of the two digits and the carry.
Store the result's digit (sum % 10) in the new node.
Update the carry to sum / 10.
Move the pointers l1, l2, and the iterator it forward.
Return the next of dummy node ans as the result.

Time Complexity: O(max(N,M)), where 
N and 𝑀 are the lengths of the input linked lists.
*/

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
    ListNode* iterative(ListNode* l1,ListNode* l2)
    {
        ListNode* ans = new ListNode(-1);
        ListNode* it = ans;
        int carry = 0;
        while(l1 || l2 || carry)
        {
            int a = l1 ? l1->val:0;
            int b = l2 ? l2->val:0;
            int sum = a+b+carry;
            int digit = sum%10;
            carry = sum/10;
            it->next = new ListNode(digit);
            it = it->next;
            l1 = l1?l1->next:nullptr;
            l2 = l2?l2->next:nullptr;
        }
        ListNode* finalAns = ans->next;
        delete ans;
        return finalAns;

    }
    ListNode* recursive(ListNode* l1,ListNode* l2,int carry = 0)
    {
        if(!l1 && !l2 && !carry) return 0;
        int a = l1?l1->val:0;
        int b = l2?l2->val:0;
        int sum = a+b+carry;
        int digit = sum%10;
        carry = sum/10;
        ListNode* ans = new ListNode(digit);
        ans->next = recursive(l1?l1->next:l1,l2?l2->next:l2,carry);
        return ans;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       // return iterative(l1,l2);

       return recursive(l1,l2);
    }
};