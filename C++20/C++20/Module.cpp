#include <iostream>
using namespace std;

import math;
//import math.time;
// 
// 오늘의 주제 : module (모듈)

import MathPartition;

int main()
{
	// 빌드단계 구분

	// 전처리
	// - #include #define
	// 컴파일
	// - 오브젝트 파일 .obj
	// 링크

	// 기존에 사용하던 방법의 문제점
	// 1) 빌드 속도 (반복된 substitution)
	// 너무 너무 느리다
	// 2) 매크로 (#define)
	// 3) 심볼 중복 정의

	// Module
	// - 모듈은 딱 한번만 import 된다 (중첩되서 빌드가 여러번 되는 일이 없다)
	// - import 순서에 상관 없음 (#define의 순서에 따라 차이가 일어난 걸 방지)
	// - 심볼 중복 정의
	// - 모듈의 이름도 지정 가능
	// - 인터페이스/구현부 분리 관리할 필요 없음

	MathTimeFunc();

	MyFunc();
	MyFunc2();
}