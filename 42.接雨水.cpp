#include <string>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
	int trap(vector<int>& height) {
		vector<int>s;
		if (height.size() <= 2) {
			return 0;
		}
		int total_rain = 0;
		for (int i = 0; i < height.size(); i++) {
			s.push_back(height[i]);
			//print(s);
			if (s.size() <= 2)continue;
			int lastwall = find_wall(s); //找到当前stack里前面最高的一个墙壁(要比curwall小的)
			int curwall = i;
			//cout << "lastwall = "<< lastwall << "  curwall = " << curwall << endl;
			//cout << "lastwall_height = " << s[lastwall] << "  curwall_height  = " << s[curwall] << endl;
			int minheight = s[lastwall] < s[curwall] ? s[lastwall] : s[curwall];
			//cout << "minheight = " << minheight << endl;
			if (minheight > 0 && s[curwall]>s[curwall-1]) {
				int rain = fill_wall(s, lastwall, curwall);//当前s里回溯填水
				total_rain += rain;
			}
		}
		return total_rain;
	}
	int fill_wall(vector<int>& s, int cur, int last) {
		cout << "====fill_wall:" << cur << " " << last << endl;
		int min_height = s[cur] < s[last] ? s[cur] : s[last];
		cout << "minheight = " << min_height << endl;
		int total_loss = 0;
		for (int j = last - 1; j >= cur + 1; j--) {
			if (s[j] > min_height)continue;
			int loss = min_height - s[j];
			total_loss += loss;
			s[j] = min_height;
		}
		cout << "total loss:" << total_loss << endl;
		return total_loss;
	}

	int find_wall(vector<int>& s) {
		int cur_height = s[s.size() - 1];
		int max_height = 0;
		int max_pos = 0;
		for (int i = s.size() - 2; i >= 0; i--) {
			if (s[i] > max_height &&s[i] != 0) {
				max_height = s[i];
				max_pos = i;
			}
		}
		return max_pos;
	}
	
	void print(vector<int>& s) {
		vector<int>::iterator p;
		for (p = s.begin(); p != s.end(); p++) {
			cout << (*p) << " ";
		}
		cout << endl;

	}
};


int main() {
	vector <int> arr = { 5,4,1,2 };
	Solution a;
	int flag = a.trap(arr);
	cout << "flag = "<<flag << endl;
		
	system("pause");
}

