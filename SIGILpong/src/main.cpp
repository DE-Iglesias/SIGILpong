#include "sl.h"
using namespace std;
#include <string>
#include <iostream>

struct Vector2
{
	int x;
	int y;
};

struct Rectangle 
{	
	int posx;
	int posy;
	int width;
	int height;
};
struct Ball
{
	int posx;
	int posy;
	int radius;
};
int speed = 5;
int ScreenWidth=800;
int ScreenHeight=400;
int P1Score = 0;
int P2Score = 0;
int gamescreen = 0;
Vector2 ballspeed = {5, 5};
Rectangle P1 = { 40,(ScreenHeight / 2),7,90 };
Rectangle P2 = { (ScreenWidth - 40), (ScreenHeight / 2), 7, 90 };
Ball ball = { (ScreenWidth / 2), (ScreenHeight / 2), 10 };
bool Collision(Ball ball, Rectangle rec)
{
	cout << " " + to_string(ball.posy);
	if (ball.posy > (rec.posy+rec.height/2) || ball.posy < rec.posy-rec.height/2)
	{
		return false;
	}
	else
	{
		return true;
	}
}
int main(int args, char *argv[])
{	
	slWindow(ScreenWidth, ScreenHeight, "SIGIL PONG", false);
	int arial = slLoadFont("arial.ttf");
	int vgafix = slLoadFont("vgafix.fon");
	while (!slShouldClose())
	{	
		if (gamescreen == 0)
		{
			slSetFont(arial, 100);
			slText(ScreenWidth / 2 - 100, ScreenHeight / 2, "Pong");
			slRender();
		}
		if (gamescreen == 1)
		{
			slSetFont(arial, 20);
			ball.posx += ballspeed.x;
			ball.posy += ballspeed.y;
			if (slGetKey('W'))
			{
				if (P1.posy < (ScreenHeight - (P1.height / 2)))
				{
					P1.posy += speed;
				}

			}
			if (slGetKey(SL_KEY_UP))
			{
				if (P2.posy < (ScreenHeight - (P2.height / 2)))
				{
					P2.posy += speed;
				}

			}
			if (slGetKey('S'))
			{
				if (P1.posy > (0 + (P1.height / 2)))
				{
					P1.posy -= speed;
				}

			}
			if (slGetKey(SL_KEY_DOWN))
			{
				if (P2.posy > (0 + (P2.height / 2)))
				{
					P2.posy -= speed;
				}

			}
			if (slGetKey(SL_KEY_ESCAPE))
			{
				gamescreen--;
			}
			if (ball.posy < 0 + ball.radius)
			{
				ballspeed.y = -ballspeed.y;
			}
			if (ball.posx < 0 + ball.radius)
			{
				ballspeed.x = -ballspeed.x;
				P2Score++;
				ball.posx = (ScreenWidth / 2);
				ball.posy = (ScreenHeight / 2);
			}
			if (ball.posy > ScreenHeight - ball.radius)
			{
				ballspeed.y = -ballspeed.y;
			}
			if (ball.posx > ScreenWidth - ball.radius)
			{
				P1Score++;
				ballspeed.x = -ballspeed.x;

			}
			if (ball.posx - ball.radius / 2 < P1.posx + P1.width / 2)
			{
				if (Collision(ball, P1))
				{
					ballspeed.x = -ballspeed.x;
				}
			}
			if (ball.posx + ball.radius / 2 > P2.posx - P2.width / 2)
			{
				if (Collision(ball, P2))
				{
					ballspeed.x = -ballspeed.x;
				}
			}
			slRectangleFill(P1.posx, P1.posy, P1.width, P1.height);
			slRectangleFill(P2.posx, P2.posy, P2.width, P2.height);
			slCircleFill(ball.posx, ball.posy, ball.radius, ball.radius);
			slText(10, ScreenHeight - 30, (to_string(P1Score)).c_str());
			slText(ScreenWidth - 20, ScreenHeight - 30, (to_string(P2Score)).c_str());
			slRender();

		}
	}
	slClose();
	return 0;
}