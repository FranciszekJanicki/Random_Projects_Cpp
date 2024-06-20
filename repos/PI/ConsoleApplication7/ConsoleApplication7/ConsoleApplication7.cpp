#include "Classes.h"

int main(void) {

	Vector3D vec1(1, 2, 3);
	Vector3D vec2(1, 2, 3);
	Point3D pnt1(1, 2, 3);
	Point3D pnt2(1, 2, 3);
	Point3D pnt3;
	Point3D pnt4;
	Point3D pnt5;

	double ans = vec1 * vec2;
	pnt3 = pnt1 + vec2;
	pnt4 = pnt2 + ans;
	pnt5 = pnt1 - vec1;

	std::cout << ans << '\n';
	std::cout << pnt3;
	std::cout << pnt4;
	std::cout << pnt5;

	return 0;
}