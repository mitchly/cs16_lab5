#include <iostream>
#include <string>
#include <cctype>
using namespace std;

void sort_string(string &sentence, int sentSize);
void print_freq(string sentence, int sentSize);

int main()
{
    string sentence;
    cout << "Enter sentence: ";
    getline(cin, sentence);

    cout << "Sorted and cleaned-up sentence:";
    sort_string(sentence, sentence.size());

    print_freq(sentence, sentence.size());

	return 0;
}

void sort_string(string &sentence, int sentSize){
    //clean loop
    string newSentence;
    int newSentSize;
    for(int clean = sentSize; clean > 0; clean--){
        if(isalpha(sentence[clean - 1]) == 0){
            sentence.replace(clean - 1, 1, "");
        }
    }
    sentSize = sentence.size();

    for(int i = sentSize - 1; i >= 0; i--){
        for(int j = 1; j <= i; j++){
            if(sentence[j - 1] > sentence[j]){
                int swap;
                swap = sentence[j - 1];
                sentence[j - 1] = sentence[j];
                sentence[j] = swap;
            }
        }
    }
    cout << sentence << endl;
}

void print_freq(string sentence, int sentSize){
    sentSize = sentence.size();

    for(int z = 0; z < sentSize; z++){
        int counter = 0;
        if(sentence[z - 1] == sentence[z]){
            continue;
        }
        cout << sentence[z] << ": ";
        for(int a = 0; a < sentSize; a++){
            if(sentence[a] == sentence[z]){
                counter++;
            }
        }
        cout << counter << endl;
    }
}