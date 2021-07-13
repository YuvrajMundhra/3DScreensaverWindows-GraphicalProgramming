#include "cgt215.h"
#include "demo.h"
#include <time.h>

using namespace std;
using namespace cgt215;

//global variables

#define storage_size 250

//structure defining attributes of every coordinate
struct Point
{
	float pos[3];
	float speed = 0.0;
	bool directionx = 0;
	bool directiony = 0;
	bool directionz = 0;
};

//creating four corner points
Point p1, p2, p3, p4;
Point copyp1[storage_size], copyp2[storage_size], copyp3[storage_size], copyp4[storage_size];

//creating screen size and count variables
int mode = 0;
static const int Screen = 400;
int c = 0;
int k = 0;
int a = 1;
int b = 0;
int d = 0;


//functions

//renders each line
void RenderLine(float *a, float *b, float *ca, float *cb) 
{
	glBegin(GL_LINES);
	glColor3f(ca[0], ca[1], ca[2]);
	glVertex3f(a[0], a[1], a[2]);
	glColor3f(cb[0], cb[1], cb[2]);
	glVertex3f(b[0], b[1], b[2]);
	glEnd();
}


//initializing starting position
void initial()
{
	p1.pos[0] = (float)(rand() % Screen) - Screen / 2;
	p1.pos[1] = (float)(rand() % Screen) - Screen / 2;
	p1.pos[2] = (float)(rand() % Screen) - Screen / 2;
	copyp1[0].pos[0] = p1.pos[0];
	copyp1[0].pos[1] = p1.pos[1];
	copyp1[0].pos[2] = p1.pos[2];

	p2.pos[0] = (float)(rand() % Screen) - Screen / 2;
	p2.pos[1] = (float)(rand() % Screen) - Screen / 2;
	p2.pos[2] = (float)(rand() % Screen) - Screen / 2;
	copyp2[0].pos[0] = p2.pos[0];
	copyp2[0].pos[1] = p2.pos[1];
	copyp2[0].pos[2] = p2.pos[2];

	p3.pos[0] = (float)(rand() % Screen) - Screen / 2;
	p3.pos[1] = (float)(rand() % Screen) - Screen / 2;
	p3.pos[2] = (float)(rand() % Screen) - Screen / 2;
	copyp3[0].pos[0] = p3.pos[0];
	copyp3[0].pos[1] = p3.pos[1];
	copyp3[0].pos[2] = p3.pos[2];

	p4.pos[0] = (float)(rand() % Screen) - Screen / 2;
	p4.pos[1] = (float)(rand() % Screen) - Screen / 2;
	p4.pos[2] = (float)(rand() % Screen) - Screen / 2;
	copyp4[0].pos[0] = p4.pos[0];
	copyp4[0].pos[1] = p4.pos[1];
	copyp4[0].pos[2] = p4.pos[2];

	p1.speed = (float)0.05;
	p1.directionx = (rand() % 2);
	p1.directiony = (rand() % 2);
	p1.directionz = (rand() % 2);

	p2.speed = (float)0.05;
	p2.directionx = (rand() % 2);
	p2.directiony = (rand() % 2);
	p2.directionz = (rand() % 2);

	p3.speed = (float)0.05;
	p3.directionx = (rand() % 2);
	p3.directiony = (rand() % 2);
	p3.directionz = (rand() % 2);

	p4.speed = (float)0.05;
	p4.directionx = (rand() % 2);
	p4.directiony = (rand() % 2);
	p4.directionz = (rand() % 2);
}


