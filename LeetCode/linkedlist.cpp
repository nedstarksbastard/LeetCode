#include "linkedlist.h"

//Definition for singly-linked list.


class Solution {
public:

	string listNodeToString(ListNode* node) {
		if (node == nullptr) {
			return "[]";
		}

		string result;
		while (node) {
			result += to_string(node->val) + ", ";
			node = node->next;
		}
		return "[" + result.substr(0, result.length() - 2) + "]";
	}

	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		bool bigTen = false;
		ListNode*tmp = new ListNode(0);
		ListNode*result = tmp;
		while (!(l1 == nullptr&&l2 == nullptr))
		{
			int a, b;
			if (l1 == nullptr)
				a = 0;
			else
			{
				a = l1->val;
				l1 = l1->next;
			}
			if (l2 == nullptr)
				b = 0;
			else
			{
				b = l2->val;
				l2 = l2->next;
			}
			int val = a + b;
			if (bigTen)
			{
				val++;
				bigTen = false;
			}
			if (val >= 10)
			{
				bigTen = true;
				val %= 10;
			}
			string out = listNodeToString(tmp);
			cout << out << endl;
			result->next = new ListNode(val);
			result = result->next;
		}
		if (bigTen)
		{
			result->next = new ListNode(1);
			result = result->next;
			bigTen = false;
		}

		result = tmp->next;
		delete tmp;
		tmp = nullptr;
		return result;

	}


	void trimLeftTrailingSpaces(string &input) {
		input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
			return !isspace(ch);
		}));
	}

	void trimRightTrailingSpaces(string &input) {
		input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
			return !isspace(ch);
		}).base(), input.end());
	}

	vector<int> stringToIntegerVector(string input) {
		vector<int> output;
		trimLeftTrailingSpaces(input);
		trimRightTrailingSpaces(input);
		input = input.substr(1, input.length() - 2);
		stringstream ss;
		ss.str(input);
		string item;
		char delim = ',';
		while (getline(ss, item, delim)) {
			output.push_back(stoi(item));
		}
		return output;
	}

	ListNode* stringToListNode(string input) {
		// Generate list from the input
		vector<int> list = stringToIntegerVector(input);

		// Now convert that list into linked list
		ListNode* dummyRoot = new ListNode(0);
		ListNode* ptr = dummyRoot;
		for (int item : list) {
			ptr->next = new ListNode(item);
			ptr = ptr->next;
		}
		ptr = dummyRoot->next;
		delete dummyRoot;
		return ptr;
	}
};


