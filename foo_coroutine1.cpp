#include <iostream>
#include <coroutine>
using namespace std;

struct ReturnObject
{
    struct promise_type {
            std::suspend_never initial_suspend() { return{};}
            std::suspend_never final_suspend() noexcept { return{};}

            ReturnObject get_return_object() { return ReturnObject{std::coroutine_handle<promise_type>::from_promise(*this)};}
            void unhandled_exception() {}

   };
   std::coroutine_handle<> handle;
   ReturnObject(std::coroutine_handle<> handle_) : handle{handle_}
   {
       
   }
};

ReturnObject foo()
{
    //co_await 10;
    std::cout <<"\n1. Hello from foo\n";
    co_await std::suspend_always{};
    std::cout <<"2. Hi from coroutine\n";
    co_await std::suspend_always{};
    std::cout <<"3. Hi from coroutine\n";
    //co_yield 10;
    //co_routine
}

int main() {
    // Write C++ code here
    std::cout << "Hello world!";
    ReturnObject retObj = foo();
    retObj.handle.resume();
    retObj.handle.resume();
    //retObj.handle();
    //retObj.handle();
    std::cout << std::boolalpha <<retObj.handle.done() << "\n";
    return 0;
}

