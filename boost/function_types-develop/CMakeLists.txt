# Copyright 2019 Mike Dev
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE_1_0.txt or copy at https://www.boost.org/LICENSE_1_0.txt
#
# NOTE: CMake support for Boost.FunctionTypes is currently experimental at best
#       and the interface is likely to change in the future

#cmake_minimum_required( VERSION 3.5 )
#project( BoostFunctionTypes  LANGUAGES CXX )

add_library( boost_function_types INTERFACE )
add_library( Boost::function_types ALIAS boost_function_types )

target_include_directories( boost_function_types INTERFACE include )

target_link_libraries( boost_function_types
    INTERFACE
        Boost::config
        Boost::core
        Boost::detail
        Boost::mpl
        Boost::preprocessor
        Boost::type_traits
)

