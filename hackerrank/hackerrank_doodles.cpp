/**
    @author [mst]
    @brief  HackerRank solutions doodle space


    @version 0.1 2022.12
*/


////////////////// LIBS
#include <iostream>            // usage of console prints
#include <vector>
#include <bits/stdc++.h>        // usage of: find_if
#include <stdio.h>
#include <stdlib.h>

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

int formingMagicSquare() {//vector<vector<int>> s) {

    // input string
    // vector<vector<int>> s{
    //     { 1, 2, 3 }, //comma separated lists
    //     { 5, 6, 7 },
    //     { 8, 9, 3 }
    // };
    vector<vector<int>> s{
        {4,9,2},
        {3,5,7},
        {8,1,5}
    };

    print2Dvec (s);

    // premeditated eight possible magic squares
    // const int magic_squares_3x3[8][9] = {
    //     {8, 1, 6, 3, 5, 7, 4, 9, 2},
    //     {4, 3, 8, 9, 5, 1, 2, 7, 6},
    //     {2, 9, 4, 7, 5, 3, 6, 1, 8},
    //     {6, 7, 2, 1, 5, 9, 8, 3, 4},
    //     {6, 1, 8, 7, 5, 3, 2, 9, 4},
    //     {8, 3, 4, 1, 5, 9, 6, 7, 2},
    //     {4, 9, 2, 3, 5, 7, 8, 1, 6},
    //     {2, 7, 6, 9, 5, 1, 4, 3, 8}
    // };

    vector<vector<vector<int>>> squares_3x3{
        {{8, 1, 6}, {3, 5, 7}, {4, 9, 2}},
        {{4, 3, 8}, {9, 5, 1}, {2, 7, 6}},
        {{2, 9, 4}, {7, 5, 3}, {6, 1, 8}},
        {{6, 7, 2}, {1, 5, 9}, {8, 3, 4}},
        {{6, 1, 8}, {7, 5, 3}, {2, 9, 4}},
        {{8, 3, 4}, {1, 5, 9}, {6, 7, 2}},
        {{4, 9, 2}, {3, 5, 7}, {8, 1, 6}},
        {{2, 7, 6}, {9, 5, 1}, {4, 3, 8}}
    };

    int min_cost = 999;

    // calculate deviation from each possible magic square
    for (int option = 0; option < 8; option++) {
        int cost = 0;
        for (int i = 0; i < 3; i ++)
            for (int j = 0; j < 3; j++)
                cost += abs(s[i][j] - squares_3x3[option][i][j]);
        if (cost < min_cost) min_cost = cost;
    }

    cout << "result: " << min_cost << endl;
    return min_cost;
}

// multiplication of two long ass numbers represented as strings
string longMultiply(string &num1, string num2) {
    string res;
    int x, y, c, n1_length, n2_length, l, k, sum, carry;
    char digit;

    n1_length = num1.size() - 1;
    n2_length = num2.size() - 1;
    carry = 0;

    // we start from the rightmost digit of each long number
    for (int i_n1 = n1_length; i_n1 >= 0; i_n1--) {
        for (int i_n2 = n2_length; i_n2 >= 0; i_n2--) {
            l = res.size() - 1;
            x = num1[i_n1] - '0';
            y = num2[i_n2] - '0';
            k = (n1_length-i_n1) + (n2_length-i_n2);

            if (l >= k)
                c = res[l-k] - '0';
            else
                c = 0;

            sum = x * y + c + carry;
            carry = sum / 10;
            digit = char(sum % 10 + '0');

            if (l >= k)
                res[l-k] = digit;
            else
                res.insert(0, &digit, 1);

            if (i_n2 == 0 && carry) {
                digit = char(carry + '0');
                res.insert(0, &digit, 1);
                carry = 0;
            }
        }
    }

    return res[0] == '0' ? "0" : res;
}
void extraLongFactorials(int n) {
    string s = "1";
    for (int i = 1; i <= n; ++i) {
        // this is the actual n! = n*(n-1)*(n-2)*...*1 (in reverse)
        s = longMultiply(s, to_string(i));
    }
    cout << s << endl;
}


int most_freq_idx(int *ar, int sz) {
    int max_val = -1;
    int max_idx = -1;

    for (int i=0; i<sz; i++)
        if (ar[i] > max_val) {
            max_val = ar[i];
            max_idx = i;
        }

    return max_idx;
}

int equalizeArray(vector<int> arr) {
    const int sz = 101; // add 1 to hold att[x]=100 safely
    int map[sz] = {0};

    // build each-num occurence map
    for (auto it = arr.begin(); it != arr.end(); it++) {
        map[*it]++;
    }

    // find the most frequent
    int dominant = most_freq_idx(map, sz);

    return arr.size() - map[dominant];
}



void rotateString(char * a, int n, int flag){
    if (flag == 0) return; // base case

    // allocate a side char array to build the desired rotation
    char *temp = (char*) malloc(sizeof(char)*(n+1));


    // this
    char *rotating = a + (int)((flag < 0)?(-flag):(n-flag));
    char *rotated_p = rotating;

    char *temp_p = temp;
    // copy from start position
    while (*rotated_p) {
        *temp_p = *rotated_p;
        rotated_p++;
        temp_p++;
    }

    char *p = a;    // conserve original pointer
    // copy remainder
    while (p != rotating) {
        *temp_p = *p;
        p++;
        temp_p++;
    }

    // we can return temp here, but we'll copy to the original addresses
    p = a;
    temp_p = temp;
    while (*p) {
        *p = *temp_p;
        p++;
        temp_p++;
    }

    free(temp);

}

