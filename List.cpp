#include<vector>
 
using namespace std;

struct RandomListNode 
{//Definition for singly-linked list with a random pointer.
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(nullptr), random(nullptr) {}
};

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

void deleteNode(ListNode* node) 
{//删除指定节点
	if (node == nullptr || node->next == nullptr)
	{
		node = nullptr;
		return;
	}
	
	node->val = node->next->val;
	node->next = node->next->next;
}
ListNode* middleNode(ListNode* head) 
{//链表中点
	if (!head || !head->next)
		return head;
	
	ListNode* pfast = head, *pslow = head;
	while (pfast->next != nullptr && pfast->next->next != nullptr)
	{
		pslow = pslow->next;
		pfast = pfast->next->next;
	}
	return pfast->next == nullptr? pslow : pslow->next;
}

ListNode* reverseList(ListNode* head) 
{ //循环
	ListNode* pcur = head, *prev = nullptr;
	while (pcur)
	{
		ListNode* nextTemp  = pcur->next;
		pcur->next = prev;
		prev = pcur;
		pcur = nextTemp ;  
	}
	
	return prev;
}
ListNode* reverseList2(ListNode* head) 
{ //递归
	if (head == nullptr || head->next == nullptr)
		return head;
	
	ListNode* p = reverseList(head->next);
	head->next->next = head;
	head->next = nullptr;
	
	return p;
}
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
{//dummy list，新建一个链表，然后两个链表中从头各取一个元素进行比较，小的写入新链表，直到结束，返回dummy.next
	ListNode dummy(0);
	ListNode* p = &dummy;
	
	while (l1 && l2)
	{
		if (l1->val >= l2->val) 
		{
			p->next = l2;
			l2 = l2->next;
		}
		else
		{
			p->next = l1;
			l1 = l1->next;
		}
		p = p->next;     
	}
	
	p->next = l1 ? l1 : l2; 
	return dummy.next;
}

ListNode* mergeTwoLists2(ListNode* l1, ListNode* l2) 
{//recursion，代码简洁，但空间复杂度高O(n)
	if (l1 == nullptr)
		return l2;
	else if (l2 == nullptr)
		return l1;
	
	ListNode* pHead = nullptr;
	if (l1->val < l2->val)
	{
		pHead = l1;
		pHead->next = mergeTwoLists(l1->next, l2);
	}
	else
	{
		pHead = l2;
		pHead->next = mergeTwoLists(l1, l2->next);
	}
	return pHead;
}
bool hasCycle(ListNode *head) 
{//pfast , pslow
	if (!head || !head->next) return false;
	
	ListNode* pfast = head, *pslow = head;
	
	while (pfast && pfast->next)
	{
		pfast = pfast->next->next;
		pslow = pslow->next;
		if (pfast == pslow)
			return true;
	}
	return false;
}

bool isPalindrome(ListNode* head)
{//O(1)的空间，将后半段的链表翻转一下，这样我们就可以按照回文的顺序比较了
	if (head == nullptr || head->next == nullptr)
		return true;
	
	ListNode* fast = head, *slow = head;
	while (fast->next != nullptr && fast->next->next != nullptr)
	{
		slow = slow->next;
		fast = fast->next->next;
	}

	slow->next = reverseList(slow->next);
	slow = slow->next;
	
	while (slow != nullptr)
	{
		if (slow->val != head->val) return false;
		head = head->next;
		slow = slow->next;
	}
	return true;
}
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
{//Two Pointers
	if (!headA || !headB) return nullptr;
	ListNode* p1 = headA;
	ListNode* p2 = headB;
	ListNode* pEnd = nullptr;
	while (p1 != p2)
	{
		if (p1->next == nullptr)
		{
			if (pEnd != nullptr && p1 != pEnd) return nullptr;
			pEnd = p1;
			p1 = headB;
		}
		else 
			p1 = p1->next;
		
		if (p2->next == nullptr)
		{
			if (pEnd != nullptr && p2 != pEnd) return nullptr;
			pEnd = p2;
			p2 = headA;
		}
		else 
			p2 = p2->next; 
	}   
	return p1;
}

