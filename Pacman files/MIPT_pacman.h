#ifndef MIPT_PACMAN_H
#define MIPT_PACMAN_H


#pragma once

bool isPressedUpButton();
bool isPressedLeftButton();
bool isPressedDownButton();
bool isPressedRightButton();

bool isPressedMovementButton();

int defineDirection();

int getCameraMoveDirection(int x, int y, int windowSizeX, int windowSizeY);

int getRandomNumber(int min, int max);

#endif
