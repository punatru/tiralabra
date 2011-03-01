all: encode decode

encode: encode.cpp node.cpp node.h trie.cpp trie.h filewriter.cpp filewriter.h
	g++ encode.cpp node.cpp trie.cpp filewriter.cpp -o encode -g -O2

decode: decode.cpp node.cpp node.h trie.cpp trie.h filereader.cpp filereader.h
	g++ decode.cpp node.cpp trie.cpp filereader.cpp -o decode -g
