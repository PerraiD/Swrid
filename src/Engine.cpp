#include "../include/Engine.h"

Engine::Engine(SDL_Surface *sdlScreen, SDL_Event *event, bool *loop)
{
    screen_ = new MenuScreen(this);
    menuScreen_ = screen_;
    gameScreen_ = new GameScreen(this);

    sdlScreen_ = sdlScreen;
    event_ = event;
    loop_ = loop;
}

Engine::~Engine()
{
    if(grid_ != NULL)
        delete grid_;
    if(menuScreen_ != NULL)
        delete menuScreen_;
    if(gameScreen_ != NULL)
        delete gameScreen_;
}

void Engine::init()
{
    screen_->show(sdlScreen_);

    grid_ = new Grid();
    grid_->new_row();
    grid_->new_row();
    grid_->new_row();
    grid_->new_row();
}

void Engine::render()
{
    screen_->render(sdlScreen_);
}

void Engine::event()
{
    screen_->event(event_, loop_);
}

/**********
* SETTERS *
**********/
void Engine::setScreen(Screen *screen)
{
    // On libère l'écran actuel
    screen_->hide(sdlScreen_);
    // On change l'écran vers le nouveau
    screen_ = screen;
    // On affiche le nouveau écran
    screen_->show(sdlScreen_);
}

/**********
* GETTERS *
**********/
Grid* Engine::getGrid()
{
    return grid_;
}

Screen* Engine::getScreen()
{
    return screen_;
}

Screen* Engine::getMenuScreen()
{
    return menuScreen_;
}

Screen* Engine::getGameScreen()
{
    return gameScreen_;
}

SDL_Surface* Engine::getSDLscreen()
{
    return sdlScreen_;
}

void Engine::setSDLscreen(SDL_Surface *newScreen)
{
    sdlScreen_ = newScreen;
}