//updates position every frame
void update()
{
	a++;

	if (p1.directionx == 1)
	{
		p1.pos[0] = (float)(p1.pos[0] + p1.speed);
	}
	else
	{
		p1.pos[0] = (float)(p1.pos[0] - p1.speed);
	}

	if (p2.directionx == 1)
	{
		p2.pos[0] = (float)(p2.pos[0] + p2.speed);
	}
	else
	{
		p2.pos[0] = (float)(p2.pos[0] - p2.speed);
	}

	if (p3.directionx == 1)
	{
		p3.pos[0] = (float)(p3.pos[0] + p3.speed);
	}
	else
	{
		p3.pos[0] = (float)(p3.pos[0] - p3.speed);
	}

	if (p4.directionx == 1)
	{
		p4.pos[0] = (float)(p4.pos[0] + p4.speed);
	}
	else
	{
		p4.pos[0] = (float)(p4.pos[0] - p4.speed);
	}

	if (p1.directiony == 1)
	{
		p1.pos[1] = (float)(p1.pos[1] + p1.speed);
	}
	else
	{
		p1.pos[1] = (float)(p1.pos[1] - p1.speed);
	}

	if (p2.directiony == 1)
	{
		p2.pos[1] = (float)(p2.pos[1] + p2.speed);
	}
	else
	{
		p2.pos[1] = (float)(p2.pos[1] - p2.speed);
	}

	if (p3.directiony == 1)
	{
		p3.pos[1] = (float)(p3.pos[1] + p3.speed);
	}
	else
	{
		p3.pos[1] = (float)(p3.pos[1] - p3.speed);
	}

	if (p4.directiony == 1)
	{
		p4.pos[1] = (float)(p4.pos[1] + p4.speed);
	}
	else
	{
		p4.pos[1] = (float)(p4.pos[1] - p4.speed);
	}

	if (p1.directionz == 1)
	{
		p1.pos[2] = (float)(p1.pos[2] + p1.speed);
	}
	else
	{
		p1.pos[2] = (float)(p1.pos[0] - p1.speed);
	}

	if (p2.directionz == 1)
	{
		p2.pos[2] = (float)(p2.pos[2] + p2.speed);
	}
	else
	{
		p2.pos[2] = (float)(p2.pos[2] - p2.speed);
	}

	if (p3.directionz == 1)
	{
		p3.pos[2] = (float)(p3.pos[2] + p3.speed);
	}
	else
	{
		p3.pos[2] = (float)(p3.pos[2] - p3.speed);
	}

	if (p4.directionz == 1)
	{
		p4.pos[2] = (float)(p4.pos[2] + p4.speed);
	}
	else
	{
		p4.pos[2] = (float)(p4.pos[2] - p4.speed);
	}



	if (p1.pos[0]<(-Screen / 2) || p1.pos[0]>(Screen / 2))
	{
		if (p1.pos[0] < (-Screen / 2))
		{
			p1.pos[0] = (float)(-Screen / 2);
			p1.directionx = 1;
		}
		else
		{
			p1.pos[0] = (float)(Screen / 2);
			p1.directionx = 0;
		}
	}

	if (p2.pos[0]<(-Screen / 2) || p2.pos[0]>(Screen / 2))
	{
		if (p2.pos[0] < (-Screen / 2))
		{
			p2.pos[0] = (float)(-Screen / 2);
			p2.directionx = 1;
		}
		else
		{
			p2.pos[0] = (float)(Screen / 2);
			p2.directionx = 0;
		}
	}

	if (p3.pos[0]<(-Screen / 2) || p3.pos[0]>(Screen / 2))
	{
		if (p3.pos[0] < (-Screen / 2))
		{
			p3.pos[0] = (float)(-Screen / 2);
			p3.directionx = 1;
		}
		else
		{
			p3.pos[0] = (float)(Screen / 2);
			p3.directionx = 0;
		}
	}

	if (p4.pos[0]<(-Screen / 2) || p4.pos[0]>(Screen / 2))
	{
		if (p4.pos[0] < (-Screen / 2))
		{
			p4.pos[0] = (float)(-Screen / 2);
			p4.directionx = 1;
		}
		else
		{
			p4.pos[0] = (float)(Screen / 2);
			p4.directionx = 0;
		}
	}

	if (p1.pos[1]<(-Screen / 2) || p1.pos[1]>(Screen / 2))
	{
		if (p1.pos[1] < (-Screen / 2))
		{
			p1.pos[1] = (float)(-Screen / 2);
			p1.directiony = 1;
		}
		else
		{
			p1.pos[1] = (float)(Screen / 2);
			p1.directiony = 0;
		}
	}

	if (p2.pos[1]<(-Screen / 2) || p2.pos[1]>(Screen / 2))
	{
		if (p2.pos[1] < (-Screen / 2))
		{
			p2.pos[1] = (float)(-Screen / 2);
			p2.directiony = 1;
		}
		else
		{
			p2.pos[1] = (float)(Screen / 2);
			p2.directiony = 0;
		}
	}

	if (p3.pos[1]<(-Screen / 2) || p3.pos[1]>(Screen / 2))
	{
		if (p3.pos[1] < (-Screen / 2))
		{
			p3.pos[1] = (float)(-Screen / 2);
			p3.directiony = 1;
		}
		else
		{
			p3.pos[1] = (float)(Screen / 2);
			p3.directiony = 0;
		}
	}

	if (p4.pos[1]<(-Screen / 2) || p4.pos[1]>(Screen / 2))
	{
		if (p4.pos[1] < (-Screen / 2))
		{
			p4.pos[1] = (float)(-Screen / 2);
			p4.directiony = 1;
		}
		else
		{
			p4.pos[1] = (float)(Screen / 2);
			p4.directiony = 0;
		}
	}

	if (p1.pos[2]<(-Screen / 2) || p1.pos[2]>(Screen / 2))
	{
		if (p1.pos[2] < (-Screen / 2))
		{
			p1.pos[2] = (float)(-Screen / 2);
			p1.directionz = 1;
		}
		else
		{
			p1.pos[2] = (float)(Screen / 2);
			p1.directionz = 0;
		}
	}

	if (p2.pos[2]<(-Screen / 2) || p2.pos[2]>(Screen / 2))
	{
		if (p2.pos[2] < (-Screen / 2))
		{
			p2.pos[2] = (float)(-Screen / 2);
			p2.directionz = 1;
		}
		else
		{
			p2.pos[2] = (float)(Screen / 2);
			p2.directionz = 0;
		}
	}

	if (p3.pos[2]<(-Screen / 2) || p3.pos[2]>(Screen / 2))
	{
		if (p3.pos[2] < (-Screen / 2))
		{
			p3.pos[2] = (float)(-Screen / 2);
			p3.directionz = 1;
		}
		else
		{
			p3.pos[2] = (float)(Screen / 2);
			p3.directionz = 0;
		}
	}

	if (p4.pos[2]<(-Screen / 2) || p4.pos[2]>(Screen / 2))
	{
		if (p4.pos[2] < (-Screen / 2))
		{
			p4.pos[2] = (float)(-Screen / 2);
			p4.directionz = 1;
		}
		else
		{
			p4.pos[2] = (float)(Screen / 2);
			p4.directionz = 0;
		}
	}

	  for (int i = a; i < a + 1;i++)
	  {
		  {
			  copyp1[a%storage_size].pos[0] = p1.pos[0];
			  copyp1[a%storage_size].pos[1] = p1.pos[1];
			  copyp1[a%storage_size].pos[2] = p1.pos[2];

			  copyp2[a%storage_size].pos[0] = p2.pos[0];
			  copyp2[a%storage_size].pos[1] = p2.pos[1];
			  copyp2[a%storage_size].pos[2] = p2.pos[2];

			  copyp3[a%storage_size].pos[0] = p3.pos[0];
			  copyp3[a%storage_size].pos[1] = p3.pos[1];
			  copyp3[a%storage_size].pos[2] = p3.pos[2];

			  copyp4[a%storage_size].pos[0] = p4.pos[0];
			  copyp4[a%storage_size].pos[1] = p4.pos[1];
			  copyp4[a%storage_size].pos[2] = p4.pos[2];
		  }
	  }
}


	void draw()
	{
		c++;
		k++;
		
		float color[3];
		float colorA[3] = { 1,0,0 };
		float colorB[3] = { 0,0.5,0.5 };
		float colorC[3] = { 0,1,0 };
		float colorD[3] = { 1,1,0 };
		if (c >= 0 && c <= 3000)
		{
			for (int i = 0; i < 3; i++)
			{
				color[i] = colorA[i];
			}
		}
		else if (c > 3000 && c <= 6000)
		{
			for (int i = 0; i < 3; i++)
			{
				color[i] = colorB[i];
			}
		}
		else if (c > 6000 && c < 9000)
		{
			for (int i = 0; i < 3; i++)
			{
				color[i] = colorC[i];
			}
		}
		else if (c > 9000 && c < 12000)
		{
			for (int i = 0; i < 3; i++)
			{
				color[i] = colorD[i];
			}
		}
		else if (c == 12000)
		{
			c = 0;
			for (int i = 0; i < 3; i++)
			{
				color[i] = colorB[i];
			}
		}
		
			RenderLine(p1.pos, p2.pos, color, color);
			RenderLine(p2.pos, p3.pos, color, color);
			RenderLine(p3.pos, p4.pos, color, color);
			RenderLine(p4.pos, p1.pos, color, color);	

			if (k >= 120)
			{
				for (int i = b; i < b + 1; i++)
				{
					{
						RenderLine(copyp1[i%storage_size].pos, copyp2[i%storage_size].pos, color, color);
						RenderLine(copyp2[i%storage_size].pos, copyp3[i%storage_size].pos, color, color);
						RenderLine(copyp3[i%storage_size].pos, copyp4[i%storage_size].pos, color, color);
						RenderLine(copyp4[i%storage_size].pos, copyp1[i%storage_size].pos, color, color);
					}
					
				}
				b++;
			}

			if (k >= 240)
			{
				for (int i = d; i < d + 1; i++)
				{
					{
						RenderLine(copyp1[i%storage_size].pos, copyp2[i%storage_size].pos, color, color);
						RenderLine(copyp2[i%storage_size].pos, copyp3[i%storage_size].pos, color, color);
						RenderLine(copyp3[i%storage_size].pos, copyp4[i%storage_size].pos, color, color);
						RenderLine(copyp4[i%storage_size].pos, copyp1[i%storage_size].pos, color, color);
					}

				}
				d++;
			}
	}
	
	

	


