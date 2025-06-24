//CHARACTER HASHING 

#include<iostream>
using namespace std;

int main()
{
    //for lower-case only 
    string s;
    cin >> s;
    
    //No limitations of array storing bcz 256 only !
    int size = s.size();
    int hash[26] = {0};// initialized all with zeroes
    // ASCII Values used ! a->97 and z->122
    //Pre-computing
    /*
    For all characters just hash[s[i]] += 1 is enough
    */
    for(int i=0;i<size;i++) 
    {
        int ch = s[i];//without this hash[s[i]-'a'] is also same and autocasted !
        hash[ch -'a'] += 1;
    } 
    
    // Number of characters you want to search
    int q;
    cin >> q;
    //here also we have to change it to hash[c]
    while(q--)
    {
        char c;
        cin >> c;
        cout << c <<"->" << hash[c-'a'] << endl;
    }    
    return 0;
}