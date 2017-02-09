#include "WordTrie.h"

WordTrie * WordTrie::AddNode(char c, std::string m, std::string r)
{
	childNodes.push_back(new WordTrie(c, r, m));
	return childNodes[childNodes.size() - 1];
}

std::string WordTrie::FindExpression(std::string string, int currentCharIndex)
{
	if (string.size() < 2) return "";
	char currentChar = string[currentCharIndex];
	for (WordTrie * child : childNodes)
	{
		if (child->character == currentChar)
		{
			if (currentCharIndex == string.size()-1)
			{
				return child->reply;
			}
			else
			{
				return child->FindExpression(string, currentCharIndex + 1);
			}
		}
	}
	return "";
}

WordTrie * WordTrie::CreateNode(std::string string, int currentCharIndex, std::string r)
{
	if (string.size() < 2) throw "Ehh :(";
	char currentChar = string[currentCharIndex];
	for (WordTrie * child : childNodes)
	{
		if (child->character == currentChar)
		{
			return child->CreateNode(string, currentCharIndex + 1, r);
		}
	}
	if (currentCharIndex == string.size() - 1)
	{
		return AddNode(currentChar, string, r);
	}
	else return CreateSubtrie(string, currentCharIndex, r);
}

WordTrie * WordTrie::CreateSubtrie(std::string string, int currentCharIndex, std::string r)
{
	if (currentCharIndex == string.size() - 1)
	{
		reply = r;
		message = string;
		return this;
	}
	char currentChar = string[currentCharIndex];
	return AddNode(currentChar, " ", " ")->CreateSubtrie(string, currentCharIndex + 1, r);
}

std::stringstream WordTrie::AllReplies()
{
	std::stringstream out;
	for (WordTrie * x : childNodes)
	{
		out << x->GetReplies();
	}
	return out;
}

std::stringstream WordTrie::AllMessages()
{
	std::stringstream out;
	for (WordTrie * x : childNodes)
	{
		out << x->GetMessages();
	}
	return out;
}

std::string WordTrie::GetReplies()
{
	std::stringstream out;
	for (WordTrie * x : childNodes)
	{
		out << x->GetReplies();
	}
	if (reply.size() > 3) out << reply << std::endl;
	return out.str();
}

std::string WordTrie::GetMessages()
{
	std::stringstream out;
	for (WordTrie * x : childNodes)
	{
		out << x->GetMessages();
	}
	if(reply.size() > 3) out << message << std::endl;
	return out.str();
}
