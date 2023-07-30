#pragma once

#include <iostream>
using namespace std;

template <class t>
class my_shared_ptr
{
    t* _ptr;
    int* _counter;;

public:
    my_shared_ptr() { _ptr = nullptr; }
    my_shared_ptr(t* ptr)
    {
        int* _counter = new int(0)
            _ptr = ptr;
        *_counter++;
    }
    my_shared_ptr(my_shared_ptr& other)
    {
        _ptr = other._ptr;
        *_counter++;
    }


    my_shared_ptr operator=(my_shared_ptr& other)
    {
        _ptr = other._ptr;
        *_counter++;
        return this;
    }


    inline t* get()const { return this->_ptr; }
    inline int use_count() { return *_counter; }

    void reset()
    {
        if (*_counter == 1)
        {
            *_counter = 0;
            _ptr = nullptr;
        }
        else
        {

            *_counter--;
        }
    }

    template<class t>
    friend ostream& operator<<(ostream& os, my_shared_ptr<t>& other);
    t operator*() { return *_ptr; }

    bool operator==(my_shared_ptr&& other)
    {
        return _ptr == other._ptr;
    }

    bool operator!=(my_shared_ptr&& other)
    {
        return _ptr != other._ptr;
    }
    ~my_shared_ptr()
    {

        if (*_counter == 1)
        {
            *_counter = 0;
            _ptr = nullptr;
        }
        else
        {

            *_counter--;
        }

    }

    bool operator bool(my_shared_ptr& other)
    {
        return other._ptr != nullptr;
    }

};
template<class t>
ostream& operator<<(ostream& os, my_shared_ptr<t>& other)
{
    os << "Address: " << (other._ptr != nullptr ? other._ptr : NULL) << endl;
    os << "Value: " << (other._ptr != nullptr ? *other._ptr : NULL) << endl;
    return os;
}


//#########################################
//For example
//##########################################
//int main()
//{
//    my_shared_ptr<int> pt1(new int(10));
//    cout << pt1 << endl;
//    my_shared_ptr<int> pt2(pt1);
//    cout << pt2.use_count();
//}
