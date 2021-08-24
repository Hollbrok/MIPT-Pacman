#ifndef DRAWTEXT_H
#define DRAWTEXT_H

#pragma once

const sf::Vector2f & getLogicPosition(float x, float y);
void drawText(sf::RenderWindow& window, sf::Text& goldCollectedText, Player& mainHero);

#endif