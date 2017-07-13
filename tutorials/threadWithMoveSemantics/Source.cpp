#include <iostream>
#include <thread>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

void task(int &i) {
    cout << "worker : " << i << endl;
}

int main() {
    // vector that stores the threads
    vector<thread> workers;
    for (int i = 0; i<5; i++) {
        auto t = thread(&task, ref(i)); 
        workers.push_back(move(t));
    }
    cout << "main thread" << endl;

    for_each(workers.begin(), workers.end(), [](thread &t)
    {
        assert(t.joinable());
        t.join();
    });

    return 0;
}
