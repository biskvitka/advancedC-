#include <iostream>

using namespace std;

struct resumable_thing {
    struct promise_type;
    coroutine_handle<promise_type> _coroutine = nullptr;

    explicit resumable_thing(coroutine_handle<promise_type> coroutine)
        : _coroutine(coroutine)
    {
    }

    ~resumable_thing() {
        if (_coroutine) {
            _coroutine.destroy();
        }
    }
};

resumable_thing counter() {
    cout << "counter: called \n";
    for (unsigned i = 1; ; ++i) {
        co_await suspend_always{};
        cout << "counter: resumed (#" << i << ")\n";
    }
}


int main() {
    cout << "main: calling counter\n";
    resumable_thing the_counter = counter();
    cout << "main: resuming counter\n" ;
    the_counter.resume();
    the_counter.resume();
    cout << "main: done\n";
    return 0;
}
