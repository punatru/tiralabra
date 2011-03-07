#include <boost/test/minimal.hpp>
#include "../myvector.h"

int test_main( int, char *[] ){
    
    MyVector<int> myvector;
    int number = 4;
    myvector.push(&number);
    BOOST_REQUIRE(myvector.getsize() == 1);
    BOOST_REQUIRE((*myvector[0])==4);
    int number2 = 82;
    myvector.push(&number2);
    int number3 = 2;
    myvector.push(&number3);
    BOOST_REQUIRE(myvector.getsize() == 3);
    BOOST_REQUIRE((*myvector[0])==2);
    BOOST_REQUIRE((*myvector[1])==4);
    BOOST_REQUIRE((*myvector[2])==82);
    BOOST_REQUIRE(myvector.find('r')==0);
    BOOST_REQUIRE((*myvector.find('R'))==82);    
    myvector.empty();
    BOOST_REQUIRE(myvector.getsize()==0);

    return 0;
}

