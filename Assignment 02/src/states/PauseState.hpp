/*
    ISPPJ1 2024
    Study Case: Flappy Bird

    Author: Johan Paredes
    jmpareds@gmail.com

    This file contains the definition of the class PauseState.
*/

#pragma once

#include <src/World.hpp>
#include <src/Bird.hpp>
#include <src/states/BaseState.hpp>

class PauseState: public BaseState
{
public:
    PauseState(StateMachine* sm) noexcept;

    void enter(std::shared_ptr<World> _world, std::shared_ptr<Bird> _bird, int score) noexcept override;

    void handle_inputs(const sf::Event& event) noexcept override;

    void render(sf::RenderTarget& target) const noexcept override;

private:
    std::shared_ptr<Bird> bird;
    std::shared_ptr<World> world;
    int score;
};
