#include "sl.h"
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
Vector2 ballspeed = {5, 5};
int main(int args, char *argv[])
{
	Rectangle P1 = {10,(ScreenHeight / 2),7,90};
	Rectangle P2 = {(ScreenWidth-10), (ScreenHeight / 2), 7, 90};
	Ball ball = {(ScreenWidth / 2), (ScreenHeight / 2), 10};
	slWindow(ScreenWidth, ScreenHeight, "Simple SIGIL Example", false);
	while (!slShouldClose() && !slGetKey(SL_KEY_ESCAPE))
	{
		ball.posx += ballspeed.x;
		ball.posy += ballspeed.y;
		if (slGetKey('W'))		{			if (P1.posy < (ScreenHeight-(P1.height /2)))
			{
				P1.posy += speed;
			}					}
		if (slGetKey(SL_KEY_UP))		{			if (P2.posy < (ScreenHeight - (P2.height / 2)))
			{
				P2.posy += speed;
			}		}
		if (slGetKey('S'))		{			if (P1.posy > (0 + (P1.height / 2)))
			{
				P1.posy -= speed;
			}		}
		if (slGetKey(SL_KEY_DOWN))		{			if (P2.posy > (0 + (P2.height / 2)))
			{
				P2.posy -= speed;
			}		}
		if (ball.posy < 0 + ball.radius)
		{
			ballspeed.y = -ballspeed.y;
		}
		if (ball.posx < 0 + ball.radius)
		{
			ballspeed.x = -ballspeed.x;
		}
		if (ball.posy > ScreenHeight - ball.radius)
		{
			ballspeed.y = -ballspeed.y;
		}
		if (ball.posx > ScreenWidth - ball.radius)
		{
			ballspeed.x = -ballspeed.x;
		}
		slRectangleFill(P1.posx, P1.posy, P1.width, P1.height);
		slRectangleFill(P2.posx, P2.posy, P2.width, P2.height);
		slCircleFill(ball.posx, ball.posy, ball.radius, ball.radius);

		slRender();
	}
	slClose();
	return 0;
}