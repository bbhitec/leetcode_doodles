#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));
    
    if      (1==n) cout << "one" << endl;
    else if (2==n) cout << "two" << endl;
    else if (3==n) cout << "three" << endl;
    else if (4==n) cout << "four" << endl;
    else if (5==n) cout << "five" << endl;
    else if (6==n) cout << "six" << endl;
    else if (7==n) cout << "seven" << endl;
    else if (8==n) cout << "eight" << endl;
    else if (9==n) cout << "nine" << endl;
    else if (n > 9) {
        cout << "Greater than 9" << endl;
    }

    // Write your code here

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
