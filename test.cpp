
#include <bits/stdc++.h>
using namespace std;

struct HuffmanNode
{
    char data;
    unsigned freq;
    HuffmanNode *left, *right;
    HuffmanNode(char data, unsigned freq)
    {
        left = right = NULL;
        this->data = data;
        this->freq = freq;
    }
};

// For comparison of two Huffman nodes (needed in min heap)
struct compare
{
    bool operator()(HuffmanNode *l, HuffmanNode *r)
    {
        return (l->freq > r->freq);
    }
};

// Prints huffman codes from the root of Huffman Tree.
void printCodes(struct HuffmanNode *root, string str)
{
    if (!root)
        return;
    if (root->data != '$')
        cout << root->data << ": " << str << "\n";
    printCodes(root->left, str + "0");
    printCodes(root->right, str + "1");
}

// The main function that builds a Huffman Tree and print codes by traversing the built Huffman Tree
void HuffmanCodes(vector<pair<char, int>> &v)
{
    struct HuffmanNode *left, *right, *top;
    int size = v.size();
    // min heap & inserts all characters of data[]
    priority_queue<HuffmanNode *, vector<HuffmanNode *>, compare> pq;
    for (int i = 0; i < size; ++i)
        pq.push(new HuffmanNode(v[i].first, v[i].second));
    // loop while size of heap doesn't become 1
    while (pq.size() != 1)
    {
        // two minimum frequency nodes
        left = pq.top();
        pq.pop();
        right = pq.top();
        pq.pop();
        // Create a new internal node with frequency equal to the sum of the minimum two nodes frequencies.
        top = new HuffmanNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        pq.push(top);
    }

    // Print Huffman codes using
    printCodes(pq.top(), "");
}

vector<pair<char, int>> frequency(string &s)
{
    vector<pair<char, int>> ans;

    map<char, int> mp;
    for (auto c : s)
        mp[c]++;
    for (auto it : mp)
    {
        ans.push_back(it);
    }
    return ans;
}
int main()
{

    string s;
    cin >> s;
    vector<pair<char, int>> v = frequency(s);
    HuffmanCodes(v);

    return 0;
}
