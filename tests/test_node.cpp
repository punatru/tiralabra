
#include <boost/test/minimal.hpp>
#include "../node.h"

int test_main( int, char *[] ){
    Node* node = new Node('m', 0, 0);
    BOOST_REQUIRE(node->addWord("mo", 1, 1)->letter=='o');
    Node* node2 = node->addWord("moi", 2, 1);
    BOOST_REQUIRE(node2->letter=='i');
    BOOST_REQUIRE(node->findWord("muu", 0)==-1);
    BOOST_REQUIRE(node->findWord("moi", 0)==2);
    BOOST_REQUIRE(node2->translate()=="moi");
    return 0;
}
