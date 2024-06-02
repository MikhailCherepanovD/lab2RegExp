#include <vector>
#include <string>
#include <map>
#include <unordered_set>
#include <set>
#include <queue>
#include <QString>
#include "algorithm"

using namespace std;
class RegExpAnalyze{
    enum State{
        S0,           //0
        S1,
        S2,
        S3,
        S4,
        S5,
        S6,
        S7,
        Se
    };
    const int AMOUNT_STATES=9;
    const int AMOUNT_CHARS=128;
    vector<vector<int>> table_state;
    int curr_state;
    int next_state;
public:
    void CreateTable();
    RegExpAnalyze();
    bool Analyse(string str);
    QString GetRandomStr();
};
