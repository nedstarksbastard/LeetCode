#pragma once
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:

	string listNodeToString(ListNode* node);

	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);

	void trimLeftTrailingSpaces(string &input);

	void trimRightTrailingSpaces(string &input);

	vector<int> stringToIntegerVector(string input);

	ListNode* stringToListNode(string input);
};

