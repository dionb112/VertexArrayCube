#include <Game.h>

bool flip = false;
int current = 1;

Game::Game() : window(VideoMode(800, 600), "OpenGL Cube")
{
	getCentre();
}

Game::~Game() {}

float vertices[] = { 
	//Front Face
	1.0f, 1.0f, -5.0f,
	-1.0f, 1.0f, -5.0f,
	-1.0f, -1.0f, -5.0f,
	1.0f, 1.0f, -5.0f,
	-1.0f, -1.0f, -5.0f,
	1.0f, -1.0f, -5.0f,
	// Back Face
	1.0f, 1.0f, -15.0f,
	-1.0f, 1.0f, -15.0f,
	-1.0f, -1.0f, -15.0f,
	1.0f, 1.0f, -15.0f,
	-1.0f, -1.0f, -15.0f,
	1.0f, -1.0f, -15.0f,
	// Right Side
	1.0f, 1.0f, -15.0f,
	1.0f, 1.0f, -5.0f,
	1.0f, -1.0f, -5.0f,
	1.0f, 1.0f, -15.0f,
	1.0f, -1.0f, -5.0f,
	1.0f, -1.0f, -15.0f,
	// Top
	-1.0f, 1.0f, -5.0f,
	1.0f, 1.0f, -5.0f,
	1.0f, 1.0f, -15.0f,
	-1.0f, 1.0f, -5.0f,
	1.0f, 1.0f, -15.0f,
	-1.0f, 1.0f, -15.0f,
	// Left
	-1.0f, 1.0f, -5.0f,
	-1.0f, 1.0f, -15.0f,
	-1.0f, -1.0f, -15.0f,
	-1.0f, 1.0f, -5.0f,
	-1.0f, -1.0f, -15.0f,
	-1.0f, -1.0f, -5.0f,
	// Bottom
	-1.0f, -1.0f, -5.0f,
	1.0f, -1.0f, -5.0f,
	1.0f, -1.0f, -15.0f,
	-1.0f, -1.0f, -5.0f,
	1.0f, -1.0f, -15.0f,
	-1.0f, -1.0f, -15.0f
};
float colors[] = { 
	1.0f, 0.0f, 0.0f,
	1.0f, 0.0f, 0.0f,
	1.0f, 0.0f, 0.0f,
	1.0f, 0.0f, 0.0f,
	1.0f, 0.0f, 0.0f,
	1.0f, 0.0f, 0.0f,
	//
	0.0f, 1.0f, 0.0f, 
	0.0f, 1.0f, 0.0f,
	0.0f, 1.0f, 0.0f,
	0.0f, 1.0f, 0.0f,
	0.0f, 1.0f, 0.0f,
	0.0f, 1.0f, 0.0f,
	//
	0.0f, 0.0f, 1.0f, 
	0.0f, 0.0f, 1.0f,
	0.0f, 0.0f, 1.0f,
	0.0f, 0.0f, 1.0f,
	0.0f, 0.0f, 1.0f,
	0.0f, 0.0f, 1.0f,
	//
	0.0f, 1.0f, 1.0f,
	0.0f, 1.0f, 1.0f,
	0.0f, 1.0f, 1.0f,
	0.0f, 1.0f, 1.0f,
	0.0f, 1.0f, 1.0f,
	0.0f, 1.0f, 1.0f,
	//
	1.0f, 1.0f, 0.0f,
	1.0f, 1.0f, 0.0f,
	1.0f, 1.0f, 0.0f,
	1.0f, 1.0f, 0.0f,
	1.0f, 1.0f, 0.0f,
	1.0f, 1.0f, 0.0f,
	//
	1.0f, 0.0f, 1.0f,
	1.0f, 0.0f, 1.0f,
	1.0f, 0.0f, 1.0f,
	1.0f, 0.0f, 1.0f,
	1.0f, 0.0f, 1.0f,
	1.0f, 0.0f, 1.0f

};
unsigned int vertex_index[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 , 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35 };

void Game::run()
{

	initialize();

	Event event;

	while (isRunning) {

		cout << "Game running..." << endl;

		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				isRunning = false;
			}


		}
		update();
		render();
	}

}

void Game::getCentre()
{
	// get centre of whole cube at once !
	for (int i = 0; i < 118; i = i + 3)
	{
		MyVector3D centreVector{ vertices[i], vertices[i + 1], vertices[i + 2] };
		m_centre += centreVector;
	}
	m_centre = m_centre / 36;
}

void Game::initialize()
{
	isRunning = true;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, window.getSize().x / window.getSize().y, 1.0, 500.0);
	glMatrixMode(GL_MODELVIEW);
}

// look at tangrams to see how to properly use the matrix rotations
void Game::update()
{
	elapsed = clock.getElapsedTime();
	for (int i = 0; i < 118; i=i+3)
	{
		MyVector3D vector{ vertices[i], vertices[i + 1], vertices[i + 2] };

		// move to origin of shape
		vector = MyMatrix3::translation(-m_centre) * vector;


		// rotate
		vector = MyMatrix3::rotationZ(0.001) * vector;
		// vector = MyMatrix3::rotationX(0.001) * vector;
		// vector = MyMatrix3::rotationY(0.001) * vector;

		// move back
		vector = MyMatrix3::translation(m_centre) * vector;

		// scale
		double scalingFactor(1);
		MyMatrix3 standardScale = MyMatrix3::scale(scalingFactor);
		vector = standardScale * vector;

		vertices[i] = vector.X();
		vertices[i + 1] = vector.Y();
		vertices[i + 2] = vector.Z();

	}

	cout << "Update up" << endl;
}

void Game::render()
{
	cout << "Drawing" << endl;

	glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);

	glVertexPointer(3, GL_FLOAT, 0, &vertices);
	glColorPointer(3, GL_FLOAT, 0, &colors);

	//glDrawArrays(GL_TRIANGLES, 0, 3);

	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, &vertex_index);

	glDisableClientState(GL_COLOR_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);

	window.display();

}

void Game::unload()
{
	cout << "Cleaning up" << endl;
}

