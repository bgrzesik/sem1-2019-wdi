//
// Created by Bartłomiej Grzesik on 2019-03-04.
//

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>
#include <vector>

class Token
{
public:
    Token(char op) : op(op), is_operator(true), val(NAN)
    {
    }

    Token(const std::string &num) : is_operator(false), op('n')
    {
        std::istringstream buf(num);
        buf >> this->val;
    }

    Token(float val) : is_operator(false), val(val)
    {
    }

    bool IsOperator() const
    {
        return is_operator;
    }

    char GetOperator() const
    {
        return op;
    }

    float GetValue() const
    {
        return val;
    }

private:
    bool is_operator;
    char op;
    float val;
};

void DebugTokens(const std::vector<Token> &tokens)
{
//    std::cout << "DEBUG ";
//    for (const Token &token: tokens) {
//        if (token.IsOperator()) {
//            std::cout << token.GetOperator();
//        } else {
//            std::cout << token.GetValue();
//        }
//        std::cout << "\t";
//    }
//    std::cout << std::endl;
}

void DebugOp(char op, float lval, float rval, float nval)
{
//    std::cout << "OP " << lval << " " << op << " " << rval << " = " << nval << std::endl;
}

template<typename Iter>
Iter ComputeValue(Iter begin, std::vector<Token> &tokens, bool &error)
{

    Iter i;

    for (i = begin; i != tokens.end(); i++) {
        Token &token = *i;

        if (!token.IsOperator()) {
            continue;
        }

        if (token.GetOperator() == '(') {
            Iter fin = ComputeValue(i + 1, tokens, error);
            if (error) {
                return fin;
            }
            i = tokens.erase(i);
            i = tokens.erase(i + 1);
            DebugTokens(tokens);

            continue;
        }

        if (token.GetOperator() == ')') {
            break;
        }
    }

    for (i = begin; i != tokens.end(); i++) {
        Token &token = *i;

        if (!token.IsOperator()) {
            continue;
        }

        if (token.GetOperator() == '^') {
            Iter left = i - 1;
            Iter right = i + 1;

            if ((*left).IsOperator() || (*right).IsOperator()) {
                error = true;
                return i;
            }

            float lval = (*left).GetValue();
            float rval = (*right).GetValue();

            float nval = pow(lval, rval);

            DebugOp('^', lval, rval, nval);

            i = tokens.erase(left, right + 1);
            tokens.insert(i, Token(nval));
            DebugTokens(tokens);
        }

        if (token.GetOperator() == ')') {
            break;
        }
    }

    for (i = begin; i != tokens.end(); i++) {
        Token &token = *i;

        if (!token.IsOperator()) {
            continue;
        }

        if (token.GetOperator() == '*' || token.GetOperator() == '/') {
            Iter left = i - 1;
            Iter right = i + 1;

            if ((*left).IsOperator() || (*right).IsOperator()) {
                error = true;
                return i;
            }

            float lval = (*left).GetValue();
            float rval = (*right).GetValue();

            float nval;
            if (token.GetOperator() == '*') {
                nval = lval * rval;
                DebugOp('*', lval, rval, nval);
            } else {
                nval = lval / rval;
                DebugOp('/', lval, rval, nval);
            }

            i = tokens.erase(left, right + 1);
            tokens.insert(i, Token(nval));
            DebugTokens(tokens);
        }

        if (token.GetOperator() == ')') {
            break;
        }
    }

    for (i = begin; i != tokens.end(); i++) {
        Token &token = *i;

        if (!token.IsOperator()) {
            continue;
        }

        if (token.GetOperator() == '-' || token.GetOperator() == '+') {
            Iter left = i - 1;
            Iter right = i + 1;

            if ((*left).IsOperator() || (*right).IsOperator()) {
                error = true;
                return i;
            }

            float lval = (*left).GetValue();
            float rval = (*right).GetValue();

            float nval;
            if (token.GetOperator() == '-') {
                nval = lval - rval;
                DebugOp('-', lval, rval, nval);
            } else {
                nval = lval + rval;
                DebugOp('+', lval, rval, nval);
            }

            i = tokens.erase(left, right + 1);
            tokens.insert(i, Token(nval));
            DebugTokens(tokens);
        }

        if (token.GetOperator() == ')') {
            break;
        }
    }

    return i;
}

int main(int argc, const char **argv)
{
    std::cout.setf(std::ios::fixed, std::ios::floatfield);
    std::cout.precision(2);

    do {
        std::string a;
        std::getline(std::cin, a);

        std::ostringstream buf;
        bool was_number = false;
        std::vector<Token> tokens;

        for (char c : a) {
            if (c == ' ') {
                continue;
            }

            if (c == '-' && !was_number) {
                buf << c;
                was_number = true;
            } else if (c == '+' || c == '-' || c == '/' || c == '*' || c == '^' || c == '(' || c == ')') {
                if (was_number) {
                    tokens.emplace_back(buf.str());

                    buf.str("");
                    buf.clear();

                    was_number = false;
                }
                tokens.emplace_back(c);
            } else if ((c >= '0' && c <= '9') || c == '.') {
                buf << c;
                was_number = true;
            } else {
                std::cerr << "ERROR: Token " << c << std::endl;
                continue;
            }
        }

        if (was_number) {
            tokens.emplace_back(buf.str());
        }

        bool error = false;
        DebugTokens(tokens);
        std::vector<Token>::const_iterator error_token = ComputeValue(tokens.begin(), tokens, error);
        DebugTokens(tokens);

        if (tokens.size() == 1 && !tokens[0].IsOperator() && !error) {
            std::cout << tokens[0].GetValue() << std::endl;
        } else {
            std::cerr << "ERROR: Syntax ";

            if ((*error_token).IsOperator()) {
                std::cerr << " OP " << (*error_token).GetOperator();
            } else {
                std::cerr << " VAL " << (*error_token).GetValue();
            }

            std::cerr << std::endl;
            continue;
        }

        break;
    } while (true);
}
