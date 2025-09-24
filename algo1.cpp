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

struct Node {
	std::string color;
	Node* leftNode;
	Node* rightNode;

	Node(std::string c): color(c), leftNode(nullptr), rightNode(nullptr) {}
};


void recursiveSort(Node* node);

int main() {
	Node* head = nullptr;
	Node* tail = nullptr;
	std::string colors[] = {"light", "dark", "light", "dark", "light", "dark"};

	for(int i = 0; i < 6; i++) {
		Node* newNode = new Node(colors[i]);

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
	while(current != nullptr) {
		std::cout << current->color;
		if(current->rightNode != nullptr) {
			std::cout << " <-> ";
		}
		current = current->rightNode;
	}
	std::cout << std::endl;



	while(head != nullptr) {
		Node* next = head->rightNode;
		delete head;
		head = next;
	}

	return 0;
}


void recursiveSort(Node* node) {
	
}
