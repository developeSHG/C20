// ���ȿ��� �ܺ� ���̺귯���� ����ϰ� ���� ��, ����
module; // global module fragment

// ���� �ܺ� ��� �߰�
// global module �����ϴ� �κа� module �����ϴ� �κ� ���̿� �ܺ� ���̺귯���� �߰�
#include <vector>

// module ����
export module math;

// import module ...

// submodule
// math.time�� import�ؼ� �ٽ� math ��⿡ �����ؼ� export
export import math.time;

void Internal()
{

}

// 3) namespace�� ����
export namespace math
{
	void TestExport2()
	{

	}
}