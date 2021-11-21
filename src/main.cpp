// simulate <algorithm>

#include <cstdio>

namespace exp
{

    template <class T>
    void
    swap(T& x, T& y)
    {
        printf("generic exp::swap\n");
        T tmp = x;
        x = y;
        y = tmp;
    }

    template <class T>
    void algorithm(T* begin, T* end)
    {
        if (end-begin >= 2)
            swap(begin[0], begin[1]);
    }

}

template <class T>
struct A
{
    friend void swap(A<T>&, A<T>&)
    {
        printf("exp::swap(A, A)\n");
    }
};


/*template <class T>
void swap(A<T>&, A<T>&)
{
    printf("exp::swap(A, A)\n");
}*/

// exercise simulation

int main()
{
    A<int> a[2];
    exp::algorithm(a, a+2);
}