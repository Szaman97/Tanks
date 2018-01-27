#pragma once
#include "Game.h"

enum direction;

class Tank
{
public:
	Tank(int x, int y, direction d, int up, int down, int left, int right);
	~Tank();

	void handleEvent(SDL_Event &e);
	void move();
	void undo();
	void respawn(int x, int y);
	void setVelocity();

	int getX();
	int getY();
	int getWidth();
	int getHeight();
	int getHp();
	int getMaxHp();
	unsigned int getScore();
	direction getDirection();
	SDL_Rect getCollider();

	void decreaseHp();
	void increaseScore();

	friend class Bullet;

private:
	//Coordinates of the tank
	int x;
	int y;

	//Velocity of the tank
	int vx;
	int vy;

	int hp;
	unsigned int score;
	direction dir;

	//Collider box
	SDL_Rect collider;

	//Steering keys
	int up;
	int down;
	int left;
	int right;

	//Flags storing information if a button is pressed
	bool upButtonPressed;
	bool downButtonPressed;
	bool leftButtonPressed;
	bool rightButtonPressed;

	//Variables storing ticks from button pressing
	Uint32 upTicks;
	Uint32 downTicks;
	Uint32 leftTicks;
	Uint32 rightTicks;

	static const int velocity;
	static const int width;
	static const int height;
	static const int maxHp;
};