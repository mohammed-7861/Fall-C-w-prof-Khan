//Assignment 1

#include <iostream>
#include <string>
using namespace std;

void extractDomain();

int main() {
    extractDomain();
    return 0;
}

void extractDomain() {
    string email;
    cout << "Enter your email address: ";
    getline(cin, email);

    
    int pos = email.find('@');

    
        string username = email.substr(0, pos);
        string domain = email.substr(pos + 1);

        cout << "Username: " << username << endl;
        cout << "Domain: " << domain << endl;
    }

//Assignment 2

#include <iostream>
#include <string>
   
using namespace std;

void switchName();

int main() {
    switchName();
    return 0;
}
void switchName() {
    string sentence;
    cout << "Enter a sentence: ";
    getline(cin, sentence);
cout << "Input:" << sentence << endl;
    size_t pos=0;

    while ((pos = sentence.find("miramar")) != string::npos)
    sentence.replace(pos, 7, "San Diego Miramar College");

    
    cout << "Output:" << sentence << endl;
}


//Assignment 3

#include <iostream>
#include <string>
#include <algorithm>  // Needed for remove and transform
#include <cctype>     // Needed for tolower

using namespace std;

void PalindromeCheck();

int main() {
    PalindromeCheck();
    return 0;
}

void PalindromeCheck() {
    string sentence;
    cout << "Enter a sentence: ";
    getline(cin, sentence);

    
    sentence.erase(remove(sentence.begin(), sentence.end(), ' '), sentence.end());
    transform(sentence.begin(), sentence.end(), sentence.begin(), ::tolower);

    string reversed = string(sentence.rbegin(), sentence.rend());

    if (sentence == reversed) {
        cout << "The sentence is a palindrome." << endl;
    } else {
        cout << "The sentence is not a palindrome." << endl;
    }
}


//Assignment 4

#include <iostream>
#include <string>

using namespace std;

void LongestWordandLength();

int main() {
    LongestWordandLength();
    return 0;
}

void LongestWordandLength() {
    string sentence;
    cout << "Enter a sentence: ";
    getline(cin, sentence);

    cout << "Input: " << sentence << endl;

    string longestWord;
    size_t maxLength = 0;

    size_t start = 0;
    size_t end;

    while ((end = sentence.find(' ', start)) != string::npos) {
        string word = sentence.substr(start, end - start);
        if (word.length() > maxLength) {
            maxLength = word.length();
            longestWord = word;
        }
        start = end + 1; 
    }

    string lastWord = sentence.substr(start);
    if (lastWord.length() > maxLength) {
        maxLength = lastWord.length();
        longestWord = lastWord;
    }

    cout << "Longest word: " << longestWord << endl;
    cout << "Length: " << maxLength << endl;
}


//Assignment 5

#include <iostream>
#include <string>
#include <algorithm>  
using namespace std;

void countletters();

int main() {
    countletters();
    return 0;
}

void countletters() {

    string sentence; 
    cout << "Enter a sentence: ";
    getline(cin, sentence);
cout << "Input: " << sentence << endl;

transform(sentence.begin(), sentence.end(), sentence.begin(), ::toupper);
    int letterCounts[26] = {0}; 

    for (char c : sentence) {
        if (isalpha(c)) {
            letterCounts[c - 'A']++;
        }
    }

    cout << "Letter counts:" << endl;
    for (int i = 0; i < 26; ++i) {
        char letter = 'A' + i;
        cout << letter << ": " << letterCounts[i] << endl;
    }

}

//Assignment 6

#include <iostream>
#include <string>
using namespace std;

void maskemail();

int main() {
    maskemail();
    return 0;
}

void maskemail() {
    string email;
    cout << "Enter your email address: ";
    getline(cin, email);

    int atPos = email.find('@');

    string username = email.substr(0, atPos);
    string domain = email.substr(atPos);

    string masked = username.front() + string(username.size() - 2, '*') + username.back();

    cout << "Masked Email: " << masked + domain << endl;
}

//XC 1

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>  
#include <cctype>   

using namespace std;

void sortWordsAlphabetically();

int main() {
    sortWordsAlphabetically();
    return 0;
}

void sortWordsAlphabetically() {
    string sentence;
    cout << "Enter a sentence: ";
    getline(cin, sentence);

    stringstream ss(sentence);
    vector<string> words;
    string word;

    while (ss >> word) {
        word.erase(remove_if(word.begin(), word.end(), ::ispunct), word.end());
        words.push_back(word);
    }

    sort(words.begin(), words.end());

    cout << "Words sorted alphabetically: \n";
    for (string &w : words)
        cout << w << endl;
}


//XC 2

#include <iostream>
#include <string>
#include <vector>
#include <sstream>  
#include <cctype>   

using namespace std;

int main() {

    string sentence;
    cout << "Enter a sentence: ";
    getline(cin, sentence);

    for (char &c : sentence) {
        if (c >= 'A' && c <= 'Z') {
            c = c + 32; // I converted it to the characters corresponding ASCII value
        }
    }

    std::cout << "Result: " << sentence << std::endl;
    return 0;

}




//XC 3

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>  
#include <cctype>   

using namespace std;

void keywordSearch();

int main() {
    keywordSearch();
    return 0;
}

void keywordSearch() {
    string text, word;
    cout << "Enter text: ";
    getline(cin, text);
    cout << "Enter word to search: ";
    getline(cin, word);

    size_t pos = text.find(word);
    bool found = false;

    while (pos != string::npos) {
        cout << "Found at index: " << pos << endl;
        found = true;
        pos = text.find(word, pos + 1);
    }

    if (!found)
        cout << "Word not found." << endl;
}


