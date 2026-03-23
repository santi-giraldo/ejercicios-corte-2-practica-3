#include <unordered_map>
#include <string>
using namespace std;

class AuthenticationManager {
private:
    int timeToLive;
    unordered_map<string, int> tokens;

public:
    AuthenticationManager(int timeToLive) {
        this->timeToLive = timeToLive;
    }
    
    void generate(string tokenId, int currentTime) {
        tokens[tokenId] = currentTime + timeToLive;
    }
    
    void renew(string tokenId, int currentTime) {
        if (tokens.count(tokenId) && tokens[tokenId] > currentTime) {
            tokens[tokenId] = currentTime + timeToLive;
        }
    }
    
    int countUnexpiredTokens(int currentTime) {
        int count = 0;
        for (auto &p : tokens) {
            if (p.second > currentTime) {
                count++;
            }
        }
        return count;
    }
};
/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */
