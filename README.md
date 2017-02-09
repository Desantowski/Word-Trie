# Word Trie
Word Trie is set of functions to operate on acyclic graph, which nodes are characters - set of connected nodes can build string. 
Our nodes store another string - reply - dedicated for chatbots.

##Usage
###WordTrie()
This is only one public constructor - should be used only once, on start, to create root node and entry point to operations.

###std::string FindExpression(std::string string, int currentCharIndex)
This function returns reply from specified Word Trie. currentCharIndex always should be zero on start, it's used recursively. String is basic
message - user input.

###WordTrie * CreateNode(std::string string, int currentCharIndex, std::string r)
r stands for reply, string is message, currentCharIndex should be zero. Adds new node to trie and returns pointer to this node.

###std::string AllMesages(), std::string AllReplies()
Returns formatted string, in which each line contains new reply/message. Line n of AllReplies is reply for line n in AllMesages().
