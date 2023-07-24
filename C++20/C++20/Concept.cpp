#include <iostream>
#include <iostream>
using namespace std;
#include <list>
#include <algorithm>
// 오늘의 주제 : Concept (컨셉)

// static void TestObject<T>(T obj) where T : GameObject
// C#에는 제네릭 문법(C++의 템플릿과 유사)을 통해 타입을 동적으로 생성하면서
// where를 통해 타입에 대해 부가적인 조건을 걸어 (어떤 클래스에 파생된다든지)
// 원하는 타입을 생성할 수 있었다.

// C++에서는 원하는 특정 조건에 대해 한정짓는 문법이 없었지만
// C++20에 오면서 추가되었다.
// 단순하긴 하지만, C#처럼 단순하진 않다. (4가지 방식이나 있기때문)

// 1) Requires Clause(절)
template<typename T>
requires std::integral<T> // 정수만 받아주고, 소수점이 들어가는 수는 제외
void TestConcept1(T number)
{
	cout << number << endl;
}

// 2) Trailing Requires Clause (뒤에 붙는~)
template<typename T>
void TestConcept2(T number) requires std::integral<T>
{
	cout << number << endl;
}

// 3) Constrained Template Parameter (강요된)
template<std::integral T>
void TestConcept3(T number)
{
	cout << number << endl;
}

// 4) Abbreviated Function Template
void TestConcept4(std::integral auto number)
{
	cout << number << endl;
}


class GameObject
{

};

class Knight : public GameObject
{

};

template<typename T>
requires std::derived_from<T, GameObject>
void TestObj(T* obj)
{

}

template<typename T>
concept MyConcept = !std::is_integral_v<T> && std::derived_from<T, GameObject>;

template<typename T>
concept Addable = requires (T a, T b)
{
	a + b;
}; // a + b가 가능해야 함

template<typename T>
concept Equality = requires(T a, T b)
{
	{ a == b } -> std::convertible_to<bool>;
	{ a != b } -> std::convertible_to<bool>;
};

template<typename T>
concept Integral = std::is_integral_v<T>;

template<typename T>
concept SignedInt = Integral<T> && std::is_signed_v<T>;

int main()
{
	TestConcept4(10);
	//TestConcept4(10.3f);
	//const bool check = _Is_any_of_v<int, short, int, long long>;


	// 언어 관련
	// same_as
	// derived_from
	// convertible_to
	// common_reference_with
	// common_with
	// assignable_from
	// swappable

	// 산술 관련
	// integral
	// signed integral
	// unsigned_integral
	// floating_point

	// 생명주기 관련
	// destructible
	// constructible_from
	// default_constructible
	// move_constructible
	// copy_constructible

	// 비교 관련
	// equality_comparable
	// totally_ordered

	// 오브젝트 관련
	// movable
	// copyable
	// semiregular
	// regular

	// 호출(Callable) 관련
	// invocable
	// regular_invocable
	// predicate

	// 반복자 관련
	// input_iterator
	// output_iterator
	// forward_iterator
	// bidirectional_iterator
	// random_access_iterator (***)
	// contiguous_iterator

	// 알고리즘/범위 관련
	// permutable
	// mergeable
	// sortable
	// ranges::input_range
	// ranges::random_access_range
	// ...

	//list<int> li;
	//std::sort(li.begin(), li.end());

	TestObj(new Knight);
	//TestObj(new int);

}