/*
    ISPPJ1 2024
    Study Case: Flappy Bird

    Author: Alejandro Mujica
    alejandro.j.mujic4@gmail.com

    This file contains the declaration of the class TitleScreenState.
*/

#include <Settings.hpp>
#include <src/text_utilities.hpp>
#include <src/states/StateMachine.hpp>
#include <src/states/TitleScreenState.hpp>

TitleScreenState::TitleScreenState(StateMachine* sm) noexcept
    : BaseState{sm}, world{std::make_shared<World>(false)}
{

}

void TitleScreenState::handle_inputs(const sf::Event& event) noexcept
{
    if (event.key.code == sf::Keyboard::Num1)
    {
        state_machine->change_state("count_down", world);
    }
    else if (event.key.code == sf::Keyboard::Num2) 
    {
        state_machine->change_state("count_down", world);
    }
}

void TitleScreenState::update(float dt) noexcept
{
    world->update(dt);
}

void TitleScreenState::render(sf::RenderTarget& target) const noexcept 
{
    world->render(target);
    render_text(target, Settings::VIRTUAL_WIDTH / 2, Settings::VIRTUAL_HEIGHT / 3, "Flappy Bird", Settings::FLAPPY_TEXT_SIZE, "flappy", sf::Color::White, true);
    render_text(target, Settings::VIRTUAL_WIDTH / 2, 2 * Settings::VIRTUAL_HEIGHT / 3, "Press 1 to enter easy mode,\n Press 2 to enter HARD mode", Settings::MEDIUM_TEXT_SIZE, "font", sf::Color::White, true);
}