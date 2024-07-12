#pragma once

#include "rclcpp/rclcpp.hpp"
#include "rclcpp_lifecycle/state.hpp"

#include <iostream>

#include <pinocchio/multibody/joint/fwd.hpp>
#include <pinocchio/multibody/fcl.hpp>
#include <pinocchio/multibody/model.hpp>
#include <pinocchio/multibody/data.hpp>
#include <pinocchio/parsers/urdf.hpp>
#include <pinocchio/spatial/se3.hpp>

#include <pinocchio/algorithm/frames.hpp>
#include <pinocchio/algorithm/joint-configuration.hpp>
#include <pinocchio/algorithm/kinematics.hpp>
#include <pinocchio/algorithm/geometry.hpp>
#include <pinocchio/algorithm/jacobian.hpp>
#include <pinocchio/algorithm/rnea.hpp>
#include <pinocchio/algorithm/aba.hpp>


#include <Eigen/Dense>

namespace rsf
{
    class PinocchioInterface
    {
        explicit PinocchioInterface(std::string urdf_path_name);
        
        virtual void Update();

        virtual void SetJointMember();
        virtual void GetJointMember();

        virtual Eigen::Isometry3d GetFrame(std::string frame_name);

        virtual Eigen::MatrixXd GetJacobianMatrix(std::string frame_name);

        virtual Eigen::VectorXd GetLagrangeG();
    };
}