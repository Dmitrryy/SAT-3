module;
#include <algorithm>
#include <tuple>
#include <vector>

export module BfRtSAT;

export bool isSolution(const std::vector<int> &vars,
                   const std::vector<std::tuple<int, int, int>> &clauses) {
  for (const auto &clause : clauses) {
    int v1 = get<0>(clause);
    int v2 = get<1>(clause);
    int v3 = get<2>(clause);
    bool c1 = (v1 > 0) ? vars[abs(v1) - 1] : !vars[abs(v1) - 1];
    bool c2 = (v2 > 0) ? vars[abs(v2) - 1] : !vars[abs(v2) - 1];
    bool c3 = (v3 > 0) ? vars[abs(v3) - 1] : !vars[abs(v3) - 1];
    if (!(c1 || c2 || c3))
      return false;
  }
  return true;
}

bool recSolve(int varIdx, std::vector<int> &vars,
              const std::vector<std::tuple<int, int, int>> &clauses) {
  if (varIdx == vars.size()) {
    return isSolution(vars, clauses);
  }

  vars[varIdx] = 0;
  if (recSolve(varIdx + 1, vars, clauses))
    return true;
  vars[varIdx] = 1;
  if (recSolve(varIdx + 1, vars, clauses))
    return true;
  return false;
}

export int countVars(const std::vector<std::tuple<int, int, int>> &clauses) {
  int result = 0;
  for (const auto &clause : clauses) {
    result = std::max(std::abs(get<0>(clause)), result);
    result = std::max(std::abs(get<1>(clause)), result);
    result = std::max(std::abs(get<2>(clause)), result);
  }
  return result;
}

export bool solve(const std::vector<std::tuple<int, int, int>> &clauses,
                  std::vector<int> &vars) {
  vars.resize(countVars(clauses));
  return recSolve(0, vars, clauses);
}
