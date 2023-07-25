// 모듈안에서 외부 라이브러리를 사용하고 싶을 때, 선언
module; // global module fragment

// 각종 외부 헤더 추가
// global module 선언하는 부분과 module 시작하는 부분 사이에 외부 라이브러리를 추가
#include <vector>

// module 시작
export module math;

// import module ...

// submodule
// math.time을 import해서 다시 math 모듈에 포함해서 export
export import math.time;

void Internal()
{

}

// 3) namespace를 지정
export namespace math
{
	void TestExport2()
	{

	}
}