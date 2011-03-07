#include <boost/test/minimal.hpp>
#include "../trie.h"

int test_main( int, char *[] ){
	Trie trie;
	trie.add("mo");
	trie.add("moi");
    BOOST_REQUIRE(trie.find("moi")==257);
    BOOST_REQUIRE(trie.find("hei")==-1);
    BOOST_REQUIRE(trie.translate(1234)=="");
    BOOST_REQUIRE(trie.translate(257)=="moi");
    BOOST_REQUIRE(trie.isemptyed()==false);
    trie.empty();
    BOOST_REQUIRE(trie.isemptyed()==true);
    BOOST_REQUIRE(trie.isemptyed()==false);
    return 0;
}
