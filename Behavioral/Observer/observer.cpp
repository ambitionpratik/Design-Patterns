#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <string>

// Observer Interface
class IObserver {
public:
    virtual void update(const std::string& news) = 0;
    virtual ~IObserver() = default;
};

// Subject Interface
class ISubject {
public:
    virtual void attach(std::shared_ptr<IObserver> observer) = 0;
    virtual void detach(std::shared_ptr<IObserver> observer) = 0;
    virtual void notify() = 0;
    virtual ~ISubject() = default;
};

// Concrete Subject
class NewsPublisher : public ISubject {
private:
    std::vector<std::shared_ptr<IObserver>> observers;
    std::string latestNews;

public:
    void attach(std::shared_ptr<IObserver> observer) override {
        observers.push_back(observer);
    }

    void detach(std::shared_ptr<IObserver> observer) override {
        observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
    }

    void notify() override {
        for (const auto& observer : observers) {
            observer->update(latestNews);
        }
    }

    void setNews(const std::string& news) {
        latestNews = news;
        notify();  // Notify all observers
    }
};

// Concrete Observer
class NewsReader : public IObserver {
private:
    std::string name;

public:
    NewsReader(const std::string& n) : name(n) {}

    void update(const std::string& news) override {
        std::cout << name << " received news: " << news << std::endl;
    }
};

// Client Code
int main() {
    auto publisher = std::make_shared<NewsPublisher>();

    auto alice = std::make_shared<NewsReader>("Alice");
    auto bob = std::make_shared<NewsReader>("Bob");

    publisher->attach(alice);
    publisher->attach(bob);

    publisher->setNews("Breaking: Observer Pattern Explained!");
    publisher->setNews("Update: Observer Pattern in C++!");

    publisher->detach(bob);
    publisher->setNews("Final News: Bob will not receive this.");

    return 0;
}
