 #include <iostream>
#include<fstream>
#include<bits/stdc++.h>
#include <stdio.h>
#include <dirent.h>
#include<string>
using namespace std;

struct Node
{
    char data = '#';
    Node* left = NULL;
    Node* right = NULL;
};


string character = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789,.?";
string symbol[39] = {".-", "-...", "-.-.", "-..",
                     ".", "..-.", "--.", "....", "..", ".---", "-.-",
                     ".-..", "--", "-.", "---", ".--.", "--.-",
                     ".-.", "...", "-", "..-", "...-", ".--", "-..-",
                     "-.--", "--..", "-----", ".----", "..---", "...--",
                     "....-",".....", "-....", "--...", "---..", "----.",
                     ".----.", "-.--.", "-.--.-"
                    };





void building_tree(Node* root)

{


    for(int i = 0; i < 39; ++i)
    {
        string code = symbol[i];
        Node* curNode = root;
        for(int j = 0; j < code.size(); ++j)
        {
            if(code[j] == '.')
            {
                if(curNode->left == NULL)
                {
                    Node* newNode = new Node();
                    curNode->left = newNode;
                }
                curNode = curNode->left;
            }
            else
            {
                if(curNode->right == NULL)
                {
                    Node* newNode = new Node();
                    curNode->right = newNode;
                }
                curNode = curNode->right;
            }
            if(j == code.size() - 1) curNode->data = character[i];
        }
    }



}



std::string current_working_directory()
{
    char* cwd = _getcwd( 0, 0 ) ; // **** microsoft specific ****
    std::string working_directory(cwd) ;
    std::free(cwd) ;
    return working_directory ;
}

void show(string &s, Node* curNode,int flag)
{
    char converter;

    if(flag == 0)    /// when flag is 0 that means it is the first letter of the sentence.
    {
        for(int i = 0; i < s.size(); ++i)
        {
            if(s[i] == '.') curNode = curNode->left;
            else curNode = curNode->right;
        }
        cout << curNode->data;
        s = "";
    }
    else if(flag!=0) /// when flag > 0 that means first letter is done rest of the letters will lower caps.
    {
        for(int i = 0; i < s.size(); ++i)
        {
            if(s[i] == '.') curNode = curNode->left;
            else curNode = curNode->right;
        }
        converter = curNode->data;

        if(converter >= 'A' && converter<= 'Z')  /// Checks does it have to convert the data if its between 'A' - 'Z', then it will convert else will just print data.
        {
            converter = converter - 'A'+ 'a';
            cout << converter;
            s = "";
        }
        else
        {
            cout << converter;
            s = "";

        }

    }


    return;

}
void morseDictionary()
{
    for(int i = 0 ; i<39; i++)
    {
        cout<<character[i]<<" = "<< symbol[i]<<endl;
    }


}
void decode(Node* root)
{



    fstream fin;
    cout<<endl;

    cout<<"Example of entering filename: D:/codes/in.txt"<<endl;

    cout<<endl;
    cout<<"!!!WARNING!!! if file name or folder name have space in their name, It will be a Invalid Input. "<<endl;
    cout<<endl;

    cout<<"Enter the path and filename: ";
    string entry;
    cin>>entry;






    fin.open(entry);
    if(fin.fail())
    {
        cout<<endl;
        cout<<"Invalid Input. "<<endl;
        cout<<"Renaming the file name or folder name containing space should solve the issue."<<endl;
    }
    else
    {
        cout<<endl;
        cout<<"File Read was Successful. "<<endl;

        cout<<endl;

        cout<<"Output File name is: out.txt"<<endl;
        cout<<"The path of the file location is: ";
        std::cout << current_working_directory() <<endl;

        cout<<endl;
        cout<<endl;
        cout<<"\t\t\t\t\t<<<< Good Bye >>>>\t\t\t\t"<<endl;
        cout<<endl;
        cout<<endl;
    }

    freopen("out.txt", "w", stdout);


    string input_MC;

    while(getline(fin, input_MC))
    {
        int flag = 0;
        string s = "";
        for(int i = 0; i < input_MC.size(); ++i)
        {
            if(input_MC[i] != ' ')
            {
                s += input_MC[i];
                if(i == input_MC.size() - 1)show(s, root,flag);
            }
            else if(input_MC[i - 1] == ' ') cout<< ' ';
            else
            {
                show(s, root,flag);
                flag++;
            }
        }
        cout<<endl;
    }

}


