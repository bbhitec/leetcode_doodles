/**
    @author [mst]
    @brief  leetcode series
    1472_design_browser_history
    You have a browser of one tab where you start on the homepage and you can visit another url, get back in the history number of steps or move forward in the history number of steps.

    Implement the BrowserHistory class:
    BrowserHistory(string homepage) Initializes the object with the homepage of the browser.
    void visit(string url) Visits url from the current page. It clears up all the forward history.
    string back(int steps) Move steps back in history. If you can only return x steps in the history and steps > x, you will return only x steps. Return the current url after moving back in history at most steps.
    string forward(int steps) Move steps forward in history. If you can only forward x steps in the history and steps > x, you will forward only x steps. Return the current url after forwarding in history at most steps.

    gains:
    -[wip]


    @version 0.1 2023.03
*/



////////////////// LIBS
#include <iostream>            // usage of console prints
#include <vector>
using namespace std;


////////////////// DECL_IMPL


// snipped
//
// sub: 84 98
class BrowserHistory
{
public:
    BrowserHistory(string homepage)
    {
        visit(homepage);
    }

    void visit(string url)
    {
        if (++index < urls.size())
            urls[index] = url;
        else
            urls.push_back(url);
        lastIndex = index;
    }

    string back(int steps)
    {
        index = max(0, index - steps);
        return urls[index];
    }

    string forward(int steps)
    {
        index = min(lastIndex, index + steps);
        return urls[index];
    }

private:
    vector<string> urls;
    int index = -1;
    int lastIndex = -1;
};

////////////////// DRIVER
int main()
{
    BrowserHistory bh("www.home.com");
    cout << "visited home\n";

    bh.visit("www.youtube.com");
    bh.visit("www.facebook.com");
    bh.visit("www.instagram.com");

    cout << (bh.back(1));




    return 0;
}