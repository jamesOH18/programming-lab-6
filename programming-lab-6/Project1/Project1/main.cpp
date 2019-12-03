#ifdef _DEBUG 
#pragma comment(lib,"sfml-graphics-d.lib") 
#pragma comment(lib,"sfml-audio-d.lib") 
#pragma comment(lib,"sfml-system-d.lib") 
#pragma comment(lib,"sfml-window-d.lib") 
#pragma comment(lib,"sfml-network-d.lib") 
#else 
#pragma comment(lib,"sfml-graphics.lib") 
#pragma comment(lib,"sfml-audio.lib") 
#pragma comment(lib,"sfml-system.lib") 
#pragma comment(lib,"sfml-window.lib") 
#pragma comment(lib,"sfml-network.lib") 
#endif 

#include "matrix.h"
#include "vector3.h"

int main()
{
	MyMatrix3 matrixOne = {};
	MyMatrix3 matrixTwo = {};
	MyMatrix3 matrixThree = {};
	MyVector3 vectorOne = { 2,3,4 };
	MyVector3 vectorTwo = {};
	double det = 0;
	double scalar = 3;
	double Pi = 3.14159265358979323846;
	int row = 0;
	int col = 0;
	std::string answer;

	matrixOne = { 1,2,3,4,5,6,7,8,9 };
	std::cout << " string test " << std::endl;
	answer = matrixOne.toString();
	std::cout << answer << std::endl;
	std::cout << "--------------------------------" << std::endl;

	matrixTwo = { 1,2,3,4,5,6,7,8,9 };
	std::cout << " operator == " << std::endl;
	if (matrixOne == matrixTwo)
	{
		std::cout << " true " << std::endl;
	}
	else
	{
		std::cout << " false " << std::endl;
	}
	std::cout << " answer should be true " << std::endl;
	std::cout << "--------------------------------" << std::endl;

	std::cout << " operator != " << std::endl;
	if (matrixOne != matrixTwo)
	{
		std::cout << " true " << std::endl;
	}
	else
	{
		std::cout << " false " << std::endl;
	}
	std::cout << " answer should be fasle " << std::endl;
	std::cout << "--------------------------------" << std::endl;

	matrixTwo = { 1,1,1,1,1,1,1,1,1 };
	matrixThree = matrixOne + matrixTwo;

	std::cout << " operator + " << std::endl;
	answer = matrixThree.toString();
	std::cout << " answer should be :" << "\n" << answer << std::endl;
	std::cout << "--------------------------------" << std::endl;

	matrixThree = matrixOne - matrixTwo;
	std::cout << " operator - " << std::endl;
	answer = matrixThree.toString();
	std::cout << " answer should be :" << "\n" << answer << std::endl;
	std::cout << "--------------------------------" << std::endl;

	matrixTwo = { 2,2,2,2,2,2,2,2,2 };
	matrixThree = matrixOne * matrixTwo;
	std::cout << " operator * " << std::endl;
	answer = matrixThree.toString();
	std::cout << " answer should be :" << "\n" << answer << std::endl;
	std::cout << "--------------------------------" << std::endl;

	vectorTwo = matrixOne * vectorOne;
	std::cout << " operator * vector " << std::endl;
	answer = vectorTwo.toString();
	std::cout << " answer should be :" << "\n" << answer << std::endl;
	std::cout << "--------------------------------" << std::endl;

	matrixThree = matrixOne * scalar;
	std::cout << " operator * scalar" << std::endl;
	answer = matrixThree.toString();
	std::cout << " answer should be :" << "\n" << answer << std::endl;
	std::cout << "--------------------------------" << std::endl;

	matrixThree = matrixOne.transpose();
	std::cout << " transpose " << std::endl;
	answer = matrixThree.toString();
	std::cout << " answer should be :" << "\n" << answer << std::endl;
	std::cout << "--------------------------------" << std::endl;

	det = matrixOne.determinant();
	std::cout << " determinant " << std::endl;
	std::cout << " answer should be :" << "\n" << det << std::endl;
	std::cout << "--------------------------------" << std::endl;

	matrixThree = matrixOne.inverse();
	std::cout << " inverse " << std::endl;
	answer = matrixThree.toString();
	std::cout << " answer should be :" << "\n" << answer << std::endl;
	std::cout << "--------------------------------" << std::endl;

	vectorOne = matrixOne.row(row);
	std::cout << " row 0 " << std::endl;
	answer = vectorOne.toString();
	std::cout << " answer should be :" << "\n" << answer << std::endl;
	std::cout << "--------------------------------" << std::endl;

	vectorOne = matrixOne.column(col);
	std::cout << " col 0 " << std::endl;
	answer = vectorOne.toString();
	std::cout << " answer should be :" << "\n" << answer << std::endl;
	std::cout << "--------------------------------" << std::endl;

	vectorOne = { 1,2,3 };

	vectorOne = MyMatrix3::rotationZ(Pi / 2) * vectorOne;
	std::cout << " rotation z " << std::endl;
	answer = vectorOne.toString();
	std::cout << " answer should be :" << "\n" << answer << std::endl;
	std::cout << "--------------------------------" << std::endl;

	vectorOne = { 1,2,3 };
	vectorOne = MyMatrix3::rotationY(Pi / 2) * vectorOne;
	std::cout << " rotation y " << std::endl;
	answer = vectorOne.toString();
	std::cout << " answer should be :" << "\n" << answer << std::endl;
	std::cout << "--------------------------------" << std::endl;

	vectorOne = { 1,2,3 };
	vectorOne = MyMatrix3::rotationX(Pi / 2) * vectorOne;
	std::cout << " rotation x " << std::endl;
	answer = vectorOne.toString();
	std::cout << " answer should be :" << "\n" << answer << std::endl;
	std::cout << "--------------------------------" << std::endl;


	vectorOne = { 5, 6, 0 };
	matrixThree = matrixOne.translation(vectorOne);
	vectorOne = { 2,2,1 };
	vectorTwo = matrixThree * vectorOne;

	std::cout << " translation " << std::endl;
	answer = vectorTwo.toString();
	std::cout << " answer should be :" << "\n" << answer << std::endl;
	std::cout << "--------------------------------" << std::endl;

	matrixOne = { 1,2,3,4,5,6,7,8,9 };
	scalar = 3;
	matrixThree = matrixOne.scale(scalar);

	std::cout << " scale " << std::endl;
	answer = matrixThree.toString();
	std::cout << " answer should be :" << "\n" << answer << std::endl;
	std::cout << "--------------------------------" << std::endl;
	system("pause");
	
	MyVector3 vectorOne{};
	MyVector3 vectorTwo{};
	MyVector3 vectorThree{};

	std::cout << "[0.0     ,0.0     ,0.0     ]" << std::endl;
	std::cout << vectorOne.toString() << std::endl;
	std::cout << "Null / default constructor" << std::endl;
	std::cout << "----------------------------" << std::endl;
	sf::Vector3f sfV3f{ 1.2f, -3.2f,1.9f };

	vectorOne = sfV3f;
	std::cout << "[1.2     ,-3.2     ,1.9     ]" << std::endl;
	std::cout << vectorOne.toString() << std::endl;
	std::cout << "sf::vector3f constructor" << std::endl;
	std::cout << "----------------------------" << std::endl;

	sf::Vector2f sfV2f = vectorOne;

	vectorOne = sfV2f;
	std::cout << "[1.2     ,-3.2  ]" << std::endl;
	std::cout << vectorOne.toString() << std::endl;
	std::cout << "sf::vector2f constructor" << std::endl;
	std::cout << "----------------------------" << std::endl;

	sf::Vector3i sfV3i = { 1,-3,5 };

	vectorOne = sfV3i;
	std::cout << "[1     ,-3 , 5 ]" << std::endl;
	std::cout << vectorOne.toString() << std::endl;
	std::cout << "sf::vector3i constructor" << std::endl;
	std::cout << "----------------------------" << std::endl;

	sf::Vector2i sfV2i = { 1,-3 };

	vectorOne = sfV2i;
	std::cout << "[1 , -3 ]" << std::endl;
	std::cout << vectorOne.toString() << std::endl;
	std::cout << "sf::vector32i constructor" << std::endl;
	std::cout << "----------------------------" << std::endl;

	sf::Vector2i sfV2u = { 1,4 };

	vectorOne = sfV2u;
	std::cout << "[1 , 4 ]" << std::endl;
	std::cout << vectorOne.toString() << std::endl;
	std::cout << "sf::vector32i constructor" << std::endl;
	std::cout << "----------------------------" << std::endl;

	vectorOne = { 1,4,3 };
	vectorTwo = { 3,7,2 };
	vectorThree = vectorOne + vectorTwo;

	std::cout << "[4, 11, 5 ]" << std::endl;
	std::cout << vectorThree.toString() << std::endl;
	std::cout << "+operator " << std::endl;
	std::cout << "----------------------------" << std::endl;

	vectorOne = { 1,4,3 };
	vectorTwo = { 3,7,2 };
	vectorThree = vectorOne - vectorTwo;

	std::cout << "[-2, -3, 1 ]" << std::endl;
	std::cout << vectorThree.toString() << std::endl;
	std::cout << "-operator " << std::endl;
	std::cout << "----------------------------" << std::endl;

	vectorOne = { 1,4,3 };
	vectorThree = vectorOne * 3;

	std::cout << "[3, 12, 9 ]" << std::endl;
	std::cout << vectorThree.toString() << std::endl;
	std::cout << " *operator " << std::endl;
	std::cout << "----------------------------" << std::endl;

	vectorOne = { 3,15,6 };
	vectorThree = vectorOne / 3;

	std::cout << "[1, 5, 2 ]" << std::endl;
	std::cout << vectorThree.toString() << std::endl;
	std::cout << " /operator " << std::endl;
	std::cout << "----------------------------" << std::endl;

	vectorOne = { 1,1,1 };
	vectorTwo = { 3,5,6 };

	vectorOne += vectorTwo;
	std::cout << "[4 ,6 ,7  ]" << std::endl;
	std::cout << vectorOne.toString() << std::endl;
	std::cout << " +=operator " << std::endl;
	std::cout << "----------------------------" << std::endl;

	vectorOne = { 1,1,1 };
	vectorTwo = { 3,5,6 };

	vectorOne -= vectorTwo;
	std::cout << "[-2 ,-4 ,-5  ]" << std::endl;
	std::cout << vectorOne.toString() << std::endl;
	std::cout << " -=operator " << std::endl;
	std::cout << "----------------------------" << std::endl;


	vectorOne = { 1,1,1 };
	vectorTwo = { 1,1,1 };

	std::cout << "[vectorOne = vectorTwo]" << std::endl;
	std::cout << std::to_string(vectorOne == vectorTwo) << std::endl;
	std::cout << "true " << std::endl;
	std::cout << "----------------------------" << std::endl;

	vectorOne = { 1,1,1 };
	vectorTwo = { 1,1,1 };

	std::cout << "[vectorOne = vectorTwo]" << std::endl;
	std::cout << std::to_string(vectorOne != vectorTwo) << std::endl;
	std::cout << "false " << std::endl;
	std::cout << "----------------------------" << std::endl;


	vectorThree = vectorOne * -1;
	std::cout << "[vectorOne = vectorTwo]" << std::endl;
	std::cout << vectorThree.toString() << std::endl;
	std::cout << "false " << std::endl;
	std::cout << "----------------------------" << std::endl;


	vectorOne = { 1,0,0 };
	vectorOne.reverseX();
	std::cout << "[-1,0,0 ]" << std::endl;
	std::cout << vectorOne.toString() << std::endl;
	std::cout << "reverse x " << std::endl;
	std::cout << "----------------------------" << std::endl;

	vectorOne = { 0,1,0 };
	vectorOne.reverseY();
	std::cout << "[0,-1,0 ]" << std::endl;
	std::cout << vectorOne.toString() << std::endl;
	std::cout << "reverse y " << std::endl;
	std::cout << "----------------------------" << std::endl;


	vectorOne = { 5,6,4 };
	std::cout << "[8.744694]" << std::endl;
	std::cout << std::to_string(vectorOne.length()) << std::endl;
	std::cout << "length " << std::endl;
	std::cout << "----------------------------" << std::endl;


	std::cout << "[77]" << std::endl;
	std::cout << std::to_string(vectorOne.lengthSquared()) << std::endl;
	std::cout << "length squared " << std::endl;
	std::cout << "----------------------------" << std::endl;

	vectorTwo = { 1,1,1 };
	std::cout << "[15]" << std::endl;
	std::cout << std::to_string(vectorOne.dot(vectorTwo)) << std::endl;
	std::cout << "dot product " << std::endl;
	std::cout << "----------------------------" << std::endl;

	vectorThree = vectorOne.crossProduct(vectorTwo);
	std::cout << "[2,-1,-1]" << std::endl;
	std::cout << vectorThree.toString() << std::endl;
	std::cout << "cross product " << std::endl;
	std::cout << "----------------------------" << std::endl;

	std::cout << "[9.274500]" << std::endl;
	std::cout << std::to_string(vectorOne.angleBetween(vectorTwo)) << std::endl;
	std::cout << "angle between " << std::endl;
	std::cout << "----------------------------" << std::endl;

	vectorThree = vectorOne.unit();
	std::cout << "[0.569803,0.683763,0.455842]" << std::endl;
	std::cout << vectorThree.toString() << std::endl;
	std::cout << "vector unit " << std::endl;
	std::cout << "----------------------------" << std::endl;

	vectorThree = { 5,7,6 };
	vectorThree.normalise();
	std::cout << "[0.476731,0.667242,0.572078]" << std::endl;
	std::cout << vectorThree.toString() << std::endl;
	std::cout << "normalise " << std::endl;
	std::cout << "----------------------------" << std::endl;

	vectorThree = vectorOne.projection(vectorTwo);
	std::cout << "[5,5,5]" << std::endl;
	std::cout << vectorThree.toString() << std::endl;
	std::cout << "projection " << std::endl;
	std::cout << "----------------------------" << std::endl;

	vectorThree = vectorOne.rejection(vectorTwo);
	std::cout << "[-4,-4,-4]" << std::endl;
	std::cout << vectorThree.toString() << std::endl;
	std::cout << "projection " << std::endl;
	std::cout << "----------------------------" << std::endl;

	MyVector3 sfVector3{ 1.1, -3.1, 1 };
	sf::Vector2f sfV2f1 = sfVector3;

	std::cout << "[1.1   ,-3.1]" << std::endl;
	std::cout << "sf::vector2f converter" << std::endl;
	std::cout << "----------------------------" << std::endl;

	MyVector3 sfVector3s{ 1.1f, -3.1f, 1.0f };
	sf::Vector2i sfV2f2 = sfVector3s;

	std::cout << "[1 ,-3 ]" << std::endl;
	std::cout << "sf::vector2i converter" << std::endl;
	std::cout << "----------------------------" << std::endl;

	MyVector3 sfVector3n{ 1.0f, -3.0f, 1.0f };
	sf::Vector2u sfV2f3 = sfVector3n;

	std::cout << "[1 ,3 ]" << std::endl;
	std::cout << "sf::vector2u converter" << std::endl;
	std::cout << "----------------------------" << std::endl;

	MyVector3 sfVector3d{ 1.1f , -3.1f ,1.5f };
	sf::Vector3i sfV2f4 = sfVector3d;

	std::cout << "[1,-3 ]" << std::endl;
	std::cout << "sf::vector3i converter" << std::endl;
	std::cout << "----------------------------" << std::endl;

	MyVector3 sfVector3b{ 1.1f , -3.1f ,1.0f };
	sf::Vector3f  vectorthree = sfVector3b;

	std::cout << "[1.1 ,-3.1 ]" << std::endl;
	std::cout << "sf::vector3f converter" << std::endl;
	std::cout << "----------------------------" << std::endl;

	std::system("pause");
	return EXIT_SUCCESS;


}