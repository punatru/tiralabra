all: myvector node trie fileio

myvector: test_myvector.cpp ../myvector.h
	g++ test_myvector.cpp -o test_myvector

node: test_node.cpp ../node.h ../node.cpp
	g++ ../node.cpp test_node.cpp -o test_node

trie: test_trie.cpp ../trie.h ../trie.cpp ../node.h ../node.cpp
	g++ ../trie.cpp ../node.cpp test_trie.cpp -o test_trie

fileio: test_fileio.cpp ../filewriter.h ../filewriter.cpp ../filereader.h ../filereader.cpp
	g++ ../filewriter.cpp ../filereader.cpp test_fileio.cpp -o test_fileio
