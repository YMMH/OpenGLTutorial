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

	//윈도우 설정
	GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);


	//OpenGL 함수 호출 전 GLAD 초기화
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	//OpenGL에 rendering window size noti
	glViewport(0, 0, WIN_WIDTH, WIN_HEIGHT);//Screen 좌표를 2D 좌표로 변환

	//모든 창의 크기가 변경 될 때마다 작성한 사이즈 변경 함수를 호출하겠다고 GLFW에 noti
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	//프로그램이 계속 실행될 수 있도록 하는 render loop
	while (!glfwWindowShouldClose(window)) {

		//입력처리
		processInput(window);

		//렌더링 명령
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		//이벤트 확인, 버퍼 교체
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();//모든 자원 정리/삭제


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