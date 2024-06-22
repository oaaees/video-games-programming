/*
    ISPPJ1 2024
    Study Case: Pong

    Author: Alejandro Mujica
    alejandro.j.mujic4@gmail.com

    This file contains the definition of the functions to init a pong paddle,
    update it, and render it.
*/

#include <allegro5/allegro_primitives.h>

#include <settings.h>
#include <src/ball.h>
#include <src/paddle.h>

void init_paddle(struct Paddle* paddle, float x, float y, float w, float h)
{
    paddle->AI = false;
    paddle->x = x;
    paddle->y = y;
    paddle->width = w;
    paddle->height = h;
    paddle->vy = 0;
}

void build_paddle_hitbox(struct Paddle paddle, struct Hitbox* hitbox)
{
    hitbox->x1 = paddle.x;
    hitbox->y1 = paddle.y;
    hitbox->x2 = paddle.x + paddle.width;
    hitbox->y2 = paddle.y + paddle.height;
}

void update_paddle(struct Paddle* paddle, struct Ball* ball, float dt)
{
    paddle->y += paddle->vy * dt;

    paddle->y = MAX(0, MIN(paddle->y, TABLE_HEIGHT - PADDLE_HEIGHT));

    if(paddle->AI) {
        float distance_from_ball = ABS((paddle->x - ball->x));
        float k = 1 - (distance_from_ball / TABLE_WIDTH);

        if ((ball->y + (ball->height / 2)) - (paddle->y + (paddle->height / 2)) < 2){ paddle->vy = -PADDLE_SPEED * k; }
        else if ((ball->y + (ball->height / 2)) - (paddle->y + (paddle->height / 2)) > 2) { paddle->vy = PADDLE_SPEED * k; }
        else { paddle->vy = 0; }
    }
}

void render_paddle(struct Paddle paddle)
{
    al_draw_filled_rectangle(
        paddle.x, paddle.y, paddle.x + paddle.width, paddle.y + paddle.height,
        al_map_rgb(255, 255, 255)
    );
}
