
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

// Node structure for Huffman Tree
struct Node {
    char ch;           // character
    int freq;          // frequency
    Node *left, *right;

    Node(char c, int f) {
        ch = c;
        freq = f;
        left = right = nullptr;
    }
};

// Custom comparator for priority queue
struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq; // min-heap based on frequency
    }
};

// Function to generate Huffman codes
void generateCodes(Node* root, string code, unordered_map<char, string>& huffmanCode) {
    if (root==nullptr) return;

    // Leaf node — contains a character
    if (!root->left && !root->right){
        huffmanCode[root->ch] = code;
        return;
    }
        
    generateCodes(root->left, code + "0", huffmanCode);
    generateCodes(root->right, code + "1", huffmanCode);
}

// Main function to build Huffman Tree and encode input text
void buildHuffmanTree(string text) {
    // Step 1: Count frequency of each character
    unordered_map<char, int> freq;
    for (char ch : text)
        freq[ch]++;

    // Step 2: Create a min-heap (priority queue)
    priority_queue<Node*, vector<Node*>, Compare> pq;
    for (auto pair : freq)
        pq.push(new Node(pair.first, pair.second));

    // Step 3: Build Huffman Tree using greedy strategy
    while (pq.size() > 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();

        Node* sum = new Node('\0', left->freq + right->freq);
        sum->left = left;
        sum->right = right;

        pq.push(sum);
    }

    // Root of Huffman Tree
    Node* root = pq.top();

    // Step 4: Generate Huffman codes
    unordered_map<char, string> huffmanCode;
    generateCodes(root, "", huffmanCode);

    cout << "Huffman Codes:\n";
    for (auto pair : huffmanCode)
        cout << pair.first << " : " << pair.second << endl;

    // Step 5: Encode the text
    string encodedString = "";
    for (char ch : text)
        encodedString += huffmanCode[ch];

    cout << "\nEncoded string:\n" << encodedString << endl;
}

int main() {
    string text;
    cout << "Enter text to encode: ";
    getline(cin, text);

    buildHuffmanTree(text);

    return 0;
}