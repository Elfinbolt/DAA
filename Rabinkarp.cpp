#include <iostream>
#include <string>
using namespace std;

void findPattern(string text, string pattern) {
    // Algorithm setup variables
    int base = 256;           // Number of ASCII characters
    int prime = 101;          // Prime number for hash calculation
    
    // Length variables
    int textLen = text.length();      // Length of input text
    int patLen = pattern.length();    // Length of pattern to find    
    
    // Hash variables
    int patternHash = 0;      // Hash value of the pattern
    int textHash = 0;         // Hash value of current text window
    int power = 1;            // Stores base^(patLen-1) mod prime
    
    // Counter for matches found
    int matchCount = 0;
    
    // Step 1: Calculate base^(patLen-1) mod prime 
    for (int i = 0; i < patLen - 1; i++) {
        power = (base * power) % prime;
    }
    
    // Step 2: Calculate initial hash values
    for (int i = 0; i < patLen; i++) {
        patternHash = (base * patternHash + pattern[i]) % prime;
        textHash = (base * textHash + text[i]) % prime;
    }
    
    // Step 3: Slide pattern over text
    for (int i = 0; i <= textLen - patLen; i++) {
        
        // Check if hash values match
        if (patternHash == textHash) {
            
            // Verify character by character
            bool found = true;
            for (int j = 0; j < patLen; j++) {
                if (text[i + j] != pattern[j]) {
                    found = false;
                    break;
                }
            }
            
            // If pattern found, print position
            if (found) {
                cout << "Pattern found at position: " << (i + 1) << endl;
                matchCount++;
            }
        }
        
        // Calculate hash for next window
        if (i < textLen - patLen) {
            textHash = (base * (textHash - text[i] * power) + text[i + patLen]) % prime;
            
            // Handle negative hash
            if (textHash < 0) {
                textHash = textHash + prime;
            }
        }
    }
    
    // Print total matches found
    if (matchCount == 0) {
        cout << "Pattern not found!" << endl;
    } else {
        cout << "Total matches found: " << matchCount << endl;
    }
}

int main() {
    string text, pattern;
    
    cout << "Enter text: ";
    cin >> text;
    
    cout << "Enter pattern: ";
    cin >> pattern;
    
    cout << endl;
    findPattern(text, pattern);
    
    return 0;
}