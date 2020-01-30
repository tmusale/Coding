#include <iostream>
#include <vector>
using namespace std;

void find_pairs(vector<int> v, int n)
{
	int count = 0;
    for (int i = 0; i < n; ++i)
    {
    	for (int j = i+1; j < n; j++) {
    		if ((v[i]+v[j] % 4) == 0) {
    			count++;
    		}
    	}
    }

    cout << count << endl;
}

int main() {
	int T;
	int n;
	int x;
	vector<int> v;
	
	cin >> T;
	while (T--) {
	    cin >> n;
	    for (int i = 0; i < n; i++) {
	        cin >> x;
	        v.push_back(x);
	    }
	    find_pairs(v, n);
	    v.clear();
	}
	return 0;
}