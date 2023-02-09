#pragma once

#include <string>

class Scanner
{
public:
    Scanner(std::string input = "") {
        _input=input;
        pos=0;
    }

    std::string next() {
        if(isDone()) throw std::logic_error("error");
        std::string result = "";
        skipWhiteSpace();
        for(auto token: tokenList) {
            if(_input.compare(pos, token.length(), token) == 0) {
                pos = pos + token.length();
                result = token;
                break;
            }
        }

        return result;

    }

    double nextDouble() {
        std::string s = "";
        skipWhiteSpace();
        
        if (_input[pos] == '-')
            s = s + _input[pos++];

        while (_input[pos] <= '9' && _input[pos] >= '0')
            s = s + _input[pos++];

        if (_input[pos] == '.')
            s = s + _input[pos++];

        while (_input[pos] <= '9' && _input[pos] >= '0')
            s = s + _input[pos++];
        
        return std::stod(s);

    }

    bool isDone() {
        skipWhiteSpace();
        return pos >= _input.length();
    }
private:
    std::string _input;
    std::string::size_type pos = 0;
    const std::vector<std::string> tokenList = {"CompoundShape", "(", ")", ",", "Vector", "Rectangle", "Circle", "Triangle"};
    void skipWhiteSpace() {
        
        while(_input[pos] == ' ' || _input[pos] == '\n') {
            pos++;
        }
    }

};