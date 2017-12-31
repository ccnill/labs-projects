/*
Creator: Christian Nill
CIS 200 Lab 5
Date Created: 16 October 2017
Last Modified: 18 October 2017
*/

#include <iostream>
#include <string>
using namespace std;

//had to use dataa instead of data since data is a reserved word
struct dataa {
	char letter;
	int occur = 0;
};

struct node {
	dataa value;
	node *next;
};

node fromString(string word) {
	node *head = NULL;
	node *current;
	node *temp;
	node *prior = new node;
	node solution;
	current = head;

	//sorts the list
	for (int i = 0; i < word.length(); i++) {
		if (head == NULL || word[i] < head->value.letter) {
			temp = head;
			head = new node;
			head->value.letter = word[i];
			head->value.occur++;
			head->next = temp;
		}
		else {
			prior = head;
			current = head->next;
			while (current != NULL && word[i] >= current->value.letter) {
				prior = current;
				current = current->next;
			}
			if (prior->value.letter == word[i]) {
				prior->value.occur++;
			}
			else {
				temp = new node;
				temp->value.letter = word[i];
				temp->value.occur++;
				temp->next = current;
				prior->next = temp;

			}
		}
	}
	//provides a returnable value
	solution.next = head->next;
	solution.value.letter = head->value.letter;
	solution.value.occur = head->value.occur;
	return solution;
}

//prints the given list
void printList(node list) {
	node *current = list.next;
	cout << list.value.letter << " : " << list.value.occur << endl;
	while (current != NULL) {
		cout << current->value.letter << " : " << current->value.occur << endl;
		current = current->next;
	}
}

node operator + (node &list1, node&list2) {
	node *current1 = &list1;
	node *current2 = &list2;
	node *head;
	node *temp;
	node *prior;
	node solution;
	head = current1;
	int count = 0;
	while (current2 != NULL) {
		if (current1->value.letter > current2->value.letter) {

			temp = current1;
			current1 = new node;

			current1->value.letter = current2->value.letter;
			current1->value.occur = current2->value.occur;
			current1->next = temp;
		}
		else {
			prior = current1;
			current1 = current1->next;
			while (current1 != NULL && current1->value.letter <= current2->value.letter) {
				prior = current1;
				current1 = current1->next;
			}
			if (prior->value.letter == current2->value.letter) {
				prior->value.occur = prior->value.occur + current2->value.occur;
			}
			else {
				temp = new node;
				temp->value.letter = current2->value.letter;
				temp->value.occur = current2->value.occur;
				temp->next = current1;
				prior->next = temp;
			}
		}
		current2 = current2->next;
		current1 = head;
	}
	solution.next = head->next;
	solution.value.occur = head->value.occur;
	solution.value.letter = head->value.letter;
	return solution;
}


int main() {
	dataa first[26];
	dataa second[26];
	node list1, list2, list3;
	string word1, word2;
	char input;
	bool done = false;
	while (!done) {
		cout << "Enter first word: ";
		cin >> word1;

		cout << "Enter second word: ";
		cin >> word2;
		//puts the word into an array
		for (int i = 0; i < word1.length(); i++) {
			first[i].letter = word1[i];
		}
		cout << "List 1: " << endl;
		list1 = fromString(word1);
		printList(list1);

		//puts the word into an array
		for (int i = 0; i < word2.length(); i++) {
			second[i].letter = word2[i];
		}
		cout << "List 2: " << endl;
		list2 = fromString(word2);
		printList(list2);

		cout << "List 3: " << endl;
		list3 = list1 + list2;
		printList(list3);
		bool done2 = false;
		while (!done2) {
			cout << "Done? (y , n): ";
			cin >> input;
			if (input == 'n') {
				done = false;
				done2 = true;
			}
			else if (input == 'y') {
				done = true;
				done2 = true;
			}
			else {
				cout << "Error: invalid input!" << endl;
				done2 = false;
			}

		}

	}

	system("pause");
	return 0;
}