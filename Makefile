all:
	g++ decode.cpp node.cpp trie.cpp -o lzw -g

encode:
	g++ encode.cpp node.cpp trie.cpp -o lzw -g

decode:
	g++ decode.cpp node.cpp trie.cpp -o lzw -g
