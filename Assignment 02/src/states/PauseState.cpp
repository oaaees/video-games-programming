/*
    ISPPJ1 2024
    Study Case: Flappy Bird

    Author: Johan Paredes
    jmpareds@gmail.com

    This file contains the declaration of the class PauseState.
*/

#include <Settings.hpp>
#include <src/text_utilities.hpp>
#include <src/states/StateMachine.hpp>
#include <src/states/PauseState.hpp>

PauseState::PauseState(StateMachine* sm) noexcept
    : BaseState{sm}, world{std::make_shared<World>(false)}
{

}

void PauseState::enter(std::shared_ptr<World> _world, std::shared_ptr<Bird> _bird, int _score) noexcept
{
    world = _world;
    bird = _bird;
    score = _score;
}

void PauseState::handle_inputs(const sf::Event& event) noexcept
{
    if (event.key.code == sf::Keyboard::P)
    {
        state_machine->change_state("playing", world, bird, score);
    }
}

void PauseState::render(sf::RenderTarget& target) const noexcept 
{
    world->render(target);
    render_text(target, Settings::VIRTUAL_WIDTH / 2, Settings::VIRTUAL_HEIGHT / 3, "PAUSED", Settings::FLAPPY_TEXT_SIZE, "flappy", sf::Color::White, true);
    render_text(target, Settings::VIRTUAL_WIDTH / 2, 2 * Settings::VIRTUAL_HEIGHT / 3, "Press P to keep playing", Settings::MEDIUM_TEXT_SIZE, "font", sf::Color::White, true);
}