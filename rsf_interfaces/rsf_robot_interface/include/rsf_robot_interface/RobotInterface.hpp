#pragma once

#include "rclcpp/rclcpp.hpp"
#include "rclcpp_lifecycle/state.hpp"

#include <iostream>

namespace rsf
{
    class RobotInterface
    {
        explicit RobotInterface();
        
        virtual void Update();
    };
}