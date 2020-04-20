#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

struct TrieNode {
	struct TrieNode* children[26];
	bool endWord;
};

TrieNode* getNode() {
	TrieNode* node = new TrieNode;
	node->endWord = false;
	for (int i = 0; i < 26; i++) {
		node->children[i] = NULL;
	}
	return node;
}
void insert(TrieNode* root, string s) {
	TrieNode* node = root;
	for (int i = 0; i < s.size(); i++) {
		int index = s[i] - 'a';
		if (node->children[index] == NULL)node->children[index] = getNode();
		node = node->children[index];
	}
	node->endWord = true;
}
bool search(TrieNode* root, string s) {
	TrieNode* node = root;
	for (int i = 0; i < s.size(); i++) {
		int index = s[i] - 'a';
		if (node->children[index] == NULL)return false;
		node = node->children[index];
	}
	return (node != NULL);
}
int main() {
	int N; cin >> N;
	vector<string>words(N);
	for (int i = 0; i < N; i++) cin >> words[i];
	TrieNode* root = getNode();
	for (int i = 0; i < words.size(); i++)insert(root, words[i]);
	while (true) {
		string s; cin >> s;
		if (s == "**")break;
		cout << search(root, s) << endl;
	}
	return 0;
}