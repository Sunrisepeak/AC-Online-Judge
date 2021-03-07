class Solution {
public:
    bool isNumber(string s) {
        if (s.size() == 0) return false;

        int bgn = s.find_first_not_of(' ');
        int ed = s.find_last_not_of(' ');
        
        if (bgn != -1) s = s.substr(bgn, ed + 1 - bgn);
        else return false;
        
        auto it = s.begin();
        end = s.end();
        bool numeric = scanInteger(it);
        if (*it == '.') {
            it++;
            numeric |= scanUInteger(it);
        }
        if ((*it & 0b11011111) == 'E') {
            it++;
            numeric &= scanInteger(it);
        }
        return numeric && it == s.end();
    }
private:
    string::iterator end;
    bool scanUInteger(string::iterator &it) {
        auto before = it;
        while (it != end && isdigit(*it)) it++;
        return it > before;
    }

    bool scanInteger(string::iterator &it) {
        if (*it == '+' || *it == '-') it++;
        return scanUInteger(it);
    }
};
