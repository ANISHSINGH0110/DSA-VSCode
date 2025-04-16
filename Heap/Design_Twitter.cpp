class Twitter {
    struct Tweet {
       int tweetId;
       int time;
       Tweet(int id, int t) : tweetId(id), time(t) {};
    };
    
    // Map userID to the tweets that the user has posted
    unordered_map<int, vector<Tweet>> tweets;
    // Map userId to a set of userIds they are following
    unordered_map<int, unordered_set<int>> following;
    
    // Min-heap comparator for tweets
    class comp {
    public:
        bool operator()(const Tweet& a, const Tweet& b) {
            return a.time > b.time;
        }
    };
    
    int time; // Global clock
    
 public:
     Twitter() {
         time = 0;
     }
     
     void postTweet(int userId, int tweetId) {
         tweets[userId].push_back(Tweet(tweetId, time++));
     }
     
     vector<int> getNewsFeed(int userId) {
         priority_queue<Tweet, vector<Tweet>, comp> minHeap;
 
         // Add userId's tweets
         if (tweets.find(userId) != tweets.end()) {
             for (auto& tweet : tweets[userId]) {
                 minHeap.push(tweet);
                 if (minHeap.size() > 10)
                     minHeap.pop(); // Keep only 10 most recent
             }
         }
 
         // Add tweets from followees
         if (following.find(userId) != following.end()) {
             for (int followeeId : following[userId]) {
                 if (tweets.find(followeeId) != tweets.end()) {
                     for (auto& tweet : tweets[followeeId]) {
                         minHeap.push(tweet);
                         if (minHeap.size() > 10)
                             minHeap.pop();
                     }
                 }
             }
         }
 
         // Extract tweets from the heap
         vector<int> newFeedTweets;
         while (!minHeap.empty()) {
             Tweet topTweet = minHeap.top();
             minHeap.pop();
             newFeedTweets.push_back(topTweet.tweetId);
         }
 
         reverse(newFeedTweets.begin(), newFeedTweets.end());
         return newFeedTweets;
     }
     
     void follow(int followerId, int followeeId) {
         if (followerId == followeeId)
             return; // Can't follow oneself
         following[followerId].insert(followeeId);
     }
     
     void unfollow(int followerId, int followeeId) {
         if (following.find(followerId) != following.end())
             following[followerId].erase(followeeId);
     }
 };