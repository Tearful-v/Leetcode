class Solution {
public:
    int minSessions(vector<int>& tasks, int sessionTime) {//для каждого множества хочу хранить: {сколько подходов для выполнения; минимальное время выполнения последнего подхода}
        int n = tasks.size();
        std::pair<int, int> best[1 << n]; //контейнер битовых масок для работы с множествами
        best[0] = {1, 0};
        for (int s = 1; s < (1 << n); ++s) { //бегаем по маскам
            best[s] = {n + 1, 0};
            for (int task = 0; task < n; ++task) {
                if (s & (1 << task)) {// есть ли таска в указанном множестве
                    auto check = best[s ^ (1 << task)]; //хочу найти результат множества без текущего веса и воткнуть его
                    if (check.second + tasks[task] <= sessionTime)
                        check.second += tasks[task]; //воткнулся
                    else {
                        ++check.first;
                        check.second = tasks[task];//не хватило места
                    }
                    best[s] = std::min(best[s], check);
                }
            }
        }
        return best[(1 << n) - 1].first;
    }
};
