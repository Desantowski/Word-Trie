#pragma once
#include <vector>
#include <string>
#include <sstream>
#include <iostream> //For std::cerr in CreateNode

/*
	CreateNode(message, index, reply):
		check if any of childrens has got next character in message
			if yes, go to line 8 for this child node with index = index+1. Do for next child while true
		if new node will be last (index = message length-1), AddNode here
		else, there are more chars left, we need to create more nodes, CreateSubtrie here and return pointer (line 18)

	CreateSubtrie(message, index, reply):
		if this is last node, set reply & message and return this pointer
		else, create new node and CreateSubtrie for this new child node with empy reply, next character from string and
																			index = index+1; return pointer to new child
*/

class WordTrie
{
public:
	//Finds expression in child nodes
	std::string FindExpression(std::string string, int currentCharIndex);

	//Creates new node from MESSAGE STRING string and REPLY STRING r
	WordTrie * CreateNode(std::string string, int currentCharIndex, std::string r = " ");

	//Creates rote node
	WordTrie() : character(0) { }

	//All nodes: messages & replies
	std::stringstream AllMessages();
	std::stringstream AllReplies();

private:
	//Set of children nodes
	std::vector<WordTrie*> childNodes;
	
	//Character for this node, message and reply
	char character;
	std::string message;
	std::string reply;

	//Constructor
	WordTrie(char c, std::string r, std::string m) : character(c), reply(r), message(m) { }

	//Creates new node set
	WordTrie * CreateSubtrie(std::string string, int currentCharIndex, std::string r = " ");

	//Adds new node
	WordTrie * AddNode(char c, std::string m = " ", std::string r = " ");

	std::string GetMessages();
	std::string GetReplies();
};
