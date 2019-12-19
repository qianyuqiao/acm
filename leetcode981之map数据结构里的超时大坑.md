TL的代码
```
class TimeMap {
public:
 
    /** Initialize your data structure here. */
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        M[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        if (M.count(key) == 0)
            return "";
        map<int, string> it = M[key];
        map<int, string>::iterator index = it.upper_bound(timestamp);
        if (index == it.begin())
            return "";
        else
        {
            index--;
            return index->second;
        }
    }
private:
    unordered_map<string, map<int, string > > M;
};
```
然后, ac代码
```
class TimeMap {
public:
 
    /** Initialize your data structure here. */
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        M[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        if (M.count(key) == 0)
            return "";
        auto it = M.find(key);
        auto index = it->second.upper_bound(timestamp);
        if (index != it->second.begin())
        {
            index--;
            return index->second;            
        }
        else
        {
            return "";
        }
    }
private:
    unordered_map<string, map<int, string > > M;
};
```
区别在于，unordered_map:: find(key) 比 unordered_map[key]的效率要更加高，大概可以快10倍
```
#include<iostream>
#include<map>
#include<set>
#include<string>
#include<utility>
#include<time.h>
using namespace std;
typedef pair<int, string> P;
 
void set(){
}
int main()
{
    clock_t begin, end;
    map<string, int> M;
    M["1"] = 1;
    M["2"] = 2;
    M["3"] = 3;
    begin = clock();
    cout << M["1"] << endl;
    end = clock();
    cout << "used: " << end-begin << endl;
 
    begin = clock();
    cout << (M.find("1"))->second << endl;
    end = clock();
    cout << "used: " << end-begin << endl;
    return 0;
}
```
结果find()比运算符[]快了10多倍
```
1
used: 25
1
used: 2
```
