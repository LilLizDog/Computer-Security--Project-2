#include "DES.h"
#include "permutation.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Function to encrypt plaintext using DES algorithm
string encryption(string plaintext, vector<string> keys) {
    // Step 1: Apply Initial Permutation (IP) to the plaintext bits
    string permuted_plaintext = "";
    for(int i = 0; i < 64; i++) {
        permuted_plaintext += plaintext[IP[i] - 1];
    }
    
    // Step 2: Split the 64 bits into left and right halves 
    string left = permuted_plaintext.substr(0, 32);
    string right = permuted_plaintext.substr(32, 32);
    
    // Step 3: Perform 16 rounds of DES
    for(int i = 0; i < 16; i++) {
        string right_expanded = expansion(right);  // Expand right from 32 to 48 bits
        string xored = XOR(right_expanded, keys[i], 48);  // XOR with round key
        string substituted = sBox(xored);  // Apply S-boxes (48 to 32 bits)
        string permuted = pBox(substituted);  // Apply P-box permutation
        
        string new_right = XOR(left, permuted, 32);  // New right = old left XOR f(old right, key)
        left = right;  // New left = old right
        right = new_right;
    }
    
    // Step 4: Swap left and right halves
    string combined = right + left;
    
    // Step 5: Apply Final Permutation (FP)
    string ciphertext = "";
    for(int i = 0; i < 64; i++) {
        ciphertext += combined[FP[i] - 1];
    }
    
    return ciphertext;
}

// Function to decrypt ciphertext using DES algorithm
string decryption(string encrypted, vector<string> keys) {
    // Step 1: Apply Initial Permutation (IP) to the encrypted bits
    string permuted_encrypted = "";
    for(int i = 0; i < 64; i++) {
        permuted_encrypted += encrypted[IP[i] - 1];
    }
    
    // Step 2: Split 64 bits into left and right halves
    string left = permuted_encrypted.substr(0, 32);
    string right = permuted_encrypted.substr(32, 32);
    
    // Step 3: Perform 16 rounds of DES with keys in reverse order
    for(int i = 15; i >= 0; i--) {
        string right_expanded = expansion(right);  // Expand right from 32 to 48 bits
        string xored = XOR(right_expanded, keys[i], 48);  // XOR with round key (reversed)
        string substituted = sBox(xored);  // Apply S-boxes (48 to 32 bits)
        string permuted = pBox(substituted);  // Apply P-box permutation
        
        string new_right = XOR(left, permuted, 32);  // New right = old left XOR f(old right, key)
        left = right;  // New left = old right
        right = new_right;
    }
    
    // Step 4: Swap left and right halves
    string combined = right + left;
    
    // Step 5: Apply Final Permutation (FP)
    string plaintext = "";
    for(int i = 0; i < 64; i++) {
        plaintext += combined[FP[i] - 1];
    }
    
    return plaintext;
}
