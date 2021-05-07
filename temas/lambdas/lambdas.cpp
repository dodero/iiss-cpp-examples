#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

int main(){
    list<int> mylist{1, 2, 3, 4, 5, 6};
    int total = 0;

    // Generic lambda
    for_each(
        begin(mylist),
        end(mylist),
        [&total](auto x) { total += x; }
    );
    cout << "Generic Lambda: " << total << endl;

    // Variadic Generic Lambda
    auto accumulator = [&total](auto... params){
        auto increment = [&total](auto elem){
            total += elem;
        };
        (increment(params), ...);
    };
    accumulator(1,2,3,4,5,6);
    cout << "Variadic Generic Lambda: " << total << endl;

    // Mutable
    auto increment = [total](auto x) mutable{
        total += x;
        cout << "Mutable Lambda Inside: " << total << endl;
    };
    increment(4);
    cout << "Mutable Lambda Outside: " << total << endl;
    
    return 0;
}