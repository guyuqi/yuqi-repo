/* 
 *
 *  Given a singly linked list, determine if it is a palindrome.
 *  Leetcode: https://leetcode.com/problems/palindrome-linked-list/description/
 * 
 *  ispalindrome:
 *
 *  1. find middle node; 
 *     P.S. 
 *         Middle node belongs to top half if total link list nodes are even. (t->next && lfast->next->next)
 *
 *         if judging condition is (lfast && lfast->next),
 *            -> Then the middle node belongs to half bottom.      
 *
 *        The code makes mid node belongs to top half.
 *            -> It is convenient to comapre the top half with reversed bottom half of link lists. 
 *            -> The next of mid node is the head of the bottom half list.    
 *
 *  2. reverse the bottom half list.
 *  3. Compare the top half list with reversed bottom half.
 *  4. restore the bottom half list.
 *  5. create the a link list to verify the code snippet.
 *
 *  Time complexity : O(n).
 *  Space complexity: O(1).
 *
 */


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef int BOOL;
#define TRUE 1
#define FALSE 0

typedef struct linknode {
    int data;
    struct linknode *next;
} LNode;


LNode* reverse_link(LNode* lhead) {
    LNode *lprev = NULL;
    LNode *lnext;

    while (lhead) {
        lnext = lhead->next;
        lhead->next = lprev;
        lprev = lhead;
        lhead = lnext;
    }

    return lprev;
}


LNode* find_mid_node(LNode* lhead) {
    LNode *lslow = lhead;
    LNode *lfast = lhead;

    while (lfast->next && lfast->next->next) {
        lslow = lslow->next;
        lfast = lfast->next->next;
    }

    return lslow;
}


BOOL is_palindrome(LNode* lhead) {
    LNode *lhd_op = lhead;
    LNode *lmid = find_mid_node(lhead);

    // The next of middle node is the head of bottom list
    LNode *revs_head = reverse_link(lmid->next);
    LNode *rhd_op = revs_head;

    while (rhd_op) {
        if (lhd_op->data != rhd_op->data) {

            //restore reversed half of the original link list
            revs_head = reverse_link(revs_head);
            lmid->next = revs_head;

            return FALSE; // not palindrome
        }

        lhd_op = lhd_op->next;
        rhd_op = rhd_op->next;
    }

    //restore reversed half of the original link list
    revs_head = reverse_link(revs_head);
    lmid->next = revs_head;

    return TRUE;
}


LNode* creat_linklist(int length) {
    int i;
    LNode *p;
    LNode *lhead;

    lhead = (LNode *)malloc(sizeof(LNode));
    if ( NULL == lhead) {
        return NULL;
    }
    lhead->data = 7;
    lhead->next = NULL;

    for (i = 0; i < length-1; i ++) {
        p = (LNode *)malloc(sizeof(LNode));
        if (NULL == p) {
            return NULL;
        }
        p->data = 7; // Each node data is 7
        p->next = lhead->next;
        lhead->next = p;
    }

    return lhead;
}

void destroy_linklist(LNode* lhead) {
    LNode* p;
    LNode* q;
    p = lhead;

    while (p) {
        q = p->next;
        free(p);
        p = q;
    }
}


int  main() {
    LNode* head;

    head = creat_linklist(6);
    if (NULL == head)
        return -1;

    if (is_palindrome(head))
        printf("Yes\n");
    else
        printf("No\n");

    destroy_linklist(head);

    return 0;
}
