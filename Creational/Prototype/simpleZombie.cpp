class Enemy {
public:
    virtual void Attack() = 0;
    virtual unique_ptr<Enemy> Clone() const = 0;
    virtual void SetHealth(int h) = 0;
    virtual ~Enemy() = default;
};

class Zombie : public Enemy {
    int health = 100;
public:
    void Attack() override {
        cout << "Zombie attacks! Health = " << health << endl;
    }

    void SetHealth(int h) override {
        health = h;
    }

    unique_ptr<Enemy> Clone() const override {
        return make_unique<Zombie>(*this); // deep copy via copy constructor
    }
};

int main() {
    auto zombiePrototype = make_unique<Zombie>();

    auto zombie1 = zombiePrototype->Clone();
    auto zombie2 = zombiePrototype->Clone();

    zombie2->SetHealth(50);

    zombie1->Attack(); // Zombie attacks! Health = 100
    zombie2->Attack(); // Zombie attacks! Health = 50
}
