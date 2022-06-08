#include "selfTest.hpp"

using namespace std;



SelfTest::SelfTest(){
}
SelfTest::SelfTest(bool verbose){
    this->verbose = verbose;
}
SelfTest::~SelfTest(){
}

bool SelfTest::test(){
    assert(true);
    try{
        if (verbose)
            cout << "Angle library test" << endl;
        Angle angle = Angle(0);
        assert(angle.getAngle() == 0);
        int a = 1;
        int b = -6;
        int c = 7;
        angle.setAngle(a);
        assert(angle.getAngle() ==a);
        angle.rotate(a);
        assert(angle.getAngle() == a + a);
        angle.rotate(b);
        assert(angle.getAngle() == 0);
        angle.rotate(c);
        assert(angle.getAngle() == 3);
        Angle angle2 = Angle(1);
        angle -= angle2;
        assert(angle.getAngle() == 2);

        if (verbose)
            cout << "Position library test" << endl; 
        Position position = Position();
        position.setXY(2, 4);
        Position position2 = Position(1, 2);
        Position position3 = Position(position2);
        position3 = position3 + position2;
        assert(position == position3);
        position.move(Angle(0), 1);
        assert(position == Position(2, 3));

        if (verbose)
            cout << "Map library test" << endl;
        Map map = Map("examples/medium.pacman");
        assert(map.getWidth() == 19);
        assert(map.getHeight() == 11);
        assert(map.getField(Position(0, 0)).wall());
        assert(map.getTotalScore() == 95);
        assert(map.getGhostReleaseTimeout() == 60);

        if (verbose)
            cout << "Entity manager library test" << endl;
        EntityManager entityManager = EntityManager();
        entityManager.importMap(&map);
        assert(entityManager.player.getPosition() == Position(9, 9));
        assert(entityManager.ghosts[0]->getPosition() == Position(9, 6));
        assert(entityManager.ghosts[1]->getPosition() == Position(8, 7));
        assert(entityManager.ghosts[2]->getPosition() == Position(9, 7));
        assert(entityManager.ghosts[3]->getPosition() == Position(10, 7));
        entityManager.player.setAngle(1);
        entityManager.tick();
        assert(entityManager.player.getPosition() == Position(10, 9)); //Validate that the player moved
        assert(entityManager.ghosts[0]->getPosition() != Position(9, 6)); //Validate that the gost moved
        entityManager.tick();
        entityManager.ghosts[0]->setPosition(Position(11, 9));
        assert(!entityManager.gameEnded());
        entityManager.tick();
        assert(entityManager.player.getLives() == 2);

        if (verbose)
            cout << "\n\nAll tests passed successfully!\n\n";
    } catch (exception const &e){
        if (verbose)
            cout << "\n\nError: " << e.what() << "\n\n";
        return false;
    }
    
    return true;
}