ListNode* oddEvenList(ListNode* head) 
{//O(1) space complexity and O(nodes) time complexity
	if (!head || !head->next) return head;
	
	ListNode* odd = head, *even = head->next;
	ListNode* evenHead = even;
	while (even && even->next)
	{
		odd->next = even->next;
		odd = even->next;
		even->next = odd->next;
		even = odd->next;    
	}
	odd->next = evenHead;
	return head;
}

ListNode* removeNthFromEnd(ListNode* head, int n) 
{//注意去除第一个节点比较特殊，
	ListNode dummy(0);
	dummy.next = head;
	ListNode* pfast = &dummy, *pslow = &dummy;
	for (int i = 1; i <= n + 1; i++) 
	{
			pfast = pfast->next;
	}

	while (pfast != nullptr)
	{
		pfast = pfast->next;
		pslow = pslow->next;
	}

	pslow->next = pslow->next->next;
	return dummy.next;
}

ListNode* sortList(ListNode* head) 
{//链表的二路归并排序
	if (!head || !head->next) return head;
	
	ListNode* pfast = head, *pslow = head, *prev = nullptr;
	while (pfast != nullptr && pfast->next != nullptr)
	{
		prev = pslow;
		pslow = pslow->next;//slow指针后移一个数据
		pfast = pfast->next->next;//fast指针后移两个数据
	}
	prev->next = nullptr;
	
	ListNode* l1 = sortList(head);
	ListNode* l2 = sortList(pslow);
	
	return mergeTwoLists(l1, l2);  
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{//(2 -> 4 -> 3) + (5 -> 6 -> 4)
	ListNode *rp = new ListNode(0);
	ListNode *p = rp,*p1 = l1,*p2 = l2;
	int cnt = 0;
	while (p1 != nullptr || p2 != nullptr || cnt == 1)
	{
		int val = cnt;
		if (p1 != nullptr)
		{
			val += p1->val;
			p1 = p1->next;
		}
		if (p2 != nullptr)
		{
			val += p2->val;
			p2 = p2->next;
		}
		p->val = val % 10;
		
		if (val > 9) 
			cnt = 1;
		else 
			cnt = 0;

		if (p1 == nullptr && p2 == nullptr && (cnt == 0))
			break;
		ListNode* pnext = new ListNode(0);
		p->next = pnext;
		p = p->next;
	}

	return rp;
}

RandomListNode *copyRandomList(RandomListNode *head) 
{
	if (head == nullptr)
		return nullptr;
	//copy next
	RandomListNode* phead = head;
	while (phead)
	{
		RandomListNode* tmp = new RandomListNode(phead->label);
		tmp->next = phead->next;
		phead->next = tmp;
		phead = tmp->next;
	}
	//copy random
	phead = head;
	RandomListNode* copy = nullptr;
	while (phead)
	{
		copy = phead->next;
		if (phead->random) 
			copy->random = phead->random->next;
		phead = copy->next;
	}
	//split
	phead = head;
	RandomListNode* copyHead = head->next;
	while (phead)
	{
		copy = phead->next;
		phead->next = copy->next;
		phead = phead->next;
		if (phead)
			copy->next = phead->next;
	}

	return copyHead;
}

ListNode* mergeKLists(vector<ListNode*>& lists, int start, int end)
{
	// base cases
	if (start == end) 
		return lists[start];
	else if (start > end) 
		return nullptr;
	// divide and conquer
	int mid = (start + end) / 2;
	ListNode* l1 = mergeKLists(lists, start, mid);
	ListNode* l2 = mergeKLists(lists, mid + 1, end);
	
	return mergeTwoLists(l1, l2);
}
ListNode* mergeKLists(vector<ListNode*>& lists) 
{//重载mergeKLists(vector<ListNode*>& lists, int start, int end)
	if (lists.empty()) return nullptr;
	return mergeKLists(lists, 0, lists.size()-1);
}
