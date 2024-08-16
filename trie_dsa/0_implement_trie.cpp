/**
 * Implement a Trie data structure with 3 methods:
 * - insert(string word): Inserts the word
 * - search(string word): Returns True/False if there's full word match
 * - startsWith(string prefix): Returns True/False if prefix exists
 * 
 * YouTube(Striver's): https://youtu.be/dBGUmUQhjaM?si=pL_WfgHWvuwVcuyk
 * Pattern: trie, basic
 */

#include <iostream>
using namespace std;

class Node {
    Node* links[26];
    bool flag = false; // If True, marks end of word

    public:
        bool containsKey(char ch) {
            return links[ch - 'a'] != nullptr;
        }

        void put(char ch, Node* node) {
            links[ch - 'a'] = node;
        }

        Node* get(char ch) {
            return links[ch - 'a'];
        }

        void setEnd() {
            flag = true;
        }

        bool isEnd() {
            return flag;
        }
};

class Trie {
    private:
        Node* root;
    public:
        Trie() {
            root = new Node();
        }

        void insert(string word) { // TC: O(len), length of word
            /**
             * Inserts a word into Trie
             * 1. Start from 'root' node and loop through characters of 'word'.
             * 2. If the char doesn't exist, create a Node and add to current Node's 'link'
             * 3. Mark the last Node's flag = True
             */
            Node* node = root;
            for(int i = 0; i < word.length(); i++) {
                if(!node->containsKey(word[i])) {
                    node->put(word[i], new Node());
                }
                node = node->get(word[i]); // move to next Node
            }
            node->setEnd(); // mark end of word
        }

        bool search(string word) {
            /**
             * Returns True/False if the full word matches with Trie's full Word.
             */
            Node* node = root;
            for(int i = 0; i < word.length(); i++) {
                if(!node->containsKey(word[i])) {
                    return false;
                }
                node = node->get(word[i]);
            }
            return node->isEnd();
        }

        bool startsWith(string prefix) {
            /**
             * Returns True/False if prefix exists
             */
            Node* node = root;
            for(int i = 0; i < prefix.length(); i++) {
                if(!node->containsKey(prefix[i])) {
                    return false;
                }
                node = node->get(prefix[i]);
            }
            return true;
        }
};

int main() {
    Trie t;
    cout << "Insert 'Prakash' to Trie:\n";
    t.insert("Prakash");
    cout << "Does 'Prakash' exist in Trie?\n" << (t.search("Prakash") ? "YES" : "NO") << endl;
    cout << "Insert 'Pramod' in Trie:\n";
    t.insert("Pramod");
    cout << "Does prefix 'Pram' exist in Trie?\n" << (t.startsWith("Pram") ? "YES" : "NO") << endl;
    cout << "Insert 'Rakesh' in Trie:\n";
    t.insert("Rakesh");
    cout << "Does prefix 'Rak' exist in Trie?\n" << (t.startsWith("Rak") ? "YES" : "NO") << endl;
    return 0;
}