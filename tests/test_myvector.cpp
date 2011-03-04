#include <boost/test/minimal.hpp>
#include "../myvector.h"

int test_main( int, char *[] )
{
    
    MyVector<int> myvector;
    int number = 4;
    myvector.push(&number);
    BOOST_REQUIRE( myvector.getsize() == 1);
    return 0;
}

