#include <boost/test/minimal.hpp>
#include "../filewriter.h"
#include "../filereader.h"

int test_main( int, char *[] ){
    FileWriter filewriter("testing.txt");
    filewriter.write(117);
    filewriter.writeemptymark();
    filewriter.close();
    FileReader filereader("testing.txt");
    BOOST_REQUIRE(filereader.eof()==false);
    BOOST_REQUIRE(filereader.read()==117);
    BOOST_REQUIRE(filereader.eof()==false);
    BOOST_REQUIRE(filereader.read()==65535);
    filereader.read();
    BOOST_REQUIRE(filereader.eof()==true);
    filereader.close();
    return 0;
}
