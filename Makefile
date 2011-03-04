all: encode decode

encode: encode.cpp node.cpp node.h trie.cpp trie.h filewriter.cpp filewriter.h myvector.h
	g++ encode.cpp node.cpp trie.cpp filewriter.cpp myvector.h -o encode -g

decode: decode.cpp node.cpp node.h trie.cpp trie.h filereader.cpp filereader.h myvector.h
	g++ decode.cpp node.cpp trie.cpp filereader.cpp myvector.h -o decode -g
