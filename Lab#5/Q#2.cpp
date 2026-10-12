
#include <iostream>
#include <queue>
using namespace std;

int findTheWin(int n, int k) {
    queue<int> q;

    for (int i = 1; i <= n; i++) {
        q.push(i);
    }

    while(q.size()>1){
     for (int i = 1; i < k; i++) {
            q.push(q.front());
            q.pop();
        }

        q.pop();
    }
    
    return q.front();
}

int main() {
    int n = 5, k = 2;

    cout << findTheWin(n, k);

    return 0;
}
