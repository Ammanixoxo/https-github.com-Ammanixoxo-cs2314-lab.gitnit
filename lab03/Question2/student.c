// Question2/student.c
// ------------------------------------------------------------
// CS Lab03 - Swap Nodes in Pairs 
//
// TODO:
//   Implement swapPairs(head) to swap every two adjacent nodes.
//
// Rules:
// - Do not allocate new nodes.
// - Do not swap values; swap nodes (rewire pointers).
// - Return the new head pointer.
// ------------------------------------------------------------
#include "student.h"

struct ListNode* swapPairs(struct ListNode* head) {
      if (!head || !head->next) return head;
      struct ListNode *new_head = head->next;
      struct ListNode *prev = NULL;
      struct ListNode *curr = head;
      while (curr && curr->next) {
            struct ListNode *next = curr->next;
            struct ListNode *next_pair = next->next;
            next->next = curr;
            if (prev) prev->next = next;
            curr->next = next_pair;
            prev = curr;
            curr = next_pair;
      }
      return new_head;
}