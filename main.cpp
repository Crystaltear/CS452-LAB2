#include <GL/glew.h>
#include <GL/freeglut.h>
#include <stdio.h>
#include "initShader.h"
//#include <cmath>
//#include "vec.h"

#define NUM_VERTICES 21


#define BUFFER_OFFSET(i) ((char *)NULL + (i))
GLuint shaderProgramID;
GLuint vao = 0;
GLuint vbo;
GLuint positionID, colorID;
GLuint indexBufferID;

int counter = 0;

//vec3 initVertex(){
//	vec3 vertices[21];
//	const float kfPi = 3.141592653589793238462643383279;
//	const float kfRadius = 0.4;
//	const float kfInnerRadius = kfRadius*(1.0/(sin((2.0*kfPi)/5.0)*2.0*cos(kfPi/10.0) + sin((3.0*kfPi)/10.0)));
//	float j;
//	float k;
//	int i=0;
//	vertices[i] = vec3(0.5f,0.5f,0.0f);
//	i++;
//	for (int iVertIndex = 0; iVertIndex < 10; ++iVertIndex) {
//		float fAngleStart	= kfPi/2.0 + (iVertIndex*2.0*kfPi)/10.0;
//		float fAngleEnd		= fAngleStart + kfPi/5.0;
//		if (iVertIndex % 2 == 0) {
//			j = 0.5 + kfRadius*cos(fAngleStart)/1.1;
//			k = 0.5 + kfRadius*sin(fAngleStart);
//			vertices[i]=vec3(j,k,0.0f);
//			i++;
//			j = 0.5 + kfInnerRadius*cos(fAngleEnd)/1.1;
//			k = 0.5 + kfInnerRadius*sin(fAngleEnd);
//			vertices[i]=vec3(j,k,0.0f);
//			i++;
//		} else {
//			j = 0.5 + kfInnerRadius*cos(fAngleStart)/1.1;
//			k = 0.5 + kfInnerRadius*sin(fAngleStart);
//			vertices[i]=vec3(j,k,0.0f);
//			i++;
//			j = 0.5 + kfRadius*cos(fAngleEnd)/1.1;
//			k = 0.5 + kfRadius*sin(fAngleEnd);
//			vertices[i]=vec3(j,k,0.0f);
//			i++;
//		}
//	}
//	return vertices;
//
//}


// Any time the window is resized, this function gets called.  It's setup to the 
// "glutReshapeFunc" in main.
void changeViewport(int w, int h){
	glViewport(0, 0, w, h);
}

// Here is the function that gets called each time the window needs to be redrawn.
// It is the "paint" method for our program, and is set up from the glutDisplayFunc in main
void render() {
	switch (counter%2) {
	case 0:
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		glDrawArrays(GL_LINE_STRIP, 0, NUM_VERTICES);
		glutSwapBuffers();
		break;
	case 1:
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		glDrawArrays(GL_TRIANGLE_FAN, 0, NUM_VERTICES);
		glutSwapBuffers();
		break;
	}
}
void mousepress(int button, int state, int x, int y){
  if(button==GLUT_RIGHT_BUTTON && state==GLUT_DOWN)//right click closes the screen
    exit(0);
  else if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN){//left click changes the shape color
	counter++;
    render();
  }
}

int main (int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA|GLUT_DOUBLE|GLUT_DEPTH);
	glutInitWindowSize(250, 250);
	glutInitWindowPosition(200, 200);
	glutCreateWindow("lab2");
	glutReshapeFunc(changeViewport);
	glutMouseFunc(mousepress);//control callback specifies the mouse controls
	glutDisplayFunc(render);
	glewInit();


	GLfloat vertices[] = {0.5f, 0.5f, 0.0f, 
						0.5f, 0.9f, 0.0f, 
						0.418359f, 0.623607f, 0.0f,
						0.418359f, 0.623607f, 0.0f,
						0.154161f, 0.623607f, 0.0f,
						0.154161f, 0.623607f, 0.0f,
						0.367901f, 0.452786f, 0.0f,
						0.367901f, 0.452786f, 0.0f,
						0.28626f, 0.176393f, 0.0f,
						0.28626f, 0.176393f, 0.0f,
						0.5f, 0.347214f, 0.0f,
						0.5f, 0.347214f, 0.0f,
						0.71374f, 0.176393f, 0.0f,
						0.71374f, 0.176393f, 0.0f,
						0.632099f, 0.452786f, 0.0f,
						0.632099f, 0.452786f, 0.0f,
						0.845839f, 0.623607f, 0.0f,
						0.845839f, 0.623607f, 0.0f,
						0.581641f, 0.623607f, 0.0f,
						0.581641f, 0.623607f, 0.0f,
						0.5f, 0.9f, 0.0f,
	};
	GLfloat colors[] = {1.0f, 1.00f, 1.0f, 1.0f, 
						0.0f, 1.00f, 0.0f, 1.0f,
						0.0f, 0.0f, 1.0f, 1.0f,
						1.0f, 0.00f, 0.0f, 1.0f, 
						0.0f, 1.00f, 1.0f, 1.0f,
						1.0f, 1.0f, 0.0f, 1.0f,
						1.0f, 0.00f, 1.0f, 1.0f, 
						0.0f, 1.00f, 0.0f, 1.0f,
						0.0f, 0.0f, 1.0f, 1.0f,
						1.0f, 0.00f, 0.0f, 1.0f, 
						0.0f, 1.00f, 1.0f, 1.0f,
						1.0f, 1.0f, 0.0f, 1.0f,
						1.0f, 0.00f, 1.0f, 1.0f, 
						1.0f, 0.00f, 0.0f, 1.0f, 
						0.0f, 1.00f, 0.0f, 1.0f,
						0.0f, 0.0f, 1.0f, 1.0f,
						1.0f, 0.00f, 0.0f, 1.0f, 
						0.0f, 1.00f, 1.0f, 1.0f,
						1.0f, 1.0f, 0.0f, 1.0f,
						1.0f, 0.00f, 1.0f, 1.0f, 
						0.0f, 1.0f, 0.0f, 1.0f
	};


	// Make a shader
	char* vertexShaderSourceCode = readFile("vertexShader.glsl");
	char* fragmentShaderSourceCode = readFile("fragmentShader.glsl");
	GLuint vertShaderID = makeVertexShader(vertexShaderSourceCode);
	GLuint fragShaderID = makeFragmentShader(fragmentShaderSourceCode);
	shaderProgramID = makeShaderProgram(vertShaderID, fragShaderID);

	// Create the "remember all"
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	// Create the buffer, but don't load anything yet
	glBufferData(GL_ARRAY_BUFFER, 7*NUM_VERTICES*sizeof(GLfloat), NULL, GL_STATIC_DRAW);
	// Load the vertex points
	glBufferSubData(GL_ARRAY_BUFFER, 0, 3*NUM_VERTICES*sizeof(GLfloat), vertices); 
	// Load the colors right after that
	glBufferSubData(GL_ARRAY_BUFFER, 3*NUM_VERTICES*sizeof(GLfloat),4*NUM_VERTICES*sizeof(GLfloat), colors);

	
	// Find the position of the variables in the shader
	positionID = glGetAttribLocation(shaderProgramID, "s_vPosition");
	colorID = glGetAttribLocation(shaderProgramID, "s_vColor");

	glVertexAttribPointer(positionID, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glVertexAttribPointer(colorID, 4, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(sizeof(vertices)));
	glUseProgram(shaderProgramID);
	glEnableVertexAttribArray(positionID);
	glEnableVertexAttribArray(colorID);
	
	glutMainLoop();
	
	return 0;
}
