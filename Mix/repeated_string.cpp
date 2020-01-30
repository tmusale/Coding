#include <iostream>
#include <string>
using namespace std;


// Complete the repeatedString function below.
long long repeatedString(string s, long long n) {
    long size = s.size();
    //cout << size << endl;
    //cout << s[0] << endl;
    long long count = 0;

    for (long long i = 0; i < size; i++) {
            if (s[i] == 'a') {
                count++;
            }
    }
        string s1 = s;
        long long add = n / size;
        long rem = n % size;
        //cout << "add ="<<add << endl;
        //for (int i = 0; i < add; i++) {
         //   s1.append(s);
        //}
        //cout << s1 << endl;
        //cout << "count = " << count << endl;
        count = count * add;
        //cout << "count = "<< count << endl;
        for (int i = 0; i < rem; i++) {
            if (s[i] == 'a') {
                count++;
            }
        }
    

    return count;
}

int main()
{
    string s;
    long long n;

    getline(cin, s);
    cin >> n;

    long long result = repeatedString(s, n);

    cout << result << endl;

    return 0;
}