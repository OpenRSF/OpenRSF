#pragma once

#include <rsf_core/typedef.hpp>

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
    size_t getNumFunctionCalls() const { return numFunctionCalls_; }

    /** Resets the number of function calls to zero. */
    void resetNumFunctionCalls() { numFunctionCalls_ = 0; }

    /** Increments the number of function calls. */
    size_t incrementNumFunctionCalls() { return ++numFunctionCalls_; }

    /**
     * 计算常微分方程流型图.
     * @param [in] t: Current time.
     * @param [in] x: Current state.
     * @return 返回的是状态关于时间的导数
     */
    virtual vector_t computeFlowMap(scalar_t t, const vector_t &x) = 0;

    /**
     * 计算通过状态切换超平面后的状态
     *
     * @param [in] time: transition time
     * @param [in] state: transition state
     * @return 通过状态切换超平面后的状态
     */
    virtual vector_t computeJumpMap(scalar_t time, const vector_t &state);

    /**
     * 计算状态切换超平面的相对位置
     *
     * @param [in] time: transition time
     * @param [in] state: transition state
     * @return 返回状态切换超平面的相对位置
     */
    virtual vector_t computeGuardSurfaces(scalar_t time, const vector_t &state);

  protected:
    /** Copy constructor */
    OdeBase(const OdeBase &rhs) : numFunctionCalls_(0) {}

  private:
    size_t numFunctionCalls_ = 0;
  };

} 