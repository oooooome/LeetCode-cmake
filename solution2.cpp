
#include <iostream>

//Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution2 {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* res = new ListNode((l1->val + l2->val) % 10);
		addNode(l1->next, l2->next, (l1->val + l2->val) / 10, res);
		return res;

	}

	void addNode(ListNode* l1, ListNode* l2, int i, ListNode* forwardNode)
	{
		
		ListNode l1o;
		ListNode l2o;

		if (l1 != nullptr)
		{
			l1o.val = l1->val;
			l1o.next = l1->next;
		}else if(i == 0)
		{
			forwardNode->next = l2;
			return;
		}
		if (l2 != nullptr)
		{
			l2o.val = l2->val;
			l2o.next = l2->next;
		}else if(i == 0)
		{
			forwardNode->next = l1;
			return;
		}

		int One = (l1o.val + l2o.val + i) % 10;
		int Ten = (l1o.val + l2o.val + i) / 10;

		ListNode* res = new ListNode(One);
		forwardNode->next = res;
		if (One == 0 && Ten == 0 && l1->next == nullptr && l2->next == nullptr)
		{
			return;
		}
		else
		{
			addNode(l1o.next, l2o.next, Ten, res);

		}


		
	}
};

int main()
{
	ListNode l11{ 1, nullptr };
	ListNode l12{ 6, &l11 };
	ListNode l13{ 0, &l12 };
	ListNode l14{ 3, &l13 };
	ListNode l15{ 3, &l14 };


	/*[1, 6, 0, 3, 3, 6, 7, 2, 0, 1]
	[6, 3, 0, 8, 9, 6, 6, 9, 6, 1]*/

	ListNode l21{ 6, nullptr };
	ListNode l22{ 3, &l21 };
	ListNode l23{ 0, &l22 };
	ListNode l24{ 8, &l23 };
	ListNode l25{ 9, &l24 };
	ListNode* l1 = &l15;
	ListNode* l2 = &l25;

	Solution2 s{};
	auto res = s.addTwoNumbers(l1, l2);
	for (;;)
	{
		if (res == nullptr)
		{
			break;;
		}
		std::cout << res->val;
		res = res->next;

	}
	return 0;
}