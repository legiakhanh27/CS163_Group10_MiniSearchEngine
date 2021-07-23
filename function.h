#ifndef _SEARCH_ENGINE_H_
#define _SEARCH_ENGINE_H_

#include <iostream>
#include <string>
#include<sstream>
#include<vector>
#include<fstream>

using namespace std;

struct TrieNode {
	TrieNode* children[42];  //0-9: number; 10-35: alphabet; 36: space; 37: dot(.); 38:(#); 39:(%); 40:($); 41:(-)
	bool isTitle;			 //To decide this word is in title or not
	bool isEndOfWord;		
	vector<int> pos;
};

class searchEngine {
public:
	void Initialize(TrieNode**& root, int n);	//Quang
	TrieNode* createNode();				//Quang
	bool isNumber(char key);			//Quan
	bool isAlphabet(char key);			//Quan
	string intToString(int num);		//Quan
	string floatToString(float num);	//Quan
	bool isAccepted(char& key);			//Phat
	int convert(char key);				//Phat
	string filter(string sen);			//Phat
	void inputFile(TrieNode*& root, ifstream& file);							//Khanh
	void insertSentence(TrieNode*& root, string sen, int& pos, bool isTitle);	//Khanh
	void insertWord(TrieNode*& root, string word, int& pos, bool isTitle);		//Khanh
	TrieNode* searchWord(TrieNode* root, string word, bool isTitle);
	bool searchTrie(TrieNode* root, TrieNode* stopwordRoot, vector<int> pos, int rankScore, string query);
	void merge(vector<int>& vec1, vector<int> vec2);
};

#endif // !_SEARCH_ENGINE_H_
