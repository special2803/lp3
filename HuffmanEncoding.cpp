#include <iostream>
#include <map>
#include <queue>
using namespace std;

// Huffman tree node
class Node
{
public:
    char data;
    int freq;

    Node *left;
    Node *right;

    Node(char data, int freq)
    {
        this->data = data;
        this->freq = freq;
        left = NULL;
        right = NULL;
    }
};

// Custom comparator for sorting Huffman tree nodes on the basis of freq
class Compare
{
public:
    bool operator()(Node *temp1, Node *temp2)
    {
        return temp1->freq <= temp2->freq;
    }
};

// Function to build Huffman tree and return root node
Node *buildHuffmanTree(map<char, int> charFreqMap)
{
    // Initialize priority queue
    priority_queue<Node *, vector<Node *>, Compare> pq;

    // Push all the character nodes to priority queue
    for (auto it : charFreqMap)
    {
        Node *temp = new Node(it.first, it.second);
        pq.push(temp);
    }

    // Iterate until only one node is left in priority queue
    while (pq.size() != 1)
    {
        // Extract first minimum freq node
        Node *left = pq.top();
        pq.pop();

        // Extract second minimum freq node
        Node *right = pq.top();
        pq.pop();

        // Create a new internal node with freq as sum of freq of left and right nodes.
        Node *temp = new Node('$', left->freq + right->freq);
        temp->left = left;
        temp->right = right;

        // Push the new internal node to the priority queue
        pq.push(temp);
    }

    // Return the remaininig root node in the priority queue
    return pq.top();
}

// Function to traverse Huffman tree to assign Huffman codes to each character
void traverseHuffmanTree(Node *root, string code, map<char, string> &charCodeMap)
{
    if (root == NULL)
    {
        return;
    }

    if (root->left == NULL && root->right == NULL)
    {
        // Store Huffman code assigned to character in map
        charCodeMap[root->data] = code;
        return;
    }

    traverseHuffmanTree(root->left, code + "0", charCodeMap);
    traverseHuffmanTree(root->right, code + "1", charCodeMap);
}

// Function to generate and return output string
string generateOutputString(string input, map<char, string> charCodeMap)
{
    // Initialize output string
    string output = "";

    // Iterate input string and build output string
    for (auto ch : input)
    {
        output += charCodeMap[ch];
    }

    // Return output string
    return output;
}

int main()
{
    // Take input string
    string input;
    cin >> input;

    // Display input string
    cout << "\nInput String : " << input << endl;
    int n = input.size();

    // Store characters with their frequency in map
    map<char, int> charFreqMap;
    for (int i = 0; i < n; i++)
    {
        charFreqMap[input[i]]++;
    }

    // Build Huffman tree
    Node *root = buildHuffmanTree(charFreqMap);

    // Traverse Huffman tree to assign Huffman codes to each character
    map<char, string> charCodeMap;
    traverseHuffmanTree(root, "", charCodeMap);

    // Display Huffman code assigned to each character
    cout << "\nHuffman Codes for each character : " << endl;
    for (auto it : charCodeMap)
    {
        cout << it.first << " -> " << it.second << endl;
    }

    // Generate output string
    string output = generateOutputString(input, charCodeMap);

    // Display output string
    cout << "\nOutput String : " << output << endl;
    cout << endl;

    return 0;
}