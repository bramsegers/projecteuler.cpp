#include <sstream>
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

vector<string> readFile(string filename){
    string line;
    vector<string> lines;
    ifstream file(filename);
    if(file.is_open()){
        while(getline(file,line))
            lines.push_back(line);
        file.close();
    }
    else cout << "Unable to open file";
    return lines;
}

vector<string> strsplit(string s,string del){
    size_t pos_start=0, pos_end, delim_len=del.length();
    string token;
    vector<string> res;
    while((pos_end=s.find(del,pos_start))!=string::npos){
        token=s.substr(pos_start,pos_end-pos_start);
        pos_start=pos_end+delim_len;
        if(token.length()) res.push_back(token);
    }
    token=s.substr(pos_start);
    if(token.length()) res.push_back(token);
    return res;
}

string replaceAll(string str,string from,string to){
    size_t start_pos=0;
    while((start_pos=str.find(from,start_pos))!=string::npos){
        str.replace(start_pos,from.length(),to);
        start_pos+=to.length();
    }
    return str;
}