#include <iostream>
#include<sstream>
#include<string>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    int flag = 1;
    string get;
    string input;
    getline(cin,input);
    stringstream ss(input);
    string token;
    while(ss >> token){
        for (char c : token)
        {
            if(c == '.'){
                flag = 2;
                break;
            }
             if(c == '/'){
                flag = 4;
                break;
            }           
            if(c == '%'){
                flag = 3;
                break;
            }
        }
    }
    int t;
    string x1,x2;
    string x3;
    string x;
    int reversed_num = 0;
    int num = stoi(input);

    switch(flag){
        case 1:

            while(num != 0)
            {
                int remainder = num % 10;
                reversed_num = reversed_num * 10 + remainder;
                num /= 10;
            }

            cout << reversed_num << endl;
            break;
        case 2:
            for(t =0;t<=input.size();t++){
                if(input[t]=='.'){
                    break;
                }
            }
            for(int p = 0;p<t;p++){
                x1.push_back(input[p]);
            }
            for(int p = t+1;p<=input.size()-1;p++){
                x2.push_back(input[p]);
            }
            
            reverse(x1.begin(),x1.end());
            reverse(x2.begin(),x2.end());
            x = x1 + '.' + x2;
            cout << x <<endl;
            break;
        case 3:
            for (int n = 0;n<=input.size()-2;n++){
                x3.push_back(input[n]);
            }
            reverse(x3.begin(),x3.end());
            x3 = x3 + '%';
            cout << x3 <<endl;
        case 4:
            for(t =0;t<=input.size();t++){
                if(input[t]=='/'){
                    break;
                }
            }
            for(int p = 0;p<t;p++){
                x1.push_back(input[p]);
            }
            for(int p = t+1;p<=input.size()-1;p++){
                x2.push_back(input[p]);
            }
            reverse(x1.begin(),x1.end());
            reverse(x2.begin(),x2.end());
            x = x1 + '/' + x2;
            cout << x <<endl;
    }
    return 0;
}
