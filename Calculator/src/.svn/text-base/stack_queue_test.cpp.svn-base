/**
 * @file stack_queue_test.cpp
 * @author Chase Geigle
 * @modified by Haozhen Ding
 * @date Summer 2014
 */

#include <cassert>
#include <memory>

#include "stack.h"
#include "queue.h"

using namespace cs225;

void test_stack_ints()
{
    stack<uint64_t> st;
    for (uint64_t i = 0; i <= 20; ++i)
        st.push(i);
    for (uint64_t i = 0; i <= 20; ++i)
    {
        assert(st.top() == 20 - i);
        st.pop();
    }
}

void test_queue_ints()
{
    queue<uint64_t> q;
    for (uint64_t i = 0; i <= 20; ++i)
        q.push(i);
    for (uint64_t i = 0; i <= 20; ++i)
    {
        assert(q.front() == i);
        q.pop();
    }
}

void test_stack_unique_ptr_ints()
{

    stack<std::unique_ptr<uint64_t>> st;
    assert(st.empty());

    for (uint64_t i = 0; i <= 20; ++i)
        st.push(std::make_unique<uint64_t>(i));
    assert(st.size() == 21);

    for (uint64_t i = 0; i <= 20; ++i)
    {
        assert(*st.top() == 20 - i);
        std::cout <<" TORF"<< std::endl;
        st.pop();
        assert(st.size() == 21 - i - 1);
    }
    assert(st.empty());

    try
    {
        st.pop();
    }
    catch(const std::runtime_error& er)
    {
    }
}

void test_queue_unique_ptr_ints()
{

    queue<std::unique_ptr<uint64_t>> q;
    assert(q.empty());

    for (uint64_t i = 0; i <= 20; ++i)
        q.push(std::make_unique<uint64_t>(i));
    assert(q.size() == 21);

    for (uint64_t i = 0; i <= 20; ++i)
    {
        assert(*q.front() == i);
        q.pop();
        assert(q.size() == 21 - i - 1);
    }
    assert(q.empty());

    try
    {
        q.pop();
    }
    catch(const std::runtime_error& er)
    {
    }

}

void test_special()
{

    stack<std::unique_ptr<uint64_t>> st;
    assert(st.empty());

    for (uint64_t i = 0; i <= 5; ++i)
        st.push(std::make_unique<uint64_t>(i));
    assert(st.size() == 6);

    auto p = std::move(st.top());
    assert(*p == 5);
    assert(!st.top());
    st.pop();
    assert(st.size() == 5);
    
}

void test_const_insert()
{
    stack<std::unique_ptr<uint64_t>> st;
    for (uint64_t i = 0; i <= 5000000; ++i)
        {st.push(std::make_unique<uint64_t>(i));
         std::cout << "text(" << ") ";}
}

int main()
{
    test_stack_ints();
    test_queue_ints();
    test_stack_unique_ptr_ints();
    test_queue_unique_ptr_ints();
    test_special();
    //test_const_insert();

    return 0;
}
