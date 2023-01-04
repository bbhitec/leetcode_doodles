/**
    @author [mst]
    @file   <filenme>.<extension>    
    @brief  HackerRank solutions doodle space
    
    Gains:
    -

    @version 0.1 2022.12
*/


////////////////// LIBS
#include <iostream>            // usage of console prints
#include <vector>
#include <bits/stdc++.h>        // usage of: find_if

using namespace std;


////////////////// DECL_IMPL

int simpleArraySum(vector<int> ar) {
    int sum = 0;
    
    for (auto i = ar.begin(); i != ar.end(); ++i) {
        sum += *i;
    }
    
    return sum;
}

void miniMaxSum(vector<int> arr) {    
    long long sum_all = 0;

    for (auto n : arr) { 
        sum_all += n;
    }
    long long min = sum_all;
    long long max = 0;

    long long res = 0;
    for (auto n : arr) {
        res = sum_all - n;
        if (res < min) min = res;
        if (res > max) max = res;
    }

    cout << min << " " << max;
}


// some input processing from HR
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

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}


////////////////// DRIVER
int main()
{
	cout << "[mst] hackerrank doodle" << '\n' << '\n';

    // string ar_count_temp;
    // getline(cin, ar_count_temp);
    // int ar_count = stoi(ltrim(rtrim(ar_count_temp)));
    // string ar_temp_temp;
    // getline(cin, ar_temp_temp);
    // vector<string> ar_temp = split(rtrim(ar_temp_temp));
    // vector<int> ar(ar_count);
    // for (int i = 0; i < ar_count; i++) {
    //     int ar_item = stoi(ar_temp[i]);
    //     ar[i] = ar_item;
    // }

    int result = 0;

    // result = simpleArraySum({1,3});
    // cout << result << endl;

    // miniMaxSum({1, 2, 3, 4, 5});
    cout << sizeof(long) << endl;
    cout << sizeof(long long) << endl;
    cout << 8*8-1 << endl;
    cout << (1<<60) << endl;

    miniMaxSum({156873294, 719583602, 581240736, 605827319, 895647130});
    

    return 0;
}



