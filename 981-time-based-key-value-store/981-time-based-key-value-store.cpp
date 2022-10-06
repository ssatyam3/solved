class TimeMap {
private:
    unordered_map<string, unordered_map<int,string>> mp;
public:
    TimeMap() {    
    }
    
    void set(string key, string value, int timestamp) {
        mp[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        if(!mp.count(key)){
            return "";
        }
        
        for(int curr = timestamp; curr>=1 ; --curr){
            if(mp[key].count(curr)){
                return mp[key][curr];
            }
        }
        
        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */