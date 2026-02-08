#include "key_utils.h"
#include <iostream>
#include <string>
#include <vector>
#include <bitset>
using namespace std;

string shift_left(string sub_key){
    // write code from here. This shifts like "1001" t0 "0011"
    if (sub_key.empty()) return sub_key;

    char first = sub_key[0];
    sub_key.erase(0, 1);
    sub_key.push_back(first);
    return sub_key;
} 

vector<string> key_gen(string key)
{
    vector<string> sub_keys;

    string perm56 = "";
    perm56.reserve(56);
    for (int i = 0; i < 56; i++)
    {
        perm56.push_back(key[PC1[i] - 1]); 
    }

    string C = perm56.substr(0, 28);
    string D = perm56.substr(28, 28);

    const int shifts[16] = {1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1};

    for (int r = 0; r < 16; r++)
    {
        for (int s = 0; s < shifts[r]; s++)
        {
            C = shift_left(C);
            D = shift_left(D);
        }

        string CD = C + D;

        string Ki = "";
        Ki.reserve(48);
        for (int i = 0; i < 48; i++)
        {
            Ki.push_back(CD[PC2[i] - 1]);
        }

        sub_keys.push_back(Ki);
    }

    return sub_keys;
}