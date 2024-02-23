#include <iostream>
#include <coroutine>
using namespace std;

struct returnObject
{
    struct promise_type {
            std::suspend_never initial_suspend() { return{};}
            std::suspend_never final_suspend() noexcept { return{};}

            returnObject get_return_object() { return {};}
            void unhandled_exception() {}

   };
};

returnObject foo()
{
    //co_await 10;
    std::cout <<"\n1. Hello from foo\n";
    co_await std::suspend_always{};
    std::cout <<"2. Hi from coroutine\n";
    //co_yield 10;
    //co_routine
}

int main() {
    // Write C++ code here
    std::cout << "Hello world!";
    foo();

    return 0;
}
