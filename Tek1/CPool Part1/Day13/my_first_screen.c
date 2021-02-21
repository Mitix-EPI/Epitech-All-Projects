/*
** EPITECH PROJECT, 2019
** my_first_screen.c
** File description:
** window
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <unistd.h>
#include <Event.h>

int main(void)
{
	sfVideoMode mode = {800, 600, 32};
	sfRenderWindow *window;
	sfEvent event;
	sfText *text;
	sfFont *font;
	sfSprite *sprite;
	sfTexture *texture;
	sfMusic *music;
	sfJoystickMoveEvent *
	
	window = sfRenderWindow_create(mode, "PARADOU GANG", sfResize | sfDefaultStyle | sfClose, NULL);
	texture = sfTexture_createFromFile("rouge.jpg", NULL);
	if (!texture)
		return (84);
	sprite = sfSprite_create();
	sfSprite_setTexture(sprite, texture, sfTrue);
	font = sfFont_createFromFile("font.ttf");
	if (!font)
		return (84);
	text = sfText_create();
	sfText_setString(text, "\n\n\n\n\n\n                         PARADOU GANG !");
	sfText_setFont(text, font);
	sfText_setCharacterSize(text, 50);
	music = sfMusic_createFromFile("sans titre.ogg");
	sfMusic_play(music);
	if (! window)
		return (84);
	while (sfRenderWindow_isOpen(window)) {
		while (sfRenderWindow_pollEvent(window, &event)) {
			if (event.type == sfEvtClosed)
				sfRenderWindow_close(window);
			if (event.type == sfEvtMouseButtonPressed || event.type == sfEvtKeyPressed)
				sfMusic_play(music);
		}
		sfRenderWindow_clear(window, sfBlack);
		sfRenderWindow_drawSprite(window, sprite, NULL);
		sfRenderWindow_drawText(window, text, NULL);
		sfRenderWindow_display(window);
	}
	sfMusic_destroy(music);
	sfFont_destroy(font);
	sfText_destroy(text);
	sfSprite_destroy(sprite);
	sfTexture_destroy(texture);
	sfRenderWindow_destroy(window);
	return (0);
}
