Name: Elizabeth Dreste and Preet Kaur

In this project, we are implementing the DES cryptography system, which is a symmetric key block cipher algorithm. 
In this part of the project, we created the encryption and decryption funcitons for the system.

This is what our encryption function does, step by step:
1. Initial Permutation (IP): Rearranges the 64-bit plaintext according to the IP table
2. Split: Divides into 32-bit left and right halves
3. 16 Rounds: Each round performs:
    Expansion of right half (32→48 bits)
    XOR with round key
    S-box substitution (48→32 bits)
    P-box permutation
    Feistel swap: new_left = old_right, new_right = old_left XOR f(old_right, key)
4. Final swap: Combines as right||left
5. Final Permutation (FP): Produces the ciphertext

This is what our decryption does, step by step:
1. Initial Permutation (IP): Rearranges the 64-bit ciphertext according to the IP table
2. Split: Divides into 32-bit left and right halves
3. 16 Rounds, but with keys in the reverse order: Each round performs:
    Expansion of right half (32→48 bits)
    XOR with round key
    S-box substitution (48→32 bits)
    P-box permutation
    Feistel swap: new_left = old_right, new_right = old_left XOR f(old_right, key)
4. Final swap: Combines as right||left
5. Final Permutation (FP): Produces the plaintext

To run the code:
Inside WSL or Linux terminal:
1. Compile the code using make:
   make

2. Run the program:
   ./main

3. When prompted, enter 'e' to encrypt or 'd' to decrypt
   - Entering 'e' will encrypt the test plaintext and display the ciphertext
   - Entering 'd' will encrypt then decrypt the test plaintext and display the original plaintext

4. To clean up compiled files:
   make clean