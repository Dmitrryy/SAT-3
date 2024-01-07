module;
#include <algorithm>
#include <cmath>
#include <optional>
#include <tuple>
#include <vector>

export module BfRtSAT;

constexpr int myAbs(int a) { return a < 0 ? -a : a; }

export template <size_t ClausesN, size_t VarsN>
constexpr bool
isSolution(const std::array<int, VarsN> &vars,
           const std::array<std::tuple<int, int, int>, ClausesN> &clauses) {
  for (const auto &clause : clauses) {
    int v1 = get<0>(clause);
    int v2 = get<1>(clause);
    int v3 = get<2>(clause);
    bool c1 = (v1 > 0) ? vars[myAbs(v1) - 1] : !vars[myAbs(v1) - 1];
    bool c2 = (v2 > 0) ? vars[myAbs(v2) - 1] : !vars[myAbs(v2) - 1];
    bool c3 = (v3 > 0) ? vars[myAbs(v3) - 1] : !vars[myAbs(v3) - 1];
    if (!(c1 || c2 || c3))
      return false;
  }
  return true;
}

template <size_t ClausesN, size_t VarsN>
constexpr std::optional<std::array<int, VarsN>>
recSolve(int varIdx, std::array<int, VarsN> &vars,
         const std::array<std::tuple<int, int, int>, ClausesN> &clauses) {
  if (varIdx == vars.size()) {
    if (isSolution(vars, clauses)) {
      return vars;
    } else {
      return std::nullopt;
    }
  }

  if consteval {
    // in compile-time we can not change 'vars', that declared outside function.
    auto tmp_vars = vars;
    tmp_vars[varIdx] = 0;
    if (recSolve(varIdx + 1, tmp_vars, clauses))
      return tmp_vars;
    tmp_vars[varIdx] = 1;
    if (recSolve(varIdx + 1, tmp_vars, clauses))
      return tmp_vars;
  } else {
    // runtime version
    vars[varIdx] = 0;
    if (recSolve(varIdx + 1, vars, clauses))
      return vars;
    vars[varIdx] = 1;
    if (recSolve(varIdx + 1, vars, clauses))
      return vars;
  }

  return std::nullopt;
}

export template <size_t VarsN, size_t ClausesN>
std::optional<std::array<int, VarsN>>
solve(const std::array<std::tuple<int, int, int>, ClausesN> &clauses) {
  std::array<int, VarsN> vars = {};
  return recSolve(0, vars, clauses);
}

export template <size_t VarsN, size_t ClausesN>
consteval std::optional<std::array<int, VarsN>>
solve_compile(const std::array<std::tuple<int, int, int>, ClausesN> &clauses) {
  std::array<int, VarsN> vars = {};
  return recSolve(0, vars, clauses);
}
