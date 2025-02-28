# Notes
****
## Everything important about C++ 98 & C++ 03.

1. C++ became international standardized in 1998. When people talk about C++ 03, they usually mean c++ 98. C++ 03 is a minor revision 

2. Core features of C++98/03 inlcludes Dealing with object lifetimes, having constructors, destructors, RAII. Using templates for generic programming. STL which includes containers, iterators, and algorithms. What was listed is the important parts of C++, it is esentially what makes C++ unqiue since C++ 98 is the first standardized version of C++. 

## Everything important about C++ 11.

1. Auto keyword, use "auto" when you don't care about what the type is. This additiona feature makes genric programming way easier to use. 

```

template<typename T>
void count_things(const std::vector<T> &vec, T value)
{
    const auto count = std:count(begin(vec), end(vec), value);
}
```

In the example above, we don't care what the iterator returns as long as it returns something. Let the compiler deduce what type it is.

2. Range for-loops

As a layer of abstraction, we don't care what type the current value is being indexed, we just want to get the output.

```
void do_things(const T &vec, int value)
{
    for (const auto &element : vec) 
        {
            // Do stuff here. 
        }
}
```

3. lambda

void count_things_less

4. variadic templates

template<typename ... T> 
void vall(const Func &function, const T & ... param) 
{
    function(param...);
}

