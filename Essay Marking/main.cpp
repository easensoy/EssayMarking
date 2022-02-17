#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <list>
#include <set>
#include <sstream> 
#include <algorithm>
#include "definitions.h" 

using namespace std;

int main(int argc, char* argv[]){
      
  // Initialisation

  char* inputFile = argv[1]; 
  char* outputFile = argv[2]; 
  createTable();
  
  // Read the input
  string input = readInput(inputFile);
  string output="";
  // Split the input into words and put it into a list of elements of class Word! 
  list<Word> w;
  istringstream ss(input);
	string word;
	while (ss >> word) 
	{
		Word wordObj(word,1,calPoints(word));
		w.push_back(wordObj);
	}
	list<Word>::iterator it,it2;
	for(it=w.begin();it!=w.end();it++){
		for(it2=it;it2!=w.end();it2++){
			if(it!=it2&&it->getWord()==it2->getWord()){
				it->setCounterPP();
			}
		}
	}
  // Task 1:
  // 1st criterion --> The shortest word 
  // 2nd criterion --> The longest word
  // 3rd criterion --> Palindrome words
  // 4th criterion --> Length of essay
  // 5th criterion --> Average number of letters and average number of point for those words
  // 6th criterion --> More than 4 letters of V not allowed!
	if(criterion1(w)){	output+="pass,";	}
	else{output+="fail,";}
	if(criterion2(w)){	output+="pass,";	}
	else{output+="fail,";}
	if(criterion3(w)){	output+="pass,";	}
	else{output+="fail,";} 
	if(criterion4(w)){	output+="pass,";	}
	else{output+="fail,";}
	if(criterion5(w)){	output+="pass,";	}
	else{output+="fail,";}
	if(criterion6(w)){	output+="pass";	}
	else{output+="fail";}   
  // Add the seperator
  // At this point add ';' as the seperator to your output 
   output+=";";
  // Task 2:
  // Shortest and longest
  // Lowest point and highest point
  // Less frequent and most frequent
	string shortest=w.begin()->getWord(),longest=w.begin()->getWord(),
	lowestP=w.begin()->getWord(),
	highestP=w.begin()->getWord(),lessF=w.begin()->getWord(),mostF=w.begin()->getWord();
/*
  int iShortest=w.begin()->getLength(),iLongest=w.begin()->getLength(),shortestPoint=w.begin()->getPoint(),
  iLowestP=w.begin()->getPoint(),iHighestP=w.begin()->getPoint(),
  iLessF = w.begin()->getCounter(),iMostF=w.begin()->getCounter(),lessFLength=w.begin()->getLength(),mostFLength=w.begin()->getLength();
  
  //OLD ALGORITHM
	for(it=w.begin();it!=w.end();it++){
	if(it->getLength()<iShortest || (it->getWord()<shortest&&it->getLength()==iShortest)){
			iShortest = it->getLength();
			shortest = it->getWord();
		}
		if(it->getLength()>iLongest ||(it->getLength()==iLongest && it->getWord()>longest)){
			iLongest = it->getLength();
			longest = it->getWord();
		}
		if(it->getPoint()<iLowestP||(it->getPoint()==iLowestP && it->getWord()<lowestP)){
			iLowestP = it->getPoint();
			lowestP = it->getWord();
		}
		if(it->getPoint()>iHighestP||(it->getPoint()==iHighestP && it->getWord()>highestP)){
			iHighestP = it->getPoint();
			highestP = it->getWord();
		}
		if(it->getCounter()<iLessF){
			iLessF = it->getCounter();
			lessF = it->getWord(); 
			lessFLength = it->getLength();
		}
		if(it->getCounter()>iMostF||(it->getCounter()==iMostF && it->getWord()>=mostF)||(it->getCounter()==iMostF && it->getLength()>mostFLength)){
			iMostF = it->getCounter();
			mostF = it->getWord();
			mostFLength = it->getLength();
		}
	}
	*/
	//New Algorithm
	list<Word> ww = w;
	ww.sort([](const Word &w1, const Word &w2) { return w1.getLength() < w2.getLength() || (w1.getLength() == w2.getLength() && w1.getWord()<w2.getWord());});
	shortest = ww.begin()->getWord();
	ww=w;
	ww.sort([](const Word &w1, const Word &w2) { return w1.getLength() > w2.getLength() || (w1.getLength() == w2.getLength() && w1.getWord()>w2.getWord());});
	longest=ww.begin()->getWord();
	ww=w;
	ww.sort([](const Word &w1, const Word &w2) { return w1.getPoint() < w2.getPoint() || (w1.getPoint() == w2.getPoint() && w1.getWord()<w2.getWord());});
	lowestP=ww.begin()->getWord();
	ww=w;
	ww.sort([](const Word &w1, const Word &w2) { return w1.getPoint() > w2.getPoint() || (w1.getPoint() == w2.getPoint() && w1.getWord()<w2.getWord());});
	highestP=ww.begin()->getWord();
	ww=w;
	ww.sort([](const Word &w1, const Word &w2) { return w1.getCounter() < w2.getCounter() || (w1.getCounter() == w2.getCounter() && w1.getPoint()<w2.getPoint());});
	lessF=ww.begin()->getWord();
	ww=w;
	ww.sort([](const Word &w1, const Word &w2) { return w1.getCounter() > w2.getCounter();});
	mostF=ww.begin()->getWord();
  // Add the seperator
  // At this point add ';' as the seperator to your output 
	output+=shortest+","+longest+","+lowestP+","+highestP+","+lessF+","+mostF+";";

  // Task 3: 
  // Number of appearance for each word
	ww = w;
	ww.sort([](const Word &w1, const Word &w2) { return w1.getCounter() < w2.getCounter();});
	int i=0;
	for(it=ww.begin();it!=ww.end();it++){
		output=output+it->getWord()+","+to_string(it->getCounter());
	}
  // Add the seperator
  // At this point add ';' as the seperator to your output 
	output+=";";
  // Task 4:
  // Student name, key and the secret
	it = w.begin();
	advance(it,9);
	string studentName = it->getWord();
	int key = (it->getPoint()%26);
	string secret = w.end()->getWord();
	int sCounter = 0;
	for(it=w.begin();it!=w.end();it++){
		if(it->getPoint()>=90&&it->getPoint()<=110){
			sCounter++;
			if(sCounter==2){
				secret = it->getWord();
				break;
			}
		}
	}
	output+=studentName+","+to_string(key)+","+secret+","+caesarDecipher(secret,key);
  // Add the seperator
  // At this point add ';' as the seperator to your output 
	output+=";";
  // Task 5:
  // The one in the middle
	ww=w;
	ww.sort([](const Word &w1, const Word &w2) { return w1.getPoint() < w2.getPoint() || (w1.getPoint() == w2.getPoint() && w1.getWord()<w2.getWord());});
	int middle = (w.size()/2)+1;
	it = ww.begin();
	advance(it,middle);
	output+=it->getWord();
	if(middle%2==0){
		it++;
		output+=it->getWord();
	}
  // Write input in the file
	writeOutput(output,outputFile);
	return 0;
}