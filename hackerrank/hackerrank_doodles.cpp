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

// helper printer
void printVec(vector<int> ar) {
    for (auto n : ar) {
        cout << n << " " ;
    }
}

// alphabet size is 0 <= a[i] < 100
vector<int> countingSort(vector<int> arr) {
    vector<int> histo(100,0);
    for (auto x : arr) histo[x]++;

    vector<int> res = {};
    for (auto i=0; i<100; i++) {
        for (auto j=0; j<histo[i]; j++) res.push_back(i);
    }
    //printVec(res);
    return res;
}

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

//printing the 2D vector
void print2Dvec (vector<vector<int>> s) {
    cout << "printing the 2D vector\n";
    for (auto it : s) {
        //it is now an 1D vector
        for (auto ij : it) {
            cout << ij << " ";
        }
        cout << endl;
    }

}
    

///// individuals:

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

int utopianTree(int n) {
    
    int size = 1;
    int period = 0;
    
    while (n) {
        size = (period)?size+1:size*2;
        period ^= 1; 
        n--;        
    }
    
    return size;
}

int formingMagicSquare(vector<vector<int>> s) {
    //[here]
    int row_sum = 15;
    int all_sum = 45;
    int sum = 0;

    for (auto it : s) {
        for (auto ij : it) {
            // cout << ij << " ";
            sum+=ij;
        }
    }
    cout << sum << endl;
}

////////////////// DRIVER
int main()
{
	cout << "[mst] hackerrank doodle" << '\n' << '\n';
    int result = 0;

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

    // result = simpleArraySum({1,3});
    // cout << result << endl;

    // miniMaxSum({1, 2, 3, 4, 5});
    // miniMaxSum({156873294, 719583602, 581240736, 605827319, 895647130});

    // vector<int> arr3 = {63,25,73,1,98,73,56,84,86,57,16,83,8,25,81,56,9,53,98,67,99,12,83,89,80,91,39,86,76,85,74,39,25,90,59,10,94,32,44,3,89,30,27,79,46,96,27,32,18,21,92,69,81,40,40,34,68,78,24,87,42,69,23,41,78,22,6,90,99,89,50,30,20,1,43,3,70,95,33,46,44,9,69,48,33,60,65,16,82,67,61,32,21,79,75,75,13,87,70,33};
    // vector<int> arr3_res = countingSort(arr3);
    // printVec(arr3_res);

    //cout <<  utopianTree(1);

    vector<vector<int> > s{
        { 1, 2, 3 }, //comma separated lists
        { 5, 6, 7 },
        { 8, 9, 3 }
    };
    print2Dvec (s);
    cout << formingMagicSquare(s);
    

    return 0;
}



