#include "graph.h"
#include "stdafx.h"

char screen[80][24];
int freqCount = 0;

Graph::Graph(){}

Graph::Graph(int iterations){

	
	Graph::xSpacer = (80/iterations);
	//std::cout << Graph::xSpacer;
	for(int i = 0; i < 80; i++){
		screen[i][22] = '-';
	}
	for(int i = 0; i < 24; i++){
		screen[1][i] = '|';
	}
	int xCount = 1;
	for(int i = 0; i < 80; i++){
		if(i%Graph::xSpacer == 0){screen[i+1][23] = (xCount)+48; xCount++;}
	}
	screen[0][0] = 1+48;
	screen[0][22] = 48;
	//screen[2][12] = 50;

}
       
void Graph::addFreq(double freq){
	freqCount++;
	bool found = false;
	for(int i = 0; i < 80 && found == false; i++){
		if(screen[i][23] == freqCount+48){
			screen[i][22-(int)(22*freq)] = 43;
			found = true;
		}
	}
}

void Graph::drawGraph(){
	
	int xCount = 1;
	for(int i = 1; i < 80; i++){
		if(i%Graph::xSpacer == 0){screen[i+1][23] = (xCount%10)+48; xCount++;}
	}
	screen[1][23] = 48;
	for(int i = 0; i <24; i++){
		for(int j = 0; j < 80; j++){	
			std::cout << screen[j][i];
		}
		//std::cout << "\n";
	}
	return;
}