#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


/*
 * min()/max()/clamp() macros that also do
 * strict type-checking.. See the
 * "unnecessary" pointer comparison.
 */
 /*void) (&_x == &_y);使得，如果_x和_y的类型不一样，
 其指针类型也会不一样，2个不一样的指针类型进行比较操作，
 则会引起编译器产生一个编译警告，提示你这两个值的类型不同。*/
#define min(x, y) ({                \
    typeof(x) _min1 = (x);          \
    typeof(y) _min2 = (y);          \
    (void) (&_min1 == &_min2);      \
    _min1 < _min2 ? _min1 : _min2; })

#define max(x, y) ({                \
    typeof(x) _max1 = (x);          \
    typeof(y) _max2 = (y);          \
    (void) (&_max1 == &_max2);      \
    _max1 > _max2 ? _max1 : _max2; })

#define min3(x, y, z) ({            \
    typeof(x) _min1 = (x);          \
    typeof(y) _min2 = (y);          \
    typeof(z) _min3 = (z);          \
    (void) (&_min1 == &_min2);      \
    (void) (&_min1 == &_min3);      \
    _min1 < _min2 ? (_min1 < _min3 ? _min1 : _min3) : \
        (_min2 < _min3 ? _min2 : _min3); })

#define max3(x, y, z) ({            \
    typeof(x) _max1 = (x);          \
    typeof(y) _max2 = (y);          \
    typeof(z) _max3 = (z);          \
    (void) (&_max1 == &_max2);      \
    (void) (&_max1 == &_max3);      \
    _max1 > _max2 ? (_max1 > _max3 ? _max1 : _max3) : \
        (_max2 > _max3 ? _max2 : _max3); })
int main()
{

}