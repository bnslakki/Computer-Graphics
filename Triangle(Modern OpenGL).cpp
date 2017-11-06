#include <GL/glew.h>
#include <GL/glut.h>
#include <chrono>
#include <math.h>

GLuint vao, vbo, vertexShader, fragmentShader, shaderProgram;

const GLchar* vertexSource = R"glsl(
    #version 150 core
    in vec2 position;
    void main()
    {
        gl_Position = vec4(position, 0.0, 1.0);
    }
)glsl";

const GLchar* fragmentSource = R"glsl(
    #version 150 core
    uniform vec3 triangleColor;
    out vec4 outColor;
    void main()
    {
        outColor = vec4(triangleColor, 1.0);
    }
)glsl";

GLfloat vertices[] = {
         0.0f,  0.5f,
         0.5f, -0.5f,
        -0.5f, -0.5f
};

void init(){
    glewInit();
     // Create Vertex Array Object

    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    //Create a Vertex Buffer Object and copy the vertex data to it

    glGenBuffers(1, &vbo);



    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // Create and compile the vertex shader
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexSource, NULL);
    glCompileShader(vertexShader);

    // Create and compile the fragment shader
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
    glCompileShader(fragmentShader);

    // Link the vertex and fragment shader into a shader program
    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glBindFragDataLocation(shaderProgram, 0, "outColor");
    glLinkProgram(shaderProgram);
    glUseProgram(shaderProgram);

    // Specify the layout of the vertex data
    GLint posAttrib = glGetAttribLocation(shaderProgram, "position");
    glEnableVertexAttribArray(posAttrib);
    glVertexAttribPointer(posAttrib, 2, GL_FLOAT, GL_FALSE, 0, 0);

    // specify color of triangle
    GLint uniColor = glGetUniformLocation(shaderProgram, "triangleColor");
    glUniform3f(uniColor, 1.0f, 0.0f, 0.0f);

}

void display(){
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    glutSwapBuffers();
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(840,480);
	glutInitWindowPosition(100,100);
	glutCreateWindow("Triangle");
	init();
	glutDisplayFunc(display);

	glutMainLoop();

    glDeleteProgram(shaderProgram);
    glDeleteShader(fragmentShader);
    glDeleteShader(vertexShader);
    glDeleteBuffers(1, &vbo);
    glDeleteVertexArrays(1, &vao);

    return 0;
}
