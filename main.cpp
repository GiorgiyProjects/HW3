#include "pretty.h"
#include <vector>
#include <string>
#include<list>
#include "print_ip.hpp"

int main()
{
    print_ip( char{-1} ); // 255
    print_ip( short{0} ); // 0.0
    print_ip( int{2130706433} ); // 127.0.0.1
    print_ip( long{8875824491850138409} ); // 123.45.67.89.101.112.131.41
    print_ip( std::string{"Hello, World!"} ); // Hello, World!
    print_ip( std::vector<int>{100, 200, 300, 400} ); // 100.200.300.400
    print_ip( std::list<short>{400, 300, 200, 100} ); // 400.300.200.100
    //print_ip( std::make_tuple(123, 456, 789, 0) ); // 123.4
    return 0;
}


