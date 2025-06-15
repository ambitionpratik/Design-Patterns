//Zombie creation is very expensive and takes many argument , like geometric Model, Animation, AI in it's config.
//since most of the stuffs are common for any Zombies we can create a Zombie once with all the config required and call it a prototype.
//next time whenever it is needed we should just clone it, do the shallow copy of the heavy stuffs, instead of re creating it.

//zombie provides the setter method to make it specialized, or differenc than prototype zombie, and that's a cheap operation.

#include <iostream>
#include <memory>
#include <string>
#include <vector>

using namespace std;

// ----- Mock Complex Classes -----

//geometric model
class Model {
public:
    string name;
    Model(string n) : name(n) {
        cout << "[Model] Loading model: " << name << endl;
    }
};

class Animation {
public:
    string type;
    Animation(string t) : type(t) {
        cout << "[Animation] Loading animation set: " << type << endl;
    }
};

class AI {
public:
    string behavior;
    AI(string b) : behavior(b) {
        cout << "[AI] Building behavior tree: " << behavior << endl;
    }
};

// ----- EnemyConfig Struct -----
struct EnemyConfig {
    shared_ptr<Model> model;         // shared
    shared_ptr<Animation> anim;      // shared
    shared_ptr<AI> aiBrain;          // shared
    vector<string> lootTable;        // copied
    int health;                      // copied
    float speed;                     // copied
};

// ----- Enemy Interface -----
class Enemy {
public:
    virtual void Attack() = 0;
    virtual unique_ptr<Enemy> Clone() const = 0;
    virtual void SetHealth(int h) = 0;
    virtual ~Enemy() = default;
};

// ----- Concrete Zombie Class -----
class Zombie : public Enemy {
    EnemyConfig config;

public:
    Zombie(const EnemyConfig& cfg) : config(cfg) {}

    // Copy constructor
    Zombie(const Zombie& other) : config(other.config) {}

    unique_ptr<Enemy> Clone() const override {
        return make_unique<Zombie>(*this);  // efficient clone
    }

    void Attack() override {
        cout << "🧟 Zombie attacks with speed " << config.speed
             << ", health: " << config.health
             << ", loot: " << config.lootTable[0] << endl;
    }

    void SetHealth(int h) override {
        config.health = h;
    }
};

// ----- Main -----
int main() {
    // Shared expensive resources
    auto model = make_shared<Model>("zombie.mesh");
    auto animation = make_shared<Animation>("zombie.anim");
    auto ai = make_shared<AI>("aggressive");

    // Base config
    EnemyConfig zombieConfig{
        model,
        animation,
        ai,
        {"Rotten Flesh", "Old Coin"},
        100,
        1.5f
    };

    // Create prototype
    unique_ptr<Enemy> zombiePrototype = make_unique<Zombie>(zombieConfig);

    // Clone zombies
    auto zombie1 = zombiePrototype->Clone();
    auto zombie2 = zombiePrototype->Clone();

    zombie2->SetHealth(50); // Damaged zombie

    zombie1->Attack(); // full health
    zombie2->Attack(); // half health

    return 0;
}
