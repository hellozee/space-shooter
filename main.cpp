#include "window.h"
#include "player.h"
#include "meteor.h"
#include "rocket.h"
#include <vector>
#include <random>

std::vector<Meteor> rockCollections;
std::vector<Rocket> rocketCollections;
int FPS = 100;

void shoot(SDL_Event event,Player p){
    if(event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_SPACE){
        int x = p.getX() + 15;
        int y = p.getY() - 20;
        Rocket temp(x,y);
        rocketCollections.push_back(temp);
    }
}

bool checkGameOver(Player p){
    for(int i=0;i<rockCollections.size();i++){
        if(p.getX()+5 > rockCollections[i].getX() && p.getX()+37 < rockCollections[i].getX()+40){
            if(p.getY() < rockCollections[i].getY() && p.getY()+62 > rockCollections[i].getY()){
                std::cout << "Game Over" << std::endl;
                return true;
            }
        }
    }
    return false;
}

void checkRocketHits(){
    for(int i=0;i<rocketCollections.size();i++){
        for(int j=0;j<rockCollections.size();j++){
           if(rocketCollections[i].getX() > rockCollections[j].getX() && rocketCollections[i].getX() + 15 < rockCollections[j].getX()+47){
               if(rocketCollections[i].getY() > rockCollections[j].getY() && rocketCollections[i].getY()+30 < rockCollections[j].getY()+45 ){
                    rockCollections.erase(rockCollections.begin()+j);
                    rocketCollections.erase(rocketCollections.begin()+i);
               }
           }
        }
    }
}

void clearMemory(){
    for(int i=0;i<rocketCollections.size();i++){
        if(rocketCollections[i].getY() < -50){
            rocketCollections.erase(rocketCollections.begin()+i);
        }
    }

    for(int i=0;i<rockCollections.size();i++){
        if(rockCollections[i].getY() > 568){
            rockCollections.erase(rockCollections.begin()+i);
        }
    }
}

void drawRock(int secs){
    int mod = FPS*50;

    if(secs%mod == 0){
        std::mt19937 rng;
        rng.seed(std::random_device()());
        std::uniform_int_distribution<std::mt19937::result_type> dist6(10,290);
        int x = dist6(rng);
        int y = -30;
        Meteor temp(x,y);
        rockCollections.push_back(temp);
    }
}

int main(){
    
    Window win("Space Shooter",320,568);
    Player ship(140,500);

    int count = 0;
    bool gameOver = false;
    while(!win.isClosed() && !gameOver){

        int FrameStartTimeMs = SDL_GetTicks();

        win.clear();
        ship.draw();
        
        drawRock(count*FPS);
        count++;
        for(int i=0;i<rockCollections.size();i++){
            rockCollections[i].draw();
        }

        for(int i=0;i<rocketCollections.size();i++){
            rocketCollections[i].draw();
        }

        SDL_Event event;

        if(SDL_PollEvent(&event)){

            win.pollEvents(event);
            ship.pollEvents(event);
            shoot(event,ship);

        }

        gameOver = checkGameOver(ship);
        checkRocketHits();

        clearMemory();

        while(SDL_GetTicks() - FrameStartTimeMs < 1000/FPS);
    }
    return 0;
}