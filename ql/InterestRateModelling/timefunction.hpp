

/*
 Copyright (C) 2000, 2001, 2002 RiskMap srl

 This file is part of QuantLib, a free-software/open-source library
 for financial quantitative analysts and developers - http://quantlib.org/

 QuantLib is free software: you can redistribute it and/or modify it under the
 terms of the QuantLib license.  You should have received a copy of the
 license along with this program; if not, please email ferdinando@ametrano.net
 The license is also available online at http://quantlib.org/html/license.html

 This program is distributed in the hope that it will be useful, but WITHOUT
 ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 FOR A PARTICULAR PURPOSE.  See the license for more details.
*/
/*! \file timefunction.hpp
    \brief Time function used for term structure fitting

    \fullpath
    ql/InterestRateModelling/%timefunction.hpp
*/

// $Id$

#ifndef quantlib_time_function_h
#define quantlib_time_function_h

#include <ql/qldefines.hpp>
#include <ql/Math/cubicspline.hpp>
#include <ql/InterestRateModelling/onefactormodel.hpp>

#include <iostream>

namespace QuantLib {

    namespace InterestRateModelling {

        class TimeFunction {
          public:
            typedef Math::CubicSpline<std::vector<Time>::iterator,
                                      std::vector<double>::iterator> Spline;
            TimeFunction()
            : updated_(false), times_(0), values_(0) {}
            ~TimeFunction() {}
            void set(Time t, double x) {
                updated_ = false;
                times_.push_back(t);
                values_.push_back(x);
            }
            void update() {
                interpolation_ = Handle<Spline>(new Spline(
                    times_.begin(), times_.end(), values_.begin()));
                updated_ = true;
            }
            void reset() {
                times_.clear();
                values_.clear();
                updated_ = false;
            }
            double operator()(Time t) {
                if (!updated_) {
                    for (Size i=0; i<times_.size(); i++)
                        if (times_[i] == t)
                            return values_[i];
                    std::cout << "interpolating at time " << t << std::endl;
                    update();
                }
                return (*interpolation_)(t);
            }
            void fitToTermStructure(const OneFactorModel& model,
                                    Size timeSteps);
          private:
            class FitFunction;

            bool updated_;
            Handle<Spline> interpolation_;
            std::vector<Time> times_;
            std::vector<double> values_;
        };

    }

}


#endif
