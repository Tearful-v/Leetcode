class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        std::vector<int> answers(tasks.size());
        long long global_time = 0;
        std::priority_queue< std::pair<int, int>, //wieght, index
            std::vector<std::pair<int, int>>,
            std::greater<std::pair<int, int>> > priority;

        for (int i = 0; i < servers.size(); ++i) {
            priority.push(std::make_pair(servers[i], i));
        }

        std::priority_queue< std::pair< int, std::pair<int, int> >,  //time, weight, index
            std::vector< std::pair< int, std::pair<int, int> > >,
            std::greater<std::pair< int, std::pair<int, int> > > >time;

        for (int i = 0; i < tasks.size(); ++i) {
            global_time = std::max(global_time, static_cast<long long>(i));
            if (priority.empty()) {
                global_time = time.top().first;
            }

            while (!time.empty() && time.top().first <= global_time) {
                auto tmp = time.top();
                priority.push({tmp.second.first, tmp.second.second});
                time.pop();
            }

            auto server = priority.top();
            priority.pop();
            answers[i] = server.second;
            time.push({global_time + tasks[i], {server.first, server.second}});
        }

        return answers;
    }
};
