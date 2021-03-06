// MiniMaxExample1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Small program to find the 
//max score that maximizing player can get

#include "pch.h"
#include <iostream>
#include <algorithm>

///-------------------------------------------------------------------------------------------------
///<summary>returns optimal value a maximizer can obtain. depth is current depth in game tree
/// nodeIndex is index of current node in scores[]. isMax is true if current move is of maximizer,
/// else false. scores[] stores leaves of the game tree. h is maximum height of Game tree.</summary>
///
///<remarks>Jose, 9/28/2018.</remarks>
///
///<param name="depth">	   The depth.</param>
///<param name="nodeIndex">Zero-based index of the node.</param>
///<param name="isMax">	   True if is maximum, false if not.</param>
///<param name="scores">   The scores.</param>
///<param name="h">		   The height.</param>
///
///<returns>An int.</returns>
///-------------------------------------------------------------------------------------------------
int minimax(int depth, int nodeIndex, bool isMax, int scores[], int h) {

	//terminating condition (leaf node is reached)
	if (depth == h) {
		return scores[nodeIndex];
	}

	//if current move is maximizer, 
	//find the maximum attainable value
	if (isMax) {
		return std::max(minimax(depth + 1, nodeIndex * 2, false, scores, h),
			minimax(depth + 1, nodeIndex * 2 + 1, false, scores, h));
	}
	//else (if current move is minimizers), find the minimum attainable value
	else {
		return std::min(minimax(depth + 1, nodeIndex * 2, true, scores, h),
			minimax(depth + 1, nodeIndex * 2 + 1, true, scores, h));
		
	}
}

///-------------------------------------------------------------------------------------------------
///<summary>utility function to find Log n in base 2.</summary>
///
///<remarks>Jose, 9/28/2018.</remarks>
///
///<param name="n">An int to process.</param>
///
///<returns>An int.</returns>
///-------------------------------------------------------------------------------------------------
int log2(int n) {
	return (n == 1) ? 0 : 1 + log2(n / 2);
}


int main()
{


    //number of elements in scores must be a power of 2
	int scores[] = { 3, 5, 2, 9, 13, 5, 23, 23,72 ,15,30,20,42,99,102,115 };
	int n = sizeof(scores) / sizeof(scores[0]);
	int h = log2(n);
	
	int res = minimax(0, 0, true, scores, h);
	std::cout << "The optimal value is: " << res << std::endl;

	std::cout << "Press any key to continue...";
	std::getchar();

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
