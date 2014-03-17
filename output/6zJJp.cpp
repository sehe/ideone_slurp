// error:	OK
// langId:	1
// langName:	C++ 4.8.1
// langVersion:	gcc-4.8.1
// time:	0
// date:	2011-10-03 01:35:15
// status:	0
// result:	15
// memory:	2860
// signal:	0
// public:	true
// ------------------------------------------------
#include <iostream>

struct Animal {
    virtual void eat(int amount ) {
        std::cout << "I eat like a generic Animal." << std::endl;
    }
    virtual ~Animal() { }
};

#if 0

// example 1
struct Wolf : Animal {
    virtual void eat(int amount) {
        std::cout << "I eat like a wolf!" << std::endl;
    }
};

struct Fish : Animal {
    virtual void eat(int amount) {
        std::cout << "I eat like a fish!" << std::endl;
    }
};

#else

// example 2

struct AnimalFood {
    virtual int readAmount() { return 5; }

    virtual void showName() {
        std::cout << "I'm generic animal food" << std::endl;
    }
};

struct PredatorFood : AnimalFood {
    virtual int readAmount() { return 500; }

    virtual void showName() {
        std::cout << "I'm food for a predator" << std::endl;
    }
};


struct Fish : Animal {
    virtual void eat(AnimalFood* aFood) {
        if (aFood->readAmount() < 50) {
            std::cout << "OK food, vitamines: " << aFood->readAmount() << std::endl;
        } else {
            std::cout << "too much food, vitamines: " << aFood->readAmount() << std::endl;
        }
    }
};

struct Shark : Fish {
    virtual void eat(AnimalFood* aFood) {
        if (aFood->readAmount() < 250) {
            std::cout << "too litle food for a shark, Im very hungry, vitamines: " << aFood->readAmount() << std::endl;
        } else {
            std::cout << "OK, vitamines: " << aFood->readAmount() << std::endl;
        }
    }
};

struct Wolf : Fish {
    virtual void eat(AnimalFood* aFood) {
        if (aFood->readAmount() < 150) {
            std::cout << "too litle food for a wolf, Im very hungry, vitamines: " << aFood->readAmount() << std::endl;
        } else {
            std::cout << "OK, vitamines: " << aFood->readAmount() << std::endl;
        }
    }
};

#endif

int main() {
    // find animals
    Wolf* loneWolf = new Wolf();
    Fish* goldenFish = new Fish();
    Shark* sharky = new Shark();

    // prepare food
    AnimalFood* genericFood = new AnimalFood();
    PredatorFood* bigAnimalFood = new PredatorFood();

    // give food to animals
    loneWolf->eat(genericFood);
    loneWolf->eat(bigAnimalFood);

    goldenFish->eat(genericFood);
    goldenFish->eat(bigAnimalFood);

    sharky->eat(genericFood);
    sharky->eat(bigAnimalFood);

    delete bigAnimalFood;
    delete genericFood;
    
    delete sharky;
    delete goldenFish;
    delete loneWolf;
}
// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout
too litle food for a wolf, Im very hungry, vitamines: 5
OK, vitamines: 500
OK food, vitamines: 5
too much food, vitamines: 500
too litle food for a shark, Im very hungry, vitamines: 5
OK, vitamines: 500

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
