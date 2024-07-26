#include <rsf_core/math/ode/OdeBase.hpp>

namespace rsf
{
  /******************************************************************************************************/
  /******************************************************************************************************/
  /******************************************************************************************************/
  std::vector<double> OdeBase::computeJumpMap(double time, const std::vector<double> &state)
  {
    return state;
  }

  /******************************************************************************************************/
  /******************************************************************************************************/
  /******************************************************************************************************/
  std::vector<double> OdeBase::computeGuardSurfaces(double time, const std::vector<double> &state)
  {
    return std::vector<double>::Ones(1);
  }
} // namespace ocs2