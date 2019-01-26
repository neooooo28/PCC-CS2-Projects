#include "system.h"
#include "random.h"
#include "MyVector.h"

#include <iostream>

#include <constants.h>
void CreateRandomParticles(int n){
    Random r;
    int xpos = 100;
    int ypos = 100;

    for (int i=0; i<n; i++){
        Vector pos(r.Next(0,SCREEN_WIDTH),r.Next(0,SCREEN_HEIGHT));
        xpos += 40;
        Vector vel(r.Next(-5,5), r.Next(-5,5));
        Vector acc(0.01,0.02);
        double mass = r.Next(5,25);


        int r_ = r.Next(0,255);
        int g_ = r.Next(0,255);
        int b_ = r.Next(0,255);

        Particle p(pos, vel, acc, mass,r_,g_,b_);
        //system.push_back(p);

    }

}
System::System()
{
    Random r;
    int xpos = 100;
    int ypos = 100;

    for (int i=0; i<15; i++){

        Vector pos(r.Next(0,WORK_PANEL-300),r.Next(0,SCREEN_HEIGHT-300));
        //Vector pos(SCREEN_WIDTH/2,SCREEN_HEIGHT/2);
        //Vector pos(SCREEN_WIDTH-20,SCREEN_HEIGHT/2);

        Vector vel(r.Next(-0.0,0.0), r.Next(-0.0,0.0));
        Vector acc(0.00,0.00);

        double mass = r.Next(4,40);
        int r_ = r.Next(0,255);
        int g_ = r.Next(0,255);
        int b_ = r.Next(0,255);

        Particle p(pos, vel, acc, mass,r_,g_,b_);
        system.push_back(p);
    }
}

/*------------------------------------------------------------------
            Movement functions:
------------------------------------------------------------------*/
void Fall(vector<Particle>& system){
    for (int i=0; i<system.size(); i++){
        system[i].Move(Vector(0.00, -0.10));
    }
}

//------------------------------------------------------------------
//------------------------------------------------------------------

void System::Step(int command){
//    Fall(system);
//    return;





//    Vector f(0.00,0.00);
//    for (int i=0; i<system.size(); i++){
//        for (int j=0; j<system.size(); j++){
//            if (i!=j){
//                cout<<i<<":"<<j<<endl;
//                Vector diff = (system[j].Pos()-system[i].Pos());
//                Vector unit = diff.Unit();

//                double dist = diff.Mag()<5?5:diff.Mag();

//                //m = m1 * m2 / d
//                double m = system[i].Mass() * system[j].Mass() / dist;

//                unit = unit * m;
//                f = f + unit;
//            }
//        }
//    system[i].Move(f);
//    }
//    return;



    for (int i=0; i<system.size(); i++){
        switch (command){
        case 4:
            system[i].Move(Vector(-10,0));
//            system[i].Move(Vector(-0.01,0));
            break;
        case 6:
            system[i].Move(Vector(0.01,0));
            break;
        }
        system[i].Move(Vector(0.00, 0.15));
        //system[i].Move();
    }
}

int System::Size(){
    return system.size();
}

void System::Draw(sf::RenderWindow& window){
    window.clear();
    for (int i=0; i<system.size(); i++){
        system[i].Draw(window);
    }

}
