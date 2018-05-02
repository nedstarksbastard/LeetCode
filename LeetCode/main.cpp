#include "linkedlist.h"



int main() {
	string line;
	while (getline(cin, line)) {
		ListNode* l1 = Solution().stringToListNode(line);
		getline(cin, line);
		ListNode* l2 = Solution().stringToListNode(line);

		ListNode* ret = Solution().addTwoNumbers(l1, l2);

		string out = Solution().listNodeToString(ret);
		cout << out << endl;
	}
	return 0;
}
