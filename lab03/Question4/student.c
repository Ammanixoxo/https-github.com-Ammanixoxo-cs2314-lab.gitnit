// Question4/student.c
// ------------------------------------------------------------
// CS Lab03 - Middle Node of Linked List
//
// TODO:
//   Implement middleNodeValue(head) using fast/slow pointers.
//
// Notes:
// - If even length, return the second middle.
// - Do not allocate new nodes.
// ------------------------------------------------------------

#include "Student.h"

int middleNodeValue(struct ListNode *head) {
    struct ListNode *slow = head;
    struct ListNode *fast = head;
    // Move fast by 2 and slow by 1. When fast reaches end, slow is at middle.
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow->val;
}