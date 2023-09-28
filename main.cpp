#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

class Content {
public:
    std::string title;
    std::vector<std::string> tags;

    Content(std::string t, std::vector<std::string> tg) : title(t), tags(tg) {}
};

class User {
public:
    std::vector<std::string> liked_tags;

    void likeTag(std::string tag) {
        liked_tags.push_back(tag);
    }
};

class RecommenderSystem {
    std::vector<Content> contents;

public:
    RecommenderSystem(std::vector<Content> c) : contents(c) {}

    std::vector<Content> recommend(User user) {
        std::map<std::string, int> scores;

        // 각 컨텐츠에 대한 사용자의 선호 점수를 계산
        for (auto &content : contents) {
            for (auto &tag : content.tags) {
                if (std::find(user.liked_tags.begin(), user.liked_tags.end(), tag) != user.liked_tags.end()) {
                    scores[content.title]++;
                }
            }
        }

        // 점수에 따라 컨텐츠를 정렬
        std::vector<Content> recommendations;
        for (auto &content : contents) {
            if (scores[content.title] > 0) {
                recommendations.push_back(content);
            }
        }

        std::sort(recommendations.begin(), recommendations.end(), [&](const Content &a, const Content &b) {
            return scores[a.title] > scores[b.title];
        });

        return recommendations;
    }
};

int main() {
    std::vector<Content> contents = {
        Content("Movie A", {"action", "comedy"}),
        Content("Movie B", {"drama", "romance"}),
        Content("Movie C", {"action", "thriller"})
    };

    User user;
    user.likeTag("action");

    RecommenderSystem system(contents);
    auto recommendations = system.recommend(user);

    std::cout << "Recommendations for user:" << std::endl;
    for (auto &content : recommendations) {
        std::cout << content.title << std::endl;
    }

    return 0;
}