/// This method is called automatically every frame of animation (usually 60 times per second).
/// Parameter lastFrameDuration is amount of time (in seconds) which was needed to render previous frame.
void renderFrame(float lastFrameDuration)
{
    // Place interactive/animated drawing code here
	enable3d();
	update();
	draw();
	if (keyPressed('1') && mode == 0)
	{
		mode = 1;
	}
	else if (keyPressed('1') && mode == 1)
	{
		mode = 0;
	}
	if (mode == 1)
	{
		drawCube();
	}
	if (keyPressed('='))
	{
		if (p1.speed >= 0.3)
		{
			cout << "Max speed reached" << endl;
		}
		else
		{
			p1.speed += (float)0.03;
			p2.speed += (float)0.03;
			p3.speed += (float)0.03;
			p4.speed += (float)0.03;
		}
		
	}
	if (keyPressed('-'))
	{
		if (p1.speed > 0.02)
		{
			p1.speed -= (float)0.03;
			p2.speed -= (float)0.03;
			p3.speed -= (float)0.03;
			p4.speed -= (float)0.03;
		}
		else
		{
			cout << "Minimum speed reached. Cannot decrease speed" << endl;
		}
	}
	if (keyPressed('e'))
	{
		//exit
		glutLeaveMainLoop();
		//cin.get();
	}
}

/// This is a special method where cgtin and cgtout can be used.
/// It is invoked once at the beginning of program.
void cgtConsole() {

}

/// Main method of the program which initializes the framework.
int main(int argc, char** argv) {
	initial();
    srand((unsigned int)time(NULL));

    /// Initializes framework
    initializeCgt215(argc, argv, cgtConsole, renderFrame, "CGT 215");

}

