/**
    @author [mst]
    @brief  leetcode series
    232. Implement Queue using Stacks
    Implement a first in first out (FIFO) queue using only two stacks.
    The implemented queue should support all the functions of a normal queue (push, peek, pop, and empty).

    gains:
    -stack and queue basics


    @version 0.1 2023.06
*/



////////////////// LIBS
#include <iostream>     // usage of console prints
#include <vector>
#include <algorithm>    // usage of sort
#include <cstring>      // use of memset
#include <numeric>      // use of accumulate
using namespace std;


////////////////// DECL_IMPL

//
//
// sub 100 15
class MyQueue {
private:
  const int MAX_SIZE = 100;
  vector<int> stackIn;
  vector<int> stackOut;
public:
    MyQueue() {
      stackIn.reserve( MAX_SIZE );
      stackOut.reserve( MAX_SIZE );
    }

    void push(int x) {
      stackIn.push_back(x);
    }

    int pop() {
      if (stackOut.empty()) {
        while (!stackIn.empty()) {
          stackOut.push_back(stackIn.back());
          stackIn.pop_back();
        }
      }
      int ans = stackOut.back();
      stackOut.pop_back();
      return ans;
    }

    int peek() {
      if (stackOut.empty()) {
        while (!stackIn.empty()) {
          stackOut.push_back(stackIn.back());
          stackIn.pop_back();
        }
      }
      int ans = stackOut.back();
      return ans;


    }

    bool empty() {
      return (max(stackIn.size(),stackOut.size()) == 0);
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

////////////////// DRIVER
int main()
{
    int x = 4;
    MyQueue* obj = new MyQueue();
    obj->push(x);
    int param_2 = obj->pop();
    int param_3 = obj->peek();
    bool param_4 = obj->empty();

    return 0;
}