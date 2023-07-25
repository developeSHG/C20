export module MathPartition;

// Partition
// module도 커지게 되면 분할 가능
export import :MathPartition_1;
export import :MathPartition_2;

// 파티션으로 만든 module들은 cpp파일에서 독립적으로 사용할 수 없다.
// (Math_TIme은 독립적이지 않아서 사용 가능)