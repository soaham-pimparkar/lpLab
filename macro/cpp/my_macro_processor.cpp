#include<iostream>
#include<fstream>
#include<vector>
#include<tuple>
#include<sstream>
#include<string>

using namespace std;

class MacroProcessor{

    vector<tuple<string, int, int>> mnt;
    vector<vector<string>> mdt;
    vector<tuple<string, string>> kpt;

    vector<vector<string>> tokens;

    MacroProcessor(string filepath){
        vector<string> lines = linize(readFile(filepath));
        for (string line : lines){
            tokens.push_back(tokenize(line));
        }
    }

    void perform(){

        
    }

    string readFile (string filePath){
        string output = "";
        fstream iStream (filePath, ios:: in);
        char c = iStream.get();
        while( !iStream.eof()){
            output += c;
            c = iStream.get();
        }
        return output;
    }

    vector<string> linize(string input){
        vector<string> lines;
        string line;
        stringstream sStream(input);
        while(getline(sStream, line, '\n')){
            lines.push_back(line);
        }
        return lines;
    }

    vector<string> tokenize (string line){
        vector<string> tokens;
        string token = "";
        stringstream sStream(line);
        while(sStream>>token){
            tokens.push_back(line);
        }
        return tokens;
    }


};