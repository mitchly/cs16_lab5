#include <iostream>
#include <string>
#include <cctype>
using namespace std;

void isAnagram(string str1, string str2);

int main()
{
	string str1;
	string str2;

	cout << "Enter first string:" << endl;
	getline(cin, str1);
	cout << "Enter second string:" << endl;
	getline(cin, str2);

	isAnagram(str1, str2);

    return 0;
}

void isAnagram(string str1, string str2){
    string newStr1;
	string newStr2;
    int newStr1Size;
	int newStr2Size;
    int str1Size = str1.size();
	int str2Size = str2.size();

	if(str1 == str2){
		cout << "The strings are anagrams.";
		return;
	}
	
	//cleaning loops
	for(int clean = 0; clean < str1Size; clean++){
        if(isalpha(str1[clean]) == 1){
            newStr1 += str1[clean];
        }
    }
	newStr1Size = newStr1.size();
	for(int clean2 = 0; clean2 < str2Size; clean2++){
        if(isalpha(str2[clean2]) == 1){
            newStr2 += str2[clean2];
        }
    }
	newStr2Size = newStr2.size();

	if(newStr1Size != newStr2Size){
		cout << "The strings are not anagrams." << endl;
		return;
	}

	//lowercase loops
	for(int i = 0; i < newStr1Size; i++){
		if(islower(newStr1[i]) == 0){
			newStr1[i] = newStr1[i] + 32;
		}
		if(islower(newStr2[i]) == 0){
			newStr2[i] = newStr2[i] + 32;
		}
	}

	//sorted loops
    for(int a = newStr1Size - 1; a >= 0; a--){
        for(int b = 1; b <= a; b++){
            if(newStr1[b - 1] > newStr1[b]){
                int swap;
                swap = newStr1[b - 1];
                newStr1[b - 1] = newStr1[b];
                newStr1[b] = swap;
            }
			if(newStr2[b - 1] > newStr2[b]){
                int swap;
                swap = newStr2[b - 1];
                newStr2[b - 1] = newStr2[b];
                newStr2[b] = swap;
	        }
    	}
	}

	if(newStr1 == newStr2){
		cout << "The strings are anagrams.";
		return;
	}
	else{
		cout << "The strings are not anagrams.";
		return;
	}
}