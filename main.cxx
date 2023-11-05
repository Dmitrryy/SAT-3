import BfRtSAT;

#include <vector>
#include <tuple>

int main(){
  std::vector<std::tuple<int, int, int>> clauses = {{1, 2, -3}, {2, 3, -1}};
  std::vector<int> vars;

  solve(clauses, vars);

  return 0;
}