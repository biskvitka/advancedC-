#include <iostream>

using namespace std;

void printStuff() {
    cout << endl;
}

template <typename Tfirst, typename... Trest>
void printStuff(Tfirst first, Trest... rest) {
    cout << first << ' ';
    printStuff(rest...);
}

void example() {
    printStuff(3, 4.3, "foo", 42);
}

int main() {
    example();


    return 0;
}
