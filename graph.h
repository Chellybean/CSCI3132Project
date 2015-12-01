#pragma once

#include "stdafx.h"

class Graph
{
    public:
		Graph();
		Graph(int iterations);
        //void initialize(); //default, 
        void addFreq(double freq);
		void drawGraph();
        
	private:
		 //[x][y]
		int xSpacer;
		std::vector<double> freqs;
};
