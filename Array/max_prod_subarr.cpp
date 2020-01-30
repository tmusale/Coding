#include <iostream>
#include <vector>
using namespace std;

int main()
{
	std::vector<int> v;
}

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int find_max_prod(vector<int> v, int n)
{
    int pow_size = pow(2, n);
    int count;
    int j;
    
    for (count = 0; count < pow_size; count++) {
        for (j = 0; j < n; j++) {
            if (count && (1 << j)) {
                cout << v[j];
            }
        }
        cout << endl;
    }
}

int main() 
{
	//code
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
	    
	    int res = find_max_prod(v, n);
	    cout << res << endl;
	    v.clear();
	}
	
	return 0;
}