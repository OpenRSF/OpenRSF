#pragma once

#include <vector>

namespace rsf
{
  /// @brief 常微分方程类
  class OdeBase
  {
  public:
    /** Default constructor */
    OdeBase() = default;

    /** Default destructor */
    virtual ~OdeBase() = default;

    /** Returns the number of function calls. */
    int getNumFunctionCalls() const { return numFunctionCalls_; }

    /** Resets the number of function calls to zero. */
    void resetNumFunctionCalls() { numFunctionCalls_ = 0; }

    /** Increments the number of function calls. */
    int incrementNumFunctionCalls() { return ++numFunctionCalls_; }

    /**
     * 计算常微分方程流型图.
     * @param [in] t: Current time.
     * @param [in] x: Current state.
     * @return 返回的是状态关于时间的导数
     */
    virtual std::vector<double> computeFlowMap(double t, const std::vector<double> &x) = 0;

    /**
     * 计算通过状态切换超平面后的状态
     *
     * @param [in] time: transition time
     * @param [in] state: transition state
     * @return 通过状态切换超平面后的状态
     */
    virtual std::vector<double> computeJumpMap(double time, const std::vector<double> &state);

    /**
     * 计算状态切换超平面的相对位置
     *
     * @param [in] time: transition time
     * @param [in] state: transition state
     * @return 返回状态切换超平面的相对位置
     */
    virtual std::vector<double> computeGuardSurfaces(double time, const std::vector<double> &state);

  protected:
    /** Copy constructor */
    OdeBase(const OdeBase &rhs) : numFunctionCalls_(0) {}

  private:
    int numFunctionCalls_ = 0;
  };

} 