bool isReverseNumber(int num) {
    int rev = 0;

    int digit = 0;
    while (0 != num) {
        digit = num %10;
        rev = rev*10 + digit;
        num /= 10;
    }
    return (rev == num);
}

// [wip] typedeffing
struct node {
    int key;
    struct node *next;
};

// reverse a linked list
node* reverse2(struct node *n) {
    if(!n->next) return n;
        struct node *ret = (struct node *)malloc(sizeof(struct node));
        ret = reverse2(n->next);
        n->next->next = n;
        n->next = NULL;
        return ret;
}

// reverse a linked list (iterative)
struct node * reverse(struct node *n) {
    if(n == NULL) return NULL;
        struct node *p,*q,*r;
        p = n;
        q = NULL;
        r = NULL;

        while (p) {
            r = q;
            q = p;
            p = p->next;
            q->next = r;
        }

        return q;
}

// add a new node to a given list with a value 'val'
void addToTail(struct node *head, int val) {
    struct node *NewNode = (struct node *)malloc(sizeof(struct node));
    NewNode->key = val;
    NewNode->next = NULL;

    if (head == NULL) {
        head = NewNode;
        return;
    }

    struct node *ptr = head;
    while (ptr && ptr->next) {
        ptr = ptr->next;
    }
    ptr->next = NewNode;

    return;
}


int sumLinkedList(struct node * h1, struct node * h2) {
    // we will reverse the two lists for an extra O(n) runtime
    h1 = reverse(h1);
    h2 = reverse(h2);

    // assisting variables
    int res = 0; // resulting number
    int sum = 0;
    int carry = 0;

    while (h1 && h2) {
        sum = h1->key + h2->key + carry;
        res = res + (0==res)? sum%10 : (10*(sum%10));   // [here]
        // use for https://leetcode.com/problems/add-two-numbers-ii/solutions/
        carry = sum / 10;

        h1=h1->next;
        h2=h2->next;
    }

    // consider the remainder
    struct node *rem;
    if (h1) {
        rem = h1;
    } else {
        rem = h2;
    }

    while (rem) {
        sum = rem->key + carry;
        res = res + 10*(sum%10);
        carry = sum / 10;

        rem = rem->next;
    }

    if (carry) res = res + carry*10;

    return res;
}


////////////////// DRIVER
int main() {
	cout << "[mst] hackerrank doodle" << endl;

    // cout << "hackerrank simpleArraySum" << endl;
    // int result = 0;
    // result = simpleArraySum({1,3});
    // cout << result << endl;


    // cout << "hackerrank miniMaxSum" << endl;
    // miniMaxSum({1, 2, 3, 4, 5});
    // miniMaxSum({156873294, 719583602, 581240736, 605827319, 895647130});


    // cout << "hackerrank countingSort" << endl;
    // vector<int> arr3 = {63,25,73,1,98,73,56,84,86,57,16,83,8,25,81,56,9,53,98,67,99,12,83,89,80,91,39,86,76,85,74,39,25,90,59,10,94,32,44,3,89,30,27,79,46,96,27,32,18,21,92,69,81,40,40,34,68,78,24,87,42,69,23,41,78,22,6,90,99,89,50,30,20,1,43,3,70,95,33,46,44,9,69,48,33,60,65,16,82,67,61,32,21,79,75,75,13,87,70,33};
    // vector<int> arr3_res = countingSort(arr3);
    // printVec(arr3_res);


    // https://www.hackerrank.com/challenges/utopian-tree/problem
    // cout << "hackerrank utopianTree" << endl;
    // cout <<  utopianTree(10) << endl;

    // cout << "hackerrank formingMagicSquare" << endl;
    // formingMagicSquare();

    // cout << "hackerrank extraLongFactorials" << endl;
    // extraLongFactorials(25);

    // cout << "hackerrank equalizeArray" << endl;
    // cout << equalizeArray({1,2,3,1,2,3,3,3}) << endl;


    // char *str = (char*)malloc(sizeof(char)*15);
    // strcpy(str, "I am very happy");
    // rotateString(str,15, 4);
    // free(str);


    // rafael test series
    // isReverseNumber(5005);



    // [here]
    //6258
    // struct node *h1;

    // manual 62
    struct node *h1 = (struct node *)malloc(sizeof(struct node));
    h1->key = 6;
    h1->next = (struct node *)malloc(sizeof(struct node));
    h1->next->key = 2;
    h1->next->next = NULL;


    // addToTail(h1,6);
    // addToTail(h1,2);
    // addToTail(h1,5);
    // addToTail(h1,8);

    //45
    // struct node *h2;

    // manual 98
    struct node *h2 = (struct node *)malloc(sizeof(struct node));
    h2->key = 9;
    h2->next = (struct node *)malloc(sizeof(struct node));
    h2->next->key = 8;
    h2->next->next = NULL;
    // addToTail(h1,4);
    // addToTail(h1,5);


    cout << sumLinkedList(h1, h2) << endl;







    return 0;
}



