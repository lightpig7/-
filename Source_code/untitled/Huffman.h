#ifndef HUFFMAN_H
#define HUFFMAN_H
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_map>
#include <fstream>
#include <cassert>

using namespace std;

struct HTNode
{
    HTNode(unsigned int w, char ch = '\0')
            : _weight(w)
            , _ch(ch)
            , _LChild(nullptr)
            , _RChild(nullptr)
    {}

    unsigned int _weight;
    char _ch;
    HTNode* _LChild;
    HTNode* _RChild;
};

class HuffmanTree
{
private:
    // Functor, build a min-heap based on weight
    struct CmpByWeight
    {
        bool operator()(const HTNode* p1, const HTNode* p2)
        {
            return p1->_weight > p2->_weight;
        }
    };

    void _HuffmanCoding(HTNode* root, string& tmp)
    {
        if (root->_LChild == nullptr && root->_RChild == nullptr)
        {
            _HuffmanCode[tmp] = root->_ch;
            return;
        }
        _HuffmanCoding(root->_LChild, tmp += '0');
        tmp.pop_back();
        _HuffmanCoding(root->_RChild, tmp += '1');
        tmp.pop_back();
    }

    // Create a Huffman tree and generate Huffman codes
    void CreateHuffmanTree(unordered_map<char, unsigned int>& frequency)
    {
        // Insert leaf nodes
        for (auto& e : frequency)
        {
            _HuffmanTree.push(new HTNode(e.second, e.first));
        }
        // Create non-leaf nodes to build the Huffman tree
        while (_HuffmanTree.size() > 1)
        {
            HTNode* s1 = _HuffmanTree.top();
            _HuffmanTree.pop();
            HTNode* s2 = _HuffmanTree.top();
            _HuffmanTree.pop();
            HTNode* parent = new HTNode(s1->_weight + s2->_weight);
            parent->_LChild = s1;
            parent->_RChild = s2;
            _HuffmanTree.push(parent);
        }
        // Recursive, calculate Huffman codes from top to bottom
        string tmp;
        _HuffmanCoding(_HuffmanTree.top(), tmp);
    }

    unordered_map<char, unsigned int> StatisticalFrequencyFromFile(const string& filename)
    {
        unordered_map<char, unsigned int> tmp;
        ifstream infile(filename);

        if (!infile.is_open())
        {
            cerr << "Error opening file: " << filename << endl;
            exit(1);
        }

        infile >> noskipws;  // 禁用空格跳过
        char c;
        while (infile >> c)
        {
            tmp[c]++;
        }

        infile.close();
        return tmp;
    }


    void Destroy(HTNode* root)
    {
        if (root == nullptr) return;
        Destroy(root->_LChild);
        Destroy(root->_RChild);
        delete root;
    }

public:
    // Default constructor
    HuffmanTree()
    {
        auto&& m = StatisticalFrequencyFromFile("Frequency.txt");

        // Build the Huffman tree and encode
        CreateHuffmanTree(m);
    }

    template<typename K, typename V>
    K find_key_by_value(const std::unordered_map<K, V>& myMap, const V& value) {
        for (const auto& pair : myMap) {
            if (pair.second == value) {
                return pair.first;
            }
        }
        // 如果值不存在，你可以抛出异常或返回一个特殊值，这里简单返回一个默认值
        return K();
    }

    string encode(const string& input)
    {
        string result;
        for (char ch : input)
        {
            string key = find_key_by_value(_HuffmanCode,ch); // 将字符转换为字符串进行查找
            if (!key .empty())
            {
                result += key ; // 使用正确的键
            }
            else
            {
                cerr << "No Huffman code found for character: " << ch << endl;
            }
        }
        return result;
    }

    string decode(const std::string& code)
    {
        std::string s;
        std::string result = "";
        int count = 0;
        for (int i = 0; i < code.size(); ++i)
        {
            s += code[i];
            auto&& it = _HuffmanCode.find(s);
            if (it != _HuffmanCode.end()) {
                char tmp[100];
                snprintf(tmp, sizeof(tmp), "%c", it->second);
                result += tmp;
                //std::cout << it->second;
                ++count;
                s.clear();
            }
        }
        result += "\n";
        if (!s.empty())
        {
            result += "...Input sequence is incorrect!\n";
            char tmp[100];
            snprintf(tmp, sizeof(tmp), "Successfully decoded %d characters\n", count);
            result += tmp;
            return result;
        }
        return result;
    }


    void Print()
    {
        ofstream outputFile("output.txt");

        if (!outputFile.is_open())
        {
            cerr << "Error opening file: output.txt" << endl;
            exit(1);
        }


        outputFile << "Character\tCode" << endl;
        for (auto& e : _HuffmanCode)
        {
            outputFile << e.second << '\t' << e.first << endl;
        }

        cout << "Huffman codes have been written to output.txt" << endl;

        outputFile.close();
    }


    ~HuffmanTree()
    {
        Destroy(_HuffmanTree.top());
    }

private:
    priority_queue<HTNode*, vector<HTNode*>, CmpByWeight> _HuffmanTree; // Min-heap, stores the forest
    unordered_map<string, char> _HuffmanCode; // Hash table, stores pairs of codes and corresponding characters
};

string runHuffman_decode(string s)
{
    HuffmanTree ht;

    cout<<ht.decode(s);
    return ht.decode(s);
}
string runHuffman_encode(string input)
{
    HuffmanTree ht;

    ht.Print();
    return ht.encode(input);
    cout << "Encoded result: " << ht.encode(input) << endl;
    cout << "Press Enter to continue...";
}
#endif // HUFFMAN_H
