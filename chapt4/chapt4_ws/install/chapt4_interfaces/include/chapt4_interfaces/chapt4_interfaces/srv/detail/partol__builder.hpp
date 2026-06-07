// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from chapt4_interfaces:srv/Partol.idl
// generated code does not contain a copyright notice

#ifndef CHAPT4_INTERFACES__SRV__DETAIL__PARTOL__BUILDER_HPP_
#define CHAPT4_INTERFACES__SRV__DETAIL__PARTOL__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "chapt4_interfaces/srv/detail/partol__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace chapt4_interfaces
{

namespace srv
{

namespace builder
{

class Init_Partol_Request_target_y
{
public:
  explicit Init_Partol_Request_target_y(::chapt4_interfaces::srv::Partol_Request & msg)
  : msg_(msg)
  {}
  ::chapt4_interfaces::srv::Partol_Request target_y(::chapt4_interfaces::srv::Partol_Request::_target_y_type arg)
  {
    msg_.target_y = std::move(arg);
    return std::move(msg_);
  }

private:
  ::chapt4_interfaces::srv::Partol_Request msg_;
};

class Init_Partol_Request_target_x
{
public:
  Init_Partol_Request_target_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Partol_Request_target_y target_x(::chapt4_interfaces::srv::Partol_Request::_target_x_type arg)
  {
    msg_.target_x = std::move(arg);
    return Init_Partol_Request_target_y(msg_);
  }

private:
  ::chapt4_interfaces::srv::Partol_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::chapt4_interfaces::srv::Partol_Request>()
{
  return chapt4_interfaces::srv::builder::Init_Partol_Request_target_x();
}

}  // namespace chapt4_interfaces


namespace chapt4_interfaces
{

namespace srv
{

namespace builder
{

class Init_Partol_Response_result
{
public:
  Init_Partol_Response_result()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::chapt4_interfaces::srv::Partol_Response result(::chapt4_interfaces::srv::Partol_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::chapt4_interfaces::srv::Partol_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::chapt4_interfaces::srv::Partol_Response>()
{
  return chapt4_interfaces::srv::builder::Init_Partol_Response_result();
}

}  // namespace chapt4_interfaces

#endif  // CHAPT4_INTERFACES__SRV__DETAIL__PARTOL__BUILDER_HPP_
