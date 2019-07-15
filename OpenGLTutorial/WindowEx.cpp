#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

#define WIN_HEIGHT 600
#define WIN_WIDTH 800

void framebuffer_size_callback(GLFWwindow *window, int width, int height);
void processInput(GLFWwindow* window);

int main()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	//glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	//������ ����
	GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);


	//OpenGL �Լ� ȣ�� �� GLAD �ʱ�ȭ
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	//OpenGL�� rendering window size noti
	glViewport(0, 0, WIN_WIDTH, WIN_HEIGHT);//Screen ��ǥ�� 2D ��ǥ�� ��ȯ

	//��� â�� ũ�Ⱑ ���� �� ������ �ۼ��� ������ ���� �Լ��� ȣ���ϰڴٰ� GLFW�� noti
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	//���α׷��� ��� ����� �� �ֵ��� �ϴ� render loop
	while (!glfwWindowShouldClose(window)) {

		//�Է�ó��
		processInput(window);

		//������ ���
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		//�̺�Ʈ Ȯ��, ���� ��ü
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();//��� �ڿ� ����/����


	return 0;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

void processInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, true);
	}
}