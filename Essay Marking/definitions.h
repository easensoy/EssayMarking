#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <list>
#include <set>
#include <sstream> 
#include <algorithm>

using namespace std;

void writeOutput (string out, char* fileName){
  ofstream stream;
  stream.open(fileName);
  stream<<out;
  stream.close();
}

string readInput (char* fileName){
	ifstream stream;
	stream.open(fileName);
	string val = "",line;
	while(!stream.eof()){
		getline(stream,line);
		val+=" "+line;
	}
	stream.close();
	return val;
}

struct letter {
  char letter;
  int point;
  bool type;
};

class Word{

  private:
    string word;
    int counter;
    int point;

  public:
    Word (string word1, int counter1, int point1) {
		word = word1;
		counter = counter1;
		point = point1;
	}
    void setWord (string word1) { word = word1;}
    const string getWord () const { return word; }
    const int getLength () const { return word.length(); }
    void setCounter (int counter1) { counter = counter1;}
    void setCounterPP () { counter+=1; }
    const int getCounter () const { return counter;}
    void setPoint (int point1) { point = point1; }
    const int getPoint () const { return point; }
};

letter letters [26];

void createTable(){
	letters[0].letter='a'; 		letters[0].point=10;		letters[0].type=true;
	letters[1].letter='b'; 		letters[1].point=21;		letters[1].type=false;
	letters[2].letter='c'; 		letters[2].point=7;		letters[2].type=false;
	letters[3].letter='d'; 		letters[3].point=2;		letters[3].type=false;
	letters[4].letter='e'; 		letters[4].point=19;		letters[4].type=true;
	letters[5].letter='f'; 		letters[5].point=18;		letters[5].type=false;
	letters[6].letter='g'; 		letters[6].point=4;		letters[6].type=false;
	letters[7].letter='h'; 		letters[7].point=8;		letters[7].type=false;
	letters[8].letter='i'; 		letters[8].point=6;		letters[8].type=true;
	letters[9].letter='j'; 		letters[9].point=11;		letters[9].type=false;
	letters[10].letter='k'; 		letters[10].point=14;		letters[10].type=false;
	letters[11].letter='l'; 		letters[11].point=3;		letters[11].type=false;
	letters[12].letter='m'; 		letters[12].point=9;		letters[12].type=false;
	letters[13].letter='n'; 		letters[13].point=22;		letters[13].type=false;
	letters[14].letter='o'; 		letters[14].point=1;		letters[14].type=true;
	letters[15].letter='p'; 		letters[15].point=23;		letters[15].type=false;
	letters[16].letter='q'; 		letters[16].point=17;		letters[16].type=false;
	letters[17].letter='r'; 		letters[17].point=5;		letters[17].type=false;
	letters[18].letter='s'; 		letters[18].point=25;		letters[18].type=false;
	letters[19].letter='t'; 		letters[19].point=13;		letters[19].type=false;
	letters[20].letter='u'; 		letters[20].point=12;		letters[20].type=true;
	letters[21].letter='v'; 		letters[21].point=26;		letters[21].type=false;
	letters[22].letter='w'; 		letters[22].point=24;		letters[22].type=false;
	letters[23].letter='x'; 		letters[23].point=16;		letters[23].type=false;
	letters[24].letter='y'; 		letters[24].point=20;		letters[24].type=false;
	letters[25].letter='z'; 		letters[25].point=15;		letters[25].type=false;
	
}

int calPoints (string str){
	int points = 0;
	for(int i=0;i<str.length();i++){
		for(int j=0;j<26;j++){
			if(str[i]==letters[j].letter){
				points+=letters[j].point;
				break;
			}	
		}
	}
 return points;
}

bool isPalindrome (string str){
	int strLen = str.length();
    for (int i = 0; i < strLen / 2; i++) {
        if (str[i] != str[strLen - i - 1]) {
            return false;
        }
    }
    return true;
}

string caesarDecipher(string secret, int key) 
{ 
	string output="";
	for(int i=0;i<secret.length();i++){
		char ch = secret.at(i);
		ch = ch - key;
        if (ch < 'a'){
         	ch = ch + 'z'-'a'+1;
		}
		output+=ch;
	}
	return output;
}

// Criterion1
bool criterion1 (list<Word> w){
    int min=w.begin()->getLength(),points = w.begin()->getPoint();
    string word = w.begin()->getWord();
	list<Word>::iterator it;
	for(it=w.begin();it!=w.end();it++){
		if((it->getLength()>1&&it->getLength()<min)||(it->getLength()==min&&it->getWord()>word)){
			word = it->getWord();
			min = it->getLength();
			points = it->getPoint();
		}
	}
	if(points>=10&&points<=50){
		return true;
	}
	else{
		return false;
	}
}

// Criterion2
bool criterion2 (list<Word> w){
  int max=w.begin()->getLength(),points = w.begin()->getPoint();
  string word = w.begin()->getWord();
	list<Word>::iterator it;
	for(it=w.begin();it!=w.end();it++)
	{
		if((it->getLength()>max)||(it->getLength()==max&&it->getWord()<word)){
			max = it->getLength();
			points = it->getPoint();
			word = it->getWord();
		}
	}
	if(points>=200&&points<=250){
		return true;
	}
	return false;
}

// Criterion3
bool criterion3 (list<Word> w){
	string palWords[5];
	int palC=0;
	bool contains;
  	list<Word>::iterator it;
  	string str;
	for(it=w.begin();it!=w.end();it++)
	{
		 str = it->getWord();
		if(isPalindrome(str)){
			contains = false;
			for(int i=0;i<palC;i++){
				if(palWords[i] == str){
					contains = true;
					break;
				}
			}
			if(contains==false){
				palWords[palC] = str;
				palC++;
			}
		}
	}
	if(palC>=5){
		return true;
	}
	else return false;
}

// Criterion4
bool criterion4 (list<Word> w){
  int wordCount = w.size();
  return (wordCount>50&&wordCount<100);
}

// Criterion5
bool criterion5 (list<Word> w){
	int avgLetters = 0,avgPoints=0;
  	list<Word>::iterator it; 
	for(it=w.begin();it!=w.end();it++)
	{
		string str = it->getWord();
		avgLetters += it->getLength();
		avgPoints += it->getPoint();;
	}
	avgLetters = avgLetters/ w.size();
	avgPoints = avgPoints / w.size();
	return ((avgLetters>=4&&avgLetters<8)&&(avgPoints>=20&&avgPoints<60));
	
}

// Criterion6
bool criterion6 (list<Word> w){
  // Please write your code here!
 int vCount = 0;
 	list<Word>::iterator it; 
	for(it=w.begin();it!=w.end();it++)
	{
		string str = it->getWord();
		vCount = 0;
		for(int i=0;i<it->getLength();i++){
			for(int j=0;j<26;j++){
				if(str[i]==letters[j].letter && letters[j].type==true){
					vCount++;
					break;
				}	
			}
		}
		if(vCount>4){
			return false;
		}
	}
	return true;
}