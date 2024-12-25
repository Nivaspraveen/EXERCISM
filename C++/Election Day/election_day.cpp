#include <string>
#include <vector>

namespace election
{

    struct ElectionResult
    {
        std::string name{};
        int votes{};
    };

    int vote_count(const ElectionResult &result)
    {
        return result.votes;
    }

    void increment_vote_count(ElectionResult &result, int votes)
    {
        result.votes += votes;
    }

    ElectionResult &determine_result(std::vector<ElectionResult> &final_count)
    {
        ElectionResult *winner = &final_count[0];
        for (auto &result : final_count)
        {
            if (result.votes > winner->votes)
                winner = &result;
        }
        winner->name = "President " + winner->name;
        return *winner;
    }
}