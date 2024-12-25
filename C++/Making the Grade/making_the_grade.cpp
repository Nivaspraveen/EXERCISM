#include <array>
#include <string>
#include <vector>
#include <sstream>

// Round down all provided student scores.
std::vector<int> round_down_scores(std::vector<double> student_scores) {
    std::vector<int> rounded_scores;
    for (double score : student_scores) rounded_scores.emplace_back(static_cast<int>(score));
    return rounded_scores;
}


// Count the number of failing students out of the group provided.
int count_failed_students(std::vector<int> student_scores) {
    int count = 0;
    for (int score : student_scores) {
        if (score <= 40) count++;
    }
    return count;
}

// Determine how many of the provided student scores were 'the best' based on the provided threshold.
std::vector<int> above_threshold(std::vector<int> student_scores, int threshold) {
    std::vector<int> filtered_scores;
    for (int score : student_scores) {
        if (score >= threshold) filtered_scores.emplace_back(score);
    }
    return filtered_scores;
}

// Create a list of grade thresholds based on the provided highest grade.
std::array<int, 4> letter_grades(int highest_score) {
    int range = highest_score - 40, interval = range / 4;
    return {41, 41 + interval, 41 + 2 * interval, 41 + 3 * interval};
}

// Organize the student's rank, name, and grade information in ascending order.
std::vector<std::string> student_ranking(std::vector<int> student_scores, std::vector<std::string> student_names) {
    std::vector<std::string> rankings;
    for (size_t i = 0; i < student_scores.size(); ++i) {
        std::ostringstream oss;
        oss << (i + 1) << ". " << student_names[i] << ": " << student_scores[i];
        rankings.emplace_back(oss.str());
    }
    return rankings;
}

// Create a string that contains the name of the first student to make a perfect score on the exam.
std::string perfect_score(std::vector<int> student_scores, std::vector<std::string> student_names) {
    for (size_t i = 0; i < student_scores.size(); ++i) {
        if (student_scores[i] == 100) return student_names[i];
    }
    return "";
}
