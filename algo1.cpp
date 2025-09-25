/*
=================================================
Pseudocode
=================================================

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

#include <string>
#include <iostream>
#include <fstream>
#include <vector>

struct Node {
	std::string color;
	Node* leftNode;
	Node* rightNode;

	Node(std::string c): color(c), leftNode(nullptr), rightNode(nullptr) {}
};


void recursiveSort(Node* node);
void swap(Node* node1, Node* node2);
void deleteNodes(Node* node);

int main() {
	std::ifstream inputFile;
	inputFile.open("DiskInput.txt");
	if(!inputFile.is_open()) {
		std::cerr << "Error: could not open DiskInput.txt\n";
	}

	std::vector<std::string> colors;

	while(!inputFile.eof()) {
		std::string input;
		std::getline(inputFile, input);
		if(input == "light" || input == "dark") {
			colors.push_back(input);
		}
	}

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

	Node* current = head;
	while(current != nullptr) {
		std::cout << current->color;
		if(current->rightNode != nullptr) {
			std::cout << " <-> ";
		}
		current = current->rightNode;
	}
	std::cout << std::endl;


	recursiveSort(head);
	while(head->leftNode != nullptr) {
		head = head->leftNode;
	}

	
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
	std::cout << std::endl;

	deleteNodes(head);

	return 0;
}


void recursiveSort(Node* node) {
	if(!node->rightNode) return;

	if(node->color == "dark" && node->leftNode && node->leftNode->color == "light") {
		swap(node->leftNode, node);
		recursiveSort(node);
		return;
	} else if(node->color == "light" && node->rightNode->color == "dark") {
		swap(node, node->rightNode);
		recursiveSort(node->leftNode);
		return;
	} else {
		recursiveSort(node->rightNode);
		return;
	}
}

void swap(Node* node1, Node* node2) {
	Node* tempPtr1 = node1->leftNode;
	Node* tempPtr2 = node2-> rightNode;
	node2->leftNode = tempPtr1;
	node2->rightNode = node1;
	node1->leftNode = node2;
	node1->rightNode = tempPtr2;
	if(tempPtr1) {
		tempPtr1->rightNode = node2;
	}
	if(tempPtr2) {
		tempPtr2->leftNode = node1;
	}
}

void deleteNodes(Node* node) {
	if(!node) {
		std::cerr << "Error: invalid node on deleteNodes() call\n";
	}
	if(node->rightNode) {
		Node* tempPtr = node->rightNode;
		delete node;
		deleteNodes(tempPtr);
		return;
	}
	delete node;
	return;
}
