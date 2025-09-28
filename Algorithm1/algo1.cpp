/*
==========
Pseudocode
==========

void recursiveFunction(headNode) {
	// Termination check: if the next node is empty
	if (!node->rightnode) return;

	// Dark disk and previous disk is light: swap and check if there are more lights to the left
	if (node->color == DARK && node->leftnode && node->leftnode->color == LIGHT) {
		swap(node, node->leftnode);
		recursiveFunction(node);
		return;

	// Light disk and next disk is dark: swap and check if dark disk needs to go more left
	} else if (node->color == LIGHT && node->rightnode->color == DARK) {
		swap(node, node->rightnode);
		recursiveFunction(node->leftnode);
		return;
	}

	// Go to next node
	recursiveFunction(node->rightnode);
}

Notes: This can be optimized for sure, but is pretty simple implementation.
*/

/*
Groups Members:
- Michael Bui
- Natalia Garcia
- Andrew Lee
*/

#include <string>
#include <iostream>
#include <fstream>
#include <vector>

/*
====================================================
Node structure for Doubly Linked List and Prototypes
====================================================
*/
struct Node {
	std::string color;
	Node* leftNode;
	Node* rightNode;

	Node(std::string c): color(c), leftNode(nullptr), rightNode(nullptr) {}
};

void recursiveSort(Node* node);
void swap(Node* node1, Node* node2);
void deleteNodes(Node* node);

int swaps = 0;


/*
==================================================
Main function, sorts an input file's list of disks
==================================================
*/

int main() {
	// open input file
	std::ifstream inputFile;
	inputFile.open("DiskInput.txt");
	if(!inputFile.is_open()) {
		std::cerr << "Error: could not open DiskInput.txt\n";
	}

	// make vector from input file
	std::vector<std::string> colors;

	while(!inputFile.eof()) {
		std::string input;
		std::getline(inputFile, input);
		if(input == "light" || input == "dark") {
			colors.push_back(input);
		}
	}

	// set up doubly linked list
	Node* head = nullptr;
	Node* tail = nullptr;

	int size = colors.size();
	for(int i = 0; i < size; i++) {
		Node* newNode = new Node(colors.at(i));

		if(head == nullptr) {
			head = newNode;
			tail = newNode;
		} else {
			tail->rightNode = newNode;
			newNode->leftNode = tail;
			tail = newNode;
		}
	}

	// print list of disks before sorting
	Node* current = head;
	while(current != nullptr) {
		std::cout << current->color;
		if(current->rightNode != nullptr) {
			std::cout << " <-> ";
		}
		current = current->rightNode;
	}
	std::cout << std::endl;

	// call sorting function, and then update head node
	recursiveSort(head);
	while(head->leftNode != nullptr) {
		head = head->leftNode;
	}

	// print and output a file showing sorted list of disks
	current = head;
	std::ofstream outputFile;
	outputFile.open("DiskOutput.txt");
	if(!outputFile.is_open()) {
		std::cerr << "Error: could not open DiskOutput.txt\n";
	}
	while(current != nullptr) {
		std::cout << current->color;
		outputFile << current->color;
		if(current->rightNode != nullptr) {
			std::cout << " <-> ";
			outputFile << " <-> ";
		}
		current = current->rightNode;
	}
	std::cout << "\nSwaps: " << swaps << std::endl;
	outputFile << "\nSwaps: " << swaps << std::endl;

	// close files
	outputFile.close();
	inputFile.close();

	// probably unnecessary but manually deleting all nodes
	deleteNodes(head);

	return 0;
}


/*
===============
Helper functions
================
*/

void recursiveSort(Node* node) {
	// termination condition: if no more nodes to the right to check then end
	if(!node->rightNode) return;

	// if dark and there is a light disk to the left, then continue to swap and check if there are more light disks to the left
	if(node->color == "dark" && node->leftNode && node->leftNode->color == "light") {
		swap(node->leftNode, node);
		recursiveSort(node);
		return;

	// if light and there is a dark to the right, then swap and check if dark needs to be pushed further left
	} else if(node->color == "light" && node->rightNode->color == "dark") {
		swap(node, node->rightNode);
		recursiveSort(node->leftNode);
		return;
		
	// if there is no need to swap, then continue to check towards the right
	} else {
		recursiveSort(node->rightNode);
		return;
	}
}

void swap(Node* node1, Node* node2) {
	// increment the global swap counter for output
	swaps++;

	// remember outer neighboring nodes
	Node* tempPtr1 = node1->leftNode;
	Node* tempPtr2 = node2-> rightNode;

	// switch the two nodes' neighbor pointers
	node2->leftNode = tempPtr1;
	node2->rightNode = node1;
	node1->leftNode = node2;
	node1->rightNode = tempPtr2;

	// assign the outer neighbor's pointers if applicable
	if(tempPtr1) {
		tempPtr1->rightNode = node2;
	}
	if(tempPtr2) {
		tempPtr2->leftNode = node1;
	}
}

void deleteNodes(Node* node) {
	// termination condition: if there are no more nodes end
	if(!node) {
		return;
	}

	// delete current node and move on to next node
	Node* tempPtr = node->rightNode;
	delete node;
	deleteNodes(tempPtr);
	return;
}