void encode()
{


    fstream fin;
    cout<<endl;

    cout<<"Example of entering filename: D:/codes/in.txt"<<endl;

    cout<<endl;
    cout<<"!!!WARNING!!! if file name or folder name have space in their name, It will be a Invalid Input. "<<endl;
    cout<<endl;

    cout<<"Enter the path and filename: ";
    string entry;
    cin>>entry;





    fin.open(entry);


    if(fin.fail())
    {
        cout<<endl;
        cout<<"Invalid Input. "<<endl;
        cout<<"Renaming the filename or Folder name containing space should solve the issue."<<endl;
    }
    else
    {
        cout<<endl;
        cout<<"File Read was Successful. "<<endl;
        cout<<endl;

        cout<<"Output File name is: out.txt"<<endl;

        cout<<"The path of the file location is: ";
        std::cout << current_working_directory() <<endl; /// expecting to keep the output file at the same directory of the .cpp file.

        cout<<endl;
        cout<<endl;
        cout<<"\t\t\t\t\t<<<< Good Bye >>>>\t\t\t\t"<<endl;
        cout<<endl;
        cout<<endl;
    }

    freopen("out.txt", "w", stdout);


    string input_T;
    while(getline(fin, input_T))
    {

        string s = "";
        for(int i = 0; i < input_T.size(); ++i)
        {
            if(input_T[i] >= 'a' && input_T[i] <= 'z')
            {
                input_T[i] = input_T[i] - 'a' + 'A';/// convert

            }
            else if(input_T[i] >= '0' && input_T[i] <= '9')
            {
                for (int j=26; j<36; j++)
                {

                    if(input_T[i]==character[j])
                    {
                        s += symbol[j];
                    }

                }

            }
            else if(input_T[i] == ',')
            {
                s += symbol[36];
            }
            else if(input_T[i] == '.')
            {
                s += symbol[37];
            }
            else if (input_T[i] == '?')
            {
                s += symbol[38];
            }
            s += symbol[input_T[i] - 'A'];///
            s+= " ";
        }
        cout<<s<<endl;
    }


}


int main()
{


    string x;

    Node* root = new Node();
    building_tree(root);

    char y = 177;
    cout<<"\t\t\t\t";
    for(int i=0; i<49; i++)
    {
        cout<<y;
    }
    cout<<endl;
    cout<<"\t\t\t\t"<<y<<" \t Morse Code Encoder and Decoder\t\t"<<y<<endl;
    cout<<"\t\t\t\t";
    for(int i=0; i<49; i++)
    {
        cout<<y;
    }

    cout<<endl;
    cout<<endl;

/// this characters are created for menu modification
    char a = 205;
    char b = 201;
    char c = 200;
    char d = 187;
    char e = 188;
    char f = 186;

    cout<<endl;
    cout<<b;
    for(int i=0; i<23; i++)
    {
        cout<<a;
    }
    cout<<d;
    cout<<endl;

    cout<<f<<"\t  Menu\t\t"<<f<<endl;
    cout<<c;
    for(int i=0; i<23; i++)
    {
        cout<<a;
    }
    cout<<e;
    cout<<endl;
    cout<<endl;



    cout<<"1. Morse Dictionary"<<endl;
    cout<<"2. Decode"<<endl;
    cout<<"3. Encode"<<endl;
    cout<<"How do you want to Do: ";
    cin>>x;

    if (x=="1")
    {
        cout<<endl;
        morseDictionary();
    }
    else if (x=="2")
    {
        decode(root);

    }
    else if (x=="3")
    {
        encode();

    }
    else
    {
        cout<<"Invalid Input"<<endl;

    }

    return 0;
}





