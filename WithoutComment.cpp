#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    cout<< "Testing: " << 16/2 << " = " << 4*2 <<".\n\n";
    char c1='/';
    ifstream file;
    ofstream ofile;
    long fptr=file.tellg();
    ofile.open("WithoutComment.cpp",ios::out);
    file.open("main.cpp",ios::in);
    char c;
    while(!file.eof())
    {
        file.read((char*)&c,sizeof(char));
        fptr=file.tellg();
        if(c=='/')
        {
            file.read((char*)&c,sizeof(char));
            if(c=='*')
            {
                while(file.read((char*)&c,sizeof(char)))
                {
                    if(c=='/')
                        break;
                }
            }
            else
            {
                cout<<"/";
                ofile.write((char*)&c1,sizeof(char));
                cout<<c;
                ofile.write((char*)&c,sizeof(char));
            }
        }
        else
        {
            cout<<c;
            ofile.write((char*)&c,sizeof(char));
        }
    }
    return 0;
}

