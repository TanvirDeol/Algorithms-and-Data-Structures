#include <bits/stdc++.h>
using namespace std;

//Find number of ways a array of N numbers can reach a target T. 
//The numbers can be used unlimited times

void backtrack(vector<vector<int> >& list, vector<int> temp, vector<int> nums, int remain, int start) {
	if (remain < 0) return;
	//if you have reduced to zero, add the combination to the 2d list
	//and clear the combination
	if (remain == 0) { list.push_back(temp); temp.clear(); }
	else {
		//starts from 0, counts 
		for (int i = start; i < nums.size(); i++) {
			temp.push_back(nums[i]);
			//after element is added to temp, it calls the backtrack
			//again with the target reduced
			//it calls i for start since you can use a element more than once
			//if this was distinct elements, start = i+1
			backtrack(list, temp, nums, remain - nums[i], i);
			//if the last element you added doesnt work(below 0)
			//it removes that answer
			temp.erase(temp.begin() + temp.size() - 1);
		}

	}
}


vector<vector<int> > combSum(vector<int> nums, int T) {
	//new list created to hold possibilities
	vector<vector<int> > list;
	//sorting numbers helps reduce small at first, 
	//then move onto bigger numbers, answers chronologically
	sort(nums.begin(), nums.end());
	//this vector holds a single combination
	vector<int> temp;
	backtrack(list, temp, nums, T, 0);
	return list;
}

int main() {
	//collect input
	int cands = 0, T = 0;
	cin >> cands >> T;
	vector<int> nums;
	for (int i = 0; i < cands; i++) {
		int inp = 0; cin >> inp;
		nums.push_back(inp);
	}
	//run method
	vector<vector<int> >ways = combSum(nums, T);
	//print answers
	for (int i = 0; i < ways.size(); i++) {
		for (int j = 0; j < ways[i].size(); j++) {
			cout << ways[i][j] << " ";
		}cout << endl;
	}

	return 0;
}