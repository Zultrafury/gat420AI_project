#include <iostream>
#include <memory>
#include <SDL.h>

#include "Node.h"
#include "NodeFunctions.h"

using namespace std;

int main(int, char**)
{
	//		A
	//    B   C
	//  D   E   F

	// create nodes with char data
	char_node_t* nodeA = new char_node_t{ 'A' };
	char_node_t* nodeB = new char_node_t{ 'B' };
	char_node_t* nodeC = new char_node_t{ 'C' };
	char_node_t* nodeD = new char_node_t{ 'D' };
	char_node_t* nodeE = new char_node_t{ 'E' };
	char_node_t* nodeF = new char_node_t{ 'F' };

	// create tree from nodes (children)
	nodeA->children.push_back(nodeB);
	nodeA->children.push_back(nodeC);
	nodeB->children.push_back(nodeD);
	nodeB->children.push_back(nodeE);
	nodeC->children.push_back(nodeE);
	nodeC->children.push_back(nodeF);

	cout << "BFS:\n";

	// get search path to 'F' from node 'A'
	auto path = NodeFunctions::getBFS(nodeA, 'F');
	// display path result
	cout << "path: ";
	for (auto node : path)
	{
		cout << "->" << node->data;
	}
	cout << '\n';

	return 0;
}
