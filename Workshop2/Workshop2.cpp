#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <map>

using namespace std;

int main()
{
    // Declaring variables
    string word; string filemane; string line;
    int numberOfWords = 0; int numberOfSentences = 0; int Count = 0;
    vector<string> wordList(39);

    // Open file and create a new one to remove punctuation for later
    ifstream input("input.txt");
    ofstream output("output.txt");

    // Removing punctuation
    while (getline(input, line)) {
        for (char& c : line) {
            if (isalnum(c) || c == ' ' || c == '\t') {
                output << c;
            }
        }
        output << '\n';
    }
    input.close();
    output.close();

    // Converting both the files to string
    fstream input2("input.txt");
    string inputstr(istreambuf_iterator<char>(input2), (istreambuf_iterator<char>()));
    fstream output2("output.txt");
    string outputstr(istreambuf_iterator<char>(output2), (istreambuf_iterator<char>()));


    // Number of sentences (looking for sentence ending punctuation)
    for (char c : inputstr) 
    {
        if (c == '.' || c == '!') 
        {
            numberOfSentences++;
        }
    }
    std::cout << "Number of sentences is " << numberOfSentences << endl;

    // Number of words
    istringstream iss(inputstr);
    while (iss >> word) 
    {
        numberOfWords++;
    }
    std::cout << "Number of words is " << numberOfWords << endl;

    // Frequency of words

    // Puts all words into vector and makes map to store frequencies
    istringstream iss2(outputstr);
    map<string, int> wordFrequency;
    while (iss2 >> word) 
    {
        wordList.push_back(word);
        wordFrequency[word]++;
    }

    // Prints words and frequencies
    for (const auto& pair : wordFrequency) 
    {
        std::cout << pair.first << " " << pair.second << endl;
    }
}