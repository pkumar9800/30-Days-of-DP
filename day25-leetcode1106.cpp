class Solution {
public:
    bool parseBoolExpr(string expression) {
        return eval(expression, 0, expression.size() - 1);
    }

private:
    bool eval(const string &expr, int l, int r) {
        if (l == r) return expr[l] == 't';

        char op = expr[l];
        vector<bool> vals;
        int balance = 0;
        int start = l + 2;  

        for (int i = l + 2; i < r; ++i) {
            if (expr[i] == ',' && balance == 0) {
                vals.push_back(eval(expr, start, i - 1));
                start = i + 1;
            } else if (expr[i] == '(') balance++;
            else if (expr[i] == ')') balance--;
        }
        vals.push_back(eval(expr, start, r - 1)); 

        if (op == '!') return !vals[0];
        else if (op == '&') {
            for (bool v : vals) if (!v) return false;
            return true;
        } else {
            for (bool v : vals) if (v) return true;
            return false;
        }
    }
};
