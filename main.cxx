import BfRtSAT;

#include <vector>
#include <tuple>

int main(){
  std::array<std::tuple<int, int, int>, 2> clauses = {{{1, 2, -3}, {2, 3, -1}}};

  solve<3>(clauses);

  return 0;
